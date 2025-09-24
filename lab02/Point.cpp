//
// Created by Danib on 9/24/2025.
//

#include "Point.h"
#include <iostream>
#include<cmath>
#include <set>
using namespace std;
Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    }
    else {
        this->x = 0;
        this->y = 0;
 }
}
int Point::getX() const {
 return x;
}
int Point::getY() const {
 return y;
}

void Point::print() const {
    std::cout<<x<<","<<y<<std::endl;
}

double dist(const Point &a, const Point &b) {
    return sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    set<double>distances;
    distances.insert(dist(a,b));
    distances.insert(dist(a,c));
    distances.insert(dist(a,d));
    distances.insert(dist(b,c));
    distances.insert(dist(b,d));
    distances.insert(dist(c,d));
    if (distances.size()==2) return true;
    return false;
}

void testIsSquare(const char *filename) {
    if(!filename) {
       cout<<"fileNotFound";
        exit(1);
    }
    int x,y;
    Point points[40][40];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            *filename>>x>>y;
        }
        if(isSquare(points[i][0],points[i][1],points[i][2],points[i][3])==1) cout<<"negyzet"<<endl;
        else cout<<"nem negyzet"<<endl;
    }
}
