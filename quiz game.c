#include <stdio.h>
#include <string.h>

typedef struct {
  char username[20];
  int points;
} stats;

void intro() {
  printf("\n");
  printf("Welcome User\n");
  printf("The Rules are Simple\n");
  printf("You must gain points through answering correctly each question\n");
  printf("Are you Ready?\n");
  printf("1.Yes\n");
  printf("2.No\n");
  printf("Enter your Choice ==>");
}

int main() {
  stats info;
  printf("Enter UserName: \n");
  scanf("%20s", info.username);
  
  char choice;
  char answer[100];
  char correct[100];
  int result,i, questions;
  info.points = 0;
  int *score = &info.points;
  questions = 10;
  int ch;
  
    do {
			intro();
			scanf("%d",&ch);
			if(ch==2) {
				printf("\n\n\nRubin Bayot");
			}
    } while(choice == 2);
    for(i = 1; i < questions + 1; i++) {
    switch(i) {
      case 1:
      printf("1. What is the capital of France?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "Paris");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      case 2:
      printf("2. Which animal is known as the King of the Jungle?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "Lion");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      case 3:
      printf("3. What is the largest planet in our solar system?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "Jupiter");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      case 4:
      printf("4. Which country is famous for the Great Wall?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "China");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      case 5:
      printf("5. What is the chemical symbol for gold?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "Au");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      case 6:
      printf("6. Which country is known for inventing pizza?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "Italy");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      case 7:
      printf("7. What is the national flower of the United States?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "Rose");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      case 8:
      printf("8. Which city is home to the Eiffel Tower?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "Paris");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      case 9:
      printf("9. Which planet is known as the Red Planet?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "Mars");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      case 10:
      printf("10. Who is the lead singer of the band U2?\n");
      scanf("%100s", answer);
      getchar();
      strcpy(correct, "Bono");
      result = strcmp(correct,answer);
      if(result == 0) {
        printf("Correct!!\n");
        (*score)++;
      } else {
        printf("Incorrect\n");
      }
      break;
      
      default:
      printf("Error....");
    }
  }
  printf("Congratulations %s\n", info.username);
  printf("You have completed the Quiz!!\n");
  printf("Your Points is %d\n",info.points);
  
  return 0;
}