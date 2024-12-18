#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n; char temp;
    scanf("%d",&n);
    char ** ptr = (char**)malloc(n*sizeof(char*));
    temp=getchar();
    for(int i=0;i<n;i++)
    {
        *(ptr+i) = (char*)malloc(50*sizeof(char));
        int j=0;
        while((temp=getchar())!='\n')
        {
            ptr[i][j]=temp;
            j++;
        }
        ptr[i][j]='\0';
    }
    char max[50];
    for(int i=0;i<n;i++)
    if(strlen(*(ptr+i))>strlen(max) > 0) strcpy(max,*(ptr+i));

    printf("%s",max);

    free(ptr);
    return 0;
}
