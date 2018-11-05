//

//  Created by Drew Boodhan on 11/26/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#include "View.h"

#include "Game_Command.h"

#include "Game_Object.h"

#include "Oxygen_Depot.h"

#include "Space_Station.h"

#include "Person.h"

#include "Astronaut.h"

#include "Model.h"


bool View :: get_subscripts(int &ix, int &iy, Cart_Point location)

{

    ix=(location.x - origin.x)/scale ;

    iy = (location.y - origin.y)/scale;

    if(ix>size || iy>size)

    {

        cout << "An object is outside the display." << endl;

        return false;

    }

    else

    {

        return true;

    }

    

}


View::View()

{

    size = 11;

    scale = 2;

    origin.x = 0;

    origin.y = 0;

    

}



void View::clear()

{

    for (int i = 0; i < view_maxsize; i++)

    {

        for (int j = 0; j < view_maxsize; j++)

        {

            grid[i][j][0] = '.';

            grid[i][j][1] = ' ';

        }

    }

}


void View::plot(Game_Object* ptr)

{

    int ix = 0;

    int iy = 0;

    if (get_subscripts(ix, iy, ptr->get_location()))

    {

        if(grid[ix][iy][0] == '.')

        {

            ptr->drawself(grid[ix][iy]);

        }

        else

        {

            grid[ix][iy][0]='*';

            grid[ix][iy][1]=' ';

        }

    }

}


void View::draw()

{

    int x = view_maxsize/2;

    int ga[x + 1];

    for (int i = 0; i < x; i++)

    {

        ga[i] = 2*i;

    }

    ga[x] = view_maxsize;

    

    for (int i = size -1; i >= 0; i--)

    {

        if (i%2 == 0)

        {

            cout << ga[i];

            if (ga[i] < 10)

            {

                cout << " ";

            }

        }

        else

        {

            cout << "  ";

        }

        

        

        for (int j = 0 ; j < size; j++)

        {

            cout << grid[j][i][0];

            cout << grid[j][i][1];

            

        }

        cout << endl;

    }

    cout << "  ";

    

    

    for (int i = 0; i <= size; i++)

    {

        if (i%2 == 0)

        {

            cout << ga[i];

            if (ga[i] < 10)

            {

                cout << " ";

            }

        }

        else

        {

            cout << "  ";

        }

    }

    cout << endl;

}
