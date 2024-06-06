#include <stdio.h>


void Fill(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = i + 1;
    }
}


void Print(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
    }

    printf("\n");
}


void Shift1(int arr[], int size){
    int first = arr[0];
    
    for(int i = 0; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }

    arr[size - 1] = first;
}


void ShiftVer1(int arr[], int size, int delta){
    delta %= size;

    for(int i = 0; i < delta; i++){
        Shift1(arr, size);
    }
}


void Reverse(int arr[], int left, int right){
    while(left < right){
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
}


void ShiftVer2(int arr[], int size, int delta){
    delta %= size;

    Reverse(arr, 0, size - 1);
    Reverse(arr, 0, size - delta - 1);
    Reverse(arr, size - delta, size - 1);
}


int main(void){
    int N = 6;
    int ARR[N];

    Fill(ARR, N);
    
    int delta;
    printf("Input delta: ");
    scanf("%d", &delta);

    printf("\nApproach 1:\n");
    Print(ARR, N);
    ShiftVer1(ARR, N, delta);
    Print(ARR, N);

    printf("\nApproach 2:\n");
    Print(ARR, N);
    ShiftVer2(ARR, N, delta);
    Print(ARR, N);

    return 0;
}
