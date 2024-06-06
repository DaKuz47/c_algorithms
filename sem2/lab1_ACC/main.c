#include <stdlib.h>
#include <stdio.h>

#define LENGTH 10

typedef int binary_op_t(int sk, int ak);


double Random(double a, double b) {
    return ((double)rand() / RAND_MAX) * (b - a) + a;
}


void FillRandom(int arr[], int size, double a, double b) {
    for(int i = 0; i < size; i++){
        arr[i] = (int)Random(a, b);
    }
}


void Print(int const arr[], int size) {
    printf("{");

    for(int i = 0; i < size - 1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d", arr[size - 1]);

    printf("}\n");
}


int BinarySum(int sk, int ak){
    return sk + ak;
}

int BinaryMax(int sk, int ak){
    return sk > ak ? sk : ak;
}

int BinaryNeg(int sk, int ak){
    if(ak < 0){
        sk++;
    }

    return sk;
}


int Accumulate(int const a[], int n, int s0, binary_op_t* op){
    int s_curr = s0;
    for(int i = 0; i < n; i++){
        s_curr = op(s_curr, a[i]);
    }

    return s_curr;
}


int main(){
    int arr[LENGTH];
    FillRandom(arr, LENGTH, -10, 10);
    Print(arr, LENGTH);

    printf("Сумма: %d\n", Accumulate(arr, LENGTH, 0, BinarySum));
    printf("Максимум: %d\n", Accumulate(arr, LENGTH, arr[0], BinaryMax));
    printf("Количество отрицательных: %d\n", Accumulate(arr, LENGTH, 0, BinaryNeg));

    return 0;
}
