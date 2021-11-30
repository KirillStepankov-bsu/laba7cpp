#include "student.h"

double CalculateAverageScoreInGroup(const std::vector <std::shared_ptr<Student>> &group){
    double sum_of_average = 0;
    for(const auto& student : group){
        sum_of_average+=student->CalculateAverageScore();
    }
    return sum_of_average/group.size();
}

double CalculateAverageScore(const std::shared_ptr<Student> array_of_student_classes[3]){
    double sum = 0;
    for(int i = 0; i < 3; i++){
        sum += array_of_student_classes[i]->CalculateAverageScore();
    }
    return sum/3;
}

