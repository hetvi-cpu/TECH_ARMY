/*Author:-
	     Team name:-TECH ARMY
	     Team members:-Hetvi,Aman,Adib,Srushti
	     Name:-Aman,Adib,hetvi,srushti
	  Objective:-To develop a customizable, intuitive classroom management tools for teachers.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    string id;

    Student(string name, string id) : name(name), id(id) {}
};

class Attendance {
public:
    string studentId;
    bool present;

    Attendance(string studentId, bool present) : studentId(studentId), present(present) {}
};

class Homework {
public:
    string title;
    string description;

    Homework(string title, string description) : title(title), description(description) {}
};

class Announcement {
public:
    string message;

    Announcement(string message) : message(message) {}
};

class ClassroomManagement {
private:
    vector<Student> students;
    vector<Attendance> attendanceRecords;
    vector<Homework> homeworkAssignments;
    vector<Announcement> announcements;

public:
    void addStudent(string name, string id) {
        students.push_back(Student(name, id));
    }

    void trackAttendance(string studentId, bool present) {
        attendanceRecords.push_back(Attendance(studentId, present));
    }

    void assignHomework(string title, string description) {
        homeworkAssignments.push_back(Homework(title, description));
    }

    void postAnnouncement(string message) {
        announcements.push_back(Announcement(message));
    }

    void viewStudents() {
        cout << "Student Profiles:\n";
        for (const auto& student : students) {
            cout << "Name: " << student.name << ", ID: " << student.id << endl;
        }
    }

    void viewAttendance() {
        cout << "Attendance Records:\n";
        for (const auto& record : attendanceRecords) {
            cout << "Student ID: " << record.studentId << ", Present: " << (record.present ? "Yes" : "No") << endl;
        }
    }

    void viewHomework() {
        cout << "Homework Assignments:\n";
        for (const auto& homework : homeworkAssignments) {
            cout << "Title: " << homework.title << ", Description: " << homework.description << endl;
        }
    }

    void viewAnnouncements() {
        cout << "Announcements:\n";
        for (const auto& announcement : announcements) {
            cout << "Message: " << announcement.message << endl;
        }
    }
};

int main() {
    ClassroomManagement cm;
    int choice;

    do {
        cout << "\nClassroom Management Tool\n";
        cout << "1. Add Student\n";
        cout << "2. Track Attendance\n";
        cout << "3. Assign Homework\n";
        cout << "4. Post Announcement\n";
        cout << "5. View Students\n";
        cout << "6. View Attendance\n";
        cout << "7. View Homework\n";
        cout << "8. View Announcements\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, id;
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student ID: ";
                cin >> id;
                cm.addStudent(name, id);
                break;
            }
            case 2: {
                string studentId;
                bool present;
                cout << "Enter student ID: ";
                cin >> studentId;
                cout << "Is the student present? (1 for Yes, 0 for No): ";
                cin >> present;
                cm.trackAttendance(studentId, present);
                break;
            }
            case 3: {
                string title, description;
                cout << "Enter homework title: ";
                cin >> title;
                cout << "Enter homework description: ";
                cin.ignore(); // To ignore the newline character
                getline(cin, description);
                cm.assignHomework(title, description);
                break;
            }
            case 4: {
                string message;
                cout << "Enter announcement message: ";
                cin.ignore(); // To ignore the newline character
                getline(cin, message);
                cm.postAnnouncement(message);
                break;
            }
            case 5:
                cm.viewStudents();
                break;
            case 6:
                cm.viewAttendance();
                break;
            case 7:
                cm.viewHomework();
                break;
            case 8:
                cm.viewAnnouncements();
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
