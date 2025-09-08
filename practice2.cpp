#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks[3];

    Student() {}

    Student(int r, string n, float m1, float m2, float m3) {
        if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100)
            throw invalid_argument("Marks must be between 0 and 100.");
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float average() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0f;
    }

    // Pre-increment: ++s
    Student& operator++() {
        for (int i = 0; i < 3; ++i) {
            if (marks[i] < 100)
                marks[i] += 1;
        }
        return *this;
    }

    // Post-increment: s++
    Student operator++(int) {
        Student temp = *this;
        for (int i = 0; i < 3; ++i) {
            if (marks[i] < 100)
                marks[i] += 1;
        }
        return temp;
    }

    // Compare based on average marks
    bool operator>(const Student& other) const {
        return average() > other.average();
    }

    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name
             << ", Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2]
             << ", Average: " << fixed << setprecision(2) << average() << "\n";
    }
};

class Gradebook {
private:
    vector<Student> students;

public:
    void loadFromFile() {
        ifstream file("gradebook.txt");
        if (!file.is_open()) return;

        students.clear();

        int r;
        string n;
        float m1, m2, m3;
        while (file >> r) {
            file.ignore(); // skip space
            getline(file, n);
            file >> m1 >> m2 >> m3;
            file.ignore(); // skip newline

            try {
                students.push_back(Student(r, n, m1, m2, m3));
            } catch (invalid_argument& e) {
                cout << "Skipping invalid record: " << e.what() << "\n";
            }
        }
        file.close();
    }

    void saveToFile() {
        ofstream file("gradebook.txt");
        for (const auto& s : students) {
            file << s.rollNo << " " << s.name << "\n"
                 << s.marks[0] << " " << s.marks[1] << " " << s.marks[2] << "\n";
        }
        file.close();
    }

    void addStudent() {
        int r;
        string n;
        float m1, m2, m3;

        cout << "Enter roll number: ";
        cin >> r;
        for (const auto& s : students) {
            if (s.rollNo == r) {
                cout << "Duplicate roll number! Cannot add.\n";
                return;
            }
        }
        cin.ignore();

        cout << "Enter name: ";
        getline(cin, n);

        cout << "Enter marks for 3 subjects: ";
        cin >> m1 >> m2 >> m3;

        try {
            Student newStudent(r, n, m1, m2, m3);
            students.push_back(newStudent);
            cout << "Student added.\n";
        } catch (invalid_argument& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "Gradebook is empty.\n";
            return;
        }
        for (const auto& s : students) {
            s.display();
        }
    }

    void searchStudent(int roll) const {
        for (const auto& s : students) {
            if (s.rollNo == roll) {
                s.display();
                return;
            }
        }
        cout << "Student with roll no " << roll << " not found.\n";
    }

    void updateMarks(int roll) {
        for (auto& s : students) {
            if (s.rollNo == roll) {
                cout << "Current marks: " << s.marks[0] << ", " << s.marks[1] << ", " << s.marks[2] << "\n";
                cout << "Enter new marks for 3 subjects: ";
                float m1, m2, m3;
                cin >> m1 >> m2 >> m3;
                try {
                    if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100)
                        throw invalid_argument("Marks must be between 0 and 100.");
                    s.marks[0] = m1;
                    s.marks[1] = m2;
                    s.marks[2] = m3;
                    cout << "Marks updated.\n";
                } catch (invalid_argument& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void bonusMarks(int roll) {
        for (auto& s : students) {
            if (s.rollNo == roll) {
                ++s;  // pre-increment bonus marks
                cout << "Bonus marks added.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void compareStudents(int r1, int r2) const {
        const Student* s1 = nullptr;
        const Student* s2 = nullptr;

        for (const auto& s : students) {
            if (s.rollNo == r1)
                s1 = &s;
            if (s.rollNo == r2)
                s2 = &s;
        }

        if (!s1 || !s2) {
            cout << "One or both students not found.\n";
            return;
        }

        if (*s1 > *s2)
            cout << s1->name << " has higher average marks.\n";
        else if (*s2 > *s1)
            cout << s2->name << " has higher average marks.\n";
        else
            cout << "Both students have the same average marks.\n";
    }
};

int main() {
    Gradebook gb;
    gb.loadFromFile();

    while (true) {
        cout << "\nStudent Gradebook Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Update Student Marks\n";
        cout << "5. Add Bonus Marks (++ Operator)\n";
        cout << "6. Compare Two Students\n";
        cout << "7. Save and Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 7) {
            gb.saveToFile();
            cout << "Data saved. Exiting...\n";
            break;
        }

        int roll1, roll2;
        switch (choice) {
            case 1:
                gb.addStudent();
                break;
            case 2:
                gb.displayAll();
                break;
            case 3:
                cout << "Enter roll number to search: ";
                cin >> roll1;
                gb.searchStudent(roll1);
                break;
            case 4:
                cout << "Enter roll number to update marks: ";
                cin >> roll1;
                gb.updateMarks(roll1);
                break;
            case 5:
                cout << "Enter roll number to add bonus marks: ";
                cin >> roll1;
                gb.bonusMarks(roll1);
                break;
            case 6:
                cout << "Enter two roll numbers to compare: ";
                cin >> roll1 >> roll2;
                gb.compareStudents(roll1, roll2);
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}