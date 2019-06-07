#include <iostream>
#include <string>
#include "weather.h"

using namespace std;


/*
 * Output WReading
 **/
ostream& operator<<(ostream& os, const WReading& wr){
    os << "Date: " << wr.date << "; Humidity: " << wr.humidity << "; Temperature: " << wr.temperature << "; Windspeed: " << wr.windspeed;
    return os;
}


/*
 * Output GPS
 **/
ostream& operator<<(std::ostream& os, const GPS& gps)
{
    os << "Latitude: " << gps.latitude << "; Longitude: " << gps.longitude;
    return os;
}


/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) : station_nm(nm), my_loc(loc) {}


string Weather::get_name() const
{
    return station_nm;
}

int Weather::get_rating() const
{
    return rating;
}

void Weather::set_rating(int new_rating)
{
    rating = new_rating;
}

void Weather::add_reading(WReading wr)
{
    wreadings.push_back(wr);
}

ostream& operator<<(ostream& os, const Weather& w)
{
    os << w.get_name() << ": rating " << w.get_rating() << " Location: " << w.my_loc << endl;
    for (WReading wr : w.wreadings)
    {
        os << "   " << wr << endl;
    }
    return os;
}
