#include <stdio.h>
#include <string.h>

struct library{
    char name[100];
};

void insertion_sort(struct library *,int);

int main()
{
    int n; char temp;
    scanf("%d",&n);
    if(!((n>=1)&&(n<=100000)))
    {
        printf("Inavild array size.\nArray size should be in the range [1,100000]");
        return 0;
    }
    getchar();
    struct library lib[n];
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<100;j++)
        {
            temp = getchar();
            if(temp=='\n')
            {
                lib[i].name[j]='\0';
                break;
            }
            lib[i].name[j]=temp;
        }
    }
    insertion_sort(lib,n);
    for(int i=0;i<n;i++) printf("\n%s",lib[i].name);
}

void insertion_sort(struct library * lib,int n)
{
    for(int j=0;j<n;j++)
    {
        char key[100];
        strcpy(key,lib[j].name);
        int i=j-1;
        while((i>=0)&&(strcmp(lib[i].name,key)>0))
        {
            strcpy(lib[i+1].name,lib[i].name);
            i--;
        }
        strcpy(lib[i+1].name,key);
    }

}

