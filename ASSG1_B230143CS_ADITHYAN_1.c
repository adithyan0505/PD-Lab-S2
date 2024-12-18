#include <stdio.h>

void insertion_sort(int *,int);

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    if((n>=1)&&(n<=100000))
    {

        int temp;
        for(int i=0;i<n;i++) 
        {
            scanf("%d",&temp);
            if((temp>=-100000)&&(temp<=100000))
            A[i]=temp;
            else 
            {
                printf("Invalid value of element(s) x. Range of x should be in [-100000,100000]");
                return 0;
            }
        }
        
    }
    else{
        printf("Inavild array size.\nArray size should be in the range [1,100000]");
        return 0;
    }
    insertion_sort(A,n);
    for(int i=0;i<n;i++) printf("%d ",A[i]);
}

void insertion_sort(int * arr,int n)
{
    for(int j=1;j<n;j++)
    {
        int key = arr[j];
        int i = j-1;
        while((i>=0)&&(arr[i]>key)){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
}