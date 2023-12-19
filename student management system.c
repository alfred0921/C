//Cyberdale University
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define PIN 3711

typedef struct {
	float *firstSem;
	float *secondSem;
} studentGrade;

typedef struct {
	char mother[100];
	char father[100];
} studentContact;

typedef struct {
	char course[100];
	int numSubjects;
	char **subjects;
} studentCourse;

typedef struct {
	char date[80];
	char *status;
} studentListing;

typedef struct {
	int num;
	char name[5][50];
	char author[5][30];
	char datePublished[5][50];
	char ID[5][10];
	char date[5][15];
} sBooksBorrowed;

typedef struct {
	char **ID;
	char **date;
} sBooksReturned;

typedef struct {
  char name[100];
  long *studentID;
  int age;
  studentContact contactNumber;
  studentGrade grades;
  studentCourse degree;
  studentListing enrollment;
  sBooksBorrowed booksBorrowed;
  sBooksReturned booksReturned;
} studentInfo;

//Menu for Log In
void menuFront(studentInfo student[],int num);
//Menu for Admins
void menuAdmin();
//Menu for Students
void menuStudent();
//Menu for course selection
void course();
//Books Available
void themes();
//Function for student Log In
void log_in_as_student(studentInfo student[],int num);
//Function to get grades for each subjecy in firs&second sem
void subjectGrades(studentInfo student[],char **subjects,int num);
//Function to View Grades of a Student
void viewGrades(studentInfo student[],int num);
//Function to display student details after enrollment
void studentDetails(studentInfo student[],int num);
//Function to browse Library
void browseLibrary(studentInfo student[],int num);
//Library Book List
void libraryList(studentInfo student[],int num,char *name,char *author,char *ID, char *datePublished);
//Function to borrow a book
void borrowBook(studentInfo student[],int num);
//Function to Return a Book
void returnBook(studentInfo student[],int num);
//Function to print data to a file
void writeFile(studentInfo student[],int num,const char*fileName);
//Function to update student info
void updateInfo(studentInfo student[],int num);
//Function to update grades
void updateGrades(studentInfo student[],int num);
//Function to display student info
void displayInfo(studentInfo student[],int num);
//Function to search student info
void searchInfo(studentInfo student[],int num);
//Function to delete student index
int deleteInfo(studentInfo student[],int num);
//Function to add student
void addStudent(studentInfo student[],int num);
//Function to select course
void selectCourse(studentInfo student[],int num);
//Function to retrieve data from a file
void readFile(studentInfo student[],int num,const char *filename);

int main() {
  studentInfo student[MAX];
  int choice,num;
  num = 0;
  readFile(student,num,"file.txt");
  menuFront(student,num);
  free(student[num].enrollment.status);
  writeFile(student,num,"file.txt");
  return 0;
}

void menuFront(studentInfo student[],int num) {
	int choice;
	int pass;
	do {
		printf("\nCyberdale University ©\n");
		printf("\nLog In as\n");
		printf("1.Student\n");
		printf("2.Admin\n");
		printf("\n\nEnter your Choice ==>");
		scanf("%d",&choice);
		switch(choice) {
      case 1:
      log_in_as_student(student,num);
      break;
      case 2:
      printf("\n\n\n•••Welcome to Admin Rights•••");
		  do {
			printf("\n\n\nPIN:");
		  scanf("%d",&pass);
		  if(pass==PIN) {
			  do {
	        menuAdmin();
	        scanf("%d",&choice);
	        switch(choice) {
					  case 1:
					  addStudent(student,num);
	          selectCourse(student,num);
	          printf("Student Successfully Added\n");
	          studentDetails(student,num);
	          num++;
	          break;
	          case 2:
	          displayInfo(student,num);
	          break;
	          case 3:
	          searchInfo(student,num);
	          break;
	          case 4:
	          updateInfo(student,num);
	          break;
	          case 5:
	          num=deleteInfo(student,num);
	          break;
	          case 6:
	          printf("Exiting Program...\n");
	          menuFront(student,num);
	          break;
	          default:
	          printf("Invalid Input\n");
	          break;
	        }
        } while(choice!=6);
		  } else {
			  printf("\n\n\nInvalid PIN");
		  }
			} while(pass!=PIN);
      break;
      default:
      printf("Invalid Input\n");
      break;
    } 
	} while(choice!=2);
}

void menuStudent() {
	printf("\n");
	printf("\nCyberdale University ©\n");
	printf("\n•|Welcome to Student Portal|•\n");
	printf("1.View Grades\n");
	printf("2.Go to Library\n");
	printf("3.Exit\n");
	printf("\n\nEnter your Choice ==>");
}

void menuAdmin() {
  //Menu for Program Operation
  printf("\n");
  printf("Cyberdale University ©\n");
  printf("\n|Welcome to Admin Rights|\n");
  printf("1.Add Student\n");
  printf("2.Display Student Details\n");
  printf("3.Search Student\n");
  printf("4.Update Studen Details\n");
  printf("5.Delete Student Record\n");
  printf("6.Exit\n");
  printf("\n\nEnter your Choice ==>");
}

void themes() {
	printf("\n•|Select Themes|•\n");
	printf("1.Programming and Software Development\n");
	printf("2.Data Science and Analytics\n");
	printf("3.Cybersecurity and Networking\n");
	printf("4.Artificial Intelligence and Robotics\n");
	printf("5.Web and Mobile Development\n");
	printf("6.Game Development and Design\n");
	printf("7.Software Engineering and Project Management\n");
	printf("8.Database Management and Information Systems\n");
	printf("9.Other Technology Topics\n");
	printf("10.Go Back\n");
	printf("\n\nEnter your Choice ==>");
}

void course() {
  //Student's Course Degree
  printf("\n");
  printf("•|Student's Degree|•\n");
  printf("1.Bachelor of Science in Computer Science (BSCS)\n");
  printf("2.Bachelor of Computer Engineering (BCompE)\n");
  printf("3.Bachelor of Information Technology (BIT)\n");
  printf("4.Bachelor of Software Engineering (BSE)\n");
  printf("5.Bachelor of Science in Data Science (BSDS)\n");
  printf("6.Bachelor of Science in Web Development (BSWD)\n");
  printf("7.Bachelor of Mobile App Development (BMAD)\n");
  printf("8.Bachelor of Science in Cybersecurity (BSCy)\n");
  printf("9.Bachelor of Game Development (BGD)\n");
  printf("10.Bachelor of Science in Software Systems (BSSS)\n");
  printf("11.Bachelor of Science in Computer Graphics (BSCG)\n");
  printf("12.Bachelor of Science in Computer Information Systems (BSCIS)\n");
  printf("13.Bachelor of Science in Mobile and Web Development (BSMWD)\n");
  printf("14.Bachelor of Science in Computational Science (BSCS)\n");
  printf("15.Bachelor of Science in Computer Engineering Technology (BSCET)\n");
  printf("16.Bachelor of Science in IT Management (BSITM)\n");
  printf("17.Bachelor of Science in Game Design and Development (BSGDD)\n");
  printf("18.Bachelor of Computer Applications (BCA)\n");
  printf("19.Bachelor of Science in Computer and Information Science (BSCIS)\n");
  printf("20.Bachelor of Science in Computer Networking (BSCN)\n");
}

void subjectGrades(studentInfo student[],char **subjects,int num) {
	student[num].degree.subjects=(char**)malloc(student[num].degree.numSubjects*sizeof(char*));
	for(int i=0;i<student[num].degree.numSubjects;i++) {
		student[num].degree.subjects[i]=(char*)malloc(100*sizeof(char));
		strcpy(student[num].degree.subjects[i],subjects[i]);
	}
	student[num].grades.firstSem=(float*)malloc(student[num].degree.numSubjects*sizeof(float));
	student[num].grades.secondSem=(float*)malloc(student[num].degree.numSubjects*sizeof(float));
	printf("\n");
	printf("•|First Semester Grades|•\n");
	for(int i = 0;i<student[num].degree.numSubjects;i++) {
		do {
			printf("%s:",student[num].degree.subjects[i]);
			scanf("%f",&student[num].grades.firstSem[i]);
			if(student[num].grades.firstSem[i]<1.0||student[num].grades.firstSem[i]>4.0) {
				printf("Invalid Grade\n");
			}
		} while(student[num].grades.firstSem[i]<1.0||student[num].grades.firstSem[i]>4.0);
	}
	float sum = 0.0;
	float average;
	for(int i = 0;i<student[num].degree.numSubjects;i++) {
		sum+=student[num].grades.firstSem[i];
	}
	average=sum/student[num].degree.numSubjects;
	printf("GPA:%.2f\n",average);
	printf("\n");
	printf("•|Second Semester Grades•|\n");
	for(int i=0;i<student[num].degree.numSubjects;i++) {
		do {
			printf("%s:",student[num].degree.subjects[i]);
			scanf("%f",&student[num].grades.secondSem[i]);
			if(student[num].grades.secondSem[i]<1.0||student[num].grades.secondSem[i]>4.0) {
				printf("Invalid Grade\n");
			}
		} while(student[num].grades.secondSem[i]<1.0||student[num].grades.secondSem[i]>4.0);
	}
	sum=0.0;
	for(int i=0;i<student[num].degree.numSubjects;i++) {
		sum+=student[num].grades.secondSem[i];
	}
	average=sum/student[num].degree.numSubjects;
	printf("GPA:%.2f\n",average);
	for(int i=0;i<student[num].degree.numSubjects;i++) {
		free(student[num].degree.subjects[i]);
	}
	free(student[num].degree.subjects);
	free(student[num].grades.firstSem);
	free(student[num].grades.secondSem);
}

void log_in_as_student(studentInfo student[],int num) {
	long id;
	int choice;
	printf("Enter the ID that has given to you by your Professor\n");
	printf("ID:");
	scanf("%ld",&id);
	printf("%ld\n",id);
	for(int i=0;i<MAX;i++) {
		printf("%ld\n",student[i].studentID);
		if(id==student[i].studentID) {
			printf("You have Successfully Logged In\n");
			do {
				menuStudent();
				scanf("%d",&choice);
				switch(choice) {
					case 1:
					viewGrades(student,i);
					break;
					case 2:
					browseLibrary(student,i);
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(choice!=2);
		} else {
			printf("Invalid ID...\n");
			break;
		}
	}
}

void viewGrades(studentInfo student[],int num) {
	float sum=0.0;
	float average;
	printf("•|First Semester Grades|•\n");
	for(int i=0;i<5;i++) {
		printf("%s:%.2f\n",student[num].degree.subjects[i],student[num].grades.firstSem[i]);
		sum+=student[num].grades.firstSem[i];
	}
	average=sum/student[num].degree.numSubjects;
	printf("Average:%.2f\n",average);
	sum=0.0;
	printf("Second Semester Grades\n");
	for(int i=0;i<5;i++) {
		printf("%s:%.2f\n",student[num].degree.subjects[i],student[num].grades.secondSem[i]);
		sum+=student[num].grades.secondSem[i];
	}
	average=sum/student[num].degree.numSubjects;
	printf("Average:%.2f\n",average);
}

void browseLibrary(studentInfo student[],int num) {
	int choice;
	do {
		printf("\nCyberdale University ©\n");
		printf("\n•|Welcome to Cyberdale's Library|•\n");
		printf("1.Borrow a Book\n");
		printf("2.Return a Book\n");
		printf("3.Exit\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
			borrowBook(student,num);
			break;
			case 2:
			returnBook(student,num);
			break;
			case 3:
			printf("\nThanks for Visiting Cyberdale Library\n");
			break;
			default:
			printf("Invalid Input\n");
			break;
		}
	} while(choice!=3);
}

void libraryList(studentInfo student[],int num,char *name,char*author,char *ID, char *datePublished) {
  //Function to correctly place the name of the book to an empty array
  time_t rawtime;
  struct tm *info;
  time(&rawtime);
  info=localtime(&rawtime);
	switch(student[num].booksBorrowed.num) {
		case 0:
		strcpy(student[num].booksBorrowed.name[0],name);
		strcpy(student[num].booksBorrowed.author[0],author);
		strcpy(student[num].booksBorrowed.ID[0],ID);
		strcpy(student[num].booksBorrowed.datePublished[0],datePublished);
		strcpy(student[num].booksBorrowed.date[0],asctime(info));
		student[num].booksBorrowed.num++;
		printf("\nYou have Borrowed the Book\n");
		printf("%s\n",student[num].booksBorrowed.name[0]);
		break;
		case 1:
		strcpy(student[num].booksBorrowed.name[1],name);
		strcpy(student[num].booksBorrowed.author[1],author);
		strcpy(student[num].booksBorrowed.ID[1],ID);
		strcpy(student[num].booksBorrowed.datePublished[1],datePublished);
		strcpy(student[num].booksBorrowed.date[1],asctime(info));
		student[num].booksBorrowed.num++;
		printf("\nYou have Borrowed the Book\n");
		printf("%s\n",student[num].booksBorrowed.name[1]);
		break;
		case 2:
		strcpy(student[num].booksBorrowed.name[2],name);
		strcpy(student[num].booksBorrowed.author[2],author);
		strcpy(student[num].booksBorrowed.ID[2],ID);
		strcpy(student[num].booksBorrowed.datePublished[2],datePublished);
		strcpy(student[num].booksBorrowed.date[2],asctime(info));
		student[num].booksBorrowed.num++;
		printf("\nYou have Borrowed the Book\n");
		printf("%s\n",student[num].booksBorrowed.name[2]);
		break;
		case 3:
		strcpy(student[num].booksBorrowed.name[3],name);
		strcpy(student[num].booksBorrowed.author[3],author);
		strcpy(student[num].booksBorrowed.ID[3],ID);
		strcpy(student[num].booksBorrowed.datePublished[3],datePublished);
		strcpy(student[num].booksBorrowed.date[3],asctime(info));
		student[num].booksBorrowed.num++;
		printf("\nYou have Borrowed the Book\n");
		printf("%s\n",student[num].booksBorrowed.name[3]);
		break;
		case 4:
		strcpy(student[num].booksBorrowed.name[4],name);
		strcpy(student[num].booksBorrowed.author[4],author);
		strcpy(student[num].booksBorrowed.ID[4],ID);
		strcpy(student[num].booksBorrowed.datePublished[4],datePublished);
		strcpy(student[num].booksBorrowed.date[4],asctime(info));
		student[num].booksBorrowed.num++;
		printf("\nYou have Borrowed the Book\n");
		printf("%s\n",student[num].booksBorrowed.name[4]);
		break;
		default:
		printf("You have reached the limit in Borrowing Books (5)\n");
		break;
	}
}

void borrowBook(studentInfo student[],int num) {
	int choice,ch,cb;
	char *name=NULL;
	name=(char*)malloc(50*sizeof(char));
	char *author=NULL;
	author=(char*)malloc(50*sizeof(char));
	char *ID=NULL;
	ID=(char*)malloc(50*sizeof(char));
	char *datePublished=NULL;
	datePublished=(char*)malloc(50*sizeof(char));
	do {
		themes();
		scanf("%d",&choice);
		switch(choice) {
			case 1:
			do {
				printf("\nSelect a Book to Borrow\n");
				printf("1.Introduction to Programming with Python\n");
				printf("2.Data Structures and Algorithms: Concepts and Applications\n");
				printf("3.Web Development: HTML, CSS, and JavaScript\n");
				printf("4.Go Back\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&ch);
				switch(ch) {
					case 1:
					do {
						printf("\nBook Details\n");
						printf("•Title:Introduction to Programming with Python\n");
						printf("•Author:John Smith\n");
					  printf("•ID:PY001\n");
					  printf("•Date Published:January 1,2022");
					  printf("\n\nBorrow this Book?");
					  printf("\n1.Yes\n");
					  printf("2.Nah, I changed my mind\n");
					  printf("\n\nEnter your Choice ==>");
					  scanf("%d",&cb);
					  switch(cb) {
							case 1:
						  strcpy(name,"Introduction to Programming with Python");
						  strcpy(author,"John Smith");
						  strcpy(datePublished,"January 1, 2022");
						  strcpy(ID,"PY001");
						  libraryList(student,num,name,author,ID,datePublished);
						  break;
						  case 2:
						  printf("You can Come Back Anytime\n");
						  break;
						  default:
						  printf("Invalid Input\n");
						  break;
					  }
					} while(cb!=1&&cb!=2);
					break;
					case 2:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Data Structures and Algorithms: Concepts and Applications\n");
						printf("•Author:Jane Doe\n");
						printf("•ID:DS002\n");
						printf("•Date Published:March 15, 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Data Structures and Algorithms: Concepts and Applications");
							strcpy(author,"Jane Doe");
							strcpy(datePublished,"March 15, 2021");
							strcpy(ID,"DS002");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 3:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Web Development: HTML, CSS, and JavaScript\n");
						printf("•Author:David Johnson\n");
						printf("•ID:WD003\n");
						printf("•Date Published:June 10, 2020");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Web Development: HTML, CSS, and JavaScript");
							strcpy(author,"David Johnson");
							strcpy(datePublished,"June 10, 2020");
							strcpy(ID,"WD003");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 4:
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(ch!=4);
			break;
			case 2:
			do {
				printf("\nSelect a Book to Borrow\n");
				printf("1.Data Science for Beginners\n");
				printf("2.Machine Learning Fundamentals\n");
				printf("3.Big Data Analytics: Techniques and Tools\n");
				printf("4.Go Back\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&ch);
				switch(ch) {
					case 1:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Data Science for Beginners\n");
						printf("•Author:Emily Brown\n");
						printf("•ID:DS004\n");
						printf("•Date Published:August 1, 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Data Science for Beginners");
							strcpy(author,"Emily Brown");
							strcpy(datePublished,"August 1, 2021");
							strcpy(ID,"DS004");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					case 2:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Machine Learning Fundamentals\n");
						printf("•Author:Michael Lee\n");
						printf("•ID:ML005\n");
						printf("•Date Published:October 5, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Machine Learning Fundamentals");
							strcpy(author,"Michael Lee");
							strcpy(ID,"ML005");
							strcpy(datePublished,"October 5, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 3:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Big Data Analytics: Techniques and Tools\n");
						printf("•Author:Sarah Clark\n");
						printf("•ID:BD006\n");
						printf("•Date Published:March 16, 2021\n");
						printf("\n\nBorrow this book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Big Data Analytics: Techniques and Tools");
							strcpy(author,"Sarah Clark");
							strcpy(ID,"BD006");
							strcpy(datePublished,"March 16, 2021");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 4:
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(ch!=4);
			break;
			case 3:
			do {
				printf("\nSelect a Book to Borrow\n");
				printf("1.Network Security Essentials\n");
				printf("2.Ethical Hacking: A Comprehensive Guide\n");
				printf("3.Cybersecurity Fundamentals\n");
				printf("4.Go Back\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&ch);
				switch(ch) {
					case 1:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Network Security Essentials\n");
						printf("•Author:Robert Williams\n");
						printf("•ID:NS007\n");
						printf("•Date Published:May 7, 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Network Security Essentials");
							strcpy(author,"Robert Williams");
							strcpy(ID,"NS007");
							strcpy(datePublished,"May 7, 2021");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 2:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Ethical Hacking: A Comprehensive Guide\n");
						printf("•Author:Alex Davis\n");
						printf("•ID:EH008\n");
						printf("•Date Published:April 27, 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Ethical Hacking: A Comprehensive Guide");
							strcpy(author,"Alex Davis");
							strcpy(ID,"EH008");
							strcpy(datePublished,"April 27, 2021");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 3:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Cybersecurity Fundamentals\n");
						printf("•Author:Jennifer Anderson\n");
						printf("•ID:CF009\n");
						printf("•Date Published:July 4, 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Cybersecurity Fundamentals");
							strcpy(author,"Jennifer Anderson");
							strcpy(ID,"CF009");
							strcpy(datePublished,"July 4, 2021");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 4:
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(ch!=4);
			break;
			case 4:
			do {
				printf("\nSelect a Book to Borrow\n");
				printf("1.Artificial Intelligence: Concepts and Applications\n");
				printf("2.Robotics Engineering: Principles and Practice\n");
				printf("3.Machine Learning and Robotics Integration\n");
				printf("4.Go Back\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&ch);
				switch(ch) {
					case 1:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Artificial Intelligence: Concepts and Applications\n");
						printf("•Author:Brian Miller\n");
						printf("•ID:AI010\n");
						printf("•Date Published:November 30, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Artificial Intelligence: Concepts and Applications");
							strcpy(author,"Brian Miller");
							strcpy(ID,"AI010");
							strcpy(datePublished,"November 30, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 2:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Robotics Engineering: Principles and Practice\n");
						printf("•Author:Kevin Wilson\n");
						printf("•ID:RE011\n");
						printf("•Date Published:December 12 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Robotics Engineering: Principles and Practice");
							strcpy(author,"Kevin Wilson");
							strcpy(ID,"RE011");
							strcpy(datePublished,"December 12, 2021");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 3:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Machine Learning and Robotics Integration\n");
						printf("•Author:Laura Smith\n");
						printf("•ID:ML012\n");
						printf("•Date Published:September 13, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Machine Learning and Robotics Integration");
							strcpy(author,"Laura Smith");
							strcpy(ID,"ML012");
							strcpy(datePublished,"September 13, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 4:
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(ch!=4);
			break;
			case 5:
			do {
				printf("\nSelect a Book to Borrow\n");
				printf("1.Responsive Web Design: Principles and Best Practices\n");
				printf("2.Mobile App Development with Flutter\n");
				printf("3.Full-Stack Web Development: Front-end and Back-end Techniques\n");
				printf("4.Go Back\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&ch);
				switch(ch) {
					case 1:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Responsive Web Design: Principles and Best Practices\n");
						printf("•Author:Jennifer White\n");
						printf("•ID:RW013");
						printf("•Date Published:June 5, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah, I changed my mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Responsive Web Design: Principles and Best Practices");
							strcpy(author,"Jennifer White");
							strcpy(ID,"RW013");
							strcpy(datePublished,"June 5, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 2:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Mobile App Development with Flutter\n");
						printf("•Author:Daniel Brown\n");
						printf("•ID:MA014\n");
						printf("•Date Published:January 16, 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Mobile App Development with Flutter");
							strcpy(author,"Daniel Brown");
							strcpy(ID,"MA014");
							strcpy(datePublished,"January 16, 2021");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 3:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Full-Stack Web Development: Front-end and Back-end Techniques\n");
						printf("•Author:Emma Johnson\n");
						printf("•ID:FS015\n");
						printf("•Date Published:October 24, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Full-Stack Web Development: Front-end and Back-end Techniques");
							strcpy(author,"Emma Johnson");
							strcpy(ID,"FS015");
							strcpy(datePublished,"October 24, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 4:
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(ch!=4);
			break;
			case 6:
			do {
				printf("\nSelect a Book to Borrow\n");
				printf("1.Game Design Fundamentals\n");
				printf("2.Unity Game Development: From Concept to Release\n");
				printf("3.Character Design for Video Games\n");
				printf("4.Go Back\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&ch);
				switch(ch) {
					case 1:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Game Design Fundamentals\n");
						printf("•Author:William Taylor\n");
						printf("•ID:GD016\n");
						printf("•Date Published:July 7, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Game Design Fundamentals");
							strcpy(author,"William Taylor");
							strcpy(ID,"GD016");
							strcpy(datePublished,"July 7, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 2:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Unity Game Development: From Concept to Release\n");
						printf("•Author:James Adams\n");
						printf("•ID:UG017\n");
						printf("•Date Published:March 1, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Unity Game Development: From Concept to Release");
							strcpy(author,"James Adams");
							strcpy(ID,"UG017");
							strcpy(datePublished,"March 1, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 3:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Character Design for Video Games\n");
						printf("•Author:Jessica Lee\n");
						printf("•ID:CD018\n");
						printf("•Date Published:October 16, 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Character Design for Video Games");
							strcpy(author,"Jessica Lee");
							strcpy(ID,"CD018");
							strcpy(datePublished,"October 16, 2021");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 4:
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(ch!=4);
			break;
			case 7:
			do {
				printf("\nSelect a Book to Borrow\n");
				printf("1.Software Architecture Patterns\n");
				printf("2.Agile Project Management: Scrum, Kanban, and Beyond\n");
				printf("3.Software Testing and Quality Assurance\n");
				printf("4.Go Back\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&ch);
				switch(ch) {
					case 1:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Software Architecture Patterns\n");
						printf("•Author:Richard Johnson\n");
						printf("•ID:SA019\n");
						printf("•Date Published:June 29, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Software Architecture Patterns");
							strcpy(author,"Richard Johnson");
							strcpy(ID,"SA019");
							strcpy(datePublished,"June 29, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 2:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Agile Project Management: Scrum, Kanban, and Beyond\n");
						printf("•Author:Lisa Anderson\n");
						printf("•ID:AP020\n");
						printf("•Date Published:December 2, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Agile Project Management: Scrum, Kanban, and Beyond");
							strcpy(author,"Lisa Anderson");
							strcpy(ID,"AP020");
							strcpy(datePublished,"December 2, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 3:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Software Testing and Quality Assurance\n");
						printf("•Author:Eric Martinez\n");
						printf("•ID:ST021\n");
						printf("•Date Published:January 6, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Min\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Software Testing and Quality Assurance");
							strcpy(author,"Eric Martinez");
							strcpy(ID,"ST021");
							strcpy(datePublished,"January 6, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 4:
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(ch!=4);
			break;
			case 8:
			do {
				printf("\nSelect a Book to Borrow\n");
				printf("1.Database Design and Implementation\n");
				printf("2.Business Intelligence and Data Warehousing\n");
				printf("3.Information Systems Management\n");
				printf("4.Go Back\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&ch);
				switch(ch) {
					case 1:
					do {
						printf("\n•Book Detaills•\n");
						printf("•Title:Database Design and Implementation\n");
						printf("•Author:Maria Garcia\n");
						printf("•ID:DD022\n");
						printf("•Date Published:August 6, 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Database Design and Implementation");
							strcpy(author,"Maria Garcia");
							strcpy(ID,"DD022");
							strcpy(datePublished,"August 6, 2021");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 2:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Business Intelligence and Data Warehousing\n");
						printf("•Author:Mark Davis\n");
						printf("•ID:BI023\n");
						printf("•Date Published:September 30, 2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Business Intelligence and Data Warehousing");
							strcpy(author,"Mark Davis");
							strcpy(ID,"BI023");
							strcpy(datePublished,"September 30, 2021");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 3:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Information Systems Management\n");
						printf("•Author:Laura Wilson\n");
						printf("•ID:IS024\n");
						printf("•Date Published:April 16,2021\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Information Systems Management");
							strcpy(author,"Laura Wilson");
							strcpy(ID,"IS024");
							strcpy(datePublished,"April 16, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 4:
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(ch!=4);
			break;
			case 9:
			do {
				printf("\nSelect a Book to Borrow?\n");
				printf("1.Introduction to Blockchain Technology\n");
				printf("2.3D Modeling and Animation Techniques\n");
				printf("3.Computer Graphics and Visual Effects\n");
				printf("4.Go Back\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&ch);
				switch(ch) {
					case 1:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Introduction to Blockchain Technology\n");
						printf("•Author:Christopher Thomas\n");
						printf("•ID:IB025\n");
						printf("•Date Published:July 9, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Introduction to Blockchain Technology");
							strcpy(author,"Christopher Thomas");
							strcpy(ID,"IB025");
							strcpy(datePublished,"July 9, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 2:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:3D Modeling and Animation Techniques\n");
						printf("•Author:Amanda Green\n");
						printf("•ID:MA026\n");
						printf("•Date Published:October 3, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"3D Modeling and Animation Techniques");
							strcpy(author,"Amanda Green");
							strcpy(ID,"MA026");
							strcpy(datePublished,"October 3, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
		          case 2:
		          printf("\nYou can Come Back Anytime\n");
		          break;
		          default:
		          printf("Invalid Input\n");
		          break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 3:
					do {
						printf("\n•Book Details•\n");
						printf("•Title:Computer Graphics and Visual Effects\n");
						printf("•Author:Robert Johnson\n");
						printf("•ID:CG027\n");
						printf("•Date Published:February 4, 2020\n");
						printf("\n\nBorrow this Book?");
						printf("1.Yes\n");
						printf("2.Nah,I changed my Mind\n");
						printf("\n\nEnter your Choice ==>");
						scanf("%d",&cb);
						switch(cb) {
							case 1:
							strcpy(name,"Computer Graphics and Visual Effects");
							strcpy(author,"Robert Johnson");
							strcpy(ID,"CG027");
							strcpy(datePublished,"February 4, 2020");
							libraryList(student,num,name,author,ID,datePublished);
							break;
							case 2:
							printf("\nYou can Come Back Anytime\n");
							break;
							default:
							printf("Invalid Input\n");
							break;
						}
					} while(cb!=1&&cb!=2);
					break;
					case 4:
					break;
					default:
					printf("Invalid Input\n");
					break;
				}
			} while(ch!=4);
			break;
			case 10:
			break;
			default:
			printf("Invalid Input\n");
		}
	} while(choice!=10);
	free(name);
	free(author);
	free(ID);
	free(datePublished);
}

void returnBook(studentInfo student[],int num) {
	char *ID;
	int a=0;
	ID=(char*)malloc(15*sizeof(char));
	student[num].booksReturned.ID=(char**)malloc(student[num].booksBorrowed.num*sizeof(char*));
	student[num].booksReturned.date=(char**)malloc(student[num].booksBorrowed.num*sizeof(char*));
	for(int i=0;i<student[num].booksBorrowed.num;i++) {
		student[num].booksReturned.ID[i]=(char*)malloc(15*sizeof(char));
		student[num].booksReturned.date[i]=(char*)malloc(15*sizeof(char));
	}
	do {
		printf("\n•|Please Enter the Book ID you Want to Return|•\n");
		printf("\nID:");
		scanf("%s",ID);
		for(int i=0;i<student[num].booksBorrowed.num;i++) {
			if(strcmp(ID,student[num].booksBorrowed.ID[i])==0) {
				for(int j=i;j<5-1;j++) {
					strcpy(student[num].booksBorrowed.name[j],student[num].booksBorrowed.name[j+1]);
					strcpy(student[num].booksBorrowed.author[j],student[num].booksBorrowed.author[j+1]);
					strcpy(student[num].booksBorrowed.ID[j],student[num].booksBorrowed.ID[j+1]);
					strcpy(student[num].booksBorrowed.date[j],student[num].booksBorrowed.date[j+1]);
				}
				student[num].booksBorrowed.num--;
				for(int k=0;k<student[num].booksBorrowed.num;k++) {
					if(student[num].booksReturned.ID[i]==NULL) {
						strcpy(&(student[num].booksReturned.ID[i]),ID);
						time_t rawdate;
						struct tm *date;
						time(&rawdate);
						date=localtime(&rawdate);
						strcpy(&(student[num].booksReturned.date[i]),asctime(date));
					}
				}
			}
			printf("\nThank You for Returning the Book\n");
			a++;
		}
		break;
	} while(a!=1);
	if(a!=1) {
		printf("\nID not Found\n");
	}
	free(student[num].booksReturned.ID);
	free(student[num].booksReturned.date);
}

void studentDetails(studentInfo student[],int num) {
	printf("\n");
	printf("•|Student Details•|\n");
	printf("\nStudent no:%d\n",num+1);
	printf("Name:%s\n",student[num].name);
	printf("ID:%ld\n",student[num].studentID);
	printf("\nCourse:%s\n",student[num].degree.course);
	printf("\n•|Subjects|•\n");
	for(int i=0;i<student[num].degree.numSubjects;i++) {
		printf("%s\n",student[num].degree.subjects[i]);
	}
	printf("\nStatus:%s\n",student[num].enrollment.status);
	printf("\nDate Enrolled:%s\n",student[num].enrollment.date);
	return;
}

void writeFile(studentInfo student[],int num,const char*fileName) {
  FILE*file=fopen(fileName,"w");
  if(num==0) {
	  printf("Student List is Empty...\n\n\n");
	  return;
  }
  if(file==NULL) {
    printf("Error Opening the File\n");
  } 
  for(int i=0;i<num;i++) {
	  fprintf(file,"Num:%d",num);
	  fprintf(file,"Name:%s",student[i].name);
	  fprintf(file,"Age:%d",student[i].age);
	  fprintf(file,"ID:%ld",student[i].studentID);
	  fprintf(file,"Mother's Contact Number:%s",student[i].contactNumber.mother);
	  fprintf(file,"Father's Contact Number:%s",student[i].contactNumber.father);
	  fprintf(file,"Course:%s",student[i].degree.course);
	  fprintf(file,"Number of Subjects:%d",student[i].degree.numSubjects);
	  fprintf(file,"Grades\n%s:%.2f,%.2f",student[i].degree.subjects,student[i].grades.firstSem,student[i].grades.secondSem);
	  fprintf(file,"Status:%s",student[i].enrollment.status);
	  fprintf(file,"Date Enrolled:%s",student[i].enrollment.date);
	  fprintf(file,"Number of Books Borrowed:%d",student[i].booksBorrowed.num);
	  for(int j=0;j<student[i].booksBorrowed.num;j++) {
		  fprintf(file,"Book Name:%s\nBook Author:%s\nDate Published:%s\nBook ID:%s\nDate Borrowed:%s\n",student[i].booksBorrowed.name[j],student[i].booksBorrowed.author[j],student[i].booksBorrowed.datePublished[j],student[i].booksBorrowed.ID[j],student[i].booksBorrowed.date[j]);
		  fprintf(file,"Book Returned ID:%s\nDate Returned:%s",student[i].booksReturned.ID[j],student[i].booksReturned.date[j]);
	  }
  }
  fclose(file);
}

void readFile(studentInfo student[],int num,const char *filename ) {
	FILE *file = fopen("filename", "r");
  if (file == NULL) {
	  printf("Unable to open file.\n");
	  exit(0);
  }
  fscanf(file,"Num:%d",&num);
  for (int i = 0; i < 10; i++) {
    // Read student information from the file
    
    fscanf(file, "Name:%s\n", student[i].name);
    fscanf(file, "Age:%d\n", &student[i].age);
    fscanf(file, "ID:%ld\n", &student[i].studentID);
    fscanf(file, "Mother's Contact Number:%s\n", student[i].contactNumber.mother);
    fscanf(file, "Father's Contact Number:%s\n", student[i].contactNumber.father);
    fscanf(file, "Course:%s\n", student[i].degree.course);
    fscanf(file, "Number of Subjects:%d\n", &student[i].degree.numSubjects);
    fscanf(file, "Grades\n%s:%f,%f\n", student[i].degree.subjects[0], &student[i].grades.firstSem, &student[i].grades.secondSem);
    fscanf(file, "Status:%s\n", student[i].enrollment.status);
    fscanf(file, "Date Enrolled:%s\n", student[i].enrollment.date);
    fscanf(file, "Number of Books Borrowed:%d\n", &student[i].booksBorrowed.num);
    for (int j = 0; j < student[i].booksBorrowed.num; j++) {
      fscanf(file, "Book Name:%s\nBook Author:%s\nDate Published:%s\nBook ID:%s\nDate Borrowed:%s\n",
             student[i].booksBorrowed.name[j], student[i].booksBorrowed.author[j],
             student[i].booksBorrowed.datePublished[j], student[i].booksBorrowed.ID[j],
             student[i].booksBorrowed.date[j]);
      fscanf(file, "Book Returned ID:%s\nDate Returned:%s\n", student[i].booksReturned.ID[j], student[i].booksReturned.date[j]);
    }
  }
  fclose(file);
}
  
void addStudent(studentInfo student[],int num) {
  //Allocate memory for every struct array
  student[num]=*(studentInfo*)malloc(sizeof(studentInfo));
  //Student's Name Input
  char firstName[30];
  char lastName[30];
  printf("\n•|Student's Name|•\n");
  printf("\nFirst Name:");
  scanf("%29s",firstName);
  strcat(firstName," ");
  printf("\nSecond Name:");
  scanf("%29s",lastName);
  strcat(firstName,lastName);
  strcpy(student[num].name,firstName);
  //Random Generated 9 Digit Student ID
  srand(time(0));
  student[num].studentID=(rand()%(999999999-10000000+1)+100000000);
  //Student's Age Input
  printf("\nStudent's Age:");
  scanf("%d",&student[num].age);
  printf("\n•|Parent's Contact Number|•\n");
  int length;
  long number;
  do {
		printf("Mother:");
		scanf("%100s",student[num].contactNumber.mother);
		length=strlen(student[num].contactNumber.mother);
		number=atol(student[num].contactNumber.mother);
		if(number==0||length!=11) {
			printf("Invalid Contact Number\n");
		}
  } while(number==0||length!=11);
  do {
		printf("Father:");
		scanf("%100s",student[num].contactNumber.father);
		length=strlen(student[num].contactNumber.father);
		number=atol(student[num].contactNumber.father);
		if(number==0||length!=11) {
			printf("Invalid Contact Number\n");
		}
  } while(number==0||length!=11);
  time_t rawtime;
  struct tm *info;
  time(&rawtime);
  info=localtime(&rawtime);
  strcpy(student[num].enrollment.date,asctime(info));
  student[num].enrollment.status=(char*)malloc(20*sizeof(char));
  strcpy(student[num].enrollment.status,"Enrolled");
}

void updateInfo(studentInfo student[],int num) {
	long ID;
	int choice;
	char first[50]="";
	char second[50]="";
	int length;
	long number;
	if(num==0) {
		printf("Student List is Empty...\n\n");
		return;
	}
	do {
		printf("\n\nEnter the Student ID you want to Update");
		printf("\nID:");
		scanf("%ld",&ID);
		for(int i=0;i<MAX;i++) {
			if(ID==student[i].studentID) {
				do {
					printf("\n\nSelect the Info you want to Update");
					printf("\n1.Name\n");
					printf("2.Student ID\n");
					printf("3.Age\n");
					printf("4.Contact Number\n");
					printf("5.Course\n");
					printf("6.Grades\n");
					printf("7.Exit\n");
					printf("\n\nEnter your Choice ==>");
					scanf("%d",&choice);
					switch(choice) {
						case 1:
						strcpy(student[i].name,"");
						printf("\n\nUpdate Student Name");
						printf("\nFirst Name:");
						scanf("%49s",first);
						printf("\nLast Name:");
						scanf("%49s",second);
						strcat(first," ");
						strcat(first,second);
						strcpy(student[i].name,first);
						printf("\n\nUpdated Name:%s",student[i].name);
						break;
						case 2:
						printf("\n\nThe System will Automatically Update the Student ID");
						srand(time(0));
						student[i].studentID=rand()%(999999999-10000000+1)+100000000;
						printf("\n\nUpdated Student ID:%ld",student[i].studentID);
						break;
						case 3:
						printf("\n\nEnter the Updated Age");
						printf("\nAge:");
						scanf("%d",&student[i].age);
						printf("\n\nUpdated Age:%d",student[i].age);
						break;
						case 4:
						strcpy(student[i].contactNumber.mother,"");
						strcpy(student[i].contactNumber.father,"");
						printf("\n\nEnter Updated Contact Number");
						do {
							printf("\n\nMother:");
							scanf("%100s",student[i].contactNumber.mother);
							length=strlen(student[i].contactNumber.mother);
							number=atol(student[i].contactNumber.mother);
							if(number==0||length!=11) {
								printf("Invalid Contact Number\n");
							}
						} while(number==0||length!=11);
						do {
							printf("\n\nFather:");
							scanf("%100s",student[i].contactNumber.father);
							length=strlen(student[i].contactNumber.father);
							number=atol(student[i].contactNumber.father);
							if(number==0||length!=11) {
								printf("Invalid Contact Number\n");
							}
						} while(number==0||length!=11);
						break;
						case 5:
						strcpy(student[i].degree.course,"");
						selectCourse(student,i);
						break;
						case 6:
						updateGrades(student,i);
						break;
						case 7:
						return;
						default:
						printf("Invalid Input\n");
						break;
					}
				} while(choice!=7);
			} 
		}
		if(ID!=student[num].studentID) {
			printf("Invalid ID\n");
		}
	} while(ID!=student[num].studentID);
}

void updateGrades(studentInfo student[],int num) {
	student[num].grades.firstSem=(float*)malloc(student[num].degree.numSubjects*sizeof(float));
	student[num].grades.secondSem=(float*)malloc(student[num].degree.numSubjects*sizeof(float));
	printf("\n");
	printf("•|First Semester Grades|•\n");
	for(int i = 0;i<student[num].degree.numSubjects;i++) {
		do {
			printf("%s:",student[num].degree.subjects[i]);
			scanf("%f",&student[num].grades.firstSem[i]);
			if(student[num].grades.firstSem[i]<1.0||student[num].grades.firstSem[i]>4.0) {
				printf("Invalid Grade\n");
			}
		} while(student[num].grades.firstSem[i]<1.0||student[num].grades.firstSem[i]>4.0);
	}
	float sum = 0.0;
	float average;
	for(int i = 0;i<student[num].degree.numSubjects;i++) {
		sum+=student[num].grades.firstSem[i];
	}
	average=sum/student[num].degree.numSubjects;
	printf("GPA:%.2f\n",average);
	printf("\n");
	printf("•|Second Semester Grades•|\n");
	for(int i=0;i<student[num].degree.numSubjects;i++) {
		do {
			printf("%s:",student[num].degree.subjects[i]);
			scanf("%f",&student[num].grades.secondSem[i]);
			if(student[num].grades.secondSem[i]<1.0||student[num].grades.secondSem[i]>4.0) {
				printf("Invalid Grade\n");
			}
		} while(student[num].grades.secondSem[i]<1.0||student[num].grades.secondSem[i]>4.0);
	}
	sum=0.0;
	for(int i=0;i<student[num].degree.numSubjects;i++) {
		sum+=student[num].grades.secondSem[i];
	}
	average=sum/student[num].degree.numSubjects;
	printf("GPA:%.2f\n",average);
	free(student[num].grades.firstSem);
	free(student[num].grades.secondSem);
}

void displayInfo(studentInfo student[],int num) {
	if(num==0) {
		printf("Student List is Empty...\n\n");
		return;
	}
	for(int i=0;i<num;i++) {
		printf("\n\nStudent No:%d\n\n",i+1);
		printf("Name:%s\n",student[i].name);
		printf("Age:%d\n",student[i].age);
		printf("Student ID:%ld\n",student[i].studentID);
		printf("Course:%s\n",student[i].degree.course);
		printf("\n•|Subjects|•\n");
		for(int k=0;k<student[i].degree.numSubjects;k++) {
		printf("%s\n",student[i].degree.subjects[k]);
		}
		printf("\nStatus:%s\n",student[i].enrollment.status);
	  printf("\nDate Enrolled:%s\n",student[i].enrollment.date);
	}
	return;
}

void searchInfo(studentInfo student[],int num) {
	long ID;
	if(num==0) {
		printf("Student List is Empty...\n\n");
		return;
	}
	printf("\n\nEnter Student ID:");
	scanf("%ld",&ID);
	for(int i=0;i<MAX;i++) {
		if(ID==student[i].studentID) {
			printf("\n\nStudent No:%d\n\n",i+1);
			printf("Name:%s\n",student[i].name);
			printf("Age:%d\n",student[i].age);
			printf("Student ID:%ld\n",student[i].studentID);
			printf("Course:%s\n",student[i].degree.course);
			printf("\n•|Subjects|•\n");
			for(int k=0;k<student[i].degree.numSubjects;k++) {
			printf("%s\n",student[i].degree.subjects[k]);
			}
			printf("\nStatus:%s\n",student[i].enrollment.status);
		  printf("\nDate Enrolled:%s\n",student[i].enrollment.date);
		} else {
			printf("\n\nStudent ID not Found\n");
		}
		break;
	}
	return;
}

int deleteInfo(studentInfo student[], int num) {
  long ID;
  if (num == 0) {
    printf("\n\nStudent List is Empty...");
    return num;
  }
  int i;
  do {
    printf("\n\nID:");
    scanf("%ld", &ID);
    for (i=0;i<num;i++) {
      if (student[i].studentID==ID) {
        for (int j=i;j<num-1;j++);
        student[j]=student[j+1];
        num--;
        printf("Student Successfully Deleted\n\n");
        return num;
      }
    }
    printf("\n\nStudent not Found...");
  } while (1); // Removed condition since we're exiting the loop explicitly
  return num; // Add this line to return num if the ID is not found
}

void selectCourse(studentInfo student[],int num) {
  int choice,major;
  char **subjects;
  subjects=(char**)calloc(6,sizeof(char*));
  for(int i=0;i<6;i++) {
		subjects[i]=(char*)calloc(100,sizeof(char));
  }
  student[num].degree.numSubjects=0;
  do {
    course();
    printf("\n\nEnter your Choice ==>");
    scanf("%d",&choice);
    switch(choice) {
      case 1:
      do {
        printf("\n");
        printf("•|Majors|•\n");
        printf("1.Software Engineering\n");
        printf("2.Data Science\n");
        printf("3.Artificial Intelligence\n");
        printf("4.Cybersecurity\n");
        printf("5.Web Development\n");
        printf("6.Mobile App Development\n");
        printf("7.Game Development\n");
        printf("\n\nEnter your Choice ==>");
        scanf("%d",&major);
        switch(major) {
          case 1:
          strcpy(subjects[0],"Software Development");
          strcpy(subjects[1],"Object-Oriented Programming");
          strcpy(subjects[2],"Software Design Patterns");
          strcpy(subjects[3],"Software Testing and Quality Assurance");
          strcpy(subjects[4],"Software Project Management");
          subjects[5]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Computer Science Major in Software Engineering");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 2:
          strcpy(subjects[0],"Data Analysis and Visualization");
          strcpy(subjects[1],"Machine Learning");
          strcpy(subjects[2],"Big Data Technologies");
          strcpy(subjects[3],"Data Mining");
          strcpy(subjects[4],"Data Ethics and Privacy");
          subjects[5]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Computer Science Major in Data Science");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 3:
          strcpy(subjects[0],"Machine Learning");
          strcpy(subjects[1],"Computer Vision");
          strcpy(subjects[2],"Robotics");
          strcpy(subjects[3],"AI Ethics and Governance");
          strcpy(subjects[4],"Natural Language Processing");
          subjects[5]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Computer Science Major in Artificial Intelligence");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 4:
		      strcpy(subjects[0],"Network Security");
          strcpy(subjects[1],"Information Security");
          strcpy(subjects[2],"Cryptography");
          strcpy(subjects[3],"Cyber Threat Intelligence");
		      strcpy(subjects[4],"Cyber Incident Response");
		      subjects[5]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Computer Science Major in Cybersecurity");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 5:
		      strcpy(subjects[0],"Front-end Web Development");
          strcpy(subjects[1],"Back-end Web Development");
          strcpy(subjects[2],"Web Design");
          strcpy(subjects[3],"Web Frameworks");
		      strcpy(subjects[4],"Web Security");
		      subjects[5]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Computer Science Major in Web Development");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 6:
		      strcpy(subjects[0],"Android App Development");
          strcpy(subjects[1],"iOS App Development");
          strcpy(subjects[2],"Cross-Platform App Development");
          strcpy(subjects[3],"Mobile UI/UX Design");
		      strcpy(subjects[4],"Mobile App Testing");
		      subjects[5]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Computer Science Major in Mobile App Development");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 7:
		      strcpy(subjects[0],"Game Design and Mechanics");
          strcpy(subjects[1],"Game Programming");
          strcpy(subjects[2],"Game Engine Development");
          strcpy(subjects[3],"Game Art and Animation");
		      strcpy(subjects[4],"Game Testing and Quality Assurance");
		      subjects[5]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Computer Science Major in Game Development");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          default:
          printf("Invalid Input\n");
          break;
        }
      } while(major!=7);
      break;
      case 2:
      do {
        printf("\n");
        printf("•|Majors|•\n");
        printf("1.Embedded Systems\n");
        printf("2.Robotics\n");
        printf("3.Digital Systems\n");
        printf("\n\nEnter your Choice ==>");
        scanf("%d",&major);
        switch(major) {
          case 1:
		      strcpy(subjects[0],"Microcontroller Programming");
          strcpy(subjects[1],"Embedded Hardware Design");
          strcpy(subjects[2],"Real-time Operating Systems");
          strcpy(subjects[3],"Embedded Systems Testing");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Computer Engineering Major in Embedded Systems");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 2:
		      strcpy(subjects[0],"Robot Control Systems");
          strcpy(subjects[1],"Robot Kinematics and Dynamics");
          strcpy(subjects[2],"Computer Vision for Robotics");
          strcpy(subjects[3],"Robot Ethics and Human-Robot Interaction");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Computer Engineering Major in Robotics");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 3:
		      strcpy(subjects[0],"Digital Logic Design");
          strcpy(subjects[1],"FPGA Programming");
          strcpy(subjects[2],"Digital Circuit Design");
          strcpy(subjects[3],"Digital Signal Processing");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Computer Engineering Major in Digital Systems");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          default:
          printf("Invalid Input\n");
          break;
        }
      } while(major!=3);
      break;
      case 3:
      do {
        printf("\n");
        printf("•|Majors|•\n");
        printf("1.Network Administration\n");
        printf("2.Software Development\n");
        printf("3.Information Security\n");
        printf("4.Database Management\n");
        printf("\n\nEnter your Choice ==>");
        scanf("%d",&major);
        switch(major) {
          case 1:
					strcpy(subjects[0],"Network Configuration and Management");
          strcpy(subjects[1],"Network Security");
          strcpy(subjects[2],"Routing and Switching");
          strcpy(subjects[3],"Network Troubleshooting");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Information Technology Major in Network Administration");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 2:
					strcpy(subjects[0],"Software Engineering");
          strcpy(subjects[1],"Object-Oriented Programming");
          strcpy(subjects[2],"Software Design and Development");
          strcpy(subjects[3],"Software Testing");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Information Technology Major in Software Development");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 3:
		      strcpy(subjects[0],"Cybersecurity Fundamentals");
          strcpy(subjects[1],"Information Assurance");
          strcpy(subjects[2],"Access Control and Identity Management");
          strcpy(subjects[3],"Security Policies and Governance");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Information Technology Major in Information Security");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 4:
		      strcpy(subjects[0],"Database Design and Implementation");
          strcpy(subjects[1],"SQL Programming");
          strcpy(subjects[2],"Database Administration");
          strcpy(subjects[3],"Big Data Technologies");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Information Technology Major in Database Management");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          default:
          printf("Invalid Input\n");
          break;
        }
      } while(major!=4);
      break;
      case 4:
      do {
        printf("\n");
        printf("•|Majors|•\n");
        printf("1.Software Architecture\n");
        printf("2.Software Testing\n");
        printf("3.Software Project Management\n");
        printf("\n\nEnter your Choice ==>");
        scanf("%d",&major);
        switch(major) {
          case 1:
		      strcpy(subjects[0],"Software Design Patterns");
          strcpy(subjects[1],"Software Architecture Design");
          strcpy(subjects[2],"Software Quality Assurance");
          strcpy(subjects[3],"Distributed Systems");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Software Engineering Major in Software Architecture");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 2:
					strcpy(subjects[0],"Software Testing Techniques");
          strcpy(subjects[1],"Test Automation");
          strcpy(subjects[2],"Quality Assurance Processes");
          strcpy(subjects[3],"Software Debugging");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Software Engineering Major in Software Testing");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 3:
					strcpy(subjects[0],"Project Planning and Scheduling");
          strcpy(subjects[1],"Agile and Scrum Methodology");
          strcpy(subjects[2],"Project Risk Management");
          strcpy(subjects[3],"Project Communication and Collaboration");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Major in Software Project Management");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          default:
          printf("Invalid Input\n");
          break;
        }
      } while(major!=3);
      break;
      case 5:
      do {
        printf("\n");
        printf("•|Majors•|\n");
        printf("1.Machine Learning\n");
        printf("2.Data Analytics\n");
        printf("3.Big Data\n");
        printf("\n\nEnter your Choice ==>");
        scanf("%d",&major);
        switch(major) {
          case 1:
					strcpy(subjects[0],"Supervised Learning");
          strcpy(subjects[1],"Unsupervised Learning");
          strcpy(subjects[2],"Deep Learning");
          strcpy(subjects[3],"Reinforcement Learning");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Data Science Major in Machine Learning");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 2:
					strcpy(subjects[0],"Data Cleaning and Preparation");
          strcpy(subjects[1],"Data Visualization");
          strcpy(subjects[2],"Statistical Analysis");
          strcpy(subjects[3],"Predictive Modeling");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Data Science Major in Data Analytics");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          case 3:
					strcpy(subjects[0],"Big Data Technologies");
          strcpy(subjects[1],"Data Warehousing");
          strcpy(subjects[2],"Cloud Computing");
          strcpy(subjects[3],"Predictive Modeling");
          subjects[4]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Data Science Major in Big Data");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
          subjectGrades(student,subjects,num);
          return;
          default:
          printf("Invalid Input\n");
          break;
        }
      } while(major!=3);
      break;
      case 6:
      do {
	    printf("\n");
        printf("•|Majors•|\n");
				printf("1.Front-end Development\n");
				printf("2.Back-end Development\n");
				printf("3.Full-Stack Development\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
					case 1:
					strcpy(subjects[0],"HTML/CSS");
          strcpy(subjects[1],"JavaScript");
          strcpy(subjects[2],"Front-end Frameworks");
          strcpy(subjects[3],"Responsive Web Design");
          subjects[4]=NULL;
					strcpy(student[num].degree.course,"Bachelor of Science in Web Development Major in Front-end Development");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
					subjectGrades(student,subjects,num);
					return;
					case 2:
					strcpy(subjects[0],"Server-side Programming");
          strcpy(subjects[1],"Database Integration");
          strcpy(subjects[2],"API Development");
          subjects[3]=NULL;
					strcpy(student[num].degree.course,"Bachelor of Science in Web Development Major in Back-end Development");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
					subjectGrades(student,subjects,num);
					return;
					case 3:
					strcpy(subjects[0],"Both Front-end and Back-end Technologies");
          strcpy(subjects[1],"Full-Stack Frameworks");
          strcpy(subjects[2],"Web Application Deployment");
          subjects[3]=NULL;
          strcpy(student[num].degree.course,"Bachelor of Science in Web Development Major in Full-Stack Development");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
					subjectGrades(student,subjects,num);
					return;
					default:
					printf("Invalid Input\n");
					break;
				}
      } while(major!=3);
      break;
      case 7:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Android App Development\n");
				printf("2.iOS App Development\n");
				printf("3.Cross-Platform App Development\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
					case 1:
					strcpy(subjects[0],"Java/Kotlin Programming");
					strcpy(subjects[1],"Android UI Design");
					strcpy(subjects[2],"Android App Components");
					strcpy(subjects[3],"Android App Deployment");
					subjects[4]=NULL;
					strcpy(student[num].degree.course,"Bachelor of Mobile App Development Major in Android App Development");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
		          student[num].degree.numSubjects++;
	          }
					subjectGrades(student,subjects,num);
					return;
					case 2:
					strcpy(subjects[0],"Swift Programming");
	        strcpy(subjects[1],"iOS UI/UX Design");
	        strcpy(subjects[2],"iOS App Components");
	        strcpy(subjects[3],"App Store Submission");
	        subjects[4]=NULL;
					strcpy(student[num].degree.course,"Bachelor of Mobile App Development");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
		          student[num].degree.numSubjects++;
	          }
					subjectGrades(student,subjects,num);
					return;
					case 3:
				  strcpy(subjects[0],"Frameworks");
          strcpy(subjects[1],"Code Reusability");
          strcpy(subjects[2],"iOS App Components");
          strcpy(subjects[3],"Platform-Specific Features");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Mobile App Development Major in Cross-Platform App Development");
				  while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
			    return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=3);
      break;
      case 8:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Network Security\n");
				printf("2.Information Security\n");
				printf("3.Ethical Hacking\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"Network Attacks and Defenses");
	        strcpy(subjects[1],"Firewalls and Intrusion Detection Systems");
	        strcpy(subjects[2],"Network Security Monitoring");
	        strcpy(subjects[3],"Secure Network Protocols");
	        subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Cybersecurity Major in Network Security");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
		          student[num].degree.numSubjects++;
	          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Cyber Threats and Vulnerabilities");
		      strcpy(subjects[1],"Security Policies and Procedures");
		      strcpy(subjects[2],"Incident Response and Management");
		      strcpy(subjects[3],"Risk Assessment and Mitigation");
		      subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Cybersecurity Major in Information Security");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 3:
				  strcpy(subjects[0],"Penetration Testing");
		      strcpy(subjects[1],"Vulnerability Assessment");
		      strcpy(subjects[2],"Web Application Security");
		      strcpy(subjects[3],"Wireless Network Security");
		      subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Cybersecurity Major in Ethical Hacking");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=3);
      break;
      case 9:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Game Design\n");
				printf("2.Game Programming\n");
				printf("3.Game Art and Animation\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"Game Mechanics and Gameplay");
          strcpy(subjects[1],"Game Conceptualization");
          strcpy(subjects[2],"Game Storytelling");
          strcpy(subjects[3],"Game User Experience");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Game Development Major in Game Design");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Game Engine Development");
		      strcpy(subjects[1],"Game AI Programming");
		      strcpy(subjects[2],"Game Physics");
		      strcpy(subjects[3],"Multiplayer Game Development");
		      subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Game Development Major in Game Programming");
				  while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 3:
				  strcpy(subjects[0],"3D Modeling and Animation");
		      strcpy(subjects[1],"Character Design");
		      strcpy(subjects[2],"Environment Design");
		      strcpy(subjects[3],"Game Asset Creation");
		      subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Game Development Major in Game Art and Animation");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=3);
      break;
      case 10:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.System Analysis and Design\n");
				printf("2.Software Quality Assurance\n");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"System Requirements Analysis");
          strcpy(subjects[1],"System Modeling and Design");
          strcpy(subjects[2],"Software Development Life Cycle");
          strcpy(subjects[3],"User Interface Design");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Software Systems Major in System Analysis and Design");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Software Testing and Verification");
          strcpy(subjects[1],"Quality Metrics and Management");
          strcpy(subjects[2],"Test Planning and Execution");
          strcpy(subjects[3],"Continuous Integration and Deployment");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Software Systems Major in Software Quality Assurance");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      case 11:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.3D Modeling and Animation\n");
				printf("2.Visual Effects\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"3D Modeling Techniques");
          strcpy(subjects[1],"Character Rigging and Animation");
          strcpy(subjects[2],"Visual Effects and Simulation");
          strcpy(subjects[3],"Rendering and Shading");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer Graphics Major in 3D Modeling and Animation");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"VFX Compositing");
          strcpy(subjects[1],"Digital Matte Painting");
          strcpy(subjects[2],"Motion Tracking and Rotoscoping");
          strcpy(subjects[3],"Visual Effects Production Pipeline");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer Graphics Major in Visual Effects");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      case 12:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Database Management\n");
				printf("2.Business Intelligence\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"Relational Database Design");
          strcpy(subjects[1],"Advanced SQL Programming");
          strcpy(subjects[2],"Data Warehousing and Data Mining");
          strcpy(subjects[3],"Database Administration");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer Information Systems Major in Database Management");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Data Analytics for Business");
          strcpy(subjects[1],"Data Visualization for Decision Making");
          strcpy(subjects[2],"Business Reporting and Dashboards");
          strcpy(subjects[3],"Predictive Analytics");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer Information Systems Major in Business Intelligence");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      case 13:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Responsive Web Design\n");
				printf("2.Mobile UI/UX Design\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"Mobile-First Design");
          strcpy(subjects[1],"CSS Frameworks");
          strcpy(subjects[2],"Cross-Browser Compatibility");
          strcpy(subjects[3],"Web Accessibility");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Mobile and Web Development Major in Responsive Web Design");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"User-Centered Design");
          strcpy(subjects[1],"Mobile App Prototyping");
          strcpy(subjects[2],"Usability Testing for Mobile Apps");
          strcpy(subjects[3],"Mobile App User Experience Optimization");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Mobile and Web Development Major in Mobile UI/UX Design");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      case 14:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Computational Physics\n");
				printf("2.Computational Biology\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"Numerical Methods in Physics");
          strcpy(subjects[1],"Computational Quantum Mechanics");
          strcpy(subjects[2],"Molecular Dynamics Simulations");
          strcpy(subjects[3],"Computational Fluid Dynamics");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computational Science Major in Computational Physics");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Numerical Methods in Physics");
          strcpy(subjects[1],"Molecular Modeling");
          strcpy(subjects[2],"Systems Biology");
          strcpy(subjects[3],"Drug Design and Discovery");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computational Science Major in Computational Biology");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      case 15:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Embedded Systems Technology\n");
				printf("2.Networking Technology\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"Microcontroller Interfacing");
          strcpy(subjects[1],"Real-Time Embedded Software");
          strcpy(subjects[2],"Sensor Networks");
          strcpy(subjects[3],"Embedded System Integration");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer Engineering Technology Major in Embedded Systems Technology");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Network Infrastructure Design");
          strcpy(subjects[1],"Cisco Networking");
          strcpy(subjects[2],"Network Troubleshooting and Maintenance");
          strcpy(subjects[3],"Network Security");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer Engineering Technology Major in Networking Technology");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      case 16:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.IT Project Management\n");
				printf("2.IT Service Management\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
					case 1:
				  strcpy(subjects[0],"Project Initiation and Planning");
          strcpy(subjects[1],"Project Execution and Control");
          strcpy(subjects[2],"Risk Management in IT Projects");
          strcpy(subjects[3],"Project Communication and Leadership");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in IT Management Major in IT Project Management");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"IT Service Delivery and Support");
          strcpy(subjects[1],"ITIL Framework Implementation");
          strcpy(subjects[2],"Service Level Management");
          strcpy(subjects[3],"IT Service Continuity Management");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in IT Management Major in IT Service Management");
					while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
		    }
      } while(major!=2);
      break;
      case 17:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Game Mechanics\n");
				printf("2.Game Level Design\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
					case 1:
				  strcpy(subjects[0],"Game Balancing and Tuning");
          strcpy(subjects[1],"Gameplay Prototyping");
          strcpy(subjects[2],"Game Mechanics Analysis");
          strcpy(subjects[3],"Game Monetization Strategies");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Game Design and Development Major in Game Mechanics");
          while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Level Design Principles");
          strcpy(subjects[1],"Game Environment Creation");
          strcpy(subjects[2],"Level Scripting and Implementation");
          strcpy(subjects[3],"Level Testing and Iteration");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Game Design and Development Major in Game Level Design");
				  while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      case 18:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Software Development\n");
				printf("2.Mobile Applications\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"Programming Fundamentals");
          strcpy(subjects[1],"Software Design and Development");
          strcpy(subjects[2],"Data Structures and Algorithms");
          strcpy(subjects[3],"Web Application Development");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Computer Applications Major in Software Development");
				  while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Mobile App Development Fundamentals");
          strcpy(subjects[1],"Mobile App UI/UX Design");
          strcpy(subjects[2],"Cross-Platform Mobile Development");
          strcpy(subjects[3],"Mobile App Deployment");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Computer Applications Major in Mobile Applications");
				  while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      case 19:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Information Systems\n");
				printf("2.Data Management\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"Information Systems Analysis and Design");
          strcpy(subjects[1],"Database Management Systems");
          strcpy(subjects[2],"Information Systems Security");
          strcpy(subjects[3],"Business Process Management");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer and Information Science Major in Information Systems");
				  while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Data Modeling and Database Design");
          strcpy(subjects[1],"Data Integration and ETL");
          strcpy(subjects[2],"Data Governance and Ethics");
          strcpy(subjects[3],"Big Data Technologies");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer and Information Science Major in Data Management");
				  while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      case 20:
      do {
				printf("\n");
				printf("•|Majors|•\n");
				printf("1.Network Administration\n");
				printf("2.Network Security\n");
				printf("\n\nEnter your Choice ==>");
				scanf("%d",&major);
				switch(major) {
				  case 1:
				  strcpy(subjects[0],"Network Configuration and Management");
          strcpy(subjects[1],"Network Security");
          strcpy(subjects[2],"Routing and Switching");
          strcpy(subjects[3],"Network Troubleshooting");
          subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer Networking Major in Network Administration");
				  while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  return;
				  case 2:
				  strcpy(subjects[0],"Network Attacks and Defenses");
		      strcpy(subjects[1],"Firewalls and Intrusion Detection Systems");
		      strcpy(subjects[2],"Network Security Monitoring");
		      strcpy(subjects[3],"Secure Network Protocols");
		      subjects[4]=NULL;
				  strcpy(student[num].degree.course,"Bachelor of Science in Computer Networking Major in Network Security");
				  while(subjects[student[num].degree.numSubjects]!=NULL) {
	          student[num].degree.numSubjects++;
          }
				  subjectGrades(student,subjects,num);
				  break;
				  default:
				  printf("Invalid Input\n");
				  break;
				}
      } while(major!=2);
      break;
      default:
      printf("Invalid Choice\n");
      break;
		} 
  } while(choice!=20);
  free(subjects);
  for(int i=0;i<6;i++) {
	  free(subjects[i]);
  }
}

