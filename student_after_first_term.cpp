#include "student.h"

StudentAfterFirstTerm::StudentAfterFirstTerm(const Student &student, const unsigned int c_first_term_marks[4])
        : Student(student) {
    for (int i = 0; i < 4; i++) first_term_marks[i] = c_first_term_marks[i];
}

StudentAfterFirstTerm::StudentAfterFirstTerm(char *c_name, int c_course, int c_group, int c_record_book_number,
                                             const unsigned int c_first_term_marks[4])
        : Student(c_name, c_course, c_group, c_record_book_number) {
    for (int i = 0; i < 4; i++) first_term_marks[i] = c_first_term_marks[i];
}

void StudentAfterFirstTerm::PrintAllFirstTermMarks() {
    for (int first_term_mark: first_term_marks) {
        std::cout << first_term_mark << " ";
    }
}

void StudentAfterFirstTerm::ChangeAllFistTermMarks(const int m_first_term_marks[4]) {
    for (int i = 0; i < 4; i++) {
        first_term_marks[i] = m_first_term_marks[i];
    }
}

std::ostream &operator<<(std::ostream &out, const StudentAfterFirstTerm &student) {
    out << dynamic_cast<const Student &>(student) << std::endl;
    for (auto i: student.first_term_marks) {
        out << i << " ";
    }
    return out;
}