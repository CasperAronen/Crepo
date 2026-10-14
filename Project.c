#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 200
#define LENGTH 64

typedef struct {
    char day[LENGTH];
    char time[LENGTH];
    char course[LENGTH];
    char room[LENGTH];
    char minutes;
}Entry;

static void trim(char *s)
{
    char * start = s;
    while (isspace((unsigned char)*start)) start++;
    memmove(s, start, strlen(start)+1);

    size_t len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len-1])) s[len-1] = '\0';
}

static int IgnoreCase(const char* a, const char* b)
{
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return 0;
        a++; b++;
    }
    return *a == *b;
}

static int CompareTime(const void *a, const void *b)
{
    return ((const Entry*)a)->minutes - ((const Entry*)b)->minutes;
}
/*Returns number of entries*/
/*Returns nothing if file cant be opened*/
static int LoadSchedule(const char *fileName, Entry entries[])
{
    FILE *f = fopen(fileName, "r");
    if (!f) return -1;

    char line [256];
    int count = 0;

    if (!fgets(line, sizeof line, f)) {
        fclose(f);
        return 0;
    }

    while (count < MAX_ENTRIES && fgets(line, sizeof line, f)) {
        char *day = strtok(line, " ");
        char *time = strtok(NULL, " ");
        char *course = strtok(NULL, " ");
        char *room = strtok(NULL, ",\r\n");
        /*Skips bad rows */
        if (!day || !time || !course || !room) continue;

        Entry *e = &entries[count];
        snprintf(e->day, LENGTH, "%s", day);
        snprintf(e->time, LENGTH, "%s", time);
        snprintf(e->course, LENGTH, "%s", course);
        snprintf(e->room, LENGTH, "%s", room);
        trim(e->day);
        trim(e->time);
        trim(e->course);
        trim(e->room);

        int h, m;
        if (sscanf(e-> time, "%d:%d", &h, &m) != 2) continue;
        e-> minutes = h * 60 + m;

        count++;
    }
    fclose(f);
    return count;
}

int main(void)
{
    Entry entries[MAX_ENTRIES];
    int total = LoadSchedule("SchoolSchedule.csv",entries);

    if (total < 0) {
        printf("SchoolSchedule.csv not found\n");
        return 1;
    }
    char input[LENGTH];

    while (1) {
        printf("Enter a day to see schedule: ");
        if (!fgets (input, sizeof input, stdin))break;
        trim(input);

        if (IgnoreCase(input, "stop")) break;

        Entry today[MAX_ENTRIES];
        int n = 0;
        for (int i=0; i<total; i++) {
            if (IgnoreCase(entries[i].day, input)) {
                today[n++] = entries[i];
            }
        }
        if (n==0) {
            printf("No classes today\n");
            continue;
        }

        qsort(today, n, sizeof(Entry), CompareTime);

        printf("On %s you have: \n", today[0].day);
        for (int i=0; i<n; i++) {
            printf("%s %s\n", today[i].time, today[i].course, today[i].room);
        }
    }
    return 0;
}
