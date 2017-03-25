//
// Created by kolobart on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <cmath>
#include <ostream>

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

        double GetX() const;
        double GetY() const;

        void SetX(double x);
        void SetY(double y);

        double x_, y_;
    };


    class Square{
    private:
        Point A_, B_, C_, D_;
    public:
        //Konstruktor parametrowy
        Square(Point A, Point B, Point C, Point D );
        //Destruktor
        ~Square();

        double Area(Point a, Point b);
        double Circumference(Point a, Point b, Point c, Point d);


        double GetA() const;
        double GetB() const;
        double GetC() const;
        double GetD() const;

        void SetA(double A);
        void SetB(double B);
        void SetC(double C);
        void SetD(double D);
    };




}

#endif //JIMP_EXERCISES_SQUARE_H