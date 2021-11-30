#include "student.h"

Student::Student(char *c_name, int c_course, int c_group, int c_record_book_number)
    : name(c_name),
            course(c_course),
            group(c_group),
            record_book_num(c_record_book_number) {
        std::random_device rd;
        std::mt19937 mersenne(rd());
        ID = mersenne() % (MAX_AMOUNT_STUDENTS + 1);
}

std::ostream &operator<<(std::ostream &out, const Student &student) {
    out << "Student ID: " << student.ID << ".\n"
        << student.name << ", course: " << student.course
        << ", group: " << student.group << '\n'
        << "Record-book: " << student.record_book_num;

    return out;
}

double StudentAfterFirstTerm::CalculateAverageScore() const {
    double sum = 0;
    for (const auto &mark: first_term_marks) {
        sum += mark;
    }
    return sum / 4;
}