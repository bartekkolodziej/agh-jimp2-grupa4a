//
// Created by kolobart on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <cmath>
#include <ostream>
#include <iomanip>
#include <iostream>


using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;


namespace geometry{
    class Point {
    public:
        //Konstruktor bezparametrowy
        Point();
        //Konstruktor parametrowy
        Point(double x, double y);
        //Destruktor wykonywany przed zwolnieniem pamięci
        ~Point();

        //Metody nie modyfikujące stanu obiektu (const na końcu metody)
        //nie mogą zmodyfikować tego obiektu.
        void ToString(std::ostream *out) const;
        double Distance(const Point &other) const;



        void SetX(double x);
        void SetY(double y);

        double x_, y_;
    };



    std::istream& operator>>(std::istream &is, Point& point);
    std::ostream& operator<<(std::ostream &is, Point& point);


}

#endif //JIMP_EXERCISES_SQUARE_H
