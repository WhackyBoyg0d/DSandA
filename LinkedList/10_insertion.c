#include <stdio.h>
#include <stdlib.h>

void display (int arr[], int size){
    for (int i = 0; i < size; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity){
        return -1;
    }
    else{
        for(int i = size - 1; i>=index; i-- ){
            if(i!=index){
                arr[i+1] = arr[i];
            }
            else{
                arr[i + 1] = arr[i];
                arr[i] = element;
                return 1;
            }
        }
    }
}

int indDeletion(int arr[], int size,  int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    else
    {
        for (int i = index; i <= size - 2; i++)
        {
            arr[i] = arr[i+1];
        }
        return 1;
    }
}

int main() {
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 2;
    display(arr, size);
    int a = indDeletion(arr, size, 100, index);
    size--;
    if(a!=-1){
        printf("Success\n");
        display(arr, size);
    }
    else{
        printf("oops");
    }
}