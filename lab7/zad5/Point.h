//
// Created by bartek on 21.04.17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <cmath>
#include <ostream>

class Point {
public:
    Point();
    Point(double x, double y);
    ~Point();

    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;

private:
    double x_, y_;
};


class

#endif //JIMP_EXERCISES_POINT_H

