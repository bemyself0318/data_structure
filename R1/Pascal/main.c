#include <stdio.h>
#include <stdlib.h>

typedef struct ns{
    int data;
    struct ns* next;
}Node;

Node* creat(int);
void insert(Node*,int); 
void print(Node*);
void freeList(Node*);
int max(Node*,int);

int factorial(int );
int combination(int,int);

int main()
{   
    int input;
    scanf("%d",&input);
    Node* ans;
    for(int j=0;j<input;j++){
         ans=creat(1);
    for(int k=0;k<=j;k++){
        
        if(k==0)
            ans->data=combination(j,k);
        else{
            insert(ans,combination(j,k));
        }
    }
     print(ans);
    }
    printf("%d\n",max(ans,input));
    return 0;
}

Node* creat(int data)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;
    n->next=NULL;
    
    return n;
}

void insert(Node* list , int data)
{
   Node* tmp=creat(data);
   while(list->next!=NULL)list=list->next;
   list->next=tmp;
}

void print(Node* list)
{
    Node* n =list;
    int flag=0;
    while(n!=NULL){
        if(flag==0){
        printf("%d",n->data);
        flag=1;
        }
        else
        printf(" %d",n->data);
        n=n->next;
    }
    printf("\n");
}

void freeList(Node* list)
{
    if(list->next!=NULL)
        freeList(list->next);
    free(list);
}

int factorial(int n)
{
    if(n==1 || n==0)
        return 1;
    return n*factorial(n-1);
}

int combination(int n, int k)
{
    return factorial(n)/(factorial(n-k)*factorial(k));
}

int max(Node* list,int size)
{
    Node* n =list;
    int cnt=0;
    int check=0;
    size%2==0?(check=size/2):(check=1+(size/2));
    while(n!=NULL){
        cnt++;
        if(cnt==check)
            return n->data;
        n=n->next;
    }
}