#include <stdio.h>

#define LENGTH 100

int IsLetter(char c){
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}


int  IsDigit(char c){
    return '0' <= c && c <= '9';
}


void ReverseWord(char str[], int start, int end){
    int k = start;
    int j = end;

    while(k < j){
        char tmp = str[k];
        str[k] = str[j];
        str[j] = tmp;
        k++;
        j--;
    }
}


void ReverseWords(char str[]){
    int word_start = 0;
    int word_end = 0;

    for(int i = 0; i < LENGTH; i++){
        if(!IsLetter(str[i]) && !IsDigit(str[i])){
            ReverseWord(str, word_start, word_end - 1);
            word_end++;
            word_start = word_end;
        } else {
            word_end++;
        }
    }

    if(IsLetter(str[LENGTH - 1]) || IsDigit(str[LENGTH - 1])){
        ReverseWord(str, word_start, LENGTH - 1);
    }
}


int main(void){
    char str[LENGTH];
    
    while(1){
        printf("Input string: ");
        fgets(str, LENGTH, stdin);
        ReverseWords(str);
        printf("Reversed words: %s", str);
        if(str[0] == '\0' || str[0] == '\n'){
            break;
        }
    }

    return 0;
}
