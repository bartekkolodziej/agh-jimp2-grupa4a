//
// Created by kolobart on 11.04.17.
//

#include "ArrayFill.h"

int main(){

    std::vector<int> vs;
    FillArray(1024, UniformFill {77}, &vs);

    for(auto x: vs) std::cout<<x<<std::endl;


}