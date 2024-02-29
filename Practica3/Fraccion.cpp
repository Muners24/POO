#include "Fraccion.h"
using std::string;
using std::istringstream; 
using std::abs;
using std::strlen;
using std::strcpy;

Fraccion::Fraccion()
{

}   

Fraccion::Fraccion(int num,int den)
{
    if(den==0) 
    {
        throw std::invalid_argument("El denominador no puede ser cero.");
    }
    this->num=num;
    this->den=den;
}   

Fraccion::Fraccion(string str)
{
    char o;
    quitarEspacio(str);
    istringstream in(str);
    in >> num >> o >> den;
    if(den==0) 
    {
        throw std::invalid_argument("El denominador no puede ser cero.");
    }
}

void Fraccion::operator=(const char* str)
{
    char o;
    char copia[strlen(str)+1];
    strcpy(copia,str);
    quitarEspacio(copia);
    istringstream in(copia);
    in >> num >> o >> den;
    if(den==0) 
    {
        throw std::invalid_argument("El denominador no puede ser cero.");
    }
}

Fraccion Fraccion::operator*(Fraccion f)
{
    Fraccion r;
    r.num=this->num*f.num;
    r.den=this->den*f.den;
    return r;
}

Fraccion Fraccion::operator+(Fraccion f)
{
    Fraccion r;
    r.num=(this->num*f.den)+(f.num*this->den);
    r.den=this->den*f.den;
    return r;
}

Fraccion Fraccion::operator-(Fraccion f)
{
    Fraccion r;
    r.num=(this->num*f.den)-(f.num*this->den);
    r.den=this->den*f.den;
    return r;
}

Fraccion Fraccion::operator/(Fraccion f)
{
    Fraccion r;
    r.num=this->num*f.den;
    r.den=this->den*f.num;
    return r;
}

Fraccion Fraccion::operator*(int num)
{
    Fraccion r;
    r.num=this->num*num;
    r.den=this->den;
    return r;
}

Fraccion Fraccion::operator+(int num)
{
    Fraccion r;
    r.num=this->num+(num*this->den);
    r.den=this->den;
    return r;
}

Fraccion Fraccion::operator-(int num)
{
    Fraccion r;
    r.num=this->num-(num*this->den);
    r.den=this->den;
    return r;
}

Fraccion Fraccion::operator/(int num)
{
    Fraccion r;
    r.num=this->num;
    r.den=this->den*num;
    return r;
}

ostream& operator<<(ostream& out, Fraccion f)
{

    if(abs(f.num)<f.den)
    {
	    out << f.num << "/" << f.den;
    }
    else
    {
        int entero;
        entero=int(f.num/f.den);
        out << entero << " " << f.num-(entero)*f.den << "/" <<f.den;
    }
	return out;
}

string quitarEspacio(string str)
{
    string copia;
    for(char c : str)
    {
        copia.push_back(c);
    }
    return copia;
}