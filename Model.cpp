

//

//  Model.cpp

//  PA3

//

//  Created by Drew Boodhan on 11/24/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#include "Model.h"

#include <iostream>

#include "Person.h"

#include "Space_Station.h"

#include "Oxygen_Depot.h"

#include "Game_Object.h"

#include "Cart_Point.h"

#include "Input_Handling.h"

#include <stdlib.h>

#include <list>


using namespace std;

Model :: Model()

{

    time = 0;

    count_down = 10;

    person_ptrs.push_back(new Astronaut(1,Cart_Point(5,1)));

    person_ptrs.push_back(new Astronaut(2,Cart_Point(10,1)));

    depot_ptrs.push_back(new Oxygen_Depot(Cart_Point(1,20),1));

    depot_ptrs.push_back(new Oxygen_Depot(Cart_Point(10,20),2));

    station_ptrs.push_back( new Space_Station());

    station_ptrs.push_back(new Space_Station(Cart_Point(5,5),2));

    alien_ptrs.push_back(new Alien(1,Cart_Point(7,14)));

    alien_ptrs.push_back(new Alien(2, Cart_Point(7,5)));

    for(list<Person*>::iterator it=person_ptrs.begin(); it != person_ptrs.end(); it++)

    {

        object_ptrs.push_back(*it);

    }

    for(list<Oxygen_Depot*> :: iterator it=depot_ptrs.begin(); it!=depot_ptrs.end(); it++)

    {

        object_ptrs.push_back(*it);

    }

    for(list<Space_Station*> :: iterator it = station_ptrs.begin(); it!= station_ptrs.end(); it++)

    {

        object_ptrs.push_back(*it);

    }

    for(list<Alien*> :: iterator it = alien_ptrs.begin(); it!= alien_ptrs.end(); it++)

    {

        object_ptrs.push_back(*it);

    }

    active_ptrs=object_ptrs;

    

    cout << "Model default constructed " << endl;

    

}



Person*Model :: get_Person_ptr(int id)

{

    list<Person*>::iterator it;

    for ( it=person_ptrs.begin(); it!= person_ptrs.end(); it++ )

    {

         int x = (*it)->get_id();

        if(x==id)

        {

            return *it;

        }

    }

    

    return 0;

}

Oxygen_Depot*Model :: get_Oxygen_Depot_ptr(int id)

{

    list<Oxygen_Depot*>::iterator it;

    for (it = depot_ptrs.begin() ; it!= depot_ptrs.end(); it++)

    {

        int x = (*it) -> get_id();

        if(x==id)

        {

            return *it;

        }

    }

    return 0;

}


Space_Station*Model :: get_Space_Station_ptr(int id)

{

    list<Space_Station*> :: iterator it;

    for(it = station_ptrs.begin(); it != station_ptrs.end() ; it++)

    {

        int x = (*it) ->get_id();

        if(x==id)

        {

            return *it;

        }

    }

    return 0;

}


Alien* Model :: get_Alien_ptr(int id)

{

    list<Alien*> :: iterator it;

    for(it = alien_ptrs.begin(); it != alien_ptrs.end() ; it++)

    {

        int x = (*it) ->get_id();

        if(x==id)

        {

            return *it;

        }

    }

    return 0;

}

bool Model::update()

{

    time++;

    bool flag = false;

    if(count_down == 0)

    {

        

        cout << "You lose!" << endl;

        exit(0);

    }

    else

    {

        if((get_Space_Station_ptr(1)->get_state() == 'u') && (get_Space_Station_ptr(2)->get_state() == 'u'))

        {

            cout << "Ready for takeoff? " << count_down << "..." << endl;

            if((get_Space_Station_ptr(1)->get_astronauts() == 0) && (get_Space_Station_ptr(2)->get_astronauts() == 0))

            {

                cout << "Missing 2 astronauts!" << endl;

                count_down--;

            }

            else if((get_Space_Station_ptr(1)->get_astronauts() > 0) && (get_Space_Station_ptr(2)->get_astronauts() > 0))

            {

                cout << "Blast Off! You Win!" << endl;

                exit(0);

            }

            else if((get_Space_Station_ptr(1)->get_astronauts() == 0) && (get_Space_Station_ptr(2)->get_astronauts() == 1))

            {

                cout << "Missing 1 astronaut!" << endl;

                count_down--;

            }

            else if((get_Space_Station_ptr(1)->get_astronauts() == 1) && (get_Space_Station_ptr(2)->get_astronauts() == 0))

            {

                cout << "Missing 1 astronaut!" << endl;

                count_down--;

            }

        }

        

    }

    list<Game_Object*> :: iterator it;

    for(it = active_ptrs.begin(); it != active_ptrs.end() ; ++it)

    {

        flag = (*it)->update();

        if (flag == true)

        {

            return true;

        }

    }

    for(it = active_ptrs.begin(); it != active_ptrs.end() ; ++it)

    {

        if((*it) -> get_state() == 'x')

        {

            it = active_ptrs.erase(it);

            cout << "Dead Object Removed" <<endl;

        }

    }

    return flag;

}


    

    void Model :: display(View &view)

    {

        cout << "Time : " << time << endl;

        view.clear();

        list<Game_Object*> :: iterator it;

        

        for (it =active_ptrs.begin(); it != active_ptrs.end() ; it++)

        {

            if((*it)->get_state()!= 'x')

            {

            view.plot(*it);

            }

        }

        view.draw();

    }

    

    void Model ::  show_status()

    {

        list<Game_Object*> :: iterator it;

        for(it = object_ptrs.begin(); it != object_ptrs.end() ; it++)

        {

            (*it)->show_status();

        }

    }


void Model :: handle_new_command(char disp, int id, double x, double y)

{

    bool d_new= true;

    bool s_new=true;

    bool p_new=true;

    bool a_new=true;

    switch(disp)

    {

        case 'd':

        {

            list<Oxygen_Depot*>::iterator it;

            for(it=depot_ptrs.begin();it!=depot_ptrs.end(); it++)

            {

                d_new = (id != (*it)-> get_id());

            }

            if (d_new == true)

            {

                depot_ptrs.push_back(new Oxygen_Depot(Cart_Point(x,y),id));

                list<Oxygen_Depot*>:: iterator new_it = depot_ptrs.end();

                --new_it;

                active_ptrs.push_back(*new_it);

                object_ptrs.push_back(*new_it);

            }

            

            else

            {

                throw Invalid_Input("ID already in use");

            }

        }

            break;

        case 's':

            {

                list<Space_Station*>::iterator it;

                for(it = station_ptrs.begin();it!=station_ptrs.end(); it++)

                {

                    s_new = (id != (*it)-> get_id());

                }

                if (s_new == true)

                {

                    station_ptrs.push_back(new Space_Station(Cart_Point(x,y),id));

                    list<Space_Station*>:: iterator new_it = station_ptrs.end();

                    --new_it;

                    active_ptrs.push_back(*new_it);

                    object_ptrs.push_back(*new_it);

                }

                

                else

                {

            

                    throw Invalid_Input("ID already in use");

                }

            }

                break;

            case 'a':

                {

                    list<Person*>::iterator it;

                    for(it = person_ptrs.begin();it!=person_ptrs.end(); it++)

                    {

                        p_new = (id != (*it)-> get_id());

                    }

                    if (p_new == true)

                    {

                        person_ptrs.push_back(new Astronaut(id,Cart_Point(x,y)));

                        list<Person*>:: iterator new_it = person_ptrs.end();

                        --new_it;

                        active_ptrs.push_back(*new_it);

                        object_ptrs.push_back(*new_it);

                    }

                    

                    else

                    {

                        

                        throw Invalid_Input("ID already in use");

                    }

                }

            break;

        case 'x':

        {

            

            list<Alien*>::iterator it;

            for(it = alien_ptrs.begin();it!=alien_ptrs.end(); it++)

            {

                a_new = (id != (*it)-> get_id());

            }

            if (a_new == true)

            {

                alien_ptrs.push_back(new Alien(id,Cart_Point(x,y)));

                list<Alien*>:: iterator new_it = alien_ptrs.end();

                --new_it;

                active_ptrs.push_back(*new_it);

                object_ptrs.push_back(*new_it);

            }

            

            else

            {

                

                throw Invalid_Input("ID already in use");

            }

                

            

        }

    }

}

Model :: ~Model()

{

    list<Game_Object*>::iterator it;

    for( it = object_ptrs.begin() ; it!=object_ptrs.end(); it++)

    {

        delete(*it);

    }

    

    cout << "Model Destructed " << endl;

    

    

}

