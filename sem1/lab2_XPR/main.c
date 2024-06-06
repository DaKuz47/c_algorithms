#include <locale.h>
#include <math.h>
#include <stdio.h>


int main(void){
    setlocale(LC_ALL, "Russian");

    const double density = 500.0;
    double weight;
    double length;

    printf("Введите массу (кг):\n");
    while(1){
        scanf("%lf", &weight);
        if (weight <= 0){
            printf("Масса должна быть положительным числом.\n");
        } else {
            break;
        }
    }

    printf("Введите длину (м):\n");
    while(1){
        scanf("%lf", &length);
        if (length <= 0){
            printf("Длина должна быть положительным числом.\n");
        } else {
            break;
        }
    }

    double diameter = 2 * sqrt(weight / (M_PI * density * length));
    printf("Диаметр равен %lf м.\n", diameter);

    return 0;
}
