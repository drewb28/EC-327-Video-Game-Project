//

//  View.hpp

//  PA3

//

//  Created by Drew Boodhan on 11/26/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#ifndef View_h

#define View_h


#include <stdio.h>

#include "Game_Object.h"

#include "Oxygen_Depot.h"

#include "Space_Station.h"

#include "Person.h"

#include "Astronaut.h"


#include "Cart_Point.h"


const int view_maxsize = 20;

class View

{

private:

    int size;

    double scale;

    Cart_Point origin;

    char grid[view_maxsize][view_maxsize][2];

    bool get_subscripts(int &ix, int &iy, Cart_Point location);

public:

    View();

    void clear();

    void plot(Game_Object * ptr);

    void draw();

    friend class Model;

    friend void Game_Object :: drawself(char*grid);

};


#endif /* View_hpp */
