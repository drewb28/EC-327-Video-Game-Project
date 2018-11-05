//

//  Game_Command.hpp

//  PA3

//

//  Created by Drew Boodhan on 11/26/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#ifndef Game_Command_h

#define Game_Command_h

#include "Model.h"

#include "View.h"

void do_move_command(char display_code,Model& model, int id, double x, double y, View& view);

void do_workadepot_command(Model& model,int id1, int id2, View& view);

void do_depositmoonstones_command(Model& model, int id1, int id2, View& view);

void do_stop_command(Model& model,int id1, View& view);

void do_lockinstation_command(Model& model,int id1, int id2, View& view);

void start_attacking_command(Model& model, int id1, int id2, View& view);

void do_go_command(Model& model,View& view);

void do_run_command(Model& model, View& view);

void do_quit_command(Model& model);

int get_int();

double get_double();

char get_new_command();

void newcommand(Model&model,char display_code,int id,double x, double y, View& view);


#endif /* Game_Command_hpp */
