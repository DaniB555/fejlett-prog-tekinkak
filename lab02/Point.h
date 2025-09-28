//
// Created by Danib on 9/24/2025.
//

#ifndef POINT_H
#define POINT_H
#include <utility>


class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;


};
double dist(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point&d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);

std::pair<Point, Point> closestPoints(Point* points, int numPoints);
std::pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);



#endif //POINT_H
