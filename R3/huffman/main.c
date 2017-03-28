#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    
    char c;
    int value;
    int parent;
    int left;
    int right;
    int exist; // 0:不存在 1:存在
    int check; // 0:還沒被選到的點 1:已經選到的點
}Tree;
Tree data[1000];
int N=0;
int Tidx;
void initail();
bool isEmpty();
void huffman();
void printCode(int x);
int cmp(const void *a ,const void *b);

int main()
{
    int cases;
    scanf("%d",&cases);
    getchar();
    
    while(cases--){
        
        initail();
        char tmp;
        int idx=0;
        N=0;
        while(1){
            
            N++;
            scanf("%c",&tmp);
            data[idx].c=tmp;
            idx++;
            
            char buffer;
            scanf("%c",&buffer);
            if(buffer=='\n') break;
        }
        
        for(int i=0;i<N;i++){
            scanf("%d",&data[i].value);
            data[i].exist=1;
        }
        int trash;
        scanf("%d",&trash);
        getchar();
       
        huffman();
        
        int check[N];
        for(int i=0;i<N;i++)check[i]=0;
        
        for(int i=0;i<N;i++){
            int min=99999,tmp;
            for(int j=0;j<N;j++){
                if(data[j].value<min && check[j]==0){
                  min=data[j].c;
                  tmp=j;
                }
            }
            printf("%c ",data[tmp].c);
                    printCode(tmp);
                    printf("\n");
                    check[tmp]=1;
        }
  
    }
    return 0;
}

void initail()
{
    for(int i=0;i<1000;i++){
        
        data[i].c=' ';
        data[i].value=999999;
        data[i].parent=-1;
        data[i].left=-1;
        data[i].right=-1;
        data[i].exist=0;
        data[i].check=0;
    }
}

bool isEmpty()
{
    bool flag=true;
    for(int i=0;i<N;i++){
        if(data[i].exist==1 && data[i].check==0){
            flag=false;
            break;
        }
    }
    return flag;
}

void huffman()
{
    
    Tidx=N-1;
    while(!isEmpty()){
       
        int min1=999,min2=999;
        int left=-1,right=-1;
        for(int i=0;i<=Tidx;i++){
        
            if(data[i].value<min1 && data[i].check==0 && data[i].exist==1){
               min1=data[i].value;
               right=i;
         }
        }
        data[right].check=1;
    
        for(int i=0;i<=Tidx;i++){
        
            if(data[i].value<min2 && data[i].check==0 && data[i].exist==1){
                min2=data[i].value;
               left=i;
          }
        }
        data[left].check=1;
    
        Tidx++;
        data[right].parent=Tidx;
        data[left].parent=Tidx;
        data[Tidx].right=right;
        data[Tidx].left=left;
        data[Tidx].value=data[left].value+data[right].value;
        data[Tidx].exist=1;
        //printf("left=%d right=%d parent=%d parent_value=%d\n",left,right,Tidx,data[Tidx].value);
    }
        
        if(data[Tidx-1].value<data[Tidx-2].value){
        Tidx++;
        data[Tidx-1].parent=Tidx;
        data[Tidx-2].parent=Tidx;
        data[Tidx].right=Tidx-1;
        data[Tidx].left=Tidx-2;
        data[Tidx].value=data[Tidx-1].value+data[Tidx-2].value;
        data[Tidx].exist=1;
        //printf("left=%d right=%d parent=%d parent_value=%d\n",Tidx-2,Tidx-1,Tidx,data[Tidx].value);
        }
        else{
            
        Tidx++;
        data[Tidx-2].parent=Tidx;
        data[Tidx-1].parent=Tidx;
        data[Tidx].right=Tidx-2;
        data[Tidx].left=Tidx-1;
        data[Tidx].value=data[Tidx-2].value+data[Tidx-1].value;
        data[Tidx].exist=1;
        //printf("left=%d right=%d parent=%d parent_value=%d\n",Tidx-1,Tidx-2,Tidx,data[Tidx].value);
        }
    int max=0,idx=-1;
    for(int i=0;i<=Tidx;i++){
        if(data[i].value>max){
            max=data[i].value;
            idx=i;
        }
    }
    data[idx].parent=idx; //root
}

void printCode(int x)
{
    //printf("ha\n");
    if(data[x].parent==x)return;
    
    else {
    printCode(data[x].parent);
    
    if(data[data[x].parent].right==x)
    printf("1");
    else if(data[data[x].parent].left==x)
    printf("0");
    }
}
