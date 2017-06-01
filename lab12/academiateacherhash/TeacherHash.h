//
// Created by bartek on 01.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

namespace academia{


    class TeacherId{
    public:
        TeacherId(){}
        TeacherId(int id){this->id = id;}
        operator int(){return this->id;}


        int id;
    };

    class Teacher{
    public:
        Teacher(TeacherId teacherid, std::string name, std::string department);;

        int Id(){return this->teacherid.id;}
        std::string Name(){return this->name;}
        std::string Department(){return this->department;}

        TeacherId teacherid;
        std::string name;
        std::string department;
    };


    class TeacherHash{
    public:
        TeacherHash(){}
        TeacherHash(Teacher teacher){}

        size_t operator()(const Teacher teacher) const;

    };


    bool operator==(const TeacherId& teacherid1, const TeacherId& teacherid2);
    bool operator!=(const TeacherId& teacherid1, const TeacherId& teacherid2);
    bool operator==(const Teacher& teacher1, const Teacher& teacher2);
    bool operator!=(const Teacher& teacher1, const Teacher& teacher2);

}

#endif //JIMP_EXERCISES_TEACHERHASH_H
