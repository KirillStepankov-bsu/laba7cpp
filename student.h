#pragma once

#include <random>
#include <iostream>
#include <vector>
#include <memory>

const unsigned MAX_AMOUNT_STUDENTS = 30000;


class Student {
public:
    Student(char *c_name, int c_course, int c_group, int c_record_book_number);

    Student(const Student &student) = default;


    [[nodiscard]] unsigned getID() const { return ID; }

    [[nodiscard]] unsigned getCourse() const { return course; }

    [[nodiscard]] unsigned getGroup() const { return group; }

    [[nodiscard]] unsigned getRecordBookNum() const { return record_book_num; }

    [[nodiscard]] char *getName() const { return name; }

    void setCourse(const int &m_course) { course = m_course; }

    void setGroup(const int &m_group) { group = m_group; }

    void setName(char *&m_name) { name = m_name; }

    [[nodiscard]] virtual double CalculateAverageScore() const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Student &student);

protected:
    unsigned ID;
    unsigned course;
    unsigned group;
    unsigned record_book_num;
    char *name;
};

class StudentAfterFirstTerm : public Student {
public:
    StudentAfterFirstTerm(const Student &student, const unsigned c_first_term_marks[4]);

    StudentAfterFirstTerm(char *c_name, int c_course, int c_group, int c_record_book_number,
                          const unsigned c_first_term_marks[4]);

    StudentAfterFirstTerm(const StudentAfterFirstTerm &student) = default;

    void PrintAllFirstTermMarks();

    [[nodiscard]] unsigned GetOneFirstTermMark(unsigned index) const { return first_term_marks[index]; }

    void ChangeOneFirstTermMark(const unsigned &index, const unsigned &value) { first_term_marks[index] = value; }

    void ChangeAllFistTermMarks(const int m_first_term_marks[4]);

    friend std::ostream &operator<<(std::ostream &out, const StudentAfterFirstTerm &student);

    [[nodiscard]] double CalculateAverageScore() const override;

protected:
    unsigned first_term_marks[4]{};
};

class StudentAfterSecondTerm : public StudentAfterFirstTerm {
public:
    StudentAfterSecondTerm(char *c_name, int c_course, int c_group, int c_record_book_number,
                           const unsigned c_first_term_marks[4], const unsigned c_second_term_marks[5]);

    StudentAfterSecondTerm(const StudentAfterFirstTerm &student, const unsigned c_second_term_marks[5]);

    StudentAfterSecondTerm(const Student &student, const unsigned c_first_term_marks[4],
                           const unsigned c_second_term_marks[5]);

    StudentAfterSecondTerm(const StudentAfterSecondTerm &student) = default;

    [[nodiscard]] unsigned GetOneSecondTermMark(const unsigned &index) const { return second_term_marks[index]; }

    void PrintAllSecondTermMarks();

    void ChangeOneSecondTermMark(const unsigned &index, const unsigned &value) { second_term_marks[index] = value; }

    void ChangeAllSecondTermMarks(const unsigned new_second_term_marks[5]);

    friend std::ostream &operator<<(std::ostream &out, const StudentAfterSecondTerm &student);

    [[nodiscard]] double CalculateAverageScore() const override;

protected:
    unsigned second_term_marks[5]{};
};

double CalculateAverageScoreInGroup(const std::vector <std::shared_ptr<Student>> &group);

double CalculateAverageScore(const std::shared_ptr<Student> array_of_student_classes[3]);