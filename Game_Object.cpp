//

//  Game_Object.cpp

//  PA3

//

//  Created by Drew Boodhan on 11/10/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//

#include <iostream>

#include "Game_Object.h"

#include "Cart_Point.h"

#include "Cart_Vector.h"

using namespace std;

Game_Object :: Game_Object(char in_code)

{

    display_code = in_code;

    id_num = 1;

    state = 's';

    cout << "Game_Object constructed" << endl;

}


Game_Object :: Game_Object(Cart_Point in_loc, int in_id, char in_code)

{

    state='s';

    display_code = in_code;

    id_num = in_id;

    double x = in_loc.x;

    double y = in_loc.y;

    location.x = x;

    location.y = y;

    cout << "Game_Object constructed" << endl;

}

Cart_Point Game_Object :: get_location()

{

    return location;

    

}

int Game_Object :: get_id()

{

    int x = id_num;

    return x;

    

}


char Game_Object :: get_state()

{

    char x = state;

    return x;

}


void Game_Object :: show_status()

{

    cout  << display_code <<  id_num << " at location " <<  location << " " ;

    return;

}

void Game_Object :: drawself(char * ptr)

{

    *ptr = display_code;

    *(1+ptr) = '0' + id_num;

    

}




Game_Object :: ~Game_Object()

{

    cout << "Game_Object destructed" << endl;

}
