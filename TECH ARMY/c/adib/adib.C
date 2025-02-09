/*Author
Team Name:- Tech Army
Team member:- Adib Puthawala, Aman Khimani, Hetvi Magiya
Name:-Adib Puthawala*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student{
    char* name;
    int stud_id;
    char* Sub1;
    char* Sub2;
    char* Sub3;
    int Maths;
    int Science;
    int English;
    char* Department;
    int total_marks;

};

int main(){
    struct Student students[5];
    int n=sizeof(students)/sizeof(struct Student);
    //Get the Student data
    students[0] = (struct Student){ "Ajay", 1, "Maths", "Science", "English", 70, 85, 60, "B.Tech", 215 };
    students[1] = (struct Student){ "Amit", 2, "Maths", "Science", "English", 85, 70, 60, "B.Tech", 215 };
    students[2] = (struct Student){ "Sumit", 3, "Maths", "Science", "English", 75, 85, 65, "B.Tech", 225 };
    students[3] = (struct Student){ "Suraj", 4, "Maths", "Science", "English", 90, 95, 90, "B.Tech", 275 };
    students[4] = (struct Student){ "Amit", 5, "Maths", "Science", "English", 50, 50, 50, "B.Tech", 150 };

    //print the student information
    printf("----------Student Records-----------\n");
    for(int i =0; i < n;i++){
        printf("\n Student %d:\n", i + 1);
        printf("Stud_id       : %d\n", students[i].stud_id);  
        printf("Name          : %s\n", students[i].name);
        printf("Subject 1     : %s\n", students[i].Sub1);
        printf("Subject 2    : %s\n", students[i].Sub2);
        printf("Subject 3     : %s\n", students[i].Sub3);
        printf("Maths         : %d\n", students[i].Maths);   
        printf("Science       : %d\n", students[i].Science); 
        printf("English      : %d\n", students[i].English); 
        printf("Department    : %s\n", students[i].Department);
        printf("Total Marks   : %d\n", students[i].total_marks);
       
        printf("----------End------------\n");

        return 0;

    }
}

