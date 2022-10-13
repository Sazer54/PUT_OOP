#include <iostream>

using namespace std;

class Student {
public:
    string name;
    string surname;
    int yearOfBirth;
    string nameOfBestTeacher;
};

class Lecture {
public:
    string name;
    int semesterNumber;
    int numberOfClasses;
    string nameOfLecturer;
};

class Lecturer {
public:
    string name;
    string surname;
    int yearOfBirth;
    Student favStudent;

    void teach(Lecture l){
        l.nameOfLecturer = name;
    };

    void favorise(Student s) {
        favStudent = s;
    };
};

int main(){
    Lecturer firstLecturer;
    Lecturer secondLecturer;
    Lecture firstLecture;
    Student firstStudent;

    firstLecturer.teach(firstLecture);
    firstLecturer.favorise(firstStudent);
    secondLecturer.favorise(firstStudent);
    return 0;
}
