#include <stdio.h>
#define SIZE 100

void build(int pstart,int pend,int istart,int iend,int treei);
char prefix[SIZE];
char infix[SIZE];
char tree[1000*SIZE];

void postorder(int);

int main()
{
    int cases;
    scanf("%d",&cases);
    
    while(cases--){
        
        int nodes=0;
        char temp;
        getchar();
        for(int i=0;i<SIZE;i++){
            
            char temp;
            scanf("%c",&temp);
            if(temp==' '){
                nodes=i;
                break;
            }
            
            prefix[i]=temp;
        }
        
        for(int i=0;i<nodes;i++){
            
            char temp;
            scanf("%c",&temp);
            infix[i]=temp;
        }
   
        for(int i=0;i<SIZE;i++)
            tree[i]='0';
        
        build(0,nodes-1,0,nodes-1,1);
        postorder(1);
        printf("\n");
    }
    return 0;
}

void build(int pstart,int pend,int istart,int iend,int treei)
{
    if(pstart>pend || istart>iend) return;
    
    char rootVal=prefix[pstart];
    tree[treei]=rootVal;
    
    int index=-1;
    for(int i=istart;i<=iend;i++){
        if(infix[i]==rootVal){
            index=i;
            break;
        }
    }

    build( (pstart + 1) , (index - istart + pstart) , istart, (index - 1) , treei*2 );
    build( (index - istart + pstart + 1) ,pend, (index + 1), iend , 1+ treei*2 );

}

void postorder(int x)
{
    if(tree[x]=='0')return ;
    postorder(x*2);
    postorder(1+x*2);
    printf("%c",tree[x]);
    
}