//

//  Person.cpp

//  PA3

//

//  Created by Drew Boodhan on 11/19/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#include "Person.h"

#include "Game_Object.h"

#include "Oxygen_Depot.h"

#include "Space_Station.h"

#include "Cart_Point.h"

#include <iostream>

#include <math.h>

#include <cmath>

using namespace std;

Person :: Person()

{
  health = 5;
    speed = 5;

    cout << "Person default constructed"<<endl;

}


Person :: Person( char in_code)

{

  health = 5;
    speed = 5;

    cout << " Person constructed " << endl;

    state = 's';

    display_code = in_code;

}


Person :: Person(Cart_Point in_loc, int in_id, char in_code) : Game_Object(in_loc, in_id, in_code)

{
	health = 5;
    speed=5;

    cout << "Person Constructed" << endl;

}

void Person :: setup_destination(Cart_Point dest)

{

    destination = dest;

    if (cart_distance(destination,location)==0)

    {

        cout << "I'm already there, see?" << endl;

    }

    else

    {

        delta = (destination - location) * (speed / cart_distance(destination, location));

    }

}

void Person :: start_moving(Cart_Point dest)

{

    if(state =='x')

    {

        Game_Object:: show_status();

        cout << "is dead." <<endl;

        return;

    }

    else

    {

    setup_destination(dest);

    state = 'm';

    cout << "Moving" << " " << id_num << " to " << destination << endl;

    cout << display_code << id_num << ": On My Way." << endl;

    return;

    }

}


void Person :: stop()

{

    if(state =='x')

    {

        Game_Object:: show_status();

        cout << "is dead." << endl;

        return;

    }

    else

    {

    state = 's';

    cout << "Stopping " << id_num << endl;

    cout << display_code << id_num << " : All Right" << endl;

    }

}


void Person :: show_status()

{

    Game_Object :: show_status();

    if (state == 's')

    {

        

        cout << "is stopped" << " " ;

        cout << "with health " << health << " ";

    }

    else if (state == 'l')

    {

        

        cout << "is locked" << " ";

        cout << "with health " << health << " ";

    }

    else if(state == 'x')

    {

        cout << "is dead" << endl;

    }

    else

    {

        

        cout << "moving at a speed of " << speed << " towards " << destination << " at each step of " << delta << " " ;

        

        

    }

    

}


bool Person :: update_location()

{

    Cart_Point location1 = Game_Object :: get_location();

    if(fabs(destination.y-location1.y)<=fabs(delta.y) && fabs(destination.x-location1.x) <= fabs(delta.x))

    {

        cout << display_code << id_num << ": I'm there!" << endl;

        location = destination;

        return true;

    }

    

    else if(delta.y == 0 && delta.x==0)

    {

        cout << "I'm already there, see?" << endl;

    }

    

    else

    {

        location = delta + location;

        cout << display_code << id_num << ": step..." << endl;

        return false;

    }

    return false;

}


void Person :: start_supplying(Oxygen_Depot*inputDepot)

{

    if(state =='x')

    {

        Game_Object:: show_status();

        cout << "is dead.";

        return;

    }

    cout << "Sorry I cant work a depot" << endl;


}


void Person :: go_to_station(Space_Station*inputStation)

{

    if(state =='x')

    {

        Game_Object:: show_status();

        cout << "is dead.";

        return;

    }

    cout << "Sorry, I can’t lock into a station" << endl;

}


void Person :: start_depositing(Space_Station*inputStation)

{

    if(state =='x')

    {

        Game_Object:: show_status();

        cout << "is dead." << endl;

        return;

    }

    cout << "Sorry, I can’t work a station" << endl;

}


bool Person :: is_alive()

{

    if(state=='x')

    {

        return false;

    }

    else

    {

        return true;

    }

}


void Person :: take_hit(int attack_strength)

{

    health = health - attack_strength;

    if(health <= 0)

    {

        cout << display_code << get_id() << ": Gasp!" << endl;

        state = 'x';

    }

    else

    {

        cout << display_code << get_id() << ": Ouch!" << endl;

    }

}

Person :: ~Person()

{

    cout << "Person Destructed"<< endl;

}
