#include <stdio.h>
#include <stdlib.h>

struct student{
    char name[20];
    int marks;
};

typedef struct student student;

student sort(student *,int,int);

int main()
{
    int n,r;
    scanf("%d",&n);
    student * stu = (student *)malloc(n*sizeof(student));
    for(int i=0;i<n;i++)
    {
        scanf("%s",(*(stu+i)).name);
        scanf("%d",&(*(stu+i)).marks);
    }
    scanf("%d",&r);

    student s = sort(stu,n,r);
    printf("%s %d",s.name,s.marks);

    free(stu);
    return 0;
}

student sort(student * arr,int n,int r)
{
    for(int j=1;j<n;j++)
    {
        student key = arr[j];
        int i = j-1;
        while((i>=0)&&(arr[i].marks<key.marks)){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
    return arr[r-1];
}