//
//  date.cpp
//  OOP
//
//  Created by Yantao Luo on 6/7/19.
//  Copyright © 2019 Yantao Luo. All rights reserved.
//

#include <iostream>
#include <string>
#include "date.hpp"


Date::Date(int d, int m, int y) {
    if ((d<1) || (d>31)) throw (d);
    if ((m<1) || (m>12)) throw (m);
    if ((y<1800) || (y>2200)) throw (y);
    
    day = d;
    month = m;
    year = y;
}

/*
 * Output Date
 **/
std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.month << "/" << date.day << "/" << date.year;
    return os;
}
