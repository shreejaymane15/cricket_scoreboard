#include<stdio.h>
#include<stdlib.h>





struct Player {
    int id;
    char name[100];
    int score;
    int balls;
    int srate;
    int overs;
    int wickets;
    int economy; 
};


struct Team {
    int id;
    char name[50];
    int score;
    int over;
    int rrate;
    int wickets;
};

struct Match {
    int toss;
    int inning;
    int olimit;
};

struct Over {
    int over;
    int ball;
};



















void acceptPlayerTeam_1();
void acceptPlayerTeam_2();
void printPlayerTeam_1();
void printPlayerTeam_2();