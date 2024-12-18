#include <stdio.h>
#include <stdlib.h>

typedef struct dll{
    struct dll * prev;
    int data;
    struct dll * next;
} * node;

node LIST_INSERT(node,int);
node CREATE_NODE(int);
void INITIAL_LIST(node);
node REVERSE_LIST(node);

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
            node new_node = LIST_INSERT(Head,n);
            if(Head==NULL) Head=new_node;
            continue;
        }
        else if(ch=='r')
        {
            Head = REVERSE_LIST(Head);
            continue;
        }
        else if(ch=='p') INITIAL_LIST(Head);
    } while (ch!='e');
    return 0;
}

node CREATE_NODE(int num)
{
    node temp = (node)malloc(sizeof(struct dll));
    if(temp==NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    else{
        temp->prev=NULL;
        temp->data=num;
        temp->next=NULL;
    }
    return temp;
}

node LIST_INSERT(node head,int x)
{
    node new = CREATE_NODE(x);
    if(head==NULL) ;
    else{
        node temp = head;
        while(temp->next!=NULL) temp=temp->next;
        new->prev=temp;
        temp->next = new;
    }
    return new;
}


void INITIAL_LIST(node head)
{
    node x=head;
    while(x!=NULL)
    {
        printf("%d ",x->data);
        x=x->next;
    } printf("\n");
}

node REVERSE_LIST(node head)
{
    node x = head;
    while(x->next!=NULL)
    {
        node temp = x->next;
        x->next = x->prev;
        x->prev = temp;
        x=x->prev;
    }
    node temp = x->next;
    x->next = x->prev;
    x->prev = temp;    
    return x;
}