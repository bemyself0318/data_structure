#include <stdio.h>

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--){
        
        int N;
        scanf("%d",&N);
        
        int graph[N][N];
        int record[N];
        for(int i=0;i<N;i++) record[i]=0;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                scanf("%d",&graph[i][j]);
                if(graph[i][j]==1){
                    record[j]++;
                }
            }
        
        int buff;scanf("%d",&buff);
        
        int ring=0;
        for(int i=0;i<N;i++){
            
            int s=-1;
            while(s<N && record[s]!=0)s++;
            
            if(s==N){
                ring=1;
                break;
            }
            record[s]=-1;
            
            for(int j=0;j<N;j++){
                if(graph[s][j]==1)
                    record[j]--;
            }
        }
        ring==1?(printf("Yes\n")):(printf("No\n"));
    }
    return 0;
}