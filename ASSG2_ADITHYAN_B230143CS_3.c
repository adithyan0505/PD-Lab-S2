#include <stdio.h>
#include <stdlib.h>

struct sll{
    int data;
    struct sll *next;
};
typedef struct sll node;

node * CreateNode(int);
node * InsertNode(node *,int);
void Print(node *);
void Sort(node *);

int main()
{
    node * Head = NULL;
    char ch; int n;
    while(ch!='e')
    {
        scanf("%c",&ch);
        if(ch=='i'){
            scanf("%d",&n);
            Head = InsertNode(Head,n);
        }
        else if(ch=='p') Print(Head);
        else if(ch=='s') Sort(Head);
    }

    return 0;
}

node * InsertNode(node * Head,int num)
{
    node *x = CreateNode(num);
    if(Head==NULL) Head=x;
    else{
        node * temp = Head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next = x;
    }
    return Head;
}

node * CreateNode(int num)
{
    node *temp = (node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    else{
        temp->data = num;
        temp->next = NULL;
    }
    return temp;
}

void Print(node * Head)
{
    node * x=Head;
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    } printf("\n");
}

void Sort(node * Head)   //selection sort
{
    node * temp = Head;
    while(temp->next!=NULL)
    {
        node * min = temp;
        node * temp1 = temp->next;
        while(temp1!=NULL)
        {
            if((temp1->data)<(min->data))
                min=temp1;
            temp1=temp1->next;
        }
        if(min!=temp)
        {
            int data = temp->data;
            temp->data = min->data;
            min->data = data;
        }

        temp=temp->next;
    }
}