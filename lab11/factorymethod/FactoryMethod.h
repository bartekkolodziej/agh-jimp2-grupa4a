//
// Created by kolobart on 23.05.17.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <complex>
#include <experimental/optional>


namespace factoryMethod {

    template<class T>

    T Create(){return T();}

   class MyType{
   public:
       std::string SayHello(){return "hello";};
   };

   template<class T>
   T Sum(T a, T b){return a + b;};


    template<class T>
    auto Value(T a){
        return *a;
    }

    template<class T>
    T Mean(std::vector<T> v1){
        T sum = 0;
        for(T x: v1) sum += x;
        return sum/v1.size();
    }

class Repository{
    public:
        size_t Size(){return this->objects.size();}
        int NextId(){};
        template<class T>
        T FindByQuery(int id){for(T x: this->objects) if(x.id == id) return x;}

        template<class T>
        std::experimental::optional<T> operator[](int id) const{return this->objects[id];}
        template<class T>
        std::vector<T> objects;
    };


}



#endif //JIMP_EXERCISES_FACTORYMETHOD_H
