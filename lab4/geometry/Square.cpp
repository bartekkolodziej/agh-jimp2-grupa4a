//
// Created by kolobart on 21.03.17.
//

#include "Square.h"
#include <iomanip>
#include <iostream>

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::istream;
using ::std::ws;


namespace geometry{

    Point::Point():x_(0),y_(0){}

    Point::Point(double x, double y){
        x_ = x;
        y_ = y;
    }

    Point::~Point(){}
    double Point::GetX()const {return x_;}
    double Point::GetY()const {return y_;}
    double Point::Distance(const Point &other) const{
        return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
    }

    void Point::ToString(ostream *out) const{
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    Square::Square(Point A, Point B, Point C, Point D ){
        A_ = A;
        B_ = B;
        C_ = C;
        D_ = D;
    }

    Square::~Square(){
    }
    Point Square::GetA()const {return A_;}
    Point Square::GetB()const {return B_;}
    Point Square::GetC()const {return C_;}
    Point Square::GetD()const {return D_;}

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


//Helper functions:
    void CheckNextChar(char c, istream* is) {
        int next_char = is->peek();
        if (next_char != c) {
            throw runtime_error("invalid character");
        }
        is->ignore();
    }

    void IgnoreWhitespace(istream* is) {
        (*is) >> ws;
    }

    double ReadNumber(istream* is) {
        double d;
        (*is) >> d;
        return d;
    }


// Właściwa definicja, obydwa argumenty funkcji nie
//są zadeklarowane jako const, bo obydwa są modyfikowane
//wewnątrz funkcji (STL nie używa naszej konwencji z przekazywaniem
//przez wskaźnik)
    istream& operator>>(istream & input, Point& p){
        CheckNextChar('(', &input);
        p.SetX(ReadNumber(&input));
        CheckNextChar(',', &input);
        IgnoreWhitespace(&input);
        p.SetY(ReadNumber(&input));
        CheckNextChar(')', &input);
        return input;      // Umożliwia cin >> a >> b >> c;
    }
    istream& operator>>(istream & output, Point& p){

    }
}