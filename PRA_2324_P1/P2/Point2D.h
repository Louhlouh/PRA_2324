#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D{
    public:
        double x, y; //declaración

        Point2D(double x = 0, double y = 0); //constructor

        static double distance(const Point2D &a, const Point2D &b); //calcula distancia euclidiana
        bool operator==(const Point2D &other) const; //comprueba si son iguales
        bool operator!=(const Point2D &other) const; //comprueba si son diferentes
        friend std::ostream& operator<<(std::ostream &out, const Point2D &p); //imprime
};

#endif
