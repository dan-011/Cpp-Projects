//
//  ECLineSegment.cpp
//  
#include "ECLineSegment.h"
#include <cmath>
#include <algorithm>

#include <string>
#include <iostream>
#include <string.h>
using namespace std;

// -----------------------------------------------------------------------------
// Point on 2D plane
EC2DPoint::EC2DPoint(): cx(0), cy(0){}
EC2DPoint::EC2DPoint(double x, double y): cx(x), cy(y){}
EC2DPoint::EC2DPoint(const EC2DPoint& point): cx(point.cx), cy(point.cy){}
double EC2DPoint::GetX() const{
    return cx;
}
double EC2DPoint::GetY() const{
    return cy;
}
std::string EC2DPoint::PointString() const{
    string str = "";
    str += "(";
    str += to_string(cx);
    str += ",";
    str += to_string(cy);
    str += ")";
    return str;
}


// your code goes here

// -----------------------------------------------------------------------------
// Line segment on 2D plane

// your code goes here
ECLineSegment::ECLineSegment(const EC2DPoint &pStart, const EC2DPoint &pEnd): pS(pStart), pE(pEnd){}

bool ECLineSegment::OnSegment(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const{
    return (min(pi.GetX(), pj.GetX()) <= pk.GetX()) && (pk.GetX() <= max(pi.GetX(), pj.GetX())) && (min(pi.GetY(), pj.GetY()) <= pk.GetY()) && (pk.GetY() <= max(pi.GetY(), pj.GetY()));
}
double ECLineSegment::Direction(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const{
    return (pk - pi)*(pj - pi);
}
bool ECLineSegment::IsIntersect(const ECLineSegment &rhs) const{
    EC2DPoint p1 = pS;
    EC2DPoint p2 = pE;
    EC2DPoint p3 = rhs.pS;
    EC2DPoint p4 = rhs.pE;

    double d1 = Direction(p3, p4, p1);
    double d2 = Direction(p3, p4, p2);
    double d3 = Direction(p1, p2, p3);
    double d4 = Direction(p1, p2, p4);
    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))){
        return true;
    }
    else if(d1 == 0 && OnSegment(p3, p4, p1)){
        return true;
    }
    else if(d2 == 0 && OnSegment(p3, p4, p2)){
        return true;
    }
    else if(d3 == 0 && OnSegment(p1, p2, p3)){
        return true;
    }
    else if(d4 == 0 && OnSegment(p1, p2, p4)){
        return true;
    }
    else{
        return false;
    }
}

double ECLineSegment::Length() const{
    // square root of (square(x2 - x1) + square(y2 - y1))
    double x1 = pS.GetX();
    double y1 = pS.GetY();
    double x2 = pE.GetX();
    double y2 = pE.GetY();

    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

void ECLineSegment::SlopeFormula(double& m, double& b) const{
    double x1 = pS.GetX();
    double y1 = pS.GetY();
    double x2 = pE.GetX();
    double y2 = pE.GetY();

    double dy = y2 - y1;
    double dx = x2 - x1;

    if(dx == 0) throw string("Vertical Line");
    else{
        m = dy/dx;
        b = y1 - (m * x1);
    }
}

bool ECLineSegment::PointIntersect(const EC2DPoint& point) const{
    double m;
    double b;
    try{
        SlopeFormula(m, b);
        return point.GetY() == ((m*point.GetX()) + b);
    }
    catch(string e){
        double x1 = pS.GetX();
        double y1 = pS.GetY();
        double y2 = pE.GetY();
        double px = point.GetX();
        double py = point.GetY();
        if(y2 < y1){
            return px == x1 && py <= y1 && py >= y2;
        }
        else{
            return px == x1 && py >= y1 && py <= y2;
        }
    }
}

int ECLineSegment::PointReference(const EC2DPoint& point) const{ // returns 1 if to the right or above line, returns -1 if to the left or below line, 0 if part of line
    double m;
    double b;
    double x = point.GetX();
    double y = point.GetY();
    try{
        SlopeFormula(m, b);
        // if mx + b < y - the point (x,y) is above the line: return 1
        // if mx + b > y - the point (x,y) is below the line: return -1
        // else return 0
        if(((m*x) + b) < y){
            return 1;
        }
        else if(((m*x) + b) > y){
            return -1;
        }
        else{
            return 0;
        }
    }
    catch(string err){
        // if x > line.pS.GetX() the point is to the right so return 1
        // if x < line.pS.GetX() the point is to the left so return -1
        // else return 0
        if(x > pS.GetX()){
            return 1;
        }
        else if(x < pS.GetY()){
            return -1;
        }
        else{
            return 0;
        }
    }
}
