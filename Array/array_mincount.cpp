/* WAP IN C++ USING DMA TO FIND THE MINIMUM DISTANCE BETWEEN TWO ELEMENTS IN THE
GIVEN ARRAY OF N ELEMENTS WHICH MIGHT CONTAIN DUPLICATES(DON'T COUNT) */

#include <iostream>
using namespace std;

int minDistance(int arr[],int n,int x,int y)
{
    int lastPos=-1,minDist=n;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x || arr[i]==y)
        {
            minDist = i - lastPos;
            if(lastPos!= -1 && arr[x]!=arr[lastPos])
            {
                int dist = i - lastPos;
                if(dist<minDist) minDist=dist;
            }
            lastPos = i;
        }
    }
    
    return minDist;
}

int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);

    int *arr;
    arr=(int *)malloc(n*sizeof(int));

    printf("Enter the elements:");

    for(int i=0;i<n;i++)
    {
        scanf("%d",(arr+i));
    }

    int dist=0;
    int x,y;
    printf("Enter the values of the starting and ending pts:");
    scanf("%d%d",&x,&y);

    dist = minDistance(arr,n,x,y);

    printf("The mininum distance between %d and %d is %d\n",x,y,dist);

    free(arr);
    return 0;
}