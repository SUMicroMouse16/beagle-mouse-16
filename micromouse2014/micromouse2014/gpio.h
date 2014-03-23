//
//  gpio.h
//  Test
//
//  Created by Lyle Moffitt on 3/19/14.
//  Copyright (c) 2014 Lyle Moffitt. All rights reserved.
//

#ifndef __Test__gpio__
#define __Test__gpio__

#include <iostream>
#include <string>
#include <array>

#include "device.cpp"
//#include "device.h"

class gpio;
class encoder;

namespace gpio_config
{
    //static const char* 
    static const auto path_ls =
    {
        "/sys/class/gpio/gpio69/",
        "/sys/class/gpio/gpio74/"
    };

    static const auto attr_ls =
    {
        "direction",    // 'in' -or- 'out'
        "value"         // '1'  -or- '0'
    };
};

struct gpio : device_dir
{
//    device_dir device;
        
#define make_getter_setter(name, type, i)           \
type name(){    return (*this)[#name].gt<i>();  }   \
void name(type val){   (*this)[#name].st(val);  }   \

    make_getter_setter(direction ,std::string ,std::string )
    make_getter_setter(value     ,bool        ,int         )
    
#undef  make_getter_setter

    template<typename... Args> 
    gpio(Args&&... args):device_dir( args... ){}
    
    gpio(int port):
    device_dir(gpio_config::path_ls.begin()[port], 
               gpio_config::attr_ls)
    {}

};




#endif /* defined(__Test__gpio__) */
