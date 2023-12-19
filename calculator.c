#include <stdio.h>

int main() {
  char operator;
  int num1;
  int num2;
  int result;

  printf("Choose an operator (+,-,*,/)");
  scanf("%c", &operator);

  printf("Enter num1: \n");
  scanf("%d", &num1);

  printf("Enter num2: \n");
  scanf("%d", &num2);

  switch(operator) {
    case '+':
    result = num1 + num2;
    printf("%d", result);
    break;

    case '-':
    result = num1 - num2;
    printf("%d", result);
    break;

    case '*':
    result = num1 * num2;
    printf ("%d", result);
    break;

    case '/':
    result = num1 / num2;
    printf ("%d", result);
    break;

    default:
    printf("%c is invalid \n", operator);

  }

  return 0;
}