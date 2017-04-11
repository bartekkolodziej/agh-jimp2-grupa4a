//
// Created by kolobart on 04.04.17.
//

#include "Student.h"

StudyYear::StudyYear(){
    this->year = 1;
}


int &operator++(StudyYear &year_){

   year_.year +=1;

}
int &operator--(StudyYear &year_){

    year_.year -=1;

}