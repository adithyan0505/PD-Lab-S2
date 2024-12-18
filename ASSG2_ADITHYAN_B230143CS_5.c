#include <stdio.h>
#include <stdlib.h>

typedef struct cll{
    int data;
    struct cll * next;
} * node;

node CreateNode(int);
node InsertNode(node,int);
int NGE(node);
void Print(node);

int main()
{
    node Head = NULL;
    char ch; int n;
    do
    {
        scanf("%c",&ch);
        if(ch=='i')
        {
            scanf("%d",&n);
            node new_node = InsertNode(Head,n);
            if(Head==NULL) Head=new_node;
            continue;
        }
        else if(ch=='g')
        {
            scanf("%d",&n);
            node temp = Head;
            do{
                if(temp->data==n) printf("%d\n",NGE(temp));
                temp=temp->next;
            }while(temp!=Head);
            continue;
        }
        else if(ch=='p') Print(Head);
    } while (ch!='e');

    return 0;
}

node CreateNode(int num)
{
    node temp = (node)malloc(sizeof(struct cll));
    if(temp==NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    else{
        temp->data=num;
        temp->next=NULL;
    }
    return temp;
}

node InsertNode(node Head,int num)
{
    node new = CreateNode(num);
    if(Head==NULL){
        Head=new;
        Head->next=Head;
    }
    else{
        node x = Head;
        while(x->next!=Head) x=x->next;
        x->next=new;
        x=x->next;
        x->next=Head;
    }
    return Head;
}

void Print(node Head)
{
    node x=Head;
    if(Head==NULL)
    {
        printf("NULL");
        return;
    }
    do
    {
        printf("%d ",x->data);
        x=x->next;
    }while(x!=Head);
    printf("\n");
}

int NGE(node num)
{
    node x=num;
    do
    {
        x=x->next;
        if((x->data)>(num->data)) return x->data;
    } while (x!=num);
    return -1;
}