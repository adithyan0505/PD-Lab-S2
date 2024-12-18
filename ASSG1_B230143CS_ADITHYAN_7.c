#include <stdio.h>

void merge_sort(int *,int,int);
void merge(int *,int,int,int);
void swap(int *, int *);


int main()
{
    int n;
    scanf("%d",&n);
    if((n>=1)&&(n<=100000))
    {
        int i=0,temp,A[n];
        while(i<n)
        {
            scanf("%d",&temp);
            if((temp>=1)&&(n<=100000)) 
            {
                A[i]=temp;
                i++;
            }
            else{
                printf("Invalid element(s) inputed.\nElemtents of array should be in the range [1,100000]");
                return 0;
            }
        }
        
        merge_sort(A,0,n-1);
        
        for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    }
    else printf("Inavild array size.\nArray size should be in the range [1,100000]");
    return 0;
}

void merge_sort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void merge(int arr[],int left,int mid,int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i=0,j=0,k=left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void swap(int * a, int * b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
