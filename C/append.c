#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwendwa.h"

int main() {
    char str[20] = "Hello";

    printf("Before appending: %s\n", str);

    append(str, '!');
    
    printf("After appending: %s\n", str);

    return 0;
}
