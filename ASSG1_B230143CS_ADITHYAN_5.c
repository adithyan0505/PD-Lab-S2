#include <stdio.h>

void swap(int *, int *);
int bubble_sort(int *,int);

int main()
{
    int n;
    scanf("%d",&n);
    if((n>=1)&&(n<=100000))
    {
        int arr[n],temp,i=0;
        while(i<n)
        {
            scanf("%d",&temp);
            if((temp>=1)&&(n<=100000)) 
            {
                arr[i]=temp;
                i++;
            }
            else{
                printf("Invalid element(s) inputed.\nElemtents of array should be in the range [1,100000]");
                return 0;
            }
        }
        int count = bubble_sort(arr,n);
        for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
        printf("\n");
        printf("%d",count);
    }
    else printf("Inavild array size.\nArray size should be in the range [1,100000]");
    return 0;
}

void swap(int * a, int * b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int bubble_sort(int * arr,int n)
{
    int c = 0;
    for(int i=0;i<n-1;i++)
    {   int flag = 0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]) 
            {
                c++;
                swap(&arr[j],&arr[j+1]);
                flag = 1;
            }
        }
        if(flag!=1) break;
    }
    return c;
}