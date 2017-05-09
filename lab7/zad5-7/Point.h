//
// Created by bartek on 21.04.17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <cmath>
#include <ostream>
#include <iostream>

class Point2D{
public:
    Point2D();
    Point2D(double x, double y);
    ~Point2D();

    double Distance(const Point2D &other) const;


    double x, y;
};


class Point3D : public Point2D{
public:
    Point3D();
    Point3D(double x, double y, double z);
    ~Point3D();

    double Distance(const Point3D &other) const;
private:
    double x,y,z;

};

std::ostream& operator<<(std::ostream &is, Point2D& point);


#endif //JIMP_EXERCISES_POINT_H

