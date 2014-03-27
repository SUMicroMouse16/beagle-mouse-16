//
//  robot.h
//  micromouse2014
//
//  Created by Lyle Moffitt on 3/20/14.
//  Copyright (c) 2014 Lyle Moffitt. All rights reserved.
//

#ifndef __micromouse2014__robot__
#define __micromouse2014__robot__

#include <iostream>


#include "lidar.h"
#include "motor.h"
#include "star.h"
#include "nav.h"

namespace robot_config 
{
    // Maximum width of the robot
    constexpr size_t max_width = 250;//mm
    
    // Maximum length of the robot
    constexpr size_t max_length = 250;//mm
}


class robot
{
    lidar   view;
    nav     navigator;
    star    algo;
    
    std::string direction; // direction that mouse is facing
	double compass;
    double xDistance, yDistance; // the current position of the robot
	double shift; // represents the difference between the current compass heading and the default, which is 90 degrees

public:
    robot();
    
    void PositionChange();
    cell* getPointerToJunction(char &sourceDirection);
    
};


#endif /* defined(__micromouse2014__robot__) */
