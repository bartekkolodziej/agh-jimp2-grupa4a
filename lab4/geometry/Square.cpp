//
// Created by kolobart on 21.03.17.
//

#include "Square.h"


using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;


namespace geometry{

    Point::Point():x_(0),y_(0){}

    Point::Point(double x, double y){
        x_ = x;
        y_ = y;
    }

    Point::~Point(){}

    double Point::Distance(const Point &other) const{
        return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
    }

    void Point::ToString(ostream *out) const{
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    Square::Square(Punkt A, Punkt B, Punkt C, Punkt D ){
        A_ = A;
        B_ = B;
        C_ = C;
        D_ = D;
    }

    Square::~Square(){
    }

    double Square::Circumference(){
        if(GetA().Distance(&GetB()) == GetB().Distance(&GetC()) && GetB().Distance(&GetC()) == GetC().Distance(&GetD()) && GetC().Distance(&GetD()) == GetD().Distance(&GetA()) && GetA().Distance(&GetC()) == GetB().distance(&GetD())) {
            return 4 * GetA().Distance(&GetB());
        }
        else return 0;
    }
    double Square::Area(){
        if(GetA().Distance(&GetB()) == GetB().Distance(&GetC()) && GetB().Distance(&GetC()) == GetC().Distance(&GetD()) && GetC().Distance(&GetD()) == GetD().Distance(&GetA()) && GetA().Distance(&GetC()) == GetB().distance(&GetD())) {
            return pow(GetA().Distance(&GetB()), 2);
        }
        else return 0;
    }
}