#include <stdio.h>

int main()
{
    int sets;
    scanf("%d",&sets);
    
    while(sets--){
        
        int nodes;
        int ring=0;
        scanf("%d",&nodes);
        
        int graph[100][100];
        int record[100];
        for(int i=0;i<100;i++)
            record[i]=0;
        
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                scanf("%d",&graph[i][j]);
                if(graph[i][j]==1)
                    record[j]++;
            }
        }
        
        int buff;
        scanf("%d",&buff);
     
        for(int i=0;i<nodes;i++){
            
            int s=0;
            while(s<nodes && record[s]!=0)++s;
            
            if(s==nodes) //ring
            {   ring=1; 
                break;
            }
            record[s]=-1;
            
            for(int j=0;j<nodes;j++){
                if(graph[s][j]==1)
                    record[j]--;
            }
        }
         if(ring==1)printf("Yes\n");
         else if(ring==0) printf("No\n");
    }
    return 0;
}