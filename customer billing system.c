#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100000
#define KWH 10.90
#define TAX 0.12
#define BUDGET 1000000000

struct invoices {
	char invoice_number[6];
	char invoice_date[50];
	char due_date[50];
	int quantity;
	float subtotal;
	float tax;
	float total_amount;
	char status[10];
};

struct customer {
	char *name;
	char contact_number[80];
	char *address;
	char bill_frequency[10];
	int customer_id;
	int num_mail;
	struct invoices billing_history[100];
};

struct transactions {
	char invoice_number[6];
	float amount;
	char type[20];
	char payment_date[50];
	char payment_method[20];
};

//Function to Pay Bill Payment
void bill_payment(struct customer consumer[],struct transactions payments[],int num);
//Function to Add Customer
void add_customer(struct customer consumer[],int num);
//Function to Create Invoices
void create_invoices(struct customer consumer[],int num);
//Function to View Mails
void mail_box(struct customer consumer[],int num);
//Function to View Report
void view_report(struct customer consumer[],struct transactions payment[]);
//Function to Update Customer Info
void update_info(struct customer consumer[],int num);
//Function to Delete Customer
void delete_customer(struct customer consumer[],int num);
//Function to read File
void read_file(struct customer consumer[],struct transactions payments[],int num,const char *file_name);
//Function to Write data to a File
void write_file(struct customer consumer[],struct transactions payments[],int num,const char *file_name);

int main() {
	struct customer *consumer=malloc(MAX*sizeof(struct customer));
	struct transactions *payments=malloc(MAX*sizeof(struct transactions));
	int choice,num,mailIndex,found;
	long customer_id;
	num=0;
	mailIndex=0;
	read_file(consumer,payments,num,"file.txt");
	do {
		printf("\n\n\n       === EnerGlobe Menu ===");
		printf("\n       1.Customer Services   ");
		printf("\n       2.Staff/Admin   ");
		printf("\n\n       Enter your Choice ==>");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
			do {
				// Prompt for customer ID
		    printf("\n\n\n      === Customer ID Required ===");
		    printf("\n       📌Note:Press 1 to Exit");
				printf("\n\n       ID:");
				scanf("%ld",&customer_id);
				
				if(customer_id==1) {
					printf("\n\n\n       === Exiting Services ===");
					break;
				}
		
				for(int i=0;i<MAX;i++) {
					if(customer_id==consumer[i].customer_id) {
						found=1;
						do {
							printf("\n\n\n       === Customer Services ===");
							printf("\n       1.Bill Payment");
							printf("\n       2.Mail");
							printf("\n       3.Exit");
							printf("\n\n       Enter your Choice ==>");
							scanf("%d",&choice);
							switch(choice) {
								case 1:
								bill_payment(consumer,payments,i);
								break;
								case 2:
								mail_box(consumer,i);
								break;
								case 3:
								break;
								default:
								printf("\n\n\n       ⛔Invalid Input⛔");
								break;
							}
						} while(choice!=3);
					} else {
						printf("\n\n\n     ⛔Invalid ID.Please try again.⛔");
						break;
					}
				}
			} while(found!=1);
			break;
			case 2:
			do {
				printf("\n\n\n       === Staff/Admin Menu ===");
				printf("\n       1.Manage Customer");
				printf("\n       2.Create Invoices");
				printf("\n       3.View Reports");
				printf("\n       4.Exit");
				printf("\n\n       Enter your Choice ==>");
				scanf("%d",&choice);
				switch(choice) {
					case 1:
					do {
						printf("\n\n\n       === Customer Management ===");
						printf("\n       1.Add Customer");
						printf("\n       2.Update Customer Info");
						printf("\n       3.Delete Customer");
						printf("\n       4.Exit");
						printf("\n\n       Enter your Choice ==>");
						scanf("%d",&choice);
						switch(choice) {
							case 1:
							add_customer(consumer,num);
							num++;
							break;
							case 2:
							update_info(consumer,num);
							break;
							case 3:
							delete_customer(consumer,num);
							break;
							case 4:
							
							break;
							default:
							printf("\n\n\n     ⛔Invalid Input⛔");
							break;
						}
					} while(choice!=4);
					break;
					case 2:
					create_invoices(consumer,num);
					break;
					case 3:
					view_report(consumer,payments);
					break;
					case 4:
					
					break;
					default:
					printf("\n\n\n     ⛔Invalid Input⛔");
					break;
				}
			} while(choice!=4);
		}
	} while(1);
	write_file(consumer,payments,num,"file.txt");
	free(consumer);
	free(payments);
	return 0;
}

void bill_payment(struct customer consumer[],struct transactions payments[],int num) {
	int choice, i, index, length, number; // Declare variables for user choice, loop index, array index, length, and number
	index = 0; // Initialize the index variable
	float amount, change; // Declare variables for amount and change
	char card_number[100], e_wallet_number[100]; // Declare character arrays for card and e-wallet numbers
	srand(time(NULL)); // Seed the random number generator with current time
	time_t rawtime; // Declare a variable to store time data
	struct tm *info; // Declare a pointer to a structure for time data
	time(&rawtime); // Get current time and store it in 'rawtime'
	info = localtime(&rawtime); // Convert the rawtime to local time and store it in 'info'
	if (consumer[num].num_mail > 0) {
    // Check if the number of emails for the consumer with index 'num' is greater than 0
		do {
    printf("\n\n\n       === Bill Payment ===");
    printf("\n       Invoice Number:");
    scanf("%s", payments[index].invoice_number); // Prompt user for invoice number and read input

    for (i = 0; i < consumer[num].num_mail; i++) {
        if (strcmp(payments[index].invoice_number, consumer[num].billing_history[i].invoice_number) == 0) {
            // Check if the entered invoice number matches any of the billing history invoices for the consumer with index 'num'

            do {
                printf("\n\n\n       === Payment Method ===");
                printf("\n       1.Cash");
                printf("\n       2.Credit Card");
                printf("\n       3.E Wallet");
                printf("\n       4.Cancel Payment");
                printf("\n\n       Enter your Choice ==>");
                scanf("%d", &choice); // Prompt user for payment method choice and read input
						switch(choice) {
							case 1:
							do {
								printf("\n\n\n       === Cash Payment ===");
								printf("\n       1.Partial Payment");
								printf("\n       2.Full Payment");
								printf("\n       3.Back");
								printf("\n\n       Enter your Choice ==>");
								scanf("%d",&choice);
								switch(choice) {
									case 1:
									printf("\n\n\n       === Cash Payment ===");
									printf("\n       Amount:");
									scanf("%f",&payments[index].amount);
									if(payments[index].amount<consumer[num].billing_history[i].total_amount) {
										change=consumer[num].billing_history[i].total_amount-amount;
										strcpy(consumer[num].billing_history[i].status,"Partially Paid");
										strcpy(payments[index].type,"Partial Payment");
										strcpy(payments[index].payment_date, asctime(info));
										strcpy(payments[index].payment_method,"Cash");
										printf("\n       Change:%.2f",change);
										printf("\n\n       === Thanks for Paying ===");
									} else {
										printf("\n\n\n ⛔Invalid Amount.Please try again.⛔");
									}
									index++;
									break;
									case 2:
									printf("\n\n\n       === Cash Payment ===");
									printf("\n       Amount:");
									scanf("%f",&payments[index].amount);
									if(payments[index].amount<consumer[num].billing_history[i].total_amount) {
										change=consumer[num].billing_history[i].total_amount-amount;
										strcpy(consumer[num].billing_history[i].status,"Fully Paid");
										strcpy(payments[index].type,"Full Payment");
										strcpy(payments[index].payment_date, asctime(info));
										strcpy(payments[index].payment_method,"Cash");
										printf("\n       Change:%.2f",change);
										printf("\n\n       === Thanks for Paying ===");
									} else {
										printf("\n\n\n ⛔Invalid Amount.Please try again.⛔");
									}
									index++;
									break;
									case 3:
									break;
									default:
									printf("\n\n\n     ⛔Invalid Input⛔");
									break;
								}
							} while(choice!=3);
							break;
							case 2:
							do {
								printf("\n\n\n       === Credit Card Payment ===");
								printf("\n       Card Number:");
								scanf("%99s",card_number);
								length=strlen(card_number);
								number=atoi(card_number);
								if(length!=11||number==0) {
									printf("\n\n\n       ⚠️Invalid Card Number⚠️");
								}
							} while(length!=11||number==0);
							do {
						    printf("\n\n\n       === Credit Card Payment ===");
						    printf("\n       1.Partial Payment");
						    printf("\n       2.Full Payment");
						    printf("\n       3.Cancel Payment");
						    printf("\n\n       Enter your Choice ==>");
						    scanf("%d",&choice);
						    switch(choice) {
									case 1:
									printf("\n\n\n       === Credit Card Payment ===");
									printf("\n       Amount:");
									scanf("%f",&payments[index].amount);
									if(payments[index].amount<consumer[num].billing_history[i].total_amount) {
										change=consumer[num].billing_history[i].total_amount-amount;
										strcpy(consumer[num].billing_history[i].status,"Partially Paid");
										strcpy(payments[index].type,"Partial Payment");
										strcpy(payments[index].payment_date, asctime(info));
										strcpy(payments[index].payment_method,"Credit Card");
										printf("\n       Change:%.2f",change);
										printf("\n\n       === Thanks for Paying ===");
									} else {
										printf("\n\n\n ⛔Invalid Amount.Please try again.⛔");
									}
									index++;
									break;
									case 2:
									printf("\n\n\n       === Credit Card Payment ===");
									printf("\n       Amount:");
									scanf("%f",&payments[index].amount);
									if(payments[index].amount<consumer[num].billing_history[i].total_amount) {
										change=consumer[num].billing_history[i].total_amount-amount;
										strcpy(consumer[num].billing_history[i].status,"Fully Paid");
										strcpy(payments[index].type,"Full Payment");
										strcpy(payments[index].payment_date, asctime(info));
										strcpy(payments[index].payment_method,"Credit Card");
										printf("\n       Change:%.2f",change);
										printf("\n\n       === Thanks for Paying ===");
									} else {
										printf("\n\n\n ⛔Invalid Amount.Please try again.⛔");
									}
									index++;
									break;
									case 3:
									break;
									default:
									printf("\n\n\n     ⛔Invalid Choice⛔");
						      break;
						    }
							  break;
							} while(choice!=3);
							break;
						  case 3:
						  do {
								printf("\n\n\n       === E Wallet Payment ===");
								printf("\n       Wallet Number:");
								scanf("%s",e_wallet_number);
								length=strlen(e_wallet_number);
								number=atoi(e_wallet_number);
								if(number==0||length!=11) {
									printf("\n\n\n       ⚠️Invalid Wallet Number⚠️");
								}
						  } while(number==0||length!=11);
						  do {
								printf("\n\n\n       === E Wallet Payment ===");
								printf("\n       1.Partial Payment");
								printf("\n       2.Full Payment");
								printf("\n       3. Cancel Payment");
								printf("\n\n       Enter your Choice ==>");
								scanf("%d",&choice);
								switch(choice) {
									case 1:
									printf("\n\n\n       === E Wallet Payment ===");
									printf("\n       Amount:");
									scanf("%f",&payments[index].amount);
									if(payments[index].amount<consumer[num].billing_history[i].total_amount) {
										change=consumer[num].billing_history[i].total_amount-amount;
										strcpy(consumer[num].billing_history[i].status,"Partially Paid");
										strcpy(payments[index].type,"Partial Payment");
										strcpy(payments[index].payment_date, asctime(info));
										strcpy(payments[index].payment_method,"E Wallet");
										printf("\n       Change:%.2f",change);
										printf("\n\n       === Thanks for Paying ===");
									} else {
										printf("\n\n\n ⛔Invalid Amount.Please try again.⛔");
									}
									index++;
									break;
									case 2:
									printf("\n\n\n       === E Wallet Payment ===");
									printf("\n       Amount:");
									scanf("%f",&payments[index].amount);
									if(payments[index].amount<consumer[num].billing_history[i].total_amount) {
										change=consumer[num].billing_history[i].total_amount-amount;
										strcpy(consumer[num].billing_history[i].status,"Fully Paid");
										strcpy(payments[index].type,"Full Payment");
										strcpy(payments[index].payment_date, asctime(info));
										strcpy(payments[index].payment_method,"E Wallet");
										printf("\n       Change:%.2f",change);
										printf("\n\n       === Thanks for Paying ===");
									} else {
										printf("\n\n\n ⛔Invalid Amount.Please try again.⛔");
									}
									index++;
									break;
									case 3:
									break;
									default:
									printf("\n\n\n     ⛔Invalid Choice⛔");
								  break;
								}
						  } while(choice!=3);
						  break;
						  case 4:
						  break;
						  default:
						  printf("\n\n\n     ⛔Invalid Choice⛔");
						  break;
						}
					} while(choice!=4);
				}
			}
			printf("\n\n\n       ⚠️Invalid Invoice Number⚠️");
		} while(1);
	} else {
		printf("\n\n\n       ⚠️There is no Invoice Issued⚠️");
	}
}

void add_customer(struct customer consumer[],int num) {
  int number, length, choice; // Declare variables for various inputs
  char first_name[50]; // Store first name
  char last_name[50]; // Store last name
  char street[50]; // Store street name
  char city[50]; // Store city name
  char province[50]; // Store province name

  srand(time(NULL)); // Seed the random number generator

  // Input customer's first name
  printf("\n\n\n       === Add New Customer ===");
  printf("\n       Customer's First Name:");
  scanf("%s", first_name);

  // Input customer's last name
  printf("\n       Customer's Last Name:");
  scanf("%s", last_name);

  // Allocate memory for customer's full name and format it
  consumer[num].name = (char*)malloc(sizeof(first_name) * sizeof(char));
  sprintf(consumer[num].name, "%s %s", first_name, last_name);

  // Loop until valid contact number is entered
  do {
    printf("\n\n\n=== Customer's Contact Information ===");
    printf("\nCustomer's Contact Number:");
    scanf("%79s", consumer[num].contact_number);

    number = atol(consumer[num].contact_number); // Convert contact number to a long
    length = strlen(consumer[num].contact_number);

    // Check for invalid contact number
    if (number == 0 || length != 11) {
      printf("\n\n\n       ⚠️Invalid Contact Number⚠️");
    }
  } while (number == 0 || length != 11);

  // Input customer's address components
  printf("\n\n\n       === Customer Address ===");
  printf("\n       Street:");
  scanf("%49s", street);
  printf("\n       City:");
  scanf("%49s", city);
  printf("\n       Province:");
  scanf("%49s", province);

  // Allocate memory for customer's address and format it
  consumer[num].address = (char*)malloc(100 * sizeof(char));
  sprintf(consumer[num].address, "%s St., %s City, %s", street, city, province);

  // Loop until valid billing frequency choice is entered
  do {
    printf("\n\n\n       === Billing Frequency === ");
    printf("\n       1. Monthly");
    printf("\n       2. Annually");
    printf("\n\n       Enter your Choice ==>");
    scanf("%d", &choice);

    // Set billing frequency based on choice
    switch (choice) {
      case 1:
      strcpy(consumer[num].bill_frequency, "Monthly");
      break;
      case 2:
      strcpy(consumer[num].bill_frequency, "Annually");
      break;
      default:
      printf("\n\n\n       ⚠️Invalid Choice⚠️");
      break;
    }
  } while (choice != 1 && choice != 2);

  // Generate a random customer ID
  consumer[num].customer_id = (rand() % (999999999 - 10000000 + 1) + 100000000);

  // Print success message and customer ID
  printf("\n\n\n       🎉Customer Successfully Added🎉");
  printf("\n\n\n%ld", consumer[num].customer_id);

  // Free allocated memory for name and address
  free(consumer[num].name);
  free(consumer[num].address);
}

void update_info(struct customer consumer[],int num) {
	int choice, customer_id, number, length; // Declare variables for user input and manipulation
	char first_name[50]; // Store first name
	char last_name[50]; // Store last name
	char street[50]; // Store street address
	char city[50]; // Store city
	char province[50]; // Store province

	// Prompt user for customer ID to update
	printf("\n\n\n       === Update Info ===");
	printf("\n       Customer ID:");
	scanf("%d", &customer_id);

	// Loop through the array of customers
	for (int i = 0; i < num; i++) {
		if (customer_id == consumer[i].customer_id) { // Check if customer ID matches
			do {
				// Display update options to the user
				printf("\n\n\n       === Update Info ===");
				printf("\n       1. Name");
				printf("\n       2. Contact Details");
				printf("\n       3. Address");
				printf("\n       4. Billing Frequency");
				printf("\n       5. Exit");
				printf("\n\n       Enter your Choice ==>");
				scanf("%d", &choice);

				switch (choice) {
					case 1:
						// Update customer's name
						printf("\n\n\n       === Update Name ===");
						printf("\n       First Name:");
						scanf("%s", first_name);
						printf("\n       Last Name:");
						scanf("%s", last_name);
						sprintf(consumer[i].name, "%s %s", first_name, last_name);
						printf("\n\n       Updated Name:%s", consumer[i].name);
						break;
					case 2:
						// Update contact details
						do {
							printf("\n\n\n=== Update Contact Information ===");
							printf("\nCustomer's Contact Number:");
							scanf("%79s", consumer[i].contact_number);
							number = atol(consumer[i].contact_number);
							length = strlen(consumer[i].contact_number);
							if (number == 0 || length != 11) {
								printf("\n\n\n       ⚠️Invalid Contact Number⚠️");
							}
						} while (number == 0 || length != 11);
						printf("\n\nUpdated Contact Number:%s", consumer[i].contact_number);
						break;
					case 3:
						// Update customer's address
						printf("\n\n\n       === Customer Address ===");
						printf("\n       Street:");
						scanf("%49s", street);
						printf("\n       City:");
						scanf("%49s", city);
						printf("\n       Province:");
						scanf("%49s", province);
						consumer[i].address = (char*)malloc(100 * sizeof(char));
						sprintf(consumer[i].address, "%s St., %s City, %s", street, city, province);
						printf("\n\n       Updated Address:%s", consumer[i].address);
						break;
					case 4:
						// Update billing frequency
						do {
							printf("\n\n\n       === Billing Frequency === ");
							printf("\n       1. Monthly");
							printf("\n       2. Annually");
							printf("\n\n       Enter your Choice ==>");
							scanf("%d", &choice);
							switch (choice) {
								case 1:
									strcpy(consumer[i].bill_frequency, "Monthly");
									break;
								case 2:
									strcpy(consumer[i].bill_frequency, "Annually");
									break;
								default:
									printf("\n\n\n       ⚠️Invalid Choice⚠️");
									break;
							}
						} while (choice != 1 && choice != 2);
						printf("\n\n       Updated Billing Frequency:%s", consumer[i].bill_frequency);
						break;
					case 5:
						// Exit the update loop
						break;
					default:
						printf("\n\n\n     ⛔Invalid Choice⛔");
						break;
				}
			} while (choice != 5); // Continue updating until the user chooses to exit
			free(consumer[i].address); // Free allocated memory for address
		}
	}
}

void delete_customer(struct customer consumer[],int num) {
	int customer_id;
	printf("\n\n\n       === Delete Customer ===");
	printf("\n       Customer ID:");
	scanf("%d",&customer_id);
	for(int i=0;i<num;i++) {
		if(customer_id==consumer[i].customer_id) {
			for(int j=i;j<num-1;j++)
			consumer[j] = consumer[j+1];
			printf("\n\n       === Customer Deleted ===");
			return;
		}
	}
	printf("\n\n\n      === Customer not Found");
}

void create_invoices(struct customer consumer[], int num) {
  int customer_id, invoice_number;  // Declare variables for customer ID and invoice number
  srand(time(NULL));  // Seed the random number generator with the current time
  time_t rawtime;
  struct tm *info;
  time(&rawtime);  // Get the current time
  info = localtime(&rawtime);  // Convert the current time to a local time struct
  time_t currentTime = time(NULL);
  struct tm *localTime = localtime(&currentTime);  // Get the current local time
  mktime(localTime);  // Normalize the local time
  printf("\n\n\n       === Create Invoices ===");
  printf("\n       Customer ID:");
  scanf("%d", &customer_id);  // Get customer ID from user input
  
  // Loop through the list of customers
  for (int i = 0; i < MAX; i++) {
    // Check if the entered customer ID matches any in the list
    if (customer_id == consumer[i].customer_id) {
      // Loop through billing history for the selected customer
      for (int j = 0; j < 100; j++) {
          // Check if invoice slot is available
        if (strlen(consumer[i].billing_history[j].invoice_number) == 0) {
            invoice_number = rand() % 90000 + 10000;  // Generate random invoice number
            sprintf(consumer[i].billing_history[j].invoice_number, "%d", invoice_number);
            strcpy(consumer[i].billing_history[j].invoice_date, asctime(info));  // Set invoice date
            
            // Check billing frequency and set due date accordingly
            if (strlen(consumer[i].bill_frequency) == 7) {
                localTime->tm_mon += 1;  // Add 1 month for monthly billing
            } else {
                localTime->tm_year += 1;  // Add 1 year for yearly billing
            }
            sprintf(consumer[i].billing_history[j].due_date, "%02d-%02d-%d",
                    localTime->tm_mon + 1, localTime->tm_mday, localTime->tm_year + 1900);
            
            printf("\n\n\n       === Power Consumption (kWh) ===");
            printf("\n       Quantity:");
            scanf("%d", &consumer[i].billing_history[j].quantity);  // Get power consumption quantity
            consumer[i].billing_history[j].subtotal = consumer[i].billing_history[j].quantity * KWH;
            consumer[i].billing_history[j].tax = consumer[i].billing_history[j].subtotal * TAX;
            consumer[i].billing_history[j].total_amount =
                consumer[i].billing_history[j].subtotal + consumer[i].billing_history[j].tax;
            strcpy(consumer[i].billing_history[j].status, "Unpaid");  // Set invoice status
            consumer[i].num_mail++;  // Increment mail count
            printf("\n\n\n       📣 Invoice Successfully Created 📣");
            return;  // Exit function after successful invoice creation
        }
      }
    }
  }
  printf("\n\n\n       ⛔ Customer not Found ⛔");  // Print message if customer is not found
}

void mail_box(struct customer consumer[],int num) {
	int customer_id;
	int choice,found,index,i;

  // Display mail notifications and options
	printf("\n\n\n    ===  🔔Mail Notifications🔔 ===");
	printf("\n       You have %d mails",consumer[num].num_mail);
	
	do {
		// Prompt for action choice
		printf("\n\n\n       === Mail Box ===");
		printf("\n       1.View");
		printf("\n       2.Delete Mail");
		printf("\n       3.Exit");
		printf("\n\n       Enter your Choice ==>");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
			// View mail details
			for(int i=0;i<consumer[num].num_mail;i++) {
				printf("\n\n\n       Mail no.%d",i+1);
				printf("\n\n       === Recipient ===");
				printf("\n       Name:%s",consumer[num].name);
				printf("\n       Address:%s",consumer[num].address);
				printf("\n\n       Invoice Number:%s",consumer[num].billing_history[i].invoice_number);
				printf("\n       Date Issued:%s",consumer[num].billing_history[i].invoice_date);
				printf("\n       Due Date:%s",consumer[num].billing_history[i].due_date);
				printf("\n       Quantity:%dkWh",consumer[num].billing_history[i].quantity);
				printf("\n       Subtotal:%.2f",consumer[num].billing_history[i].subtotal);
				printf("\n       Tax:%.2f",consumer[num].billing_history[i].tax);
				printf("\n       Total Amount:%.2f",consumer[num].billing_history[i].total_amount);
				printf("\n       Status:%s",consumer[num].billing_history[i].status);
	    }
			break;
			
			case 2:
			// Delete mail by shifting array elements
			printf("\n\n\n       === Delete Mail ===");
			printf("\n       Mail No:");
			scanf("%d",&index);
			for(int i=index-1;i<consumer[i].num_mail-1;i++);
			consumer[num].billing_history[i]=consumer[num].billing_history[i+1];
		  consumer[num].num_mail--;
		  printf("\n\n       Mail No:%d Successfully Deleted",index);
			break;
			
			case 3:
			break;
			
			default:
			printf("\n\n\n     ⛔Invalid Input⛔");
			break;
		}
	} while(choice!=3);
} 

void view_report(struct customer consumer[],struct transactions payments[]) {
	float sum=0;
	float tax;
	printf("\n\n\n       === Business Report ===");
	printf("\n       Annual Budget:%d",BUDGET);
  for(int i=0;i<MAX;i++) {
		sum+=payments[i].amount;
  }
  printf("\n       Revenue:%.2f",sum);
  tax=sum*TAX;
  printf("\n       Tax:%.2f",tax);
  printf("\n       Profit:%.2f",sum-tax);
}

void read_file(struct customer consumer[],struct transactions payments[],int num, const char *file_name) {
	FILE *file = fopen("file_name","r");
	if(file==NULL) {
		printf("\n\n\n       Unable to Open File");
		exit(0);
	}
	fscanf(file,"Num:%d",&num);
	for(int i=0;i<num;i++) {
		fscanf(file,"Name:%s",consumer[i].name);
		fscanf(file,"Contact:%s",consumer[i].contact_number);
		fscanf(file,"Address:%s",consumer[i].address);
		fscanf(file,"Frequency:%s",consumer[i].bill_frequency);
		fscanf(file,"ID:%d",&consumer[i].customer_id);
		fscanf(file,"Number of Mails:%d",consumer[i].num_mail);
		for(int j=i;j<consumer[i].num_mail;j++) {
			fscanf(file,"Invoice Number:%s",consumer[i].billing_history[j].invoice_number);
			fscanf(file,"Invoice Date:%s",consumer[i].billing_history[j].invoice_date);
			fscanf(file,"Due Date:%s",consumer[i].billing_history[j].due_date);
			fscanf(file,"Quanitity:%d",&consumer[i].billing_history[j].quantity);
			fscanf(file,"Subtotal:%f",&consumer[i].billing_history[j].subtotal);
			fscanf(file,"Tax:%f",&consumer[i].billing_history[j].tax);
			fscanf(file,"Total Amount:%f",&consumer[i].billing_history[j].total_amount);
			fscanf(file,"Status:%s",consumer[i].billing_history[j].status);
		}
		fscanf(file,"Invoice Number:%s",payments[i].invoice_number);
		fscanf(file,"Amount:%f",&payments[i].amount);
		fscanf(file,"Type:%s",payments[i].type);
		fscanf(file,"Payment Date:%s",payments[i].payment_date);
		fscanf(file,"Payment Method:%s",payments[i].payment_method);
	}
}

void write_file(struct customer consumer[],struct transactions payments[],int num,const char *file_name) {
	FILE *file = fopen("file_name","w");
	if(file==NULL) {
		printf("\n\n\n       Unable to Open File");
		exit(0);
	}
	fprintf(file,"Num:%d",num);
	for(int i=0;i<num;i++) {
		fprintf(file,"Name:%s",consumer[i].name);
		fprintf(file,"Contact:%s",consumer[i].contact_number);
		fprintf(file,"Address:%s",consumer[i].address);
		fprintf(file,"Frequency:%s",consumer[i].bill_frequency);
		fprintf(file,"ID:%d",consumer[i].customer_id);
		fprintf(file,"Number of Mails:%d",consumer[i].num_mail);
		for(int j=i;j<consumer[i].num_mail;j++) {
			fprintf(file,"Invoice Number:%s",consumer[i].billing_history[j].invoice_number);
			fprintf(file,"Invoice Date:%s",consumer[i].billing_history[j].invoice_date);
			fprintf(file,"Due Date:%s",consumer[i].billing_history[j].due_date);
			fprintf(file,"Quanitity:%d",&
			consumer[i].billing_history[j].quantity);
			fprintf(file,"Subtotal:%f",consumer[i].billing_history[j].subtotal);
			fprintf(file,"Tax:%f",consumer[i].billing_history[j].tax);
			fprintf(file,"Total Amount:%f",consumer[i].billing_history[j].total_amount);
			fprintf(file,"Status:%s",consumer[i].billing_history[j].status);
		}
		fprintf(file,"Invoice Number:%s",payments[i].invoice_number);
		fprintf(file,"Amount:%f",payments[i].amount);
		fprintf(file,"Type:%s",payments[i].type);
		fprintf(file,"Payment Date:%s",payments[i].payment_date);
		fprintf(file,"Payment Method:%s",payments[i].payment_method);
	}
}