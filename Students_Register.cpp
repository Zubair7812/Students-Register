#include <iostream>
#include <vector>
#include <iomanip>

class Student {
public:
    std::string name;
    int rollNumber;
    double marks;

    Student(std::string n, int roll, double m)
        : name(n), rollNumber(roll), marks(m) {}
};

class StudentRecordSystem {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void displayStudents() const {
        std::cout << std::setw(20) << "Name" << std::setw(15) << "Roll Number"
                  << std::setw(10) << "Marks" << std::endl;

        for (const auto& student : students) {
            std::cout << std::setw(20) << student.name
                      << std::setw(15) << student.rollNumber
                      << std::setw(10) << student.marks << std::endl;
        }
    }

    void searchStudent(int rollNumber) const {
        auto it = std::find_if(students.begin(), students.end(),
            [rollNumber](const Student& student) { return student.rollNumber == rollNumber; });

        if (it != students.end()) {
            std::cout << "Student found:\n";
            std::cout << std::setw(20) << "Name" << std::setw(15) << "Roll Number"
                      << std::setw(10) << "Marks" << std::endl;
            std::cout << std::setw(20) << it->name
                      << std::setw(15) << it->rollNumber
                      << std::setw(10) << it->marks << std::endl;
        } else {
            std::cout << "Student not found.\n";
        }
    }
};

int main() {
    StudentRecordSystem recordSystem;

    // Add some initial student records
    recordSystem.addStudent(Student("John Doe", 101, 85.5));
    recordSystem.addStudent(Student("Jane Smith", 102, 92.0));
    recordSystem.addStudent(Student("Bob Johnson", 103, 78.3));

    int choice;
    do {
        std::cout << "\nOptions:\n";
        std::cout << "1. Display Students\n";
        std::cout << "2. Search Student\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                recordSystem.displayStudents();
                break;
            case 2: {
                int rollNumber;
                std::cout << "Enter the roll number of the student: ";
                std::cin >> rollNumber;

                recordSystem.searchStudent(rollNumber);
                break;
            }
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
