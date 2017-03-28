#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct{
    
    int x;
    int y;
}STACK;

int Sx,Sy,Ex,Ey;
int money=0;
int flag=0;
void draw(int m[][10] , int c[][10],int size,int cx , int cy);

int main()
{
    int SIZE;
    scanf("%d",&SIZE);
    
    int sx=0,sy=0,ex=0,ey=0;
    scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
   
    int maze[SIZE][SIZE];
    /* 0:road , 1: wall , 2:cion */
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            scanf("%d",&maze[i][j]);
    
    STACK stack[SIZE*SIZE];
    stack[0].x=sx;
    stack[0].y=sy;
    int idx=0;
    
    bool vist[SIZE][SIZE];
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            vist[i][j]=false;

    int color[SIZE][SIZE]; //0: white 1:red 2:yellow 3:blue
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++){
            color[i][j]=0;
            if(maze[i][j]==2)color[i][j]=2;
        }
    
    int current_x;
    int current_y;
    Sx=sx;Sy=sy;Ex=ex;Ey=ey;
    while( idx >= 0){   // stack is full
        
        current_x=stack[idx].x;
        current_y=stack[idx].y;
        idx--;
        vist[current_x][current_y]=true;
        color[current_x][current_y]=3;
        
        sleep(1);
        draw(maze,color,SIZE,current_x,current_y);
        
        if(maze[current_x][current_y]==2)money++;
        
        if(current_x==ey && current_y==ex){
            break;
        }
        
        if(!vist[current_x][current_y-1] && maze[current_x][current_y-1]!=1){
            idx++;
            stack[idx].x=current_x;
            stack[idx].y=current_y-1 ;
        }
        
        if(!vist[current_x+1][current_y] && maze[current_x+1][current_y]!=1){
            idx++;
            stack[idx].x=current_x+1;
            stack[idx].y=current_y ;
        }
        
        if(!vist[current_x][current_y+1] && maze[current_x][current_y+1]!=1){
            idx++;
            stack[idx].x=current_x;
            stack[idx].y=current_y+1 ;
        }
        
        if(!vist[current_x-1][current_y] && maze[current_x-1][current_y]!=1 ){
            idx++;
            stack[idx].x=current_x-1;
            stack[idx].y=current_y ;
        }
        
    }
    flag=1;
    draw(maze,color,SIZE,current_x,current_y);
    return 0;
}

void draw(int m[][10] , int c[][10] ,int size ,int cx , int cy)
{
    c[Sx][Sy]=1;  //start
    c[Ey][Ex]=1; //end
    for(int i=0;i<100;i++)printf("\n");
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            
            
            if(i==cx && j==cy){
                printf("\033[1;32m☺ \33\[0m");
            }
            else if(c[i][j]==0) //white
            {
               if(m[i][j]==1) //wall
               {
                   printf("\033[1;30m≡ \33\[0m");
               }
               else if (m[i][j]==0) //road
               {
                   printf("≡ ");
               }
            }
                
            else if(c[i][j]==1)  // red
                printf("\033[1;31m⌂ \33\[0m");
                
            else  if(c[i][j]==2)//yellow
                printf("\033[1;33mθ \33\[0m");
                
            else  if(c[i][j]==3)//blue
                printf("\033[1;34m≡ \33\[0m");
        }
        
        if(i==0)printf("     ---------");
        if(i==1)printf("     |score=%d|",money);
        if(i==2)printf("     ---------");
        
        if(flag==1){
            if(i==3)printf("\033[1;31m     ---------\33\[0m");
            if(i==4)printf("\033[1;31m     | E N D |\33\[0m");
            if(i==5)printf("\033[1;31m     ---------\33\[0m");
        }
        printf("\n");
    }
}