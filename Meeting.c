//
// Created by samda on 07/12/2023.
//

#include "Meeting.h"
Meeting *createMeeting(){
    Meeting *temp=(Meeting*) malloc(sizeof (Meeting));
    printf("entrez le jour du rdv\n");
    temp->jour=scanInt();
    printf("entrez le mois du rdv\n");
    temp->mois=scanInt();
    printf("entrez le l'annee du rdv\n");
    temp->annee= scanInt();
    printf("entrez le l'heure du rdv\n");
    temp->heure=scanInt();
    printf("entrez la minute du rdv\n");
    temp->minute=scanInt();
    printf("entrez la duree en heure du rdv\n");
    temp->heureDuree=scanInt();
    printf("entrez la duree en minute du rdv\n");
    temp->minuteDuree=scanInt();
    printf("entrez l'objet du rdv");
    scanString(temp->objet);
    temp->next=NULL;
    return temp;
}

void scanString(char chaine[]){
    scanf("%s",chaine);
    for(int i=0;chaine[i]!='\0';i++){
        if(chaine[i]<97){
            chaine[i]=chaine[i]+32;
        }
    }
}

int scanInt(){
    int temp;
    scanf("%d",&temp);
    return temp;
}

MeetingList *createMeetingList(){
    MeetingList *temp=(MeetingList*)malloc(sizeof (MeetingList));
    temp->first=NULL;
    return temp;
}
void addMeeting(MeetingList* list){
    if(list->first==NULL){
        list->first=createMeeting();
    }else{
        Meeting* temp=list->first;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=createMeeting();
    }
}
void displayMeeting(MeetingList* list){
    Meeting *temp=list->first;
    while(temp!=NULL){
        printf("%d/%d/%d\n ",temp->jour,temp->mois,temp->annee);
        printf("%d H %d\n ",temp->heure,temp->minute);
        printf("l'objet est: %s\n",temp->objet);
        temp=temp->next;
    }
}