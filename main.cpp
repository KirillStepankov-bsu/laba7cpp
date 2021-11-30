#include "student.h"

int main() {
    unsigned fmarks[4] {4,5,6,8};
    unsigned smarks[5] {5,9,1,0,8};
    StudentAfterFirstTerm student1("Kirill", 1, 4, 4546, fmarks);

    unsigned fmarks2[4] {4,8,0,8};
    unsigned smarks2[5] {0,7,3,0,8};
    StudentAfterFirstTerm student2("Lera", 1, 4, 4506, fmarks2);

    std::vector<std::shared_ptr<Student>> group;
    group.push_back(std::make_shared<StudentAfterFirstTerm>(student1));
    group.push_back(std::make_shared<StudentAfterFirstTerm>(student2));
    std::cout << CalculateAverageScoreInGroup(group);


}
