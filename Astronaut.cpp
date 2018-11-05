

//  PA3

//

//  Created by Drew Boodhan on 11/20/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#include "Astronaut.h"

#include "Person.h"

#include "Game_Object.h"

#include "Oxygen_Depot.h"

#include <iostream>

#include "Cart_Point.h"

#include "Cart_Vector.h"

using namespace std;

Astronaut :: Astronaut() : Person('A')

{

    amount_oxygen = 20;

    amount_moonstones = 0;

    depot = NULL;

    home = NULL;

    cout << "Astronaut default constructed" << endl;

}


Astronaut :: Astronaut(int in_id, Cart_Point in_loc) :Person(in_loc, in_id, 'A')

{

    amount_moonstones = 0;

    amount_oxygen = 20;

    depot = NULL;

    home = NULL;

    cout << "Astronaut constructed" << endl;

}


bool Astronaut :: update()

{

    /*if (amount_oxygen==0)

    {

        cout << "Im out of O2 "<< endl;

        state = 'x';

        return true;

    }*/

    if(health < 3)

    {

        /*int x;

         char y =display_code;

         x = int(y);

         int newx = x + 32;

         char t = char(newx);

         *///display_code = t;

        display_code = 'a';

    }

    switch (state)

    {

            

        case 's':

        {

            if (amount_oxygen==0)

            {

                cout << "Im out of O2 "<< endl;

                state = 'x';

                return true;

            }

            return false;

        }

        case 'm':

        {

            bool x = update_location();


            if (x == false)

            {

                if (amount_oxygen==0)

                {

                    cout << "Im out of O2 "<< endl;

                    state = 'x';

                    return true;

                }

                amount_moonstones = amount_moonstones+1;

                amount_oxygen--;

                //state = 's';

                return false;

            }

            else if (x==true)

            {

                state='s';

                return true;

            }

        }

        case 'o':

        {

            bool x = update_location();

            if (amount_oxygen==0)

            {

                cout << "Im out of O2 "<< endl;

                state = 'x';

                return true;

            }


            if (x == false)

            {

                

                //state = 'g';

                amount_moonstones = amount_moonstones+1;

                amount_oxygen--;

                return false;

            }

            else if (x==true)

            {

                state = 'g';

                return true;

            }

        }

        case 'g':

        {

            if (amount_oxygen==0)

            {

                cout << "Im out of O2 "<< endl;

                state = 'x';

                return true;

            }

            double amounte;

            

            amounte = depot -> extract_oxygen();

            amount_oxygen = amounte + amount_oxygen;

            cout << display_code << id_num << " Got: "<< amounte << " oxygen." <<endl;

            state = 's';

            return true;

        }

        case 'i':

        {

            bool x = update_location();

            if (amount_oxygen==0)

            {

                cout << "Im out of O2 "<< endl;

                state = 'x';

                return true;

            }

            if (x == false)

            {

                

                //state = 'd';

                amount_moonstones = amount_moonstones+1;

                amount_oxygen--;

                return false;

            }

            else if (x==true)

            {

                state = 'd';

                return true;

            }

        }

        case 'd':

        {

            if (amount_oxygen==0)

            {

                cout << "Im out of O2 "<< endl;

                state = 'x';

                return true;

            }

           

            home -> deposit_moonstones(amount_moonstones);

            cout << display_code << id_num << " Depositing " << amount_moonstones << " moonstones" << endl;

            amount_moonstones = 0;

            state = 's';

            return true;

            

        }

        case 'l':

        {

            bool x = update_location();

            if (amount_oxygen==0)

            {

                cout << "Im out of O2 "<< endl;

                state = 'x';

                return true;

            }

            if (x == false)

            {

                amount_moonstones = amount_moonstones+1;

                amount_oxygen--;

                

                //home -> add_astronaut();

                return false;

            }

            else if (x==true)

            {

                home -> add_astronaut();

                return true;

            }

        }

        case 'x':

        {

            return false;

        }

    }

    return false;

}





void Astronaut :: show_status()

{

    cout << "Astronaut Status: ";

    Person :: show_status();

    if (state == 's')

    {

        

        cout << "with "<< amount_oxygen << " " << "oxygen and " << amount_moonstones << " "  << "moon stones." << endl;

    }

    else if ( state == 'm')

    {

        cout << endl;

        

        //Person :: show_status();

    }

    else if ( state =='o')

    {

        

        cout << "is outbound to a Depot with " << amount_oxygen << " oxygen and " << amount_moonstones << " moonstones. " << endl;

    }

    else if (state == 'g')

    {

        

        cout << "getting oxygen from depot"<< endl;

    }

    else if (state == 'i')

    {

        

        cout << "is inbound to home with load: " << amount_moonstones << "moonstones" <<endl;

    }

    else if (state == 'd')

    {

        

        cout << "Deposting " << amount_moonstones << " moonstones"<< endl;

    }

    else if (state == 'l')

    {

        

        cout << "Out of oxygen"<< endl;

    }

}

void Astronaut ::  start_supplying(Oxygen_Depot* inputDepot)

{

    if (state == 'x')

    {

        cout << "I'm Dead" << endl;

        return;

    }

    depot=inputDepot;

    setup_destination(inputDepot -> get_location());

    state = 'o';

    cout << "Astronaut " << id_num << " supplying from Oxygen Depot" << inputDepot -> get_id() << endl;

    cout << display_code << id_num  << ": Yes, my lord " << endl;

}


void Astronaut :: start_depositing(Space_Station* inputStation)

{

    if (state == 'x')

    {

        cout << "I'm Dead" << endl;

        return;

    }

    home = inputStation;

    setup_destination(inputStation -> get_location());

    state = 'i';

    cout << "Astronaut " << id_num << " Depositing to Space Station " << inputStation -> get_id() << endl;

    cout << display_code << id_num << ": Yes, my lord " << endl;

}

void Astronaut :: go_to_station(Space_Station* inputStation)

{

    if (state == 'x')

    {

        cout << "I'm Dead" << endl;

        return;

    }

    home = inputStation;

    setup_destination(inputStation -> get_location());

    state = 'l';

    cout << "Astronaut " << id_num << "locking in at Space Station " << inputStation->get_id() << endl;

}

Astronaut :: ~Astronaut()

{

    cout << "Astronaut Destructed" << endl;

    

}

