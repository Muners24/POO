#pragma once
#include <iostream>
#include <string>
using std::string;
using std::ostream;

class Fraccion
{
public:
    int num;
    int den;
    Fraccion();
    Fraccion(int num,int den);
    Fraccion(string str);
    
    void operator=(const char* str);
    Fraccion operator+(Fraccion f);
    Fraccion operator-(Fraccion f);
    Fraccion operator*(Fraccion f);
    Fraccion operator/(Fraccion f);
    Fraccion operator+(int num);
    Fraccion operator-(int num);
    Fraccion operator*(int num);
    Fraccion operator/(int num);
    
};

ostream &operator<<(ostream& out, Fraccion f);

string quitarEspacio(string str);