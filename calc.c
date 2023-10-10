#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calc.h"
int main() {  
    char expression[100]; 
    double ans = get_previous_ANS();
    printf(">> "); 
    scanf("%99[^\n]", expression);
    getchar();

    while (strcmp(expression, "EXIT") != 0) {
        ans = string_logic(expression,ans);

        printf(">> ");
        scanf("%99[^\n]", expression);
        getchar();
    }
}