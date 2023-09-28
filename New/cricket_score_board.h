#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



struct Match
{
	char toss;
	int inning;
};

struct Player
{
	int s_batsman;
	int r_batsman;
	int s_bat_score;
	int r_bat_score;
	int b_score[11];
	int b_balls[11];
	int bowler;
	int bowlerover[11][5];
	int batsman[11];
};


struct Over
{
	int b_count;
	int o_count;
	char b_run[3];
	int o_limit;
};


struct Team
{
	char t_name[10];
	char p_name[11][100];
	int p_runs;
	int p_wickets;
	int t_score;
	int t_wicket;
	int t_r_rate;
	int t_s_rate;
};



void Print_Line();
void Print_Team1();
void Print_Team2();
void Team_Names();
void Load_Teams();
void Toss();
void Choose_Batsman();
void printBatsman();
void Choose_Bowler();
void scoreCard();
void bowling();
void printBowler();
