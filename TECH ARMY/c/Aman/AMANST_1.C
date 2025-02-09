#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to hold student information
typedef struct {
    int id;
    char name[50];
    float marks[3]; // 0: Maths, 1: Science, 2: English
    char department[50];
} Student;

// Global array to hold student records and a counter for the number of students
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudentByID();
void deleteStudentByID();
void updateStudentDetails();
void findHighestMarks();
void countTotalStudents();
void reverseStudentList();
void sortStudentsByMarks();
void findAverageMarks();

void main() {
    int choice;
    clrscr(); // Clear the screen


    // Main menu loop
    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search for a Student by ID\n");
        printf("4. Delete a Student Record by ID\n");
        printf("5. Update Student Details\n");
        printf("6. Find the Student with the Highest Marks\n");
        printf("7. Count the Total Number of Students\n");
        printf("8. Reverse the Student List\n");
        printf("9. Sort Students by Marks\n");
        printf("10. Find Average Marks of All Students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudentByID(); break;
            case 4: deleteStudentByID(); break;
            case 5: updateStudentDetails(); break;
            case 6: findHighestMarks(); break;
            case 7: countTotalStudents(); break;
            case 8: reverseStudentList(); break;
            case 9: sortStudentsByMarks(); break;
            case 10: findAverageMarks(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
}

// Function to add a new student record
void addStudent() {
    Student newStudent;
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent.name); // Read string with spaces
    printf("Enter Marks (Maths, Science, English): ");
    scanf("%f %f %f", &newStudent.marks[0], &newStudent.marks[1], &newStudent.marks[2]);
    printf("Enter Department: ");
    scanf(" %[^\n]", newStudent.department);

    students[studentCount++] = newStudent; // Add new student to the array
    printf("Student record added successfully.\n");
}

// Function to display all student records
void displayStudents() {
	int i;
    if (studentCount == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("\nStudent Records:\n");
    for (i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f, %.2f, %.2f, Department: %s\n",
               students[i].id, students[i].name, students[i].marks[0], students[i].marks[1], students[i].marks[2], students[i].department);
    }
}

// Function to search for a student by ID
void searchStudentByID() {
    int id,i;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    for ( i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Student found: ID: %d, Name: %s, Marks: %.2f, %.2f, %.2f, Department: %s\n",
                   students[i].id, students[i].name, students[i].marks[0], students[i].marks[1], students[i].marks[2], students[i].department);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// ```c
// Function to delete a student record by ID
void deleteStudentByID() {
    int id,i,j;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    for ( i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            // Shift all students after the deleted one to the left
	    for ( j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--; // Decrease the student count
            printf("Student record with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to update student details
void updateStudentDetails() {
    int id,i;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    for ( i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Updating details for ID: %d\n", id);
            printf("Enter new Marks (Maths, Science, English): ");
            scanf("%f %f %f", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
            printf("Enter new Department: ");
            scanf(" %[^\n]", students[i].department);
            printf("Student details updated successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to find the student with the highest marks
void findHighestMarks() {
	int highestIndex;
    Student newStudent;
    int i;
    if (studentCount == 0) {
	printf("No student records available.\n");
	return;
    }

    for ( i = 1; i < studentCount; i++) {
        float totalMarksCurrent = students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
        float totalMarksHighest = students[highestIndex].marks[0] + students[highestIndex].marks[1] + students[highestIndex].marks[2];
        if (totalMarksCurrent > totalMarksHighest) {
            highestIndex = i;
        }
    }
    printf("Student with the highest marks: ID: %d, Name: %s, Marks: %.2f, %.2f, %.2f, Department: %s\n",
           students[highestIndex].id, students[highestIndex].name, students[highestIndex].marks[0],
           students[highestIndex].marks[1], students[highestIndex].marks[2], students[highestIndex].department);
}

// Function to count the total number of students
void countTotalStudents() {
    printf("Total number of students: %d\n", studentCount);
}

// Function to reverse the student list
void reverseStudentList() {
	int i;
    for ( i = 0; i < studentCount / 2; i++) {
        Student temp = students[i];
        students[i] = students[studentCount - 1 - i];
        students[studentCount - 1 - i] = temp;
    }
    printf("Student list reversed successfully.\n");
}

// Function to sort students by marks
void sortStudentsByMarks() {
    int order,i,j;
    printf("Enter 1 for Ascending or 2 for Descending order: ");
    scanf("%d", &order);
    for ( i = 0; i < studentCount - 1; i++) {
	for ( j = 0; j < studentCount - i - 1; j++) {
	    float totalMarksCurrent = students[j].marks[0] + students[j].marks[1] + students[j].marks[2];
	    float totalMarksNext = students[j + 1].marks[0] + students[j + 1].marks[1] + students[j + 1].marks[2];
            if ((order == 1 && totalMarksCurrent > totalMarksNext) || (order == 2 && totalMarksCurrent < totalMarksNext)) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted successfully.\n");
}

// Function to find average marks of all students
void findAverageMarks() {
	int totalMarks,i;
    Student newStudent;
    float averageMarks = totalMarks / (studentCount * 3); // Total subjects
    if (studentCount == 0) {
	printf("No student records available.\n");
	return;
    }

    for (i = 0; i < studentCount; i++) {
	totalMarks += students[i].marks[0] + students[i].marks[1] + students[i].marks[2];
    }

    printf("Average marks of all students: %.2f\n", averageMarks);
}