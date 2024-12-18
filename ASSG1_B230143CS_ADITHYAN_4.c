#include <stdio.h>

void swap(int *,int *);

int main()
{
    int n,k;
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
        scanf("%d",&k);
        if((k<1)||(k>n))
        {
            printf("Invalid value of k.\nValue of k should be in the range [1,%d]",n);
            return 0;
        }

        for(int i=0;i<n-1;i++)
        {
            int key = i;
            for(int j=i+1;j<n;j++)
                if(arr[key]>arr[j]) key=j;
            if(key!=i) swap(&arr[i],&arr[key]);
        }

        printf("%d",arr[k-1]);
    }
    else printf("Inavild array size.\nArray size should be in the range [1,100000]");
    return 0;
}

void swap(int * a, int * b){
    int temp = *b;
    *b = *a;
    *a = temp;
}