//
// Created by kolobart on 04.04.17.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include <string>
#include <iostream>


class StudyYear{
public:

        int year;
    StudyYear();

};

int &operator++();
int &operator--(StudyYear &year_);


class Student{
public:

    std::string id;
    std::string first_name;
    std::string last_name;
    std::string program;
    std::string year;
    StudyYear year_;



};








#endif //JIMP_EXERCISES_STUDENT_H
