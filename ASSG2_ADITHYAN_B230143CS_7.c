#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char url[50];
    struct stack * next;
}* history;

history Visit_New_Page(char *,history);
history New_Node(char *);
history Go_Back(history);
history Clear_History(history);

int main()
{
    int ch; char page_url[50];
    history top=NULL;
    do
    {
        printf("\nMenu\n1. Visit New Page\n2.Go Back\n3.Clear History\n4.Display History\n5.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("Enter URL: ");
            scanf("%s",page_url);
            top = Visit_New_Page(page_url,top);
            printf("Page: '%s' visted successfully.\n",top->url);
        }
        else if (ch==2)
        {
            top = Go_Back(top);
            if(top!=NULL)
            printf("Navigating back to page '%s'.\n",top->url);
            else
            printf("Empty History\n");
        }
        else if (ch==3)
        {
            if(top!=NULL)
            {
                top = Clear_History(top);
                printf("History Cleared.\n");
            }
            else printf("History already cleared!\n");
        }
        else if (ch==4) 
        {
            printf("Browsing History:\n");
            history temp = top;
            while(temp!=NULL)
            {
                printf("%s\n",temp->url);
                temp = temp->next;
            }
        }
    } while (ch!=5);
    
}

history Visit_New_Page(char * url,history top)
{
    history new = New_Node(url);
    if(new!=NULL)
    {
        if(top==NULL)
        {
            new->next = NULL;
            top = new;
        }
        else
        {
            new->next = top;
            top = new;
        }
        return top;
    }
    return NULL;
}

history New_Node(char * data)
{
    history new = (history)malloc(sizeof(struct stack));
    if(new==NULL){
        printf("Memory Allocation Error");
    }
    else{
        strcpy(new->url,data);
       return new;
    }
    return NULL;
}

history Go_Back(history top)
{
    if(top!=NULL)
    {
        history new = top->next;
        free(top);
        return new;
    }
    else return NULL;
}

history Clear_History(history top)
{
    while(top!=NULL)
    {
        history temp = top->next;
        free(top);
        top = temp;
    }
    return top;
}