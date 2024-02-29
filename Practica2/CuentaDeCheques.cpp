#include "CuentaDeCheques.h"
#include <ctime>
#include <cstdlib>
#include <stdio.h>
//usar Clase Persona
CuentaDeCheques::CuentaDeCheques(Persona &datosDueno, float saldoInicial, int numCuenta)
{
    propietario=datosDueno;
    saldo=saldoInicial;
    numeroCuenta=numCuenta;

}

bool CuentaDeCheques::transferencia(CuentaDeCheques &destino,float cantidad)
{
    if(cantidad > 0)
    {
        if(saldo >= cantidad)
        {
            saldo -= cantidad;
            destino.saldo += cantidad;
            actualFecha();
            destino.actualFecha();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool CuentaDeCheques::depositar(float cantidad)
{
    if(cantidad > 0)
    {
        saldo+=cantidad;
        actualFecha();
        return true;
    }
    else
    {
        return false;
    }
}

bool CuentaDeCheques::retirar(float cantidad)
{
    if(cantidad > 0)
    {
        if(saldo >= cantidad)
        {
            saldo -= cantidad;
            actualFecha();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void CuentaDeCheques::actualFecha()
{
    time_t t;
    t = time(NULL);
    fecha = localtime(&t);
}

void CuentaDeCheques::estadoCuenta()
{
    cout << "\n\nEstado de la cuenta\n\n";
    cout << "Propietario\n";
    cout << "Nombre: "<<propietario.GetNombre() << "\nEdad: " << propietario.GetEdad();
    cout << "\nNumero de cuenta: " << numeroCuenta;
    cout << "\nSaldo: " << saldo;
    cout << "\nFecha de ultima transaccion: ";
    printf(" %02d/%02d/%d %02d:%02d",fecha->tm_mday,fecha->tm_mon+1,fecha->tm_year+1900,fecha->tm_hour,fecha->tm_min);
    cout << endl;
}