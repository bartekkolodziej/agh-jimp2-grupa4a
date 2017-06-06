//
// Created by bartek on 01.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template<class T, class E>
class SequentialIdGenerator{
public:
    SequentialIdGenerator(){ this->id = -1;};
    SequentialIdGenerator(int id){ this->id = id-1;};


    T NextValue(){
        this->id++;
        return T{id};
    };

    int id;
};

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
