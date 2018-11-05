//

//  Game_Command.cpp

//  PA3

//

//  Created by Drew Boodhan on 11/26/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#include "Game_Command.h"

#include "Game_Object.h"

#include "Oxygen_Depot.h"

#include "Space_Station.h"

#include "Person.h"

#include "Astronaut.h"

#include "Model.h"

#include "View.h"

#include "Input_Handling.h"

#include <stdlib.h>





void do_move_command(char display_code,Model&model, int id, double x, double y, View& view)

{

    if(display_code == 'a')

    {

    model.get_Person_ptr(id)->start_moving(Cart_Point(x,y));

    

    }

    

    else if(display_code=='x')

    {

        model.get_Alien_ptr(id)->start_moving(Cart_Point(x,y));

        

    }

    

}

void do_workadepot_command(Model& model,int id1, int id2, View& view)

{

    

    model.get_Person_ptr(id1)->start_supplying(model.get_Oxygen_Depot_ptr(id2));

    

    

}


void do_depositmoonstones_command(Model& model, int id1, int id2, View& view)

{

    

    model.get_Person_ptr(id1)->start_depositing(model.get_Space_Station_ptr(id2));

   

    

}


void do_stop_command(Model& model,int id1, View& view)

{

    

    cout << "A" << id1 << ":" << " " << "Stopped." << endl;

    Person*person;

    person = model.get_Person_ptr(id1);

    person->stop();

    

    

    

}

void do_lockinstation_command(Model& model,int id1, int id2, View& view)

{

    

    model.get_Person_ptr(id1)-> go_to_station(model.get_Space_Station_ptr(id2));

    

    

}


void do_go_command(Model& model, View& view)

{

    cout << "Advancing one tick" << endl;

    model.update();

    model.show_status();

    model.display(view);

    

}


void do_run_command(Model& model, View& view)

{

    cout << "Advancing to next event" << endl;

    bool up = false;

    int counter=0;

    while(!up && counter < 5)

    {

        up=model.update();

        counter++;

    }

    model.show_status();

    model.display(view);

    

}


void start_attacking_command(Model& model, int id1, int id2, View& view)

{

    model.get_Alien_ptr(id1) -> start_attack(model.get_Person_ptr(id2));

    

}

void do_quit_command(Model& model)

{

    cout << "Terminating Program" << endl;

    

    

}


int get_int()

{

        int i;

        if(!(cin >> i))

        {

            throw Invalid_Input("Need an integer");

        }

        return i;

}


double get_double()

{

    double i;

    if (!(cin>> i))

    {

        throw Invalid_Input("Need a double");

    }

    return i;

}


char get_new_command()

{

    char i;

    if(!(cin>>i))

    {

        throw Invalid_Input("Need a character");

    }

    else

    {

        if(i!='d'&& i!='s' && i!= 'x' && i!='a')

        {

            throw Invalid_Input("Please enter proper command");

            return i;

        }

    }

    return i;

}


void newcommand(Model& model,char display_code,int id,double x, double y, View& view )

{

    model.handle_new_command(display_code, id , x, y);

    model.display(view);

}
