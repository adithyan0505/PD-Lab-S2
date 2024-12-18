#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sll{
    char name[30];
    char number[13];
    char time[6];
    struct sll * next;
} * node;

node CreateNode(char *,char *,char *);
node InsertNode(node,char *,char *,char *);
void Print(node);
node Delete(node,char *);

int main()
{
    node Head = NULL;
    int ch;
    char name[30],number[13],time[6];
    do
    {
        printf("\nMenu:\n1. Add Reservation\n2. View Next Booking Request\n3. Cancel Reservation\n4. Display Reservation Queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            char temp; int i;

            printf("Customer Name: ");
            temp = getchar();i=0;
            while((temp=getchar())!='\n')
            {
                name[i]=temp;
                i++;
            }
            name[i]='\0';

            printf("Mobile Number: ");i=0;
            while((temp=getchar())!='\n')
            {
                number[i]=temp;
                i++;
            }
            number[i]='\0';

            printf("Arrival Time: ");i=0;
            while((temp=getchar())!='\n')
            {
                time[i]=temp;
                i++;
            }
            time[i]='\0';
            Head = InsertNode(Head,name,number,time);
        }
        else if(ch==2)
        {
            printf("Next Booking Request: %s (%s)\n",Head->name,Head->time);
        }
        else if(ch==3)
        {
            char string[30];
            printf("Reservation to cancel:\n");
            char temp = getchar();int i=0;
            while((temp=getchar())!='\n')
            {
                string[i]=temp;
                i++;
            }
            string[i]='\0';
            Head=Delete(Head,string);
        }
        else if(ch==4)
        {
            Print(Head);
        }
    }while(ch!=5);
    printf("Exiting...");
    return 0;
}

node CreateNode(char * name,char * number, char * time)
{
    node temp = (node)malloc(sizeof(struct sll));
    if(temp==NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    else{
        strcpy(temp->name,name);
        strcpy(temp->number,number);
        strcpy(temp->time,time);
        temp->next = NULL;
    }
    return temp;
}

node InsertNode(node Head,char * name,char * number, char * time)
{
    node x = CreateNode(name,number,time);
    if(Head==NULL) Head=x;
    else{
        node temp = Head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next = x;
    }
    return Head;
}

void Print(node Head)
{
    node x=Head;
    if(x==NULL) printf("\nReservation Queue is empty.");
    else printf("\nReservation Queue:\n");
    while(x!=NULL)
    {
        printf("%s (%s)\n",x->name,x->time);
        x=x->next;
    } printf("\n");
}

node Delete(node Head,char * name)
{
    node Tail;
    if(strcmp(Head->name,name)==0)
    {
        node temp = Head;
        Head=Head->next;
        free(temp);
        printf("Reservation for %s cancelled successfully.\n",name);
        return Head;
    }
    node x=Head;
    while(x->next!=NULL)
    {
        if(strcmp((x->next)->name,name)==0)
        {
            node temp = x->next;
            x->next = (x->next)->next;
            free(temp);
            printf("Reservation for %s cancelled successfully.\n",name);
            break;
        }
        x=x->next;
    }
    while(x->next!=NULL) x=x->next;
    Tail = x;
    if(strcmp(Tail->name,name)==0)
    {
        node x = Head;
        while(x->next!=Tail) x=x->next;
        x->next = NULL;
        free(Tail);
        printf("Reservation for %s cancelled successfully.\n",name);
    }
    return Head;
}