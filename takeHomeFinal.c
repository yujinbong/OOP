
//==============================================
// Take Home Final Assessment
// Name:           Yujin Bong
// Student Number: 147525208
// Email:          ybong@myseneca.ca
// Section:        NJJ
// Date:           Aug 10, 2021
//
// Group:          Yujin Bong
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

#define MAX_NAME_LEN 10 // 의미 없음 그냥 문자열 10까지 받아들일수 있다는 뜻으로 받아들이자!
#define NUM_ACTIVITY_NAMES 5
#define MAX_ACTIVITY_NAME_LEN 10 
#define MAX_NUM_PARTICIPANTS 10
 // 구조체 만들땐 항상 그림을 머릿속에 생각하고 구성하자.

struct Date {
    int year;
    int month;
    int day;
};
struct Activity {
    struct Date date;  // 액티비티 안에 date를 포함시킨다.
    double distance;
    char activityType;
};

struct Participant { // 최종 Participant안에 모든것을 포함시킨다.
    int numActivities;
    char name[MAX_NAME_LEN + 1];
    struct Activity activities[NUM_ACTIVITY_NAMES]; // 구조체 완성
};

struct NameDist { // 나중에 sort를 하기위해 따로 만든 NameDist구조체
    char name[MAX_NAME_LEN + 1]; // +1을 하는 이유는 문자열 끝에 null을 설정하기 위해서이다.
    double dist;
};

// prototypes 프로토타입을 설정해야하는 이유는? 다시한번 확인하기!! 확실해질때까지
int zeller(const struct Date* date) ;
char findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int count, char* activity) ;
int findParticipant(struct Participant participants[], int count, char name[]) ;
int readActivityFile(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1]);
void sortNameDist(struct NameDist nameDist[], int count) ;
void listAll(struct Participant* participants, int count) ;
void listTotal(struct Participant* participants, int count, char typeToFind) ;
void listBest(struct Participant* participants, int count, char typeToFind) ;
int readInt(int beg , int end) ;

// definitions
int zeller(const struct Date* date) {
      int month = date->month;
      int year = date->year;
      if (date->month < 3)
      {
            year--;
            month += 12;
      }
      int yr = year % 100;
      int century = year / 100;
      int result = date->day;
      result += 13 * (month + 1) / 5;
      result += yr;
      result += yr / 4;
      result += century / 4;
      result -= 2 * century;
      result = result % 7;
      return result;
}

// Given acitivity to search from activNames, return the first character of the activity
// For example, if activity is 'swim', return 's'
char findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int count, char* activity) {
    int is_name_found = 0; 
    char type = ' ';
    for (int i = 0; i < count && is_name_found == 0; i++) { // i는 주어진 count보다 작고 name이 0인 동안 루프를 수행하라.
        if ((activNames[i], activity) == 0) {
            is_name_found = 1;
            type = activNames[i][0]; // get the first char, 만약 swim일시 s를 반환한다.
        }
    }
    return type;
}

// return the index of participants whose name matches. If not found, return -1
int findParticipant(struct Participant participants[], int count, char name[]) {
    int is_name_found = 0;
    int foundIdx = -1;

    for (int i = 0; i < count && is_name_found == 0; i++) {
        if (strcmp(participants[i].name, name) == 0) { // match found!
            is_name_found = 1;
            foundIdx = i;
        }
    }
    return foundIdx;
}

int readActivityFile(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1]) {
    int count = 0, ch, addPosn, actPosn;
    char activity[16];
    char name[MAX_NAME_LEN + 1];
    int year = 0, month = 0, day = 0;
    double dist = 0.0;
    while (!feof(fp))
    {
        fscanf(fp, "%[^~]s%*c", name);
        ch = fgetc(fp);
        fscanf(fp, "%[^~]s%*c", activity);
        ch = fgetc(fp);
        fscanf(fp, "%d", &year);
        ch = fgetc(fp);
        fscanf(fp, "%d", &month);
        ch = fgetc(fp);
        fscanf(fp, "%d", &day);
        ch = fgetc(fp);
        fscanf(fp, "%lf", &dist);
        ch = fgetc(fp);
        addPosn = findParticipant(participants, count, name);
        if (addPosn < 0)
        {
            addPosn = count;
            count++;
            participants[addPosn].numActivities = 0;
            strcpy(participants[addPosn].name, name);
        }

        actPosn = participants[addPosn].numActivities;
        participants[addPosn].activities[actPosn].activityType =
            findString(activNames, NUM_ACTIVITY_NAMES, activity);
        //             given                           run
        participants[addPosn].activities[actPosn].date.year = year;
        participants[addPosn].activities[actPosn].date.month = month;
        participants[addPosn].activities[actPosn].date.day = day;
        participants[addPosn].activities[actPosn].distance = dist;
        participants[addPosn].numActivities++;

        ch = fgetc(fp);
        if (!feof(fp)) ungetc(ch, fp);
    }
    return count;
}

// Given name and distance array, sort it in descending order
void sortNameDist(struct NameDist nameDist[], int count) {
    int i, j;
    struct NameDist temp;

    for (i = count - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (nameDist[j].dist < nameDist[j + 1].dist) {
                temp = nameDist[j];
                nameDist[j] = nameDist[j + 1];
                nameDist[j + 1] = temp;
            }
        }
    }
}

void listAll(struct Participant* participants, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", participants[i].name);
        printf("----------------------------------------------\n");
        for (int j = 0; j < participants[i].numActivities; j++) {
            int day = participants[i].activities[j].date.day;

            char* monthStr = NULL;
            int month = participants[i].activities[j].date.month;;

            char type = participants[i].activities[j].activityType;
            char* typeStr = NULL;

            int dayOfWeek = zeller(&participants[i].activities[j].date);
            char* dayOfWeekStr = NULL;

            double dist = participants[i].activities[j].distance;

            // get Month string
            switch (month) {
                case 1: monthStr = "Jan"; break;
                case 2: monthStr = "Feb"; break;
                case 3: monthStr = "Mar"; break;
                case 4: monthStr = "Apr"; break;
                case 5: monthStr = "May"; break;
                case 6: monthStr = "Jun"; break;
                case 7: monthStr = "Jul"; break;
                case 8: monthStr = "Aug"; break;
                case 9: monthStr = "Sep"; break;
                case 10: monthStr = "Oct"; break;
                case 11: monthStr = "Nov"; break;
                case 12: monthStr = "Dec"; break;

            }

            // get day of week string
            switch(dayOfWeek) {
                case 0: dayOfWeekStr = "Sat"; break;
                case 1: dayOfWeekStr = "Sun"; break;
                case 2: dayOfWeekStr = "Mon"; break;
                case 3: dayOfWeekStr = "Tue"; break;
                case 4: dayOfWeekStr = "Wed"; break;
                case 5: dayOfWeekStr = "Thu"; break;
                case 6: dayOfWeekStr = "Fri"; break;
            }

            // get activity 
            switch (type) {
                case 'r': typeStr = "run"; break;
                case 's': typeStr = "swim"; break;
                case 'b': typeStr = "bike"; break;
            }
            printf("%5s %s %s %d %5.1lf\n", typeStr, dayOfWeekStr, monthStr, day, dist);
        }
        printf("\n");
    }
}

void listTotal(struct Participant* participants, int count, char typeToFind) {
    char* name = NULL;
    struct NameDist nameDist[MAX_NUM_PARTICIPANTS] = { 0 };

    // Try each of participants
    for (int i = 0; i < count; i++) {
        name = participants[i].name;
        double total = 0.000000001; // to handle round off properly

        // Try each activity
        for (int j = 0; j < participants[i].numActivities; j++) {

            // Only find the same type of activity
            if (participants[i].activities[j].activityType == typeToFind) {
                total = total + participants[i].activities[j].distance;
            }
        }
        strcpy(nameDist[i].name, name);
        nameDist[i].dist = total;
    }
    
    char* typeStr = NULL;
    if (typeToFind == 'r') {
        typeStr = "RUN";
    }
    else if (typeToFind == 'b') {
        typeStr = "BIKE";
    }
    else if (typeToFind == 's') {
        typeStr = "SWIM";
    }

    sortNameDist(nameDist, count); // sort in descending order

    printf("       *** TOTAL %s ***\n", typeStr);
    for (int i = 0; i < count; i++) {
        printf("          %10s %5.1lf\n", nameDist[i].name, nameDist[i].dist);
    }
    printf("\n");
}

void listBest(struct Participant* participants, int count, char typeToFind) {
    char* name = NULL;
    struct NameDist nameDist[MAX_NUM_PARTICIPANTS] = { 0 };

    // Try each of participants
    for (int i = 0; i < count; i++) {
        name = participants[i].name;
        double best = 0;

        // Try each activity
        for (int j = 0; j < participants[i].numActivities; j++) {

            // Only find the same type of activity
            if (participants[i].activities[j].activityType == typeToFind) {
                double dist = participants[i].activities[j].distance;
                if (dist > best) {
                    best = dist;
                }
            }
        }
        strcpy(nameDist[i].name, name);
        nameDist[i].dist = best;
    }
    
    // Find the correct activity name
    char* typeStr = NULL;
    if (typeToFind == 'r') {
        typeStr = "RUN";
    }
    else if (typeToFind == 'b') {
        typeStr = "BIKE";
    }
    else if (typeToFind == 's') {
        typeStr = "SWIM";
    }

    sortNameDist(nameDist, count); // sort in descending order

    printf("       *** TOTAL %s ***\n", typeStr);
    for (int i = 0; i < count; i++) {
        printf("          %10s %5.1lf\n", nameDist[i].name, nameDist[i].dist);
    }
    printf("\n");
}

int readInt(int beg , int end) {
    int input = -1;
    char newline = '\0';
    int continueLoop = 1;
    while (continueLoop == 1) {
        scanf("%d%c", &input, &newline);
        if (newline != '\n') {   // not a number
            while (getchar() != '\n');
            printf("Invalid! must enter an number\n");
            continueLoop = 1;
        }
        else if (input < beg || input > end) { // invalid number
            printf("Enter a number between 0 and 7: ");
            continueLoop = 1;
        }
        else { // good
            continueLoop = 0;
        }
    }
    return input;
}

int main() {

    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL){
      printf("ERROR: data.txt is missing\n");
      return 0;
    }
    struct Participant participants[MAX_NUM_PARTICIPANTS] = { 0 };

    // handles this activities
    const char activNames[][MAX_ACTIVITY_NAME_LEN + 1] = {
        "swim",
        "bike",
        "run"
    };
    int count = readActivityFile(fp, participants, activNames);
    int input = -1;
    printf("Read %d participants\n", count);
    printf("\n");

    // show menu until 0 is entered
    while (input != 0) {
        printf("Select one of the following options :\n");
        printf("0 - Exit\n");
        printf("1 - list all participants and events\n");
        printf("2 - list total run distances\n");
        printf("3 - list total swim distances\n");
        printf("4 - list total bike distances\n");
        printf("5 - list best run distances\n");
        printf("6 - list best swim distances\n");
        printf("7 - list best bike distances\n");
        input = readInt(0, 7);

        if (input == 0) {
            printf("GoodBye");
        }
        else if (input == 1) {
            listAll(participants, count);
        }
        else if (input == 2) {
            listTotal(participants, count, 'r');
        }
        else if (input == 3) {
            listTotal(participants, count, 's');
        }
        else if (input == 4) {
            listTotal(participants, count, 'b');
        }
        else if (input == 5) {
            listBest(participants, count, 'r');
        }
        else if (input == 6) {
            listBest(participants, count, 's');
        }
        else if (input == 7) {
            listBest(participants, count, 'b');
        }
    }
    return 0;
}
*/