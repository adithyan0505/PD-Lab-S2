#include <stdio.h>
#include <string.h>

struct store{
    char name[100];
    int price;
};

void selection_sort(struct store *,int);
void swap1(int *, int *);
void swap2(char *, char *);

int main(){
    int n;
    scanf("%d",&n);
    struct store S[n];
    if((n>=1)&&(n<=100000))
    {
        for(int i=0;i<n;i++)
        {
            char temp[10000];
            scanf("%s",temp);
            printf("%d",strlen(temp));
            if(strlen(temp)>100)
            {
                printf("Invalid input for name. Length of string name exceeds 100");
                return 0;
            }
            strcpy(S[i].name,temp);
            scanf("%d",&S[i].price);
        }
    }
    else{
        printf("Inavild array size.\nArray size should be in the range [1,100000]");
        return 0;
    }

    selection_sort(S,n);
    for(int i=0;i<n;i++)
    printf("%s\t",S[i].name);
    printf("\n");
    for(int i=0;i<n;i++)
    printf("%d\t",S[i].price);
    return 0;
}

void swap1(int * a, int * b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void swap2(char * a, char * b)
{
    char temp[100];
    strcpy(temp,b);
    strcpy(b,a);
    strcpy(a,temp);
}

void selection_sort(struct store * s,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int ind=i;
        for(int j=i+1;j<n;j++)
            if(s[j].price<s[ind].price) ind=j;
        if(ind!=i) 
        {
        swap1(&(s[ind].price),&(s[i].price));
        swap2(s[ind].name,s[i].name);
        }
    }
}

