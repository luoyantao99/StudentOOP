//
//  date.hpp
//  OOP
//
//  Created by Yantao Luo on 6/7/19.
//  Copyright © 2019 Yantao Luo. All rights reserved.
//

#ifndef date_hpp
#define date_hpp

#include <string>
#include <vector>


class Date {
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
public:
    Date(int d, int m, int y);
private:
    int day;
    int month;
    int year;
};


#endif /* date_hpp */
