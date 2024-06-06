#include <stdlib.h>
#include <stdio.h>


float Random(float a, float b) {
    return ((float)rand() / RAND_MAX) * (b - a) + a;
}


void FillFloats(float arr[], int size, float a, float b) {
    for(int i = 0; i < size; i++){
        arr[i] = Random(a, b);
    }
}


void PrintFloats(float const arr[], int size) {
    printf("{");

    for(int i = 0; i < size - 1; i++){
        printf("%f, ", arr[i]);
    }
    printf("%f", arr[size - 1]);

    printf("}\n");
}


void WriteText(char const* filename, float arr[], int length){
    FILE* file = fopen(filename, "w");
    for(int i = 0; i < length - 1; i++){
        fprintf(file, "%.1f ", arr[i]);
    }
    fprintf(file, "%.1lf ", arr[length - 1]);

    fclose(file);
}


void WriteBinary(char const* filename, float arr[], int length){
    FILE* file = fopen(filename, "wb");
    fwrite(arr, sizeof(float), length, file);

    fclose(file);
}


float* ReadText(char const* filename, int* length){
    *length = 1;
    float* arr = (float*)malloc(sizeof(float));

    FILE* file = fopen(filename, "r");

    float value;
    while(fscanf(file, "%f", &value) > 0){
        arr = (float*)realloc(arr, sizeof(float) * *length);
        arr[*length - 1] = value;
        *length += 1;
    }
    *length -= 1;
    fclose(file);

    return arr;
}


float* ReadBinary(char const* filename, int* length){
    FILE* file = fopen(filename, "r");

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *length = size / sizeof(float);

    float* arr = (float*)malloc(*length * sizeof(float));
    fread(arr, size, *length, file);
    fclose(file);

    *length = size / sizeof(float);

    return arr;
}



void FileDump(const char* filename){
    int const byte_per_row = 16;

    FILE* file = fopen(filename, "r");

    int sym;
    int counter = 0;
    while((sym = fgetc(file)) != EOF){
        if(counter % byte_per_row == 0){
            printf("\n%08ld: ", ftell(file) - 1);
        }
        counter++;
        printf("%02x ", sym);
    };

    fclose(file);
}


int main(void){
    int const N = 9;
    const char* arr_text = "array.txt";
    const char* arr_binary = "array.bin";

    float arr[N];

    FillFloats(arr, N, 0., 100.);

    WriteText("array.txt", arr, N);
    WriteBinary("array.bin", arr, N);

    printf("Text file data:\n");
    int readed_len;
    float* arr_t = ReadText(arr_text, &readed_len);
    PrintFloats(arr_t, readed_len);
    FileDump(arr_text);

    printf("\nBinary file data:\n");
    float* arr_b = ReadBinary(arr_binary, &readed_len);
    PrintFloats(arr_b, readed_len);
    FileDump(arr_binary);
    return 0;
}
