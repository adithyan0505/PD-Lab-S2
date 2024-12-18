#include <stdio.h>

typedef struct job{
    int id;
    int priority;
}Job;

int parent(int i){return (i-1)/2;}

void swap(Job * a,Job * b)
{
    Job temp = *b;
    *b = *a;
    *a = temp;
}

void add(Job *,int,int,int);
void schedule(Job *,int *);
void next_job(Job *,int);
void replace_priority(Job *,int,int,int);
void display(Job *,int);

int main()
{
    char ch;
    int id,p,a=-1;
    Job job[20];
    do{
        scanf("%c",&ch);
        if(ch=='a')
        {
            scanf("%d %d",&id,&p);
            a++;
            add(job,id,p,a);
        }
        else if(ch=='s')
        {
            schedule(job,&a);
        }
        else if(ch=='n')
        {
            next_job(job,a);
        }
        else if(ch=='r')
        {
            scanf("%d %d",&id,&p);
            replace_priority(job,id,p,a);
        }
        else if(ch=='d')
        {
            display(job,a);
        }
    }while(ch!='e');
    
    return 0;
}

void add(Job * Que,int ID,int p,int size)
{
    Que[size].id=ID; Que[size].priority=p;
    int i=size;
    while((i>0)&&(Que[parent(i)].priority<Que[i].priority))
    {
        swap(&Que[parent(i)],&Que[i]);
        i = parent(i);
    }
}

void schedule(Job * Que,int * size)
{
    if(*size==-1)
    {
        printf("-1");
        return;
    }
    else printf("%d\n",Que[0].id);

    swap(&Que[0],&Que[*size]);
    (*size)--;
    int i=*size;
    while((i>0)&&(Que[parent(i)].priority<Que[i].priority))
    {
        swap(&Que[parent(i)],&Que[i]);
        i = parent(i);
    }
}

void next_job(Job * Que,int size)
{
    if(size==-1)
    {
        printf("-1");
        return;
    }
    else printf("%d\n",Que[0].id);
}

void replace_priority(Job * Que,int ID,int np,int size)
{
    int flag=0; int i;
    for(i=0;i<=size;i++)
    {
        if(Que[i].id==ID)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("-1");
        return;
    }

    int p = Que[i].priority;
    Que[i].priority=np;

    if(np>p)
    {
        i=size;
        while((i>0)&&(Que[parent(i)].priority<Que[i].priority))
        {
            swap(&Que[parent(i)],&Que[i]);
            i = parent(i);
        }
    }
    else
    {
        while(i<=size)
        {
            int highest = i;
            int left = 2*i+1;
            int right = 2*i+2;
            if((left<=size)&&(Que[left].priority>Que[highest].priority))
                highest=left;
            if((right<=size)&&(Que[right].priority>Que[highest].priority))
                highest=right;
            
            if(highest!=i)
            {
                swap(&Que[highest],&Que[i]);
                i=highest;
            }
        }
    }
}

void display(Job * Que,int size)
{
    if(size==-1)
    {
        printf("-1");
        return;
    }
    for(int i=0;i<=size;i++)
    {
        printf("%d %d\n",Que[i].id,Que[i].priority);
    }
}