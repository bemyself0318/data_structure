#include <stdio.h>

struct node
{
    int value;
    char letter;
    struct node* left;
    struct node* right;
}

typedef struct node Node;

int findSmaller(Node* array[], int different);
void buildHuffmanTree(Node **tree);
void fillTable(int codeTable[], Node *tree, int Code);

int main()
{
    return 0;
}

int findSmaller(Node* array[], int different)
{
    int smaller,i=0;
    
    while(array[i]->value == -1) i++;
    smaller=i;
    
    for(i=1;i<27;i++){
        if (array[i]->value==-1)
            continue;
        if (i==differentFrom)
            continue;
        if (array[i]->value < array[smaller]->value)
            smaller = i;
    }
    
    return smaller;
}

void buildHuffmanTree(Node **tree){
    Node *temp;
    Node *array[27];
    int i, subTrees = 27;
    int smallOne,smallTwo;

    for (i=0;i<27;i++){
        array[i] = malloc(sizeof(Node));
        array[i]->value = englishLetterFrequencies[i];
        array[i]->letter = i;
        array[i]->left = NULL;
        array[i]->right = NULL;
    }

    while (subTrees>1){
        smallOne=findSmaller(array,-1);
        smallTwo=findSmaller(array,smallOne);
        temp = array[smallOne];
        array[smallOne] = malloc(sizeof(Node));
        array[smallOne]->value=temp->value+array[smallTwo]->value;
        array[smallOne]->letter=127;
        array[smallOne]->left=array[smallTwo];
        array[smallOne]->right=temp;
        array[smallTwo]->value=-1;
        subTrees--;
    }

    *tree = array[smallOne];

return;
}

void fillTable(int codeTable[], Node *tree, int Code){
    if (tree->letter<27)
        codeTable[(int)tree->letter] = Code;
    else{
        fillTable(codeTable, tree->left, Code*10+1);
        fillTable(codeTable, tree->right, Code*10+2);
    }

    return;
}