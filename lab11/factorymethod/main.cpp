//
// Created by kolobart on 23.05.17.
//

#include "FactoryMethod.h"

using ::factoryMethod::Sum;
using ::factoryMethod::Value;
using ::factoryMethod::Mean;

    int main(){

         double a=2.4;
        double b=9.34;
        std::string c = "abc";
        std::string d = "cdf";
        std::cout << Sum(a,b) << std::endl;
        std::cout << Sum(c,d) << std::endl;




        std::unique_ptr<int> v1 = std::make_unique<int>(2);
        std::string abc = "avcxg";
        std::string* v2 = &abc;
        std::shared_ptr<double> v3 = std::make_shared<double>(4.76);
        std::cout << Value(std::move(v1)) << std::endl;
        std::cout << Value(v2) << std::endl;
        std::cout << Value(v3) << std::endl;



    std::vector<int> v4{1,2,3,4,5,6,7,};
    std::vector<double> v5{3.564, 3.53, 89.54, 11.22};
        std::cout << Mean(v4) << std::endl;
        std::cout << Mean(v5) << std::endl;


    return 0;
    }
