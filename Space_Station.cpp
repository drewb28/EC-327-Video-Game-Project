//

//  Space_Station.cpp

//  PA3

//

//  Created by Drew Boodhan on 11/15/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#include "Space_Station.h"

#include "Oxygen_Depot.h"

#include <iostream>

#include "Game_Object.h"

#include "Cart_Point.h"

#include "Cart_Vector.h"

using namespace std;

Space_Station :: Space_Station()

{

    amount_moonstones=0;

    id_num=1;

    number_astronauts=0;

    display_code='s';

    state = 'o';

    cout << "Space_Station default Constructed"<<endl;

}


Space_Station :: Space_Station(Cart_Point inputLoc, int inputId)

{

    display_code = 's';

    location.x = inputLoc.x;

    location.y = inputLoc.y;

    id_num = inputId;

    state = 'o';

    cout << "Space_Station constructed"<<endl;

}


void Space_Station :: deposit_moonstones(double deposit_amount)

{

    double x =deposit_amount + amount_moonstones;

    amount_moonstones = x;

    return;

}


bool Space_Station :: add_astronaut()

{

    if (state == 'u')

    {

        number_astronauts = number_astronauts + 1;

        return true;

    }

    else

    {

        return false;

    }

    

}


int Space_Station :: get_astronauts()

{

    return number_astronauts;

}


bool Space_Station :: update()

{

    if (amount_moonstones >= 10 && state != 'u')

    {

        state = 'u';

        display_code = 'S';

        cout << display_code << id_num << " has been upgraded." << endl;

        return true;

    }

    else

    {

        return false;

    }

    

}


void Space_Station :: show_status()

{

    cout << "Space Station status: ";

    Game_Object :: show_status();

    Space_Station :: update();

    cout << " contains " << amount_moonstones << " moonstones and contains " << number_astronauts << " astronauts.";

    

    if(state=='u')

    {

        cout << "Upgraded." << endl;

    }

    else

        cout << "Not yet upgraded." << endl;

}


Space_Station :: ~Space_Station()

{

    cout << "Space Station Destructed" << endl;

}
