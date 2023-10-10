#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double get_previous_ANS(){
    char char_store[255];
    double ans = 0;
    FILE* file;

    if ((file = fopen("ans.txt", "r")) != NULL) {
        fscanf(file, "%s", char_store);
        ans = atof(char_store);
        fclose(file);
    }
    return ans;
}

double string_logic(char* expression, double ans){
        FILE* file;
        int space_count = 0;
        char first_num[255], op, second_num[255];
        for (int i = 0; expression[i] != '\0'; i++) {
            if (expression[i] == ' ') {
                space_count++;
            }
        }
        if (sscanf(expression, "%s %c %s", first_num, &op, second_num) != 3 || space_count != 2) {
           printf("SYNTAX ERROR\n");     
        } 
        else {

        if (strcmp(first_num, "ANS") == 0 && strcmp(second_num, "ANS") == 0) {
            sprintf(first_num, "%f", ans);
            sprintf(second_num, "%f", ans);
        }
        else if (strcmp(first_num, "ANS") == 0) {
            sprintf(first_num, "%f", ans);
        }
        else if (strcmp(second_num, "ANS") == 0) {
            sprintf(second_num, "%f", ans);
        }
        if ((atof(first_num) == 0 && first_num[0] != '0') || (atof(second_num) == 0 && second_num[0] != '0')) {
            printf("SYNTAX ERROR\n");
        }
        else if (op != '+' && op != '-' && op != 'x' && op != '/' && op != '%') {
            printf("SYNTAX ERROR\n");
        }
        else if ((op == '/' || op == '%') && atof(second_num) == 0) {
            printf("MATH ERROR\n");
        }
        else {
            double num1 = atof(first_num); 
            double num2 = atof(second_num);
            double res;
            switch (op) {
            case '+':
                res = num1 + num2;
                break;
            case '-':
                res = num1 - num2;
                break;
            case 'x':
                res = num1 * num2;
                break;
            case '/':
                res = num1 / num2;
                break;
            case '%':
                res = (int)num1 % (int)num2;
                break;
            }
            
            printf("%.2f\n", res);
            ans = res;

            file = fopen("ans.txt", "w");
            fprintf(file, "%.2f", ans);
            fclose(file);
        }
        }
        return ans;
}