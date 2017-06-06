//
// Created by bartek on 01.06.17.
//

#include "TeacherHash.h"

namespace academia {

    Teacher::Teacher(TeacherId teacherid, std::string name, std::string department) {
        this->teacherid = teacherid;
        this->name = name;
        this->department = department;
    }

    size_t TeacherHash::operator()(const Teacher teacher) const {
        std::size_t h1 = std::hash<std::string>{}(teacher.name);
        std::size_t h2 = std::hash<std::string>{}(teacher.department);
        std::size_t h3 = std::hash<int>{}(teacher.teacherid.id);
        return h1*h2 + h3;
    }


    bool operator==(const TeacherId &teacherid1, const TeacherId &teacherid2) {
        return teacherid1.id == teacherid2.id;
    }

    bool operator!=(const TeacherId &teacherid1, const TeacherId &teacherid2) {
        return teacherid1.id != teacherid2.id;
    }

    bool operator==(const Teacher &teacher1, const Teacher &teacher2) {
        return teacher1.teacherid.id == teacher2.teacherid.id && teacher1.name == teacher2.name && teacher1.department == teacher2.department;
    }

    bool operator!=(const Teacher &teacher1, const Teacher &teacher2) {
        return teacher1.teacherid.id != teacher2.teacherid.id || teacher1.name != teacher2.name || teacher1.department != teacher2.department;
    }
}