//

//  Alien.hpp

//  PA3

//

//  Created by Drew Boodhan on 12/3/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#ifndef Alien_h

#define Alien_h

#include "Cart_Point.h"

#include "Person.h"

#include "Cart_Vector.h"

#include <stdio.h>

class Alien : public Game_Object

{

private:

    int attack_strength;

    double range;

    Person*target;

    double speed;

    Cart_Point destination;

    Cart_Vector delta;

protected:

    void setup_destination(Cart_Point dest);

    bool update_location();

public:

    Alien();

    Alien(int in_id,Cart_Point in_loc);

    void start_attack(Person * in_target);

    bool update();

    void show_status();

    void start_moving(Cart_Point dest);

    void stop();

};

#endif /* Alien_hpp */
