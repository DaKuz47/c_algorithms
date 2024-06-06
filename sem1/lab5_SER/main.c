#include <math.h>
#include <stdio.h>

#define EPS 0.0001


double f(double x){
    double current = pow(x, 2);
    double sum = current;

    int k = 1;
    while(fabs(current) > EPS){
        current = -current * 4 * pow(x, 2) / (4 * pow(k, 2) + 6 * k + 2);
        sum += current;

        k++;
    }

    return sum;
}


double g(double x){
    return pow(sin(x), 2);
}


void PrintTable(double a, double b, int m){
    double step = (b - a) / (m - 1);

    printf("+-----+-----+-------------+-------------+-------------+\n");
    printf("|%5s|%5s|%13s|%13s|%13s|\n", "i", "x", "f(x)", "g(x)", "f(x)-g(x)");
    printf("+-----+-----+-------------+-------------+-------------+\n");

    for(int i = 0; i < m; i++){
        double x = a + step * i;
        double numeric_res = f(x);
        double etalone_res = g(x);

        printf(
            "|%5d|%5.1lf|%13.2lf|%13.2lf|%13.2le|\n",
            i, x, numeric_res, etalone_res, numeric_res - etalone_res
        );
    }

    printf("+-----+-----+-------------+-------------+-------------+\n");
}

int main(void){
    double a, b;
    int m;

    printf("Input bounds a, b: \n");
    while(1){
        scanf("%lf %lf", &a, &b);
        if (fabs(a) > 1 || fabs(b) > 1){
            printf("Wrong interval bounds. |x| <= 1");
        } else {
            break;
        }
    }

    printf("Input m: \n");
    while(1){
        scanf("%d", &m);
        if (m < 1){
            printf("Wrong value. m > 1");
        } else {
            break;
        }
    }

    PrintTable(0.53, 0.85, 4);

    return 0;
}
