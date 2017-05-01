//
// Created by bartek on 21.04.17.
//

#include "Point.h"


Point2D::Point2D(){
    std::cout<<"Konstruktor 2D" << std::endl;
    this->x = 0;
    this->y = 0;
}

Point2D::Point2D(double x, double y){
    std::cout<<"Konstruktor 2D" << std::endl;
    this->x = x;
    this->y = y;
}

Point2D::~Point2D(){
    std::cout<< "Destruktor Point2D" << std::endl;
}


double Point2D::Distance(const Point2D &other) const {
    double distance;
    distance = sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2) );
    return distance;
}

double Point3D::Distance(const Point3D &other) const {
    double distance;
    distance = sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2) + pow(other.z - this->z, 2) );
    return distance;
}

Point3D::Point3D() : Point2D(){
    std::cout<<"Konstruktor 3D" << std::endl;
    this->z = 0;
}

Point3D::Point3D(double x, double y, double z){
    std::cout<<"Konstruktor 3D" << std::endl;
    this->x = x;
    this->y = y;
    this->z = z;
}

Point3D::~Point3D(){
    std::cout<< "Destruktor Point3D" << std::endl;
};


std::ostream& operator<<(std::ostream &output, Point2D& p){
    output<<"(";
    output << p.x;
    output << ",";
    output << p.y;
    output<<")";
    return output;
}