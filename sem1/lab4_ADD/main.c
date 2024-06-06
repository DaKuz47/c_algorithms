#include <math.h>
#include <stdio.h>

#define LENGTH 10


int Fill(int number, int digits[], int length){
    int n_leading_zeros = 0;

    for(int i = 0; i < length; i++){
        if (number == 0){
            n_leading_zeros++;
        } else {
            n_leading_zeros = 0;
        }

        digits[i] = number % 10;
        number /= 10;
    }
    
    return length - n_leading_zeros;
}


void Print(int const digits[], int n_digits, int length){
    for(int i = 0; i < length - n_digits; i++){
        printf(" ");
    }
    for(int i = n_digits - 1; i >= 0; i--){
        printf("%d", digits[i]);
    }

    printf("\n");
}


int Add(int const x[], int const y[], int xy[], int length){
    int n_dec = 0;
    int n_leading_zeros = 0;

    for(int i = 0; i < length; i++){
        int tmp_num = x[i] + y[i] + n_dec;
        if (tmp_num == 0){
            n_leading_zeros++;
        } else {
            n_leading_zeros = 0;
        }

        xy[i] = tmp_num % 10;
        n_dec = tmp_num / 10;
    }

    return length - n_leading_zeros;
}


int Collect(int const digits[], int length){
    int number = 0;

    for(int i = 0; i < length; i++){
        number += digits[i] * pow(10, i);
    }

    return number;
}


int main(void){
    int A[LENGTH];
    int B[LENGTH];
    int C[LENGTH];
    int a;
    int b;

    printf("Input number a:\n");
    scanf("%d", &a);
    printf("Input number b:\n");
    scanf("%d", &b);

    int n_digits_A = Fill(a, A, LENGTH);
    int n_digits_B = Fill(b, B, LENGTH);
    int n_digits_C = Add(A, B, C, LENGTH);
    
    printf("\n");

    Print(A, n_digits_A, n_digits_C);
    Print(B, n_digits_B, n_digits_C);
    for(int i = 0; i < n_digits_C; i++){
        printf("-");
    }
    printf("\n");
    Print(C, n_digits_C, n_digits_C);

    int column_res = Collect(C, LENGTH);
    int etalonre_res = a + b;

    if (column_res == etalonre_res){
        printf("Result correct!\n");
    } else {
        printf("Something Wrong :(\n");
    }
    return 0;
}
