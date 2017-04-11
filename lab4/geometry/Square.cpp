//
// Created by kolobart on 21.03.17.
//

#include "Square.h"


using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::istream;
using ::std::ws;


namespace geometry{


    ostream& operator<<(std::ostream &output, Point& p){

        output<<"(";
        output << p.x_;
        output << ",";
        output << p.y_;
        output<<")";

        return output;
    }

    Point::Point():x_(0),y_(0){}

    Point::Point(double x, double y){
        x_ = x;
        y_ = y;
    }

    Point::~Point(){}



    void Point::SetX(double x){
        this->x_ = x;
    }

    void Point::SetY(double y){
        this->y_ = y;
    }

}