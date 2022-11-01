//
//  ECTriangle.h
//  
<<<<<<< HEAD
=======
//
>>>>>>> b8ec8ebb35ed8f99b603bda34f8e4077636a55ec

#ifndef ECTriangle_h
#define ECTriangle_h

#include "ECLineSegment.h"
#include "ECAbstractConvexPolygon.h"

// -----------------------------------------------------------------------------
// Triangle on 2D plane

class ECTriangle : public ECAbstractConvexPolygon
{
public:
    ECTriangle(const EC2DPoint &p1, const EC2DPoint &p2, const EC2DPoint &p3);
    
    // Test if the polygon is convex? Return false if not
    virtual bool IsConvex() const;
    
    // Get area of the triangle
    virtual double GetArea() const;

private:
    
    // your code here if needed
};


#endif /* ECTriangle_h */
