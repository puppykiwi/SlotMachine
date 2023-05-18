#ifndef mwendwa_h
#define mwendwa_h

#include <string.h>
#include <stdio.h>

//func to append a charcater to string a string because... C
void append(char* str, char c) {
    int i = 0;
    while (str[i] != '\0') {i++;}
    str[i] = c;
    str[i + 1] = '\0';
}

#endif