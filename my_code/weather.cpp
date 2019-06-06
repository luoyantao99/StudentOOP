#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

ostream& operator<<(std::ostream& os, const GPS& gps)
{
    os << "Latitude: " << gps.latitude << " Longitude: " << gps.longitude;
    return os;
}

Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

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

ostream& operator<<(ostream& os, const Weather& w)
{
    os << w.station_nm << ": rating " << w.get_rating() << " Location: " << w.my_loc;
    return os;
}
