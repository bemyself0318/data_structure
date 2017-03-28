#include <stdio.h>


void rotate();
int tmp[5][5];
int M[5][5];
void show();

int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            scanf("%d",&M[i][j]);
        }
    char c;
    getchar();
    while(scanf("%c",&c)!=EOF){
        getchar();
        
        if(c!='L') printf("error\n");
        else{
            rotate();
        }
    }
    show();
    return 0;
}

void rotate()
{
    for(int i=4,k=0;i>=0,k<5;i--,k++)
        for(int j=0;j<5;j++){
            tmp[k][j]=M[j][i];
        }
        
    for(int a=0;a<5;a++)
        for(int b=0;b<5;b++){
            M[a][b]=tmp[a][b];
        }
}

void show()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(j==0) printf("%d",M[i][j]);
            else printf(" %d",M[i][j]);
        }
        printf("\n");
    }
}