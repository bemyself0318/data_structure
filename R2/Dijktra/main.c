#include <stdio.h>
#include <stdbool.h>
#define MAX(x,y) ((x)>=(y))?(x):(y)

int main()
{
    int cases;
    scanf("%d",&cases);
    
    while(cases--){
        
        int line;
        scanf("%d",&line);
        
        int start,end;
        scanf("%d %d",&start,&end);
        
        int weight[100][100];
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                weight[i][j]=1e9;
                
        int s,t,w;
        int N=0;
        while(line--){
            scanf("%d %d %d",&s,&t,&w);
            
                weight[s][t]=w;
                N=MAX(N,MAX(s,t));
        }
        N++;
     
        int buff;
        scanf("%d",&buff);
        
        bool vist[N];
        for(int i=0;i<N;i++)
            vist[i]=false;
        
        int d[N];
        for(int i=0;i<N;i++)
            d[i]=1e9;
            
        d[start]=0;
        
        for(int k=0;k<N;k++){
            
            int a=-1,b=-1,min=1e9;
            for(int i=0;i<N;i++){
                if(!vist[i] && d[i]<min){
                    a=i;
                    min=d[i];
                }
            }
            
            if(a==-1)break;
            vist[a]=true;
            
            for(b=0;b<N;b++){
                if(!vist[b] && d[a] + weight[a][b] < d[b]){
                    d[b]= d[a] + weight[a][b];
                }
            }
        }
            printf("%d\n",d[end]);
    }
    return 0;
}