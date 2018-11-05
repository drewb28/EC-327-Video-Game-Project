//

//  main.cpp

//  PA3

//

//  Created by Drew Boodhan on 11/8/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#include <iostream>

#include "Cart_Vector.h"

#include "Cart_Point.h"

#include "Game_Object.h"

#include "Oxygen_Depot.h"

#include "Space_Station.h"

#include "Person.h"

#include "Astronaut.h"

#include "Model.h"

#include "Game_Command.h"

#include "View.h"

#include "Input_Handling.h"

using namespace std;


int main() {

    

    cout<< "EC 327: Introduction to Software Engineering" << endl << "Fall 2017" << endl << "Programming Assignment 3" << endl;

    

    View view;

    Model model;

    char c;

    model.show_status();

    model.display(view);

    while(c!='q')

    {

        cout << "Enter Command: ";

        cin >> c;

        try{

        switch(c)

        {

            case 'm':

            {

                char display_code;

                int id = get_int();

                double x = get_double();

                double y = get_double();

                cout << "Move Astronaut (enter 'a') or Alien (enter 'x'):";

                cin >> display_code;

                do_move_command(display_code,model,id,x,y,view);

            }

                break;

            case 'w' :

            {

                int id1= get_int();

                int id2 = get_int();

                do_workadepot_command(model,id1,id2,view);

                

            }

                break;

            case 'd' :

            {

                int id1 = get_int();

                int id2 = get_int();

                do_depositmoonstones_command(model,id1,id2,view);

                

            }

                break;

            case 's':

            {

                int id1= get_int();

                do_stop_command(model,id1,view);

                

            }

                break;

            case 'l':

            {

                int id1 = get_int();

                int id2 = get_int();

                do_lockinstation_command(model,id1,id2,view);

                

            }

                break;

            case 'a':

            {

                int id1 = get_int();

                int id2 = get_int();

                start_attacking_command(model, id1, id2, view);

            }

                break;

            case 'g':

            {

                do_go_command(model,view);

                

            }

                break;

            case 'r':

            {

                do_run_command(model,view);

                

            }

                break;

            case 'n':

            {

                char disp = get_new_command();

                int id1 = get_int();

                double x = get_double();

                double y = get_double();

                newcommand(model,disp,id1,x,y,view);

            }

                break;

            case 'q':

            {

                do_quit_command(model);

                

            }

                break;

                

            default:

            {

                throw Invalid_Input("Invalid Entry, Please Enter a viable command");

            }

        }

        }

            catch(Invalid_Input& except)

            {

                cout << "Invalid input - " << except.msg_ptr << endl;

                cin.clear();

            }

        }

    }



