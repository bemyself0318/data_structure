#include <stdio.h>
#include <stdbool.h>
#define MAX(x,y) ((x)>(y))?(x):(y)

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--){
        
        int lines;
        int start,end;
        scanf("%d",&lines);
        scanf("%d %d",&start,&end);
        
        int weight[100][100];
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                weight[i][j]=1e9;
                
        int s,t,w;
        int nodes=0;
        while(lines--){
            
            scanf("%d %d %d",&s,&t,&w);
            weight[s][t]=w;
            nodes=MAX(nodes,MAX(s,t));
        }
        nodes++;
        int buff;
        scanf("%d",&buff);
        
        bool vist[nodes];
        for(int i=0;i<nodes;i++) vist[i]=false;
        
        int d[nodes];
        for(int i=0;i<nodes;i++) d[i]=1e9;
        d[start]=0;
        
        for(int k=0;k<nodes;k++){
            
            int a=-1,b=-1,min=1e9;
            for(int i=0;i<nodes;i++){
                if(!vist[i] && d[i]<min){
                    a=i;
                    min=d[i];
                }
            }
            if(a==-1) break;
            vist[a]=true;
            
            for(b=0;b<nodes;b++){
                if(!vist[b] && d[a]+weight[a][b]<d[b]){
                    d[b]=d[a]+weight[a][b];
                }
            }
        }
        printf("%d\n",d[end]);
        
    }
    return 0;
}