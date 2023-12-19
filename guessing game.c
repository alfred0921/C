#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int lowest, highest, count, input, num;
  lowest = 1;
  highest = 100;
  count = 1;
  
  srand(time(0));
  
    for (int i = 0; i < count; i++) {
        num = (rand() % (highest - lowest + 1)) + lowest;
        printf("Guess the Number!\n");
        printf("Enter a Number: \n");
        scanf("%d", &input);
    }
        if(input == num) {
          printf("The number is %d\n", num);
          printf("You got it Right!!\n");
        } else {
          printf("The number is %d\n", num);
          printf("Better Luck Next Time\n");
        }
  
  return 0;
}