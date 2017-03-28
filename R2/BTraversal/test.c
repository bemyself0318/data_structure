#include <stdio.h>
#define SIZE 100

char prefix[SIZE];
char infix[SIZE];
char tree[SIZE*100];
void build(int ,int,int,int,int);
void postorder(int);

int main()
{
    int cases;
    scanf("%d",&cases);
    
    while(cases--){
        
        getchar();
        char tmp;
        int N;
        for(int i=0;i<SIZE;i++){
            scanf("%c",&tmp);
            if(tmp==' '){
                N=i;
                break;
            }
            prefix[i]=tmp;
        }
        
        int buff;scanf("%d",&buff);
        
        for(int i=0;i<N;i++){
            scanf("%c",&tmp);
            infix[i]=tmp;
        }
        
        for(int i=0;i<SIZE*100;i++){
            tree[i]='0';
        }
        
        build(0,N-1,0,N-1,1);
        postorder(1);
        printf("\n");
        
    }
}

void build(int pstart, int pend , int istart ,int iend ,int treei)
{
    if(pstart>pend || istart>iend) return;
    
    char root=prefix[pstart];
    tree[treei]=root;
    
    int index=-1;
    for(int i=istart;i<=iend;i++){
        if(infix[i]==root){
            index=i;
            break;
        }
    }
    
    build(pstart+1,index-istart+pstart,istart,index-1,treei*2);
    build(index-istart+pstart+1,pend,index+1,iend,1+treei*2);
}

void postorder(int x)
{
    if(tree[x]=='0') return;
    
    postorder(x*2);
    postorder(1+x*2);
    printf("%c",tree[x]);
}