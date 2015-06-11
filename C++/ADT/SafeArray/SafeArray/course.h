#ifndef COURSE_H
#define COURSE_H

#include "safearray.h"
#include <iostream>
using namespace std;

int const MAX_LINES = 10;

class course {

  public:
    string name;
    string title;
    safearray<string> description;
     
    course() : name(""), title(""), description(MAX_LINES) {}
    course(string name, string title) : 
        name(name), title(title), description(MAX_LINES) {}

    friend ostream& operator<<(ostream&, const course&);        
    friend istream& operator>>(istream&, course&);
};

ostream& operator<<(ostream& out, const course& c) {

    out << c.name << ": " << c.title << "\n";

    int index = 0;
    while (c.description[index] != "") {
        out << c.description[index++] << "\n";    
    }

    return out;
}

istream& operator>>(istream& in, course& c) {

    getline(in, c.name);
    getline(in, c.title);

    string line;
    getline(in, line);
    int number = 0;
    while (line != "") {
        c.description[number++] = line;
        getline(in, line);
    }
    
    return in;
}

#endif
