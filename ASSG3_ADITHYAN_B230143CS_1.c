 #include <stdio.h>

struct car{
    char name[50];
    int mileage;
};

void swap(struct car *,struct car *);
void min_heapify(struct car *,int,int);
void heapsort(struct car *,int);

int main()
{
    int N; char ch;
    scanf("%d",&N);
    struct car cars[N];
    for(int j=0;j<N;j++)
    {
        int i=0;
        getchar();
        while((ch=getchar())!=':')
        {
            cars[j].name[i]=ch;
            i++;
        }
        cars[j].name[i]='\0';
        scanf("%d",&(cars[j].mileage));
    }
    heapsort(cars,N);
    for(int j=0;j<N;j++)
    printf("%s:%d\n",cars[j].name,cars[j].mileage);
    return 0;
}

void swap(struct car * a,struct car * b)
{
    struct car temp = *b;
    *b = *a;
    *a = temp;
}

void min_heapify(struct car * arr,int i,int n)
{
    int smallest = i;
    int left = 2*i+1, right = 2*i+2;
    if((left<n)&&((arr[left].mileage)<(arr[smallest].mileage)))
    smallest=left;
    if((right<n)&&(arr[right].mileage<arr[smallest].mileage))
    smallest=right;

    if(smallest!=i){
        swap(&arr[i],&arr[smallest]);
        min_heapify(arr,smallest,n);
    }
}

void heapsort(struct car * arr,int n)
{
    for(int i = (n/2)-1;i>=0;i--)
        min_heapify(arr,i,n);

    for(int j=n-1;j>0;j--)
    {
        swap(&arr[0],&arr[j]);
        min_heapify(arr,0,j);
    }
}