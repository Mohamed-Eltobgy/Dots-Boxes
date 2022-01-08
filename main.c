#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include "grid.h" //Calling all functions
#include "mainMenu.h"
#include "print.h"
#include "Scorefun.h"
#include "SaveFun.h"
#include "GamePlay.h"
#include "Undo.h"
#include "Redo.h"
#include "moveshist.h"
#include "AI.h"
int main()
{
    mainMenu();
    time_t t1;
    system(" ");
    system("cls");
    if(l1==0){
    printf("Player one Name: ");
    scanf("%s",p1.name);
    if(playerNumber==2){
        printf("Player two Name: ");
       scanf("%s",p2.name);
        system("cls");
    }

    printf(ANSI_COLOR_YELLOW"Enter (N) The size of The Grid which is NxN boxes : "ANSI_COLOR_RESET);
    scanf("%d",&x);
    size1= x*2+2 ;
    }
    int arr1[size1][size1];
    if(l1==0){
    grid(size1,arr1);
    totalmoves= 2*x*(x+1);
    system("cls");
    }
   // History U[totalmoves+1];
    if(l1==1){
        for(int i=0 ; i<size1 ;i++){
            for(int j=0; j<size1 ; j++){
                arr1[i][j]=arr2[i][j];
            }
        }
    }
    t1=time(0);
    if(v!=1){
        goto there2 ;
    }
    moveshist(moves1 ,moves2 ,totalmoves ,size1 ,arr1, U ); ////////////////////////////////
    there :
    while(moves<totalmoves){
        v=1 ;
        moveshist(moves1 ,moves2 ,totalmoves ,size1 ,arr1, U );
        GamePlay(playerNumber,size1,arr1,totalmoves,U,t1);
        if(v !=1){
            moves++ ;
            moves2++;
            MovesAfterLoad++;  //////////////
            moveshist(moves1,moves2,totalmoves ,size1 ,arr1, U );
            system("cls");
            goto jump3;
        }
        system("cls");
        moves++;
        moves1++;
        MovesAfterLoad++;
        jump4:
        playes.move = moves ;
        playes.move1 = moves1 ;
        if(moves>totalmoves){break ;}
        int tempScore1 = Scorefun(v,size1,arr1);
        for(int i=0 ;i<size1; i++){
            for(int j=0 ; j<size1 ; j++){
                playes.arr[i][j] = arr1[i][j];
            }
        }
        score1 += tempScore1 ;
        playes.scoreplayer1 = score1;
        playes.scoreplayer2 = score2;
        if(tempScore1){
            goto there;
        }
        // Player Two
        there2 :
       //////// moveshist(moves1 ,moves2 ,totalmoves ,size1 ,arr1, U ); ////////////////////
        if(playerNumber==2){
            v=2 ;
        }else{
            v=0 ;
        }
        if(moves<totalmoves){
           /* playes.WhichPlayer = v ;
            U[moves]= playes ;*/
            moveshist(moves1 ,moves2 ,totalmoves ,size1 ,arr1, U );//////////////////// extra
            GamePlay(playerNumber,size1,arr1,totalmoves,U ,t1);
            if(v !=2 && v!=0){
                moves++ ;
                moves1++;
                MovesAfterLoad++;
                moveshist(moves1,moves2,totalmoves ,size1 ,arr1,  U);
                system("cls");
                goto jump4;
            }
        there4:
        system("cls");
        moves++;
        moves2++;
        MovesAfterLoad++;
        jump3:
        playes.move = moves ;
        playes.move2 = moves2 ;
        int tempScore2 = Scorefun(v,size1, arr1);
        for(int i=0 ;i<size1; i++){
            for(int j=0 ; j<size1 ; j++){
                playes.arr[i][j] = arr1[i][j] ;
            }
        }
        score2 += tempScore2 ;
        playes.scoreplayer1 = score1;
        playes.scoreplayer2 = score2;
        U[moves]=playes ;
        if(tempScore2){
             goto there2 ;
        }
        }else{
            break ;
        }
    }

    print(size1,arr1);
    printf(ANSI_COLOR_BLUE "  Player ONE Score : %d "ANSI_COLOR_RESET ,score1) ;
    printf(ANSI_COLOR_RED "      \t\t\t\t\t\t Player TWO Score : %d\n"ANSI_COLOR_RESET ,score2) ;
    p1.score = score1;
    if(playerNumber == 2){
        p2.score = score2;
    }
    FILE *topten;
    topten =fopen("ArrayIndex.bin","rb");

    if(score1 > score2){
        strcpy(top10[index].name,p1.name);
        top10[index].score = p1.score;
    }else if(p2.score > score1){
        strcpy(top10[index].name,p2.name);
        top10[index].score = p2.score;
    }else{
        strcpy(top10[index].name,p1.name);
        top10[index].score = p1.score;
        strcpy(top10[index].name,p2.name);
        top10[index].score = p2.score;
    }
    fclose(topten);
    return 0;
}
