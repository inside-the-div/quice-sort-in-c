#include<stdio.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high){
    int i,j;
    int pivot = arr[low];
    i = low;
    j = high;
    while(i<j){
        do{
            i++;
        }while(arr[i]<=pivot);
        do{
            j--;
        }while(arr[j]>pivot);

        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
int quick_sort(int arr[], int low, int high){

    if(low < high){
        //divide and conquer
        int p = partition(arr,low,high);
        //recursively call left and right side array
        quick_sort(arr, low, p);
        quick_sort(arr, p + 1, high);
    }
}

int main(){

    //out actual array is = [40,3,100,5,10,20,50,60]
    //We take an infinite number (100000) at the last for our calculation

    int arr[] = {40,3,100,5,10,20,50,60,100000};
    int size = sizeof(arr)/sizeof(arr[0]);

    //call quicksort function
    quick_sort(arr,0,size-1);
    int i;
    for (i=0; i < size-1; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
