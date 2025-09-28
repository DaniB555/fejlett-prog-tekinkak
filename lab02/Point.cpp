//
// Created by Danib on 9/24/2025.
//

#include "Point.h"
#include <iostream>
#include<cmath>
#include <set>
#include<fstream>
#include<time.h>
#include <algorithm>
#include <vector>
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
    ifstream ifs(filename);
    if(!ifs) {
       cout<<"fileNotFound";
        exit(1);
    }
    int x,y;
    Point points[4];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 4; ++j) {
            ifs>>x>>y;
            points[j]=Point(x,y);
        }
        if(isSquare(points[0],points[1],points[2],points[3])==1) cout<<"negyzet"<<endl;
        else cout<<"nem negyzet"<<endl;
    }
}

Point * createArray(int numPoints) {


    Point* array = new Point[numPoints];

    for (int i = 0; i < numPoints; ++i) {
        array[i]=Point(rand()%2001,rand()%2001);
    }
    return array;
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        cout<<points[i].getX()<<" "<<points[i].getY()<<endl;
    }
}

std::pair<Point, Point> closestPoints(Point *points, int numPoints) {
    pair<Point,Point> closest;
    double distancMin=INT_MAX;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i+1; j < numPoints; ++j) {
                if (dist(points[i],points[j])<distancMin) {
                    distancMin=dist(points[i],points[j]);
                    closest={points[i],points[j]};
                }
        }
    }
    return closest;
}

std::pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    pair<Point,Point> farthest;
    double distancMin=INT_MIN;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i+1; j < numPoints; ++j) {
            if (dist(points[i],points[j])>distancMin) {
                distancMin=dist(points[i],points[j]);
                farthest={points[i],points[j]};
            }
        }
    }
    return farthest;
}

void sortPoints(Point *points, int numPoints) {
    std::sort(points, points + numPoints, [](const Point& a, const Point& b) {
        return a.getX() < b.getX();
    });
}

/*
Point * farthestPointsFromOrigin(Point *points, int numPoints) {
    double tavolsag=0;
    Point array[10];
    int p=0;
    for (int i = 0; i < numPoints; ++i) {
        if (dist(points[i],Point(0,0))>tavolsag) {
            tavolsag=dist(points[i],Point(0,0));
           array[p]=points[i];
            p++;
        }
    }
    return array;
}*/
///ez meg nincs kesz