#include <stdio.h>
#include <stdbool.h>

int q[10]={-1};
bool Isempty(int);
bool Isfull(int);
int index=-1;

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&q[i]);
        index=i;
    }
    
    int condition=0,data=0;
    while(scanf("%d",&condition)!=EOF){
        
        if(condition==1){ //enqueue
            scanf("%d",&data);
            if(Isfull(index)) continue;
            else{
                index++;
                q[index]=data;
            }
            
        }
        
        else if(condition==2) //dequeue
        {
            if(Isempty(index))continue;
            else{
                if(index>=1){
                    for(int i=1;i<=index;i++){
                        q[i-1]=q[i];
                    }
                    q[index]=-1;
                    index--;
                }
                else if(index==0){
                    q[0]=-1;
                    index=-1;
                }
            }
         
        }
    }
    for(int i=0;i<=index;i++){
        if(i==0)
            printf("%d",q[i]);
        else
            printf(" %d",q[i]);
    }
    printf("\n");
    return 0;
}

bool Isempty(int a)
{
  if(a==-1)
    return true;
  else
    return false;
    
}
bool Isfull(int a)
{
    if(a==9)return true;
    else return false;
}