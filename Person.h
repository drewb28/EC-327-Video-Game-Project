//

//  Person.hpp

//  PA3

//

//  Created by Drew Boodhan on 11/19/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#ifndef Person_h

#define Person_h
#include <iostream>

#include <stdio.h>

#include "Game_Object.h"

#include "Space_Station.h"

#include "Cart_Point.h"

#include "Cart_Vector.h"

#include "Oxygen_Depot.h"



class Person : public Game_Object {

friend class Alien;

private:

    double speed;

    Cart_Point destination;

    Cart_Vector delta;

protected:

    bool update_location();

    void setup_destination(Cart_Point dest);

    int health;

public:

    Person();

    Person(char in_code);

    Person(Cart_Point in_loc, int in_id, char in_code);

    void start_moving(Cart_Point dest);

    void stop();

    void show_status();

    virtual void start_supplying(Oxygen_Depot*inputDepot);

    virtual void start_depositing(Space_Station*inputStation);

    virtual void go_to_station(Space_Station*inputStation);

    virtual bool is_alive();

    void take_hit(int attack_strength);

    virtual ~Person();

};

#endif /* Person_hpp */
