//

//  Input_Handling.hpp

//  PA3

//

//  Created by Drew Boodhan on 12/9/17.

//  Copyright © 2017 Drew Boodhan. All rights reserved.

//


#ifndef Input_Handling_h

#define Input_Handling_h


#include <stdio.h>

class Invalid_Input

{

    public :

    Invalid_Input (char * in_ptr) : msg_ptr (in_ptr) { }

    const char * const msg_ptr;

    private :

    Invalid_Input ( ) ; // no default construction

};

#endif /* Input_Handling_hpp */
