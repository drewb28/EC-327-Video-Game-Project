//
//  Cart_Point.cpp
//  PA3
//
//  Created by Drew Boodhan on 11/10/17.
//  Copyright © 2017 Drew Boodhan. All rights reserved.
//

#include "Cart_Point.h"
#include <cmath>
#include <iostream>
using namespace std;

Cart_Point :: Cart_Point()
{
    x = 0;
    y = 0;
}
Cart_Point :: Cart_Point(double inputx, double inputy)
{
    x = inputx;
    y = inputy;
}
double cart_distance(Cart_Point p1 , Cart_Point p2)
{
    double x1=p1.x;
    double x2 = p2.x;
    double y1 = p1.y;
    double y2 = p2.y;
    double actx = abs(x2 - x1);
    double acty = abs(y2 - y1);
    double eqx = actx*actx;
    double eqy = acty*acty;
    double eqn = eqx + eqy;
    double answer = sqrt(eqn);
    return answer;
}

ostream& operator<<(ostream& c, Cart_Point &p1)
{
    c << '(' << p1.x << ", " << p1.y << ')' ;
    return c;
}

Cart_Point operator+(Cart_Vector v1,Cart_Point p1)
{
    double newx = v1.x + p1.x;
    double newy = v1.y + p1.y;
    Cart_Point output (newx,newy);
    return output;
}

Cart_Vector operator-(Cart_Point p1 , Cart_Point p2)
{
    double actx = p1.x - p2.x;
    double acty = p1.y - p2.y;
    Cart_Vector output (actx,acty);
    return output;
}

