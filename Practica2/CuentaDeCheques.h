#pragma once
#include <iostream>
#include "Persona.h"

using std::cout;
using std::endl;
using std::string;

#pragma once

class CuentaDeCheques
{
    Persona propietario;
protected:
	int numeroCuenta;
	float saldo;
    struct tm *fecha;
    void actualFecha();

public:
    CuentaDeCheques();
    CuentaDeCheques(Persona &datosDueno, float saldoInicial, int numCuenta);
    bool transferencia(CuentaDeCheques &destino,float cantidad);
    bool depositar(float cantidad);
    bool retirar(float cantidad);
    void estadoCuenta();
    
};