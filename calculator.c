#include <stdio.h>
#include "calculator.h"
#include "operations.h"
#include "utils.h"

void calculator() {
    double num1, num2, result;
    char operator;

    while (1) {
        printf("Enter an expression (e.g., 3 + 4) or 'q' to quit: ");
        if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3) {
            char quit[2];
            scanf("%s", quit);
            if (quit[0] == 'q') {
                break;
            } else {
                printf("Invalid input. Please try again.\n");
                continue;
            }
        }

        switch (operator) {
            case '+':
                result = add(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case '-':
                result = subtract(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case '*':
                result = multiply(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case '/':
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result: %.2lf\n", result);
                } else {
                    printf("Error: Division by zero.\n");
                }
                break;
            default:
                printf("Invalid operator. Please use +, -, *, or /.\n");
        }
    }
}

