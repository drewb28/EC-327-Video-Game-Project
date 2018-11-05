//

//

//  Model.hpp

//  PA3

//

//  Created by Drew Boodhan on 11/24/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#ifndef Model_h

#define Model_h


#include <stdio.h>

#include <iostream>

#include "Game_Object.h"

#include "Astronaut.h"

#include "Person.h"

#include "Oxygen_Depot.h"

#include "Space_Station.h"

#include "View.h"

#include "Alien.h"

#include <list>

using namespace std;

class Model

{

    

private:

    int time;

    int count_down;

    list<Game_Object*> object_ptrs;

    list<Game_Object*> active_ptrs;

    list<Person*>person_ptrs;

    list<Oxygen_Depot*>depot_ptrs;

    list<Space_Station*>station_ptrs;

    list<Alien*>alien_ptrs;

    //Game_Object*object_ptrs[10];

    //int num_objects;

    //Person*person_ptrs[10];

    //int num_persons;

    //Oxygen_Depot*depot_ptrs[10];

    //int num_depots;

    //Space_Station*station_ptrs[10];

    //Alien*alien_ptrs[10];

    //int num_stations;

    //int num_aliens;

    

public:

    Model();

    ~Model();

    Person * get_Person_ptr(int id);

    Oxygen_Depot * get_Oxygen_Depot_ptr(int id);

    Space_Station * get_Space_Station_ptr(int id);

    Alien*get_Alien_ptr(int id);

    bool update();

    void display(View& view);

    void show_status();

    void handle_new_command(char disp, int id, double x, double y);

};


#endif /* Model_hpp */
