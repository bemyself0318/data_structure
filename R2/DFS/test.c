#include <stdio.h>
#include <string.h>

int main()
{
    int N,path,fire,goal;
    scanf("%d %d %d %d",&N,&path,&fire,&goal);
    
    int fireofmon[N];
    for(int i=0;i<N;i++)
        scanf("%d",&fireofmon[i]);
        
    int map[N][N];
    memset(map,0,sizeof(map));
    int from,to;
    for(int i=0;i<path;i++){
        
        scanf("%d %d",&from,&to);
        map[from][to]=1;
    }
    
    int stack[path] ;
    memset(stack,-1,sizeof(stack));
    stack[0]=0;
    int idx=0;
    
    int fail=0,defeat=0;
    while(idx>=0 && fire<goal){
        
        int current=stack[idx];
        idx--;
        if(fire>fireofmon[current]){
            
            fire+=fireofmon[current];
            for(int i=N-1;i>=0;i--){
                if(map[current][i]==1){
                    idx++;
                    stack[idx]=i ;
                }
            }
            defeat++ ;
            continue;
        }
        fail++;
    }
    printf("%d %d %d\n",fail,defeat,fire);
    return 0;
}