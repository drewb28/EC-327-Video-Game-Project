//
//  Cart_Point.hpp
//  PA3
//
//  Created by Drew Boodhan on 11/10/17.
//  Copyright © 2017 Drew Boodhan. All rights reserved.
//

#ifndef Cart_Point_h
#define Cart_Point_h
#include <iostream>
#include <stdio.h>
#include "Cart_Vector.h"
using namespace std;
class Cart_Point
{
public:
    double x,y;
    Cart_Point();
    Cart_Point(double,double);
    friend ostream& operator<<(ostream& c, Cart_Point &p1);
};

double cart_distance(Cart_Point p1 , Cart_Point p2);
Cart_Point operator+(Cart_Vector v1 , Cart_Point p1);
Cart_Vector operator-(Cart_Point p1 , Cart_Point p2);

#endif /* Cart_Point_hpp */
