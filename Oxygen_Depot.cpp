//  Oxygen_Depot.cpp

//  PA3

//

//  Created by Drew Boodhan on 11/15/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#include "Oxygen_Depot.h"

#include <iostream>

#include "Game_Object.h"

#include "Cart_Point.h"

using namespace std;

Oxygen_Depot :: Oxygen_Depot()

{

    amount_oxygen = 50;

    display_code = 'O';

    cout << id_num << endl;

    state = 'f';

    cout << "Oxygen_Default Constructed" << endl;

}

Oxygen_Depot :: Oxygen_Depot(Cart_Point inputLoc, int inputId)

{

    display_code = 'O';

    location.x = inputLoc.x;

    location.y = inputLoc.y;

    id_num = inputId;

    amount_oxygen = 50;

    cout << "Oxygen Depot Constructed" << endl;

}

bool Oxygen_Depot :: is_empty()

{

    if (amount_oxygen == 0)

    {

        return true;

    }

    else

    {

        return false;

    }

}

double Oxygen_Depot :: extract_oxygen(double amount_to_extract)

{

    if (amount_oxygen >= amount_to_extract)

    {

        amount_oxygen = amount_oxygen + amount_to_extract;

        return amount_to_extract;

    }

    else

    {

        amount_oxygen = 0;

        return amount_oxygen;

    }

}

bool Oxygen_Depot :: update()

{

    

    if (amount_oxygen == 0 && state != 'e' && display_code != 'o')

    {

        state = 'e';

        display_code = 'o';

        cout << "Oxygen Depot " << id_num << " has been depleted." << endl;

        return true;

    }

    else

    {

        return false;

    }

}

void Oxygen_Depot :: show_status()

{

    cout << "Oxygen Depot status: ";

    Game_Object :: show_status();

    cout  << "contains " << amount_oxygen << "." << endl;

}

Oxygen_Depot :: ~Oxygen_Depot()

{

    cout << "Oxygen_Depot Destructed" << endl;

}
