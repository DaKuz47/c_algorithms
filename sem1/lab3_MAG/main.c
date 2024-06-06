#include <stdio.h>

int main(void){
    int mag_num_ciffers[50];
    int current_ciffer = 2;
    int dec_count = 0;
    int n_mag_num_ciffers = 0;

    for(int i = 0; i < 50; i++){
        mag_num_ciffers[i] = current_ciffer;
        int next_ciffer = current_ciffer * 2;
        current_ciffer = next_ciffer % 10 + dec_count;
        dec_count = next_ciffer / 10;
        n_mag_num_ciffers++;

        if (current_ciffer == 2 && dec_count == 0){
            break;
        }
    }

    printf("Magic number:\n");
    for(int i = n_mag_num_ciffers - 1; i >= 0; i--){
        printf("%d", mag_num_ciffers[i]);
    }
    printf("\n");

    return 0;
}
