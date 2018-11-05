//

//  Oxygen_Depot.hpp

//  PA3

//

//  Created by Drew Boodhan on 11/15/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#ifndef Oxygen_Depot_h

#define Oxygen_Depot_h

#include <iostream>

#include <stdio.h>

#include "Cart_Point.h"

#include "Game_Object.h"

class Oxygen_Depot : public Game_Object{

private:

    double amount_oxygen;

public:

    Oxygen_Depot();

    Oxygen_Depot(Cart_Point inputLoc, int inputId);

    bool is_empty();

    double extract_oxygen(double amount_to_extract = 20.0);

    bool update();

    void show_status();

    ~Oxygen_Depot();

};

#endif /* Oxygen_Depot_hpp */
