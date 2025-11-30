#ifndef OPERACOES_H
#define OPERACOES_H

#include "models.h"

// Operações principais
Numero somar(Numero a, Numero b);
Numero subtrair(Numero a, Numero b);
Numero multiplicar(Numero a, Numero b);
Numero dividir(Numero a, Numero b);
Numero modulo(Numero a, Numero b);

// Operação personalizada (exemplo: fatorial)
Numero fatorial(Numero n);

#endif