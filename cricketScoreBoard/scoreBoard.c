#include"scoreBoard.h"



struct Player p1;










void acceptPlayerTeam_1(){
    
    FILE *fp, *fs;
    if((fs = fopen("Team1.txt", "r")) == NULL){
        printf("Error 404!!! Please Try Again!!!!");
        exit(1);
    }
    if((fp = fopen("Team1.bin", "wb")) == NULL){
        printf("Error 404!!\nPlease Try Again!!");                      // Check if File is not opened
        exit(1);
    }    
    fclose(fp);
    if((fp = fopen("Team1.bin", "wb")) == NULL){
        printf("Error 404!!\nPlease Try Again!!");                      // Check if File is not opened
        exit(1);
    }    
    for(int i = 1; i<= 11 ; i++)
    {
        p1.id = i;
        fgets(p1.name, 100, fs);
        /*printf("Enter Player Name ");
        for(int j = 0; j<= 100 ; j++)
        { 
            scanf("%c", &p1.name[j]);
            if(p1.name[j] == '\n')
            {
                break;
            }s
        }*/
        

        fwrite(&p1, sizeof(struct Player), 1, fp);  
    }
    fclose(fp);
    fclose(fs);
}

void acceptPlayerTeam_2(){
    
    FILE *fp, *fs;
    if((fs = fopen("Team2.txt", "r")) == NULL){
        printf("Error 404!!! Please Try Again!!!!");
        exit(1);
    }
    if((fp = fopen("Team2.bin", "wb")) == NULL){
        printf("Error 404!!\nPlease Try Again!!");                      // Check if File is not opened
        exit(1);
    }    
    fclose(fp);
    if((fp = fopen("Team2.bin", "wb")) == NULL){
        printf("Error 404!!\nPlease Try Again!!");                      // Check if File is not opened
        exit(1);
    }    
    for(int i = 1; i<= 11 ; i++)
    {
        p1.id = i;
        fgets(p1.name, 100, fs);
        /*printf("Enter Player Name ");
        for(int j = 0; j<= 100 ; j++)
        { 
            scanf("%c", &p1.name[j]);
            if(p1.name[j] == '\n')
            {
                break;
            }s
        }*/
        

        fwrite(&p1, sizeof(struct Player), 1, fp);  
    }
    fclose(fp);
    fclose(fs);
}

void printPlayerTeam_1(){
    FILE *fp;
    if((fp = fopen("Team1.bin", "rb")) == NULL){
        printf("Error 404!!\nPlease Try Again!!");                      //File is not opening
        exit(1);
    }
    while(fread(&p1, sizeof(struct Player), 1, fp))
    {
        printf("%d %s", p1.id, p1.name);  
    }
    fclose(fp);
}


void printPlayerTeam_2(){
    FILE *fp;
    if((fp = fopen("Team2.bin", "rb")) == NULL){
        printf("Error 404!!\nPlease Try Again!!");                      //File is not opening
        exit(1);
    }
    while(fread(&p1, sizeof(struct Player), 1, fp))
    {
        printf("%d %s", p1.id, p1.name);  
    }
    fclose(fp);
}



