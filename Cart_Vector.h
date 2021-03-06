//
//  Cart_Vector.hpp
//  PA3
//
//  Created by Drew Boodhan on 11/8/17.
//  Copyright © 2017 Drew Boodhan. All rights reserved.
//

#ifndef Cart_Vector_h
#define Cart_Vector_h
#include <iostream>
#include <stdio.h>
using namespace std;

class Cart_Vector
{
public:
    double x,y;
    Cart_Vector();
    Cart_Vector(double,double);
    friend ostream& operator<<(ostream& c, Cart_Vector &v1);
};


Cart_Vector operator*(Cart_Vector  v1 , double d);
Cart_Vector operator/(Cart_Vector  v1 , double d);


#endif /* Cart_Vector_hpp */
