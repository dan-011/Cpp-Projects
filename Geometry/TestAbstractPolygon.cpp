#include "ECConvexPolygon.h"
#include "ECTriangle.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int main(){
    EC2DPoint p1(0,0);
    EC2DPoint p2(0,1);
    EC2DPoint p3(1,1);
    EC2DPoint p4(1,0);
    EC2DPoint p5(0.5, 0.5);
    EC2DPoint p6(2, 2);

    EC2DPoint p7(0.25,0.25);
    EC2DPoint p8(0.25,0.75);
    EC2DPoint p9(0.75,0.75);
    EC2DPoint p10(0.75,0.25);
    vector<EC2DPoint> listNodes1 = {p1, p2, p3, p4};
    ECConvexPolygon poly1(listNodes1);

    vector<EC2DPoint> listNodes2 = {p7, p8, p9, p10};
    ECConvexPolygon poly2{listNodes2};

    EC2DPoint p11(0.5, 0);
    EC2DPoint p12(1.5, 0);
    EC2DPoint p13(1.5, 1);
    EC2DPoint p14(0.5, 1);
    vector<EC2DPoint> listNodes3 = {p11, p12, p13, p14};
    ECConvexPolygon poly3(listNodes3);

    EC2DPoint p15(5, 3);
    EC2DPoint p16(5, 0);
    EC2DPoint p17(8, 2);
    EC2DPoint p18(5, 3);
    vector<EC2DPoint> listNodes4 = {p15, p16, p17};
    ECTriangle tri1(p15, p16, p17);
    ECConvexPolygon poly4(listNodes4);

    assert(poly4.IsPointInside(p18));
    assert(tri1.IsPointInside(p18));

    EC2DPoint p19(3,2);
    EC2DPoint p20(5,2);
    EC2DPoint p21(9,0);
    EC2DPoint p22(3,0);
    EC2DPoint p23(0,2);
    vector<EC2DPoint> listNodes5 = {p19, p20, p21, p22};
    ECConvexPolygon poly5(listNodes5);

    assert(!poly5.IsPointInside(p23));
    assert(poly1.IsConvex());
    assert(poly1.IsPointInside(p5));
    assert(!poly1.IsPointInside(p6));
    assert(poly1.IsContaining(poly2));
    assert(!poly2.IsContaining(poly1));
    assert(poly1.IsIntersecting(poly2));
    assert(poly2.IsIntersecting(poly1));
    assert(poly1.IsIntersecting(poly3));
    assert(poly3.IsIntersecting(poly1));
    assert(fabs(poly1.GetArea() - poly3.GetArea()) < .0000000001);
    //assert(poly1.GetArea() == 1);
    return 0;
}