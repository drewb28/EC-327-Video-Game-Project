//
//  Cart_Vector.cpp
//  PA3
//
//  Created by Drew Boodhan on 11/8/17.
//  Copyright © 2017 Drew Boodhan. All rights reserved.
//
#include <iostream>
#include "Cart_Vector.h"
#include<cmath>
using namespace std;

Cart_Vector :: Cart_Vector()
{
    x = 0;
    y = 0;
}
Cart_Vector :: Cart_Vector (double inputx, double inputy)
{
    x = inputx;
    y = inputy;
}
Cart_Vector operator*(Cart_Vector v1 , double d)
{
    double actx = v1.x * d;
    double acty = v1.y * d;
    Cart_Vector output(actx,acty);
    return output;
}
Cart_Vector operator/(Cart_Vector v1 , double d)
{
    if (d==0)
    {
        return v1;
    }
    double actx = v1.x/d;
    double acty = v1.y/d;
    Cart_Vector output(actx, acty);
    return output;
}
ostream& operator<<(ostream& c, Cart_Vector &v1)
{
    c << '<'<< v1.x << ", " << v1.y << '>';
    return c;
}



