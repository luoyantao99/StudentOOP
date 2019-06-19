#include <iostream>
#include <string>
#include "weather.h"

using namespace std;


const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;



// Output
ostream& operator<<(ostream& os, const WReading& wr){
    os << "Date: " << wr.date << "; Humidity: " << wr.humidity << "; Temperature: " << wr.temperature << "; Windspeed: " << wr.windspeed;
    return os;
}

ostream& operator<<(std::ostream& os, const GPS& gps)
{
    os << "Latitude: " << gps.latitude << "; Longitude: " << gps.longitude;
    return os;
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





// Image class
Image::Image(int w, int h, std::string flnm) : width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}


// copy constructor:
Image::Image(const Image& img2) {
    height = img2.height;
    width = img2.width;
    filename = img2.filename;
    image_buf = new char[image_sz()]; // Allocate
    for (int i = 0; i<image_sz(); i++)
    {
        image_buf[i] = img2.image_buf[i]; // Initialize
    }
}

// destructor
Image::~Image() {
    if (image_buf != nullptr)
    { delete[] image_buf; }
}

// assignment operator:
Image& Image::operator=(const Image& img2) {
    if (this != &img2) {
        // Free up resources (as needed)
        if (image_buf != nullptr)
        { delete[] image_buf; }
        // Allocate new resources (as needed)
        height = img2.height;
        width = img2.width;
        filename = img2.filename;
        image_buf = new char[image_sz()];
        // Copy over all data
        for (int i = 0; i<image_sz(); i++)
        {
            image_buf[i] = img2.image_buf[i]; // Initialize
        }
    }
    return *this;
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
}

/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
string Image::display(std::string s) {
    cout << "Displaying image " << s << endl;
    return s;
}


// polymorphism
string Png::display(std::string s)
{
    cout << "Displaying png " << s << endl;
    return s;
}

string Jpeg::display(std::string s)
{
    cout << "Displaying jpg " << s << endl;
    return s;
}

string Gif::display(std::string s)
{
    cout << "Displaying gif " << s << endl;
    return s;
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



double WReading::get_tempF() {
    return (temperature * C_TO_F) + 32;
}

void WReading::display_image() const
{
    if(!image) cout << "no image display" << endl;
    else image->display("from weather reading");
}

void Weather::display_images() const
{
    for (WReading wr : wreadings)
    {
        wr.display_image();
    }
}
