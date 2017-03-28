#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int sdk[5]={-1};
int sdkIndex=-1;
bool Isempty();
int top();
void pop();
void push(int);

int main()
{
    char tmp[300];
    int A[100]={-1};
    fgets(tmp,300,stdin);
    char* d=" ";
    char* p;
    p=strtok(tmp,d);
    int i=0;
    while(p!=NULL){
        A[i]=atoi(p);
        i++;
        p=strtok(NULL,d);
    }
    int len=i-1;
    //for(int j=0;j<i;j++)printf("%d ",A[j]);
    int B[100]={-1};
    for(int i=0;i<len;i++){
        scanf("%d",&B[i]);
    }
    
    int indexA=0,indexB=0;
    bool ok=true;
    while(indexB<=len){
        
        if(A[indexA]==B[indexB]){indexA++; indexB++;}
        else if(!Isempty() && top()==B[indexB]) {pop(); indexB++;}
        else if(indexA<=len){push(A[indexA]) ; indexA++; }
        else {ok=false ; break;}
    }
    printf("%s\n",ok?"Yes":"No");
    return 0;
}

bool  Isempty()
{
    if(sdkIndex==-1) return true;
    else return false;
}

int top()
{
    return sdk[sdkIndex];
}

void pop()
{
    sdk[sdkIndex]=-1;
    sdkIndex--;
}

void push(int data)
{
    if(sdkIndex>4) printf("error!\n");
    
    sdkIndex++;
    sdk[sdkIndex]=data;
}