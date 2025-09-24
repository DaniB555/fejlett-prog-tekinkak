#include <iostream>
#include "Point.h"
#include <fstream>
using namespace std;


int main(int argc, char** argv) {
    Point p1(0,0);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(0, 2);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    //pp1->print();


    Point * sz1=new Point(3,5);
    Point * sz2=new Point(2,2);
    cout<<dist(p1,p2)<<endl;
    cout<<dist(*sz1,*sz2)<<endl;
    Point p3(2,0);
    Point p4(2,2);
    if(isSquare(p1,p2,p3,p4)==1) cout<<"negyzet"<<endl;
    else cout<<"nem negyzet"<<endl;


    testIsSquare("data/input.txt");
    delete sz1;
    delete sz2;
    delete pp1;
    delete pp2;
    return 0;
}
