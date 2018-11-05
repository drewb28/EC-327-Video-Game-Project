//  PA3

//

//  Created by Drew Boodhan on 11/20/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#ifndef Astronaut_h

#define Astronaut_h


#include <stdio.h>

#include <iostream>

#include "Person.h"

#include "Oxygen_Depot.h"

#include "Space_Station.h"

class Astronaut : public Person{

private:

    double amount_moonstones;

    double amount_oxygen;

    Oxygen_Depot* depot;

    Space_Station* home;

    

public:

    Astronaut();

    Astronaut(int in_id, Cart_Point in_loc);

    bool update();

    void show_status();

    void start_supplying(Oxygen_Depot* inputDepot);

    void start_depositing(Space_Station* inputStation);

    void go_to_station(Space_Station* inputStation);

    ~Astronaut();

    

};

#endif /* Astronaut_hpp */
