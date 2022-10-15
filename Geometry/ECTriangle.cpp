//
//  ECTriangle.cpp
//  
#include "ECTriangle.h"
#include <cmath>
#include <vector>
using namespace std;

// your code goes here

ECTriangle::ECTriangle(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3): point1(p1), point2(p2), point3(p3), l1(p1, p2), l2(p2,p3), l3(p3,p1){}

double ECTriangle::GetArea() const{
    double a = l1.Length();
    double b = l2.Length();
    double c = l3.Length();

    double s = (a + b + c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool ECTriangle::IsPointInside(const EC2DPoint& pt) const{
    /*if(l1.PointIntersect(pt) || l2.PointIntersect(pt) || l3.PointIntersect(pt)){
        return true;
    }
    ECTriangle t1(point1, point2, pt);
    ECTriangle t2(point2, point3, pt);
    ECTriangle t3(point3, point1, pt);
    
    return fabs(GetArea() - (t1.GetArea() + t2.GetArea() + t3.GetArea())) < 0.0000000000001;*/
    double point1X = point1.GetX();
    double point1Y = point1.GetY();

    double point2X = point2.GetX();
    double point2Y = point2.GetY();

    double point3X = point3.GetX();
    double point3Y = point3.GetY();

    double ptX = pt.GetX();
    double ptY = pt.GetY();

    double num1 = (point1X * (point3Y - point1Y)) + ((ptY - point1Y) * (point3X - point1X)) - (ptX * (point3Y - point1Y));
    double den1 = ((point2Y - point1Y) * (point3X - point1X)) - ((point2X - point1X) * (point3Y - point1Y));

    double weight1 = num1/den1;

    double num2 = ptY - point1Y - (weight1 * (point2Y - point1Y));
    double den2 = point3Y - point1Y;

    double weight2 = num2/den2;

    return ((weight1 >= 0) && (weight2 >= 0) && (weight1 + weight2 <= 1)) || l1.PointIntersect(pt) || l2.PointIntersect(pt) || l3.PointIntersect(pt);
    
}

bool ECTriangle::IsContaining(const ECTriangle &rhs) const{
    return (IsPointInside(rhs.point1) && IsPointInside(rhs.point2) && IsPointInside(rhs.point3)); //|| (rhs.IsPointInside(point1) && rhs.IsPointInside(point2) && rhs.IsPointInside(point3));
}

bool ECTriangle::IsIntersecting(const ECTriangle &rhs) const{
    const ECTriangle thisTriangle(point1, point2, point3);
    if(IsContaining(rhs) || rhs.IsContaining(thisTriangle)){
        return true;
    }
    vector<const ECLineSegment*> t1LineSegments = {&l1, &l2, &l3};
    vector<const ECLineSegment*> t2LineSegments = {&rhs.l1, &rhs.l2, &rhs.l3};

    for(const ECLineSegment* t1 : t1LineSegments){
        for(const ECLineSegment* t2 : t2LineSegments){
            if((*t1).IsIntersect(*t2)){
                return true;
            }
        }
    }
    return false;
}
