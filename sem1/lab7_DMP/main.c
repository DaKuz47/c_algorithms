#include <stdio.h>


void FillInt(int arr[], int size){
    int number = 600;

    for(int i = 0; i < size; i++){
        arr[i] = number + 2 * i;
    }
}


void FillDouble(double arr[], int size){
    double number = 600;

    for(int i = 0; i < size; i++){
        arr[i] = number + 2 * i;
    }
}


void PrintInt(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}



void PrintDouble(double arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%lf ", arr[i]);
    }

    printf("\n");
}


void MemoryDump(void const* ptr, int size){
    int const byte_per_row = 16;
    int row_count = size / byte_per_row;
    if(size % byte_per_row > 0){
        row_count++;
    }

    for(int i = 0; i < row_count; i++){
        int n_rest_bytes = size - i * byte_per_row;
        int n_current_bytes = n_rest_bytes < byte_per_row ? n_rest_bytes : byte_per_row;

        printf("%p: ", ptr);
        for(int j = 0; j < n_current_bytes; j++){
            printf("%02x ", *(char*)ptr);
            ptr += 1;
        }

        printf("\n");
    }
}


int main(void){
    int N = 9;
    int A[N];
    double B[N];

    FillInt(A, N);
    FillDouble(B, N);

    printf("Int array:\n");
    PrintInt(A, N);
    MemoryDump(A, sizeof(A));

    printf("\n");

    printf("Double array:\n");
    PrintDouble(B, N);
    MemoryDump(B, sizeof(B));

    return 0;
}
