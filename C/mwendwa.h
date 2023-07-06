#ifndef mwendwa_h
#define mwendwa_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>


//func to append a charcater to a string because... C
void append(char* str, char c) {
    int i = 0;
    while (str[i] != '\0') {i++;}
    str[i] = c;
    str[i + 1] = '\0';
}

char analyze (char* result){
    int length = strlen(result);

    for (int i=0; i<length; i = i + 3){
        if (result[i] == result[i+1] && result[i+1] == result[i+2]){
            //printf("%c - %c - %c\n",result[i],result[i+1],result[i+2]); //for debugging
            return result[i];
        } 
    }
    return '0';
}
#endif