//
//  ECLineSegment.h
//  

#ifndef ECLineSegment_h
#define ECLineSegment_h
#define MIN(P1, P2)(((P1) < (P2)) ? P1 : P2
// -----------------------------------------------------------------------------
// Point on 2D plane
#include <string>
class EC2DPoint
{
public:
    EC2DPoint();//: cx(0), cy(0){}
    EC2DPoint(double x, double y);//: cx(x), cy(y){}
    EC2DPoint(const EC2DPoint& point);
    EC2DPoint& operator=(const EC2DPoint& point){
        if(&point == this) return *this;
        cx = point.cx;
        cy = point.cy;
        return *this;
    }
    EC2DPoint operator-(const EC2DPoint& point) const{
        EC2DPoint res(cx - point.cx, cy - point.cy);
        return res;
    }
    double operator*(const EC2DPoint& point){
        return (cx*point.cy) - (point.cx*cy);
    }
    bool operator==(const EC2DPoint& point) const{
        return (cx == point.cx) && (cy == point.cy);
    }
    double GetX() const;
    double GetY() const;
    std::string PointString() const;

private:
    // your code goes here
    double cx;
    double cy;
};

// -----------------------------------------------------------------------------
// Line segment on 2D plane

class ECLineSegment
{
public:
    ECLineSegment(const EC2DPoint &pStart, const EC2DPoint &pEnd);
    bool IsIntersect(const ECLineSegment &rhs) const;
    double Length() const;
    bool PointIntersect(const EC2DPoint &point) const;
    void SlopeFormula(double& m, double& b) const;
    int PointReference(const EC2DPoint& point) const; // returns 1 if to the right or above line, returns -1 if to the left or below line, 0 if part of line

private:
    EC2DPoint pS;
    EC2DPoint pE;
    double Direction(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const;
    bool OnSegment(const EC2DPoint &pi, const EC2DPoint &pj, const EC2DPoint &pk) const;
};


#endif /* ECLineSegment_h */
