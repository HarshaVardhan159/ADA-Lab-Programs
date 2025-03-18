#include<stdio.h>
#include<time.h>

int a[20],n;

void simplesort(int a[],int,int,int);
void mergesort(int a[],int,int);

int main()
{

    clock_t start,end;
    double timetaken;

    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {

        scanf("%d",&a[i]);
    }
    start=clock();
    mergesort(a,0,n-1);
    end=clock();

    timetaken=(double)(end-start)/(CLOCKS_PER_SEC);

    printf("Sorted array\n");
    for(int i=0;i<n;i++)
    {

        printf("%d",a[i]);
    }

    printf("\nTime taken:%f\n",timetaken);
    printf("Name: Kalaga Harsha Vardhan\nUSN: 1BM23CS136");

    return 0;
}

void mergesort(int a[],int low,int high)
{

    if(low<high)
    {

        int mid =(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        simplesort(a,low,mid,high);
    }
}

void simplesort(int a[],int low,int mid,int high)
{

    int i=low;
    int k=low;
    int j=mid+1;

    int c[n];

    while(i<=mid && j<=high)
    {

        if(a[i]<a[j])
        {

            c[k++]=a[i++];
        }
        else
        {
            c[k++]=a[j++];
        }
    }
    while(i<=mid)
    {

        c[k++]=a[i++];
    }

    while(j<=high)
    {

        c[k++]=a[j++];
    }
    for(int i=low;i<=high;i++)
    {

        a[i]=c[i];
    }
}
