#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Maximum numbers of schedule entries and maximum length of text fields*/
#define MAX_ENTRIES 200
#define LENGTH 64

typedef struct {
    char day[LENGTH];
    char time[LENGTH];
    char course[LENGTH];
    char room[LENGTH];
    int minutes;
}Entry;
/*Trim removes space after commas*/
static void trim(char *s)
{
    char * start = s;
    /*Moves over spaces and whitespace at beginning of a string*/
    while (isspace((unsigned char)*start)) start++;
    /*move text to the beginning of  the string*/
    memmove(s, start, strlen(start)+1);

    /*Remove space from end of the string*/
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
        /*Splits the CSV into separate fields*/
        char *day = strtok(line, ",");
        char *time = strtok(NULL, ",");
        char *course = strtok(NULL, ",");
        char *room = strtok(NULL, ",\r\n");
        /*Skips rows that dont contain all fou fields*/
        if (!day || !time || !course || !room) continue;
        /*Select the next available entry in the array*/
        Entry *e = &entries[count];
        /*Copy each field into the entry*/
        snprintf(e->day, LENGTH, "%s", day);
        snprintf(e->time, LENGTH, "%s", time);
        snprintf(e->course, LENGTH, "%s", course);
        snprintf(e->room, LENGTH, "%s", room);
        /*Remove unwanted spaces*/
        trim(e->day);
        trim(e->time);
        trim(e->course);
        trim(e->room);

        int h, m;

        /*Converts hours to minutes*/
        /*Skips the row if times not in the right format*/
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

    /*Loads the schedule from CSV file*/
    int total = LoadSchedule("SchoolSchedule.csv",entries);
    /*Stops program if file cant be opened*/
    if (total < 0) {
        printf("SchoolSchedule.csv not found\n");
        return 1;
    }
    char input[LENGTH];

    /*Continues to ask user for a day until user enters "stop"*/
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
        /*Tells if no classes are found*/
        if (n==0) {
            printf("No classes today\n");
            continue;
        }
        /*Sort the classes from earliest to latest*/
        qsort(today, n, sizeof(Entry), CompareTime);
        /*Displays the schedule for the selected day*/
        printf("On %s you have: \n", today[0].day);
        for (int i=0; i<n; i++) {
            printf("%s %s\n",
                today[i].time,
                today[i].course,
                today[i].room);
        }
    }
    return 0; /*Program ends*/
}
