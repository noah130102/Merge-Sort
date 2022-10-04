#include<iostream>
using namespace std;

void merge(int arr[], int a , int m , int b){

    int x=m-a+1;
    int y=b-m;
    int arr1[x];
    int arr2[y];
    for (int i = 0; i < x; i++)
    {
        arr1[i]=arr[a+i];
    }
    for (int i = 0; i < y; i++)
    {
        arr2[i]=arr[m+1+i];
    }
    int p1 = 0;
    int p2 = 0;
    int traverse = a;
    while (p1<x && p2<y)
    {
        if (arr1[p1]>arr2[p2])
        {
            arr[traverse]=arr2[p2];
            traverse++;
            p2++;
        }
        else
        {
            arr[traverse]=arr1[p1];
            traverse++;
            p1++;
        }
    }
    while (p1<x)
    {
        arr[traverse]=arr1[p1];
            traverse++;
            p1++;
    }
    while (p2<y)
    {
        arr[traverse]=arr2[p2];
            traverse++;
            p2++;
    }
    
}

void mergeSort(int arr[], int a, int b){
    if (a<b)
    {
        int m = (a+b)/2;
        mergeSort(arr,a,m);
        mergeSort(arr,m+1,b);

        merge(arr, a, m, b);
    }
    

}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);

    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}