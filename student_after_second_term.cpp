#include "student.h"

StudentAfterSecondTerm::StudentAfterSecondTerm(char *c_name, int c_course, int c_group, int c_record_book_number,
                                               const unsigned c_first_term_marks[4],
                                               const unsigned c_second_term_marks[5])
        : StudentAfterFirstTerm(c_name, c_course, c_group, c_record_book_number, c_first_term_marks) {
    for (int i = 0; i < 5; i++) second_term_marks[i] = c_second_term_marks[i];
}

StudentAfterSecondTerm::StudentAfterSecondTerm(const StudentAfterFirstTerm &student,
                                               const unsigned c_second_term_marks[5])
        : StudentAfterFirstTerm(student) {
    for (int i = 0; i < 5; i++) second_term_marks[i] = c_second_term_marks[i];
}

StudentAfterSecondTerm::StudentAfterSecondTerm(const Student &student, const unsigned c_first_term_marks[4],
                                               const unsigned c_second_term_marks[5])
        : StudentAfterFirstTerm(student, c_first_term_marks) {
    for (int i = 0; i < 5; i++) second_term_marks[i] = c_second_term_marks[i];
};

void StudentAfterSecondTerm::PrintAllSecondTermMarks() {
    for (int second_term_mark: second_term_marks) {
        std::cout << second_term_mark << " ";
    }
}

void StudentAfterSecondTerm::ChangeAllSecondTermMarks(const unsigned new_second_term_marks[5]) {
    for (int i = 0; i < 5; i++) {
        second_term_marks[i] = new_second_term_marks[i];
    }
}

std::ostream &operator<<(std::ostream &out, const StudentAfterSecondTerm &student) {
    out << dynamic_cast<const StudentAfterFirstTerm &>(student);
    out << '\n' << "Marks after second term: ";
    for (auto i: student.second_term_marks) {
        out << i << " ";
    }
    return out;
}

double StudentAfterSecondTerm::CalculateAverageScore() const {
    double sum_of_marks_after_first_term = StudentAfterFirstTerm::CalculateAverageScore() * 4;
    double sum = 0;
    for (unsigned int second_term_mark: second_term_marks) {
        sum += second_term_mark;
    }
    return (sum + sum_of_marks_after_first_term) / 9;
}