//

//  Game_Object.hpp

//  PA3

//

//  Created by Drew Boodhan on 11/10/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#ifndef Game_Object_h

#define Game_Object_h

#include "Cart_Point.h"

#include <iostream>


#include <stdio.h>


class Game_Object

{

    friend class Model;

protected:

    Cart_Point location;

    int id_num;

    char display_code;

    char state;

public:

    Game_Object() {};

    Game_Object(char in_code);

    Game_Object(Cart_Point in_loc, int in_id, char in_code);

    Cart_Point get_location();

    int get_id();

    char get_state();

    virtual void show_status();

    virtual bool update()=0;

    void drawself(char * ptr);

    virtual ~Game_Object();

};

#endif
