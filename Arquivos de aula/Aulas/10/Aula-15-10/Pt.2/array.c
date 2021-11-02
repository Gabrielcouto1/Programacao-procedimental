#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

const int MAX=10;
const int PRIME=23;

int maiorUniArrayOfInt(const int n[],int ma)
{
    int p;
    int i;
    
    for(i=p=0;i<=ma;i++)
        if(n[i]>n[p])
            p=i;

    return p;
}

void loadUniArrayOfInt(int n[])
{
    int i;

    srand(time(NULL));
    for (i=0;i<MAX;i++)
        n[i]=rand()%PRIME;
    
}

void showUniArrayOfInt(int n[])
{
    int i;
    for (i=0;i<MAX;i++)
        printf("%d ",n[i]);
    printf("\n\n");
}

void SortArray(int n[])
{
    int p=0;
    int t=0;
    int i;

    for(i=MAX-1;i>=0;i--){
        t=n[i];
        p=maiorUniArrayOfInt(n,i);
        n[i]=n[p];
        n[p]=t;
    }
}