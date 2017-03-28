#include <stdio.h>
#include <string.h>

int main()
{
    int N,J,K,L;
    scanf("%d %d %d %d",&N,&J,&K,&L);
    
    int fireOfMonster[N];
    for(int i=0;i<N;i++)
        scanf("%d",&fireOfMonster[i]);
    
    int map[N][N];
    memset(map,0,sizeof(map));
    int from,to;
    for(int i=0;i<J;i++){
        scanf("%d %d",&from,&to);
        map[from][to]=1;
    }
    
    int fail=0,defeat=0;
    int stack[J];
    memset(stack,-1,sizeof(stack));
    stack[0]=0;
    int idx=0;
    
    while(idx>=0 && K<L){
        
        int current=stack[idx];
        idx--;
        
        if(K>fireOfMonster[current]){
            
            K+=fireOfMonster[current];
            for(int i=N-1;i>=0;i--)
                if(map[current][i]==1){
                    idx++;
                    stack[idx]=i;
                }
            defeat++;
            continue;
        }
        fail++;
    }
    printf("%d %d %d\n",fail,defeat,K);
    return 0;
}