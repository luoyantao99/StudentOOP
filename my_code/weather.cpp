#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

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
ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.month << "/" << date.day << "/" << date.year;
    return os;
}


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
