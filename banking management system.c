#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct {
  long customerID;
  char name[100];
  long account_number;
  long balance;
  int PIN;
  char address[100];
  long contactNumber;
} account;

void front();
void transaction(account customer[],int repo,int res);
void addAccount(account customer[],int repo);
int loginAccount(account customer[],int repo);
void verifyAccount(account customer[],int repo);
void depositAccount(account customer[],int repo,int res);
void withdrawAccount(account customer[],int repo,int res);
void moneyTransfer(account customer[],int repo,int res);
void accountSettings(account customer[],int repo,int res);
void searchAccount(account customer[],int repo,int res);
void updateAccount(account customer[],int repo,int res);
void changeName(account customer[],int repo,int res);
void changeAddress(account customer[],int repo,int res);
void changeContact(account customer[],int repo,int res);
void changePIN(account customer[],int repo,int res);
void exportBank(account customer[],int repo,int res);
void deleteAccount(account customer[],int repo,int res);

int main() {
  int choice,res;
  int repo = 0;
  account customer[MAX];
  
  do { 
    front();
    scanf("%d",&choice);
    switch(choice) {
      case 1:
      addAccount(customer,repo);
      verifyAccount(customer,repo);
      repo++;
      break;
      case 2:
      res = loginAccount(customer,repo);
      if(res >= 0) {
          transaction(customer,repo,res);
      }
      break;
    } 
  }while(choice!=3);
  return 0;
}

void front() {
  printf("\n");
  printf("Rural Bank\n");
  printf("1. Sign Up\n");
  printf("2. Sign In\n");
}

void transaction(account customer[],int repo,int res) {
  int choice;
  do {
  printf("1. Deposit\n");
  printf("2. Withdraw\n");
  printf("3. Money Transfer\n");
  printf("4. Account Settings\n");
  printf("5. Log Out\n");
  scanf("%d",&choice);
  switch(choice) {
    case 1:
    depositAccount(customer,repo,res);
    break;
    case 2:
    withdrawAccount(customer,repo,res);
    break;
    case 3:
    moneyTransfer(customer,repo,res);
    break;
    case 4:
    accountSettings(customer,repo,res);
    break;
    case 5:
    printf("Signing Out....\n");
    return;
    break;
    default:
    printf("Invalid Input\n");
    break;
   }
  } while (choice!=5);
}

void accountSettings(account customer[],int repo,int res) {
  int choice;
  do {
    printf("1.Search Account\n");
    printf("2.Update Account Info\n");
    printf("3.Export Bank Card\n");
    printf("4.Delete Account\n");
    printf("5.Back\n");
    scanf("%d",&choice);
    switch(choice) {
      case 1:
      searchAccount(customer,repo,res);
      break;
      case 2:
      updateAccount(customer,repo,res);
      break;
      case 3:
      exportBank(customer,repo,res);
      break;
      case 4:
      deleteAccount(customer,repo,res);
        do { 
          front();
          scanf("%d",&choice);
          switch(choice) {
            case 1:
            addAccount(customer,repo);
            verifyAccount(customer,repo);
            repo++;
            break;
            case 2:
            res = loginAccount(customer,repo);
            if(res >= 0) {
          transaction(customer,repo,res);
           }
            break;
          } 
        } while(choice!=3);
      break;
      case 5:
      return;
      break;
      default:
      printf("Invalid Input\n");
      break;
    }
  } while(choice!=5);
}

void updateAccount(account customer[],int repo,int res) {
  int choice;
  do {
    printf("1. Name\n");
    printf("2. Address\n");
    printf("3. Contact Number\n");
    printf("4. PIN\n");
    printf("5. Back\n");
    scanf("%d",&choice);
    switch(choice) {
      case 1:
      changeName(customer,repo,res);
      break;
      case 2:
      changeAddress(customer,repo,res);
      break;
      case 3:
      changeContact(customer,repo,res);
      break;
      case 4:
      changePIN(customer,repo,res);
      break;
      case 5:
      return;
      break;
      default:
      printf("Invalid Input\n");
      break;
    }
  } while(choice!=5);
}

void addAccount(account customer[],int repo) {
  customer[repo] = *(account*)malloc(sizeof(account));
  char first[50];
  char second[50];
  char full[] = " ";
  long low = 100000000;
  long high = 999999999;
  int attempt = 1;
  printf("Account Creation Portal\n");
  printf("Enter your Name\n");
  printf("First Name: \n");
  scanf("%99s", first);
  getchar();
  printf("Last Name: \n");
  scanf("%99s", second);
  getchar();
  strcat(first,full);
  strcat(first,second);
  strcpy(customer[repo].name,first);
  srand(time(0));
  customer[repo].customerID=(rand()%(high-low+1)) + low;
  customer[repo].account_number = (rand()%(high*100)-(low*100)+1)+low*100;
  while(customer[repo].PIN < 1000 || customer[repo].PIN > 9999) {
  printf("Create a One Time Pin\n");
  printf("Enter 4 Digit Number: \n");
  scanf("%d",&customer[repo].PIN);
  }
}

int loginAccount(account customer[],int repo) {
  long contact;
  int otp;
  printf("Enter Contact Number: \n");
  scanf("%ld",&contact);
  printf("Enter PIN: \n");
  scanf("%d",&otp);
  for(int i = 0;i < repo;i++) {
    if(contact==customer[i].contactNumber&&otp==customer[i].PIN) {
        printf("You have successfully logged in\n");
        printf("Welcome to Rural Bank\n");
        printf("%s\n",customer[i].name);
        printf("Balance: %ld\n",customer[i].balance);
        return i;
      } 
    printf("Incorrect Input\n");
  } return -1;
}

void verifyAccount(account customer[],int repo) {
  char street[20];
  char city[20];
  char province[20];
  char mid[] = " ";
  printf("\n");
  printf("Bank Account Verification\n");
  printf("Address\n");
  printf("Street: \n");
  scanf("%19s",street);
  getchar();
  strcat(street,mid);
  strcat(street,"St.,");
  printf("City: \n");
  scanf("%19s",city);
  getchar();
  strcat(city,mid);
  strcat(city,"City,");
  printf("Province: \n");
  scanf("%19s",province);
  getchar();
  strcat(province,mid);
  strcat(province,"Province");
  strcpy(customer[repo].address,street);
  strcat(customer[repo].address,mid);
  strcat(customer[repo].address,city);
  strcat(customer[repo].address,mid);
  strcat(customer[repo].address,province);
  printf("\n");
  while(customer[repo].contactNumber<10000000000 || customer[repo].contactNumber>99999999999) {
  printf("Contact Information\n");
  printf("Contact Number(11 Digits): \n");
  scanf("%ld",&customer[repo].contactNumber);
  }
  printf("Congratulations!!\n");
  printf("You can now access your Bank Account\n");
}

void depositAccount(account customer[],int repo,int res) {
  int otp;
  long money;
  printf("Amount: \n");
  scanf("%ld",&money);
  printf("Verification Process...\n");
  printf("Enter PIN: \n");
  scanf("%d",&otp);
  if(otp==customer[res].PIN) {
      customer[res].balance+=money;
      printf("Successfully Deposited %ld\n",money);
      printf("Balance:%ld\n",customer[res].balance);
  } else {
      printf("Incorrect PIN\n");
    }
}

void withdrawAccount(account customer[],int repo,int res) {
  int otp;
  long money;
  printf("Amount: \n");
  scanf("%ld",&money);
  printf("Verification Process...\n");
  printf("Enter PIN: \n");
  scanf("%d",&otp);
  if(otp==customer[res].PIN) {
      customer[res].balance-=money;
      printf("You have successfully withdraw\n");
      printf("Balance:%ld\n",customer[res].balance);
  } else {
      printf("Incorrect PIN\n");
    }
}

void moneyTransfer(account customer[],int repo,int res) {
  int otp;
  long number;
  long money;
  printf("Contact Number: \n");
  scanf("%ld",&number);
  for(int i = 0;i < MAX;i++) {
    if(number==customer[i].contactNumber) {
        printf("Amount: \n");
        scanf("%ld",&money);
        printf("Verification Process...\n");
        printf("Enter PIN: \n");
        scanf("%d",&otp);
        if(otp==customer[res].PIN&&customer[res].balance>=money) {
          customer[i].balance+=money;
          printf("Money Successfully Transfered\n");
          printf("Sender\n");
          printf("Contact Number:%ld\n",customer[res].contactNumber);
          printf("Name:%s\n",customer[i].name);
          printf("Recipient\n");
          printf("Contact Number:%ld\n",customer[i].contactNumber);
          printf("Name:%s\n",customer[i].name);
      }
    } else {
      printf("Contact Number does not Exist...\n");
    } break;
  }
}

void searchAccount(account customer[],int repo,int res) {
  long contact;
  printf("Contact Number: \n");
  scanf("%ld",&contact);
  for(int i = 0;i < repo;i++) {
    if(contact==customer[i].contactNumber) {
      printf("Result\n");
      printf("Name:%s\n",customer[i].name);
      printf("Address:%s\n",customer[i].address);
      printf("Contact Number:%ld\n",customer[i].contactNumber);
      break;
    } 
    printf("Incorrect Number\n");
    break;
  } 
}

void changeName(account customer[],int repo,int res) {
  char first[50];
  char second[50];
  printf("Update New Name\n");
  printf("First Name: \n");
  scanf("%49s",first);
  printf("Last Name: \n");
  scanf("%49s",second);
  strcat(first," ");
  strcat(first,second);
  strcpy(customer[res].name,"");
  strcpy(customer[res].name,first);
  printf("Updated Name:%s\n",customer[res].name);
}

void changeAddress(account customer[],int repo,int res) {
  strcpy(customer[res].address,"");
  char street[20];
  char city[20];
  char province[20];
  char mid[] = " ";
  printf("\n");
  printf("Update New Address\n");
  printf("Street: \n");
  scanf("%19s",street);
  getchar();
  strcat(street,mid);
  strcat(street,"St.,");
  printf("City: \n");
  scanf("%19s",city);
  getchar();
  strcat(city,mid);
  strcat(city,"City,");
  printf("Province: \n");
  scanf("%19s",province);
  getchar();
  strcat(province,mid);
  strcat(province,"Province");
  strcpy(customer[res].address,street);
  strcat(customer[res].address,mid);
  strcat(customer[res].address,city);
  strcat(customer[res].address,mid);
  strcat(customer[res].address,province);
  printf("Updated Address:%s\n",customer[res].address);
}

void changeContact(account customer[],int repo,int res) {
  printf("Update Contact Information\n");
  printf("New Contact Number: \n");
  scanf("%ld",&customer[res].contactNumber);
  printf("Updated Contact Number:%ld\n",customer[res].contactNumber);
}

void changePIN(account customer[],int repo,int res) {
  printf("Update Pin\n");
  printf("Enter 4 Digit Number: \n");
  scanf("%d",&customer[res].PIN);
  printf("Updated PIN:%d\n",customer[res].PIN);
}

void exportBank(account customer[],int repo,int res) {
  printf("Rural Bank Card\n");
  printf("Card Holder:%s\n",customer[res].name);
  printf("Address:%s\n",customer[res].address);
  printf("Account Number:%ld\n",customer[res].account_number);
  printf("Customer ID:%ld\n",customer[res].customerID);
}

void deleteAccount(account customer[],int repo,int res) {
  for(int i = res;i < repo-1;i++) {
    customer[i]=customer[i+1];
  } 
  printf("Account Successfully Deleted\n");
  repo--;
  printf("Returning to Main Page...\n");
}