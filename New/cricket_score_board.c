#include"cricket_score_board.h"


struct Match m;
struct Over o1;
struct Over o2;
struct Team c1 = {0, 0, 0, 0, 0, 0, 0, 0};
struct Team c2 = {0, 0, 0, 0, 0, 0, 0, 0};
struct Player p1 = {0, 0, 0, 0, 0, 0, 0, 0};
struct Player p2 = {0, 0, 0, 0, 0, 0, 0, 0};



void Team_Names()
{
	printf("Enter Team 1 Name : ");
	for(int i=0;i<=10;i++)
	{
		scanf("%c",&c1.t_name[i]);
		if(c1.t_name[i]== '\n')
		{
			c1.t_name[i] = '\0';
			break;
		}
	}
	printf("Enter Team 2 Name : ");
	for(int i=0;i<=10;i++)
	{
	
		scanf("%c", &c2.t_name[i]);
		if(c2.t_name[i]== '\n')
		{
			c2.t_name[i] = '\0';
			break;
		}
	}
}

void Load_Teams()
{
	FILE *fp;
	FILE *fs;
	fp = fopen("team_1.txt", "r");
	if (fp == NULL)
      		printf("File can't open");
	fs = fopen("team_2.txt", "r");
	if (fs == NULL)
      		printf("File can't open");
	
	
	for(int i=1;i<=11;i++)
	{
		int len;
		fgets(c1.p_name[i], 60, fp);
		len = strlen(c1.p_name[i]);	
		//printf("%d\n",len);
		/*for(int j = 0; j<=len ; j++)
		{
			//printf("%c",c1.p_name[i][j]);
			if(c1.p_name[i][j] == '\n')
			{
				printf("YES");
    				c1.p_name[i][j] = '\0';
			}
		}*/
		fgets(c2.p_name[i], 60, fs);
		len = strlen(c2.p_name[i]);
		/*for(int j = 0; j<=len ; j++)
		{
			if(c2.p_name[i][j] == '\n')
    				c2.p_name[i][j] = '\0';
		}*/
	}
	fclose(fp);
	fclose(fs);
}

void Print_Team1()
{
	printf("\n\t\t\t%s\n", c1.t_name);
	for(int i=1;i<=11;i++)
		printf("%s", c1.p_name[i]);	
}

void Print_Team2()
{
	printf("\n\n\t\t\t%s\n",c2.t_name);
	for(int i=1; i<=11;i++)
		printf("%s", c2.p_name[i]);
}

void Toss()
{
	printf("\nEnter Over Limit = ");
	scanf("%d", &o1.o_limit);
	m.toss=0;
	while(!m.toss)
	{
		printf("\n\n\t\t\tToss\n\t\tHead(H) / Tail(T)\n");
		printf("\nEnter Your Choice = ");
		scanf(" %c", &m.toss);
		if(m.toss == 'h' || m.toss == 'H' || m.toss == 't' || m.toss == 'T')
		{
			int num;
			srand(time(0));
			num = (rand()%10) + 1;
			if(num <= 5)
			{						
				printf("\n\n\t\t%s won the toss. \n\t\t%s will bat first.\n", c2.t_name, c2.t_name);
				m.toss = 1;
				break;
			}
			else
			{
				printf("\n\n\t\t%s won the toss. \n\t\t%s will bat first.\n",c1.t_name, c1.t_name);
				m.toss = 0;
				break;
			}
		}
		else
		{
			m.toss = 0;
			printf("You have to provide H/T\n");
		}
	}
	m.inning = 1;
	c1.t_wicket = 0;
}


void Choose_Batsman()
{
	printf("\n\t\tBatting Team\n");
	if(m.toss == 0)
	{
		if(c1.t_wicket == 0)
		{
			Print_Team1();
			printf("\n\nChoose Batsman = ");
			scanf("%d", &p1.s_batsman);
			printf("%s", c1.p_name[p1.s_batsman]);
			p1.batsman[0] = p1.s_batsman;
			printf("\n\nChoose Runner = ");
			scanf("%d", &p1.r_batsman);
			printf("%s", c1.p_name[p1.r_batsman]);
			p1.batsman[1] = p1.r_batsman;
		}
		else
		{
			printBatsman();
			printf("\n\nChoose Batsman = ");
			scanf("%d", &p1.s_batsman);
			for(int i = 0; i<= 11; i++)
			{
				if(p1.s_batsman == p1.batsman[i])
				{
					printf("Please Choose Right Option\n");
					Choose_Batsman();
					break;
				}
				else if(p1.batsman[i] == 0)
				{
					p1.batsman[i] = p1.s_batsman;
					printf("%s", c1.p_name[p1.s_batsman]);
					break;
				}
			}
		}
	}
	else if(m.toss == 1)
	{
		if(c2.t_wicket == 0)
		{
			Print_Team2();
			printf("\n\nChoose Batsman = ");
			scanf("%d", &p2.s_batsman);
			printf("%s", c2.p_name[p2.s_batsman]);
			p2.batsman[0] = p2.s_batsman;
			printf("\n\nChoose Runner = ");
			scanf("%d", &p2.r_batsman);
			printf("%s", c2.p_name[p2.r_batsman]);
			p2.batsman[1] = p2.r_batsman;
		}
		else
		{
			printBatsman();
			printf("\n\nChoose Batsman = ");
			scanf("%d", &p2.s_batsman);
			for(int i = 0; i<=11; i++)
			{
				if(p2.s_batsman == p2.batsman[i])
				{
					printf("Please Choose Right Option\n");
					Choose_Batsman();
					break;
				}
				else if(p2.batsman[i] == 0)
				{
					p2.batsman[i] = p2.s_batsman;
					printf("%s", c2.p_name[p2.s_batsman]);
					break;
				}
			}
		}
	}
}

void printBatsman()
{
	if(m.toss == 0)
	{
		for(int i = 1; i<= 11 ; i++)
		{
			for(int j = 0 ; j<=11; j++)
			{
				if(i == p1.batsman[j])
					break;
				else if(i == j)
					printf("%s",c1.p_name[i]);
			}
		}	
	}
	else if(m.toss == 1)
	{
		for(int i = 1 ; i<= 11; i++)
		{
			for(int j = 0 ; j<=11; j++)
			{
				if(i == p2.batsman[j])
					break;
				else if(i == j)
					printf("%s",c2.p_name[i]);
			}
		}
	}	
	
}


void Choose_Bowler()
{
	printf("\n\n\t\tBowling Team\n");
	if(m.toss == 0)
	{
		if(o1.o_count == 0 && o1.b_count == 0)
		{
			Print_Team2();
			printf("\n\nChoose Bowler = ");
			scanf("%d", &p2.bowler);
			printf("%s", c2.p_name[p2.bowler]);
		}
		else
		{
			printBowler();
			printf("\n\nChoose Bowler = ");
			scanf("%d", &p2.bowler);
			printf("%s", c2.p_name[p2.bowler]);
		}
	}
	else if(m.toss == 1)
	{	
		if(o1.o_count == 0 && o1.b_count == 0)
		{	
			Print_Team1();
			printf("\n\nChoose Bowler = ");
			scanf("%d", &p1.bowler);
			printf("%s", c1.p_name[p1.bowler]);
		}
		else
		{
			printBowler();
			printf("\n\nChoose Bowler = ");
			scanf("%d", &p1.bowler);
			printf("%s", c1.p_name[p1.bowler]);
		}
	}
}


void printBowler()
{
	if(m.toss == 0)
	{
		for(int i = 1; i<= 11 ; i++)
		{
			if(i == p2.bowler)
				continue;
			else
				printf("%s",c2.p_name[i]);
		}
	}
	else if(m.toss == 1)
	{
		for(int i = 1 ; i<= 11; i++)
		{
			if(i == p1.bowler)
				continue;
			else
				printf("%s",c1.p_name[i]);
		}
	}
}
				

void scoreCard()
{
	if(m.toss == 0)
	{
		printf("\n\n\t%s\t\t%d / %d", c1.t_name, c1.t_score, c1.t_wicket);
		printf("\n\tOvers:\t\t(%d.%d)\n\n", o1.o_count, o1.b_count);  
		if(m.inning == 2)
			printf("\n\nTarget: %s \t%d / %d \t(%d.%d)\n", c2.t_name, c2.t_score, c2.t_wicket, o2.o_count, o2.b_count);
		printf("%s\t\t%d - %d\n", c1.p_name[p1.s_batsman], p1.b_score[p1.s_batsman], p1.b_balls[p1.s_batsman]);
		printf("%s\t\t%d - %d\n", c1.p_name[p1.r_batsman], p1.b_score[p1.r_batsman], p1.b_balls[p1.r_batsman]);
		printf("%s\t\t%d %d %d %d\n", c2.p_name[p2.bowler], p2.bowlerover[p2.bowler][0], p2.bowlerover[p2.bowler][1],p2.bowlerover[p2.bowler][2],p2.bowlerover[p2.bowler][3]);
	}
	else if(m.toss == 1)
	{
		printf("\n\n\t%s  \t\t%d / %d", c2.t_name, c2.t_score, c2.t_wicket);
		printf("\n\tOvers:\t\t(%d.%d)\n\n", o1.o_count, o1.b_count);  
		if(m.inning == 2)
			printf("\n\nTarget: %s \t%d / %d \t(%d.%d)\n", c1.t_name, c1.t_score, c1.t_wicket, o2.o_count, o2.b_count);
		printf("%s\t\t%d - %d\n", c2.p_name[p2.s_batsman], p2.b_score[p2.s_batsman], p2.b_balls[p2.s_batsman]);
		printf("%s\t\t%d - %d\n", c2.p_name[p2.r_batsman], p2.b_score[p2.r_batsman], p2.b_balls[p2.r_batsman]);
		printf("%s\t\t%d %d %d %d\n", c1.p_name[p2.bowler], p1.bowlerover[p1.bowler][0], p1.bowlerover[p1.bowler][1],p1.bowlerover[p1.bowler][2],p1.bowlerover[p1.bowler][3]);
	}		
}

void bowling()
{
	int i, res, temp = 0;
	o1.o_count = 0;
	c1.t_score = 0;
	c2.t_score = 0;
	c1.t_wicket = 0;
	c2.t_wicket = 0;
	while(o1.o_count != o1.o_limit)
	{
		o1.b_count = 1;
		Choose_Bowler();
		while(o1.b_count <= 6)
		{
			char *arr[9] = {"00", "01", "02", "03", "04","06", "WK", "WD", "NO"};
			printf("\nOver %1d.%1d: ", o1.o_count, o1.b_count);
			scanf("%s", o1.b_run);
			for(i = 0 ; i < 9; i++)
			{
				res = strcmp(o1.b_run, arr[i]);
				if(res == 0)
				{
					break;
				}
			}	
			switch(i)
			{
				case 0:
					o1.b_count += 1;
					break;
				case 1:
					o1.b_count += 1;
					if(m.toss == 0)
					{
						
						c1.t_score += 1;
						p1.b_score[p1.s_batsman] += 1;
						p1.b_balls[p1.s_batsman] += 1;
						p2.bowlerover[p2.bowler][1] += 1;
						temp = p1.s_batsman;
						p1.s_batsman = p1.r_batsman;
						p1.r_batsman = temp;
					}	
					else if(m.toss == 1)
					{
						c2.t_score += 1;
						p2.b_score[p2.s_batsman] += 1;
						p2.b_balls[p2.s_batsman] += 1;
						p1.bowlerover[p1.bowler][1] += 1;
						temp = p2.s_batsman;
						p2.s_batsman = p2.r_batsman;
						p2.r_batsman = temp;
					}
					break;
				case 2:
					o1.b_count += 1;
					if(m.toss == 0)
					{
						c1.t_score += 2;
						p1.b_score[p1.s_batsman] += 2;
						p1.b_balls[p1.s_batsman] += 1;
						p2.bowlerover[p2.bowler][1] += 2;
					}
					else if(m.toss == 1)
					{
						c2.t_score += 2;
						p2.b_score[p2.s_batsman] += 2;
						p2.b_balls[p2.s_batsman] += 1;
						p1.bowlerover[p1.bowler][1] += 2;
					}
					break;
				case 3:
					o1.b_count += 1;
					if(m.toss == 0)
					{
						c1.t_score += 3;
						p1.b_score[p1.s_batsman] += 3;
						p1.b_balls[p1.s_batsman] += 1;
						p2.bowlerover[p2.bowler][1] += 3;
						temp = p1.s_batsman;
						p1.s_batsman = p1.r_batsman;
						p1.r_batsman = temp;
					}
					else if(m.toss == 1)
					{
						c2.t_score += 3;
						p1.b_score[p1.s_batsman] += 3;
						p1.b_balls[p1.s_batsman] += 1;
						p1.bowlerover[p1.bowler][1] += 3;
						temp = p2.s_batsman;
						p2.s_batsman = p2.r_batsman;
						p2.r_batsman = temp;
					}
					break;
				case 4:	
					o1.b_count += 1;
					if(m.toss == 0)
					{
						c1.t_score += 4;
						p1.b_score[p1.s_batsman] += 4;
						p1.b_balls[p1.s_batsman] += 1;
						p2.bowlerover[p2.bowler][1] += 4;
					}
					else if(m.toss == 1)
					{
						c2.t_score += 4;
						p2.b_score[p2.s_batsman] += 4;
						p2.b_balls[p2.s_batsman] += 1;
						p1.bowlerover[p1.bowler][1] += 4;
					}
					break;
				case 5:
					o1.b_count += 1;
					if(m.toss == 0)
					{
						c1.t_score += 6;
						p1.b_score[p1.s_batsman] += 6;
						p1.b_balls[p1.s_batsman] += 1;
						p2.bowlerover[p2.bowler][1] += 6;
					}
					else if(m.toss == 1)
					{
						c2.t_score += 6;
						p2.b_score[p2.s_batsman] += 6;
						p2.b_balls[p2.s_batsman] += 1;
						p1.bowlerover[p1.bowler][1] += 6;
					}
					break;
				case 6:
					o1.b_count += 1;
					if(m.toss == 0)
					{
						c1.t_wicket += 1;
						p1.b_balls[p1.s_batsman] += 1;
						p2.bowlerover[p2.bowler][2] += 1;
					}
					else if(m.toss == 1)
					{
						c2.t_wicket += 1;
						p1.b_balls[p1.s_batsman] += 1;
						p1.bowlerover[p1.bowler][2] += 1;
					}
					Choose_Batsman();
					break;
				case 7:
					if(m.toss == 0)
					{
						c1.t_score += 1;
						p2.bowlerover[p2.bowler][1] += 1;
					}
					else if(m.toss == 1)
					{
						c2.t_score += 1;
						p1.bowlerover[p1.bowler][1] += 1;
					}
					printf("WIDE!!!");
					break;
				case 8:
					if(m.toss == 0)
					{
						c1.t_score += 1;
						p2.bowlerover[p2.bowler][1] += 1;
					}
					else if(m.toss == 1)
					{
						c2.t_score += 1;
						p1.bowlerover[p1.bowler][1] += 1;
					}
					printf("NO BALL!!");
					break;
				
				default:
					printf("Invalid Runs! Pls Enter Valid Options\n");
					break;
			}	
		}
		if(o1.b_count == 7)
		{
			o1.b_count = 0;
			o1.o_count += 1;
			if(m.toss == 0)
			{
				p2.bowlerover[p2.bowler][0] += 1;
				p2.bowlerover[p2.bowler][3] = p2.bowlerover[p2.bowler][1]/p2.bowlerover[p2.bowler][0];
				temp = p1.s_batsman;
				p1.s_batsman = p1.r_batsman;
				p1.r_batsman = temp;
			}
			else if(m.toss == 1)
			{
				p1.bowlerover[p1.bowler][0] += 1;
				p1.bowlerover[p1.bowler][3] = p1.bowlerover[p1.bowler][1]/p1.bowlerover[p1.bowler][0];
				temp = p2.s_batsman;
				p2.s_batsman = p2.r_batsman;
				p2.r_batsman = temp;
			}
		}
		scoreCard();
	}
	if((m.toss == 1) && (o1.o_count == o1.o_limit) && (m.inning == 1))
	{
		m.inning = 2;
		m.toss = 0;
		o2.o_count = o1.o_count;
		o1.o_count == 0;
	}
	else if((m.toss == 0) && (o1.o_count == o1.o_limit) && (m.inning == 1))
	{
		m.inning = 2;
		m.toss = 1;
		o2.o_count = o1.o_count;		
		o1.o_count = 0;
	}
}		
	

