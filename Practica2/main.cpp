#include "CuentaDeCheques.h"
#include "Persona.h"

int main()
{
    Persona p1("llll",15);
    Persona p2("mmmm",20);

    CuentaDeCheques cuenta1(p1,0,1234);
    CuentaDeCheques cuenta2(p2,0,4321);

    cuenta1.depositar(15);
    cuenta1.estadoCuenta();
    
    //no cambia el estado porque sobrepasa el valor actual del saldo
    cuenta1.retirar(20);

    cuenta1.estadoCuenta();

    cuenta1.depositar(500);
    cuenta1.transferencia(cuenta2,300);
    cuenta2.estadoCuenta();
    
    //no cambia el estado porque no acepta numeros negativos
    cuenta2.depositar(-13);

    cuenta2.estadoCuenta();
    return 0;
}

