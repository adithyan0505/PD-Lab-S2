#include <stdio.h>

void quick_sort(int *, int, int);
int partition(int *, int, int);
void swap(int *, int *);

int main()
{
    int n;
    scanf("%d",&n);
    if((n>=1)&&(n<=10000))
    {
        int i=0,temp,A[n];
        while(i<n)
        {
            scanf("%d",&temp);
            if((temp>=1)&&(n<=1000000)) 
            {
                A[i]=temp;
                i++;
            }
            else{
                printf("Invalid element(s) inputed.\nElemtents of array should be in the range [1,1000000]");
                return 0;
            }
        }
        
        quick_sort(A,0,n-1);
        
        for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    }
    else printf("Inavild array size.\nArray size should be in the range [1,10000]");
    return 0;
}

void quick_sort(int arr[], int low, int high)
{
    if(low<high)
    {
        int p = partition(arr,low,high);

        quick_sort(arr,low,p-1);
        quick_sort(arr,p+1,high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = high+1;
    for(int j=high;j>=low;j--)
    {
        if(arr[j]>pivot)
        {
            i--;
            swap(&arr[i],&arr[j]);
        }
        
    }
    swap(&arr[i-1],&arr[low]);
    return (i-1);
}

void swap(int * a, int * b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}