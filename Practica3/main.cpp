#include <iostream>
#include <string>
#include <sstream>
#include "Fraccion.h"
using std::string;
using std::cout;

int main()
{
    Fraccion f1(3,4);
    Fraccion f2("3/10");
    Fraccion f3;
    f3=f1 * f2;
    cout << f1 << " * " << f2 << " = " << f3 <<"\n";
    f3=f1+f2;
    cout << f1 << " + " << f2 << " = " << f3 <<"\n";
    f3=f1-f2;
    cout << f1 << " - " << f2 << " = " << f3 <<"\n";
    f3=f1/f2;
    cout << f1 << " / " << f2 << " = " << f3 <<"\n";

    try
    {
        Fraccion f0(3,0);
        cout << f0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Fraccion f0("15 /0 ");
        cout << f0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

  
    f3=f1*5;
    cout << f1 << " * " << 5 << " = " << f3 <<"\n";
    f3=f1+5;
    cout << f1 << " + " << 5 << " = " << f3 <<"\n";
    f3=f1-5;
    cout << f1 << " - " << 5 << " = " << f3 <<"\n";
    f3=f1/5;
    cout << f1 << " / " << 5 << " = " << f3 <<"\n";

    Fraccion f4;
    f4 = "8 / 15";
    cout << f4 <<"\n";

    try
    {
        Fraccion f5;
        f5 = "6/0";
        cout <<f5;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}