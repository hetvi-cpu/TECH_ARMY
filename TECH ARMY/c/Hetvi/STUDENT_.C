/*
   Author:
     Team Name: Tech Army
     Team Memebers: Aman,Adib,Hetvi
     Name:Hetvi
   Objective:Customizable student record Management System
*/
#include<stdio.h>
#include<conio.h>
#define size 10
struct student
{
 int rollno;
 char name[30],department;
 int science,maths,eng,average;
 int flag;

}
s[size];

void addStudent();
void displayStudent();
int search(int rollno);
int delStudent(int rollno);
int updateStudent(int rollno);
void highestMarks();
void totalStudents();
void reverseStudentList();
void sortList();
void averageMArksOfStudent();

// Main section

void main()
{
  int choice,rollno,i=-1;
  do
  {
  clrscr();
  printf("\n1-------ADD STUDENT");
  printf("\n2-------DISPLAY STUDET");
  printf("\n3-------SEARCH STUDET");
  printf("\n4-------UPDATE STUDET");
  printf("\n5-------HIGHEST MARKS");
  printf("\n6-------TOTAL STUDENT");
  printf("\n7-------REVERSE LIST");
  printf("\n8-------SORT LIST");
  printf("\n9-------AVERAGE MARKS ALL STUDET");
  printf("\n10------DELETE STUDNET");
  printf("\n11------EXIT");

  printf("\n\nENTER YOUR CHOICE:");
  scanf("%d",&choice);

  switch(choice)
  {
  case 1:addStudent();
	 break;
  case 2:displayStudent();
	 break;
  case 3:printf("Enter Rollno U Want To Search:");
	 scanf("%d",&rollno);
	 i=search(rollno);
	 if(i<0)
	 {
	 printf("NO DATA FOUND");
	 }
	 else
	 {
	 printf("\nRollno:%d\nName:%s\nEnglish:%d\nMaths:%d\nScience:%d\nDepartment:%s\n",s[i].rollno,s[i].name,s[i].eng,s[i].maths,s[i].science,s[i].department);
	 }
	 break;
 case 4:printf("Enter Rollno U Want To Search:");
	 scanf("%d",&rollno);
	 i=search(rollno);
	 if(i<0)
	 {
	 printf("NO DATA FOUND");
	 }
	 else
	 {
	 printf("\nUPDATED DETAILS");
	 printf("\nRollno:%d\nName:%s\nEnglish:%d\nMaths:%d\nScience:%d\nDepartment:%s\n",s[i].rollno,s[i].name,s[i].eng,s[i].maths,s[i].science,s[i].department);
	 }
	 break;
 case 10: printf("Enter Rollno U Want To Search:");
	 scanf("%d",&rollno);
	 i=search(rollno);
	 if(i<0)
	 {
	 printf("NO DATA FOUND");
	 }
	 else
	 {
	  delStudent(i);
	 }
	 break;
 case 11:exit(0);
	 break;
 }
 getch();
 goto start;
 }

 void  addStudent()
 {
  int i;
  for(i=0;i<2;i++)
  {
   printf("\nEnter Rollno and Name");
   scanf("%d %s",&s[i].rollno,s[i].name);
   printf("\nEnter  MARKS of English");
   scanf("%d",s[i].eng);
   printf("\nEnter  MARKS of Maths");
   scanf("%d",s[i].maths);
   printf("\nEnter  MARKS of Science");
   scanf("%d",s[i].science);
    printf("\nEnter Department");
   scanf("%d",s[i].department);
   printf("n-----------");
 }
}

 void displayStudent()
 {
 int i;
  for(i=0;i<2;i++)
  {
  printf("\n%d\t%s\t%d\t%d\t%d\t%s",s[i].rollno,s[i].name,s[i].eng,s[i].maths,s[i].science);
  }
 }

 int search(int rollno)
 {
 int i;
 for(i=0;i<2;i++)
 {
  if(rollno==s[i].rollno)
  {
   return i;
  }
  }
  return -1;
 }

 int delStudent(int rollno)
 {
 int i;
 i=search(rollno);
 if(i>=0)
 {
 s[i].flag=-1;
 return 1;
 }
 return -1;
 }

 void averagestudent()
 {
 int i;
 for(i=0;i<2;i++)
 {
   s[i].average=s[i].eng+s[i].science+s[i].maths;
   printf("AVERAGE MARKS OF %d = %d",s[i].rollno,s[i].average);
 }
 }

 int updateStudent(int rollno)
 {
 int i,choice;
 float temp;
 i=search(rollno);
   if(i>=0)
  {
   printf("\n1---maths");
   printf("\n2---English");
   printf("Enter your Choice");
   scanf("%d",&choice);
  }
  return -1;
}


