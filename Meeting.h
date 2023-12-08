//
// Created by samda on 07/12/2023.
//
#include "stdlib.h"
#include "stdio.h"
#ifndef PROJECT_LIST_MODIFICATION_DISPLAY_MEETING_H
#define PROJECT_LIST_MODIFICATION_DISPLAY_MEETING_H
typedef struct Meeting{
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;
    int heureDuree;
    int minuteDuree;
    char objet[300];
    struct Meeting *next;
}Meeting;

typedef struct MeetingList{
    struct Meeting *first;
}MeetingList;

Meeting *createMeeting();
void scanString(char*);
int scanInt();
MeetingList *createMeetingList();
void addMeeting(MeetingList*);
void displayMeeting(MeetingList*);
#endif //PROJECT_LIST_MODIFICATION_DISPLAY_MEETING_H
