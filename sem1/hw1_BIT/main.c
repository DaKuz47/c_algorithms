#include <locale.h>
#include <stdio.h>

typedef unsigned char integer_t;
// typedef unsigned short integer_t;
// typedef unsigned int integer_t;
// typedef unsigned long integer_t;

typedef unsigned long MaxInt;


void printBites(integer_t x, int new_line){
    int byte, i;

    for(i = sizeof(integer_t) * 8 - 1; i >= 0; i--){
        byte = (x >> i) & 1;
        printf("%d", byte);
    }

    if(new_line){
        printf("\n");
    }
}


integer_t Process(integer_t n){
    integer_t result = 0;

    int size = sizeof(integer_t) * 8;

    for(int i = 0; i < size / 4; i++){
        integer_t high_pair = (n >> (size - 2 * (i + 1))) & 3; // 3 == 011
        integer_t low_pair = (n >> (2 * i)) & 3;

        result |= (low_pair << (size - 2 * (i + 1)));
        result |= (high_pair << (2 * i));
    }

    return result;
}


int getWidth(integer_t a, integer_t b){
    integer_t max_num = a > b ? a : b;

    int width = max_num != 0;
    while(max_num > 0){
        width++;
        max_num /= 10;
    }

    return width;
}


int main(void){
    setlocale(LC_ALL, "Russian");

    MaxInt num;

    do {
        printf("Введите число: ");
        scanf("%ld", &num);
        
        integer_t converted_num = (integer_t)num;
        integer_t processed = Process(converted_num);
        int dec_width = getWidth(converted_num, processed);
        printf("Вы ввели  : %*i = ", dec_width, converted_num);
        printBites(converted_num, 1);
        printf("Результат : %*i = ", dec_width, processed);
        printBites(processed, 1);

    } while(num);
    return 0;
}
