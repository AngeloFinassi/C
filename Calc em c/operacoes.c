#include "models.h"
#include "operacoes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Soma apenas valores absolutos, auxilia outras operações
static Numero somarAbsoluto(Numero a, Numero b) {
    if (b.tamanho > a.tamanho) {
        Numero tmp = a;
        a = b;
        b = tmp;
    }
    
    Numero r;
    r.tamanho = a.tamanho + 1;
    r.digitos = (int*)malloc(r.tamanho * sizeof(int));
    r.sinal = 1;
    
    int carry = 0;
    int i;
    
    for (i = 0; i < b.tamanho; i++) {
        int soma = a.digitos[i] + b.digitos[i] + carry;
        r.digitos[i] = soma % 10;
        carry = soma / 10;
    }
    
    for (; i < a.tamanho; i++) {
        int soma = a.digitos[i] + carry;
        r.digitos[i] = soma % 10;
        carry = soma / 10;
    }
    
    r.digitos[i] = carry;
    
    if (carry == 0) {
        r.tamanho--;
    }
    
    return r;
}

// Subtrai valores absolutos, assumindo |a| >= |b|
static Numero subtrairAbsoluto(Numero a, Numero b) {
    Numero r;
    r.tamanho = a.tamanho;
    r.digitos = (int*)malloc(r.tamanho * sizeof(int));
    r.sinal = 1;
    
    int borrow = 0;
    int i;
    
    for (i = 0; i < b.tamanho; i++) {
        int sub = a.digitos[i] - b.digitos[i] - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        r.digitos[i] = sub;
    }
    
    for (; i < a.tamanho; i++) {
        int sub = a.digitos[i] - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        r.digitos[i] = sub;
    }
    
    removerZerosEsquerda(&r);
    return r;
}

Numero somar(Numero a, Numero b) {
    // Mesmos sinais: soma absolutos e mantém sinal
    if (a.sinal == b.sinal) {
        Numero r = somarAbsoluto(a, b);
        r.sinal = a.sinal;
        return r;
    }
    
    // Sinais diferentes: subtrai o menor do maior
    int cmp = compararAbsoluto(a, b);
    
    if (cmp == 0) {
        // São iguais em módulo: resultado é zero
        Numero zero = criarNumero("0");
        return zero;
    }
    
    Numero r;
    if (cmp > 0) {
        // |a| > |b|
        r = subtrairAbsoluto(a, b);
        r.sinal = a.sinal;
    } else {
        // |b| > |a|
        r = subtrairAbsoluto(b, a);
        r.sinal = b.sinal;
    }
    
    return r;
}

Numero subtrair(Numero a, Numero b) {
    //Inverte o sinal de b e soma
    Numero b_neg = copiarNumero(b);
    b_neg.sinal = -b_neg.sinal;
    Numero r = somar(a, b_neg);
    liberarNumero(&b_neg);
    return r;
}

Numero multiplicar(Numero a, Numero b) {
    Numero r;
    r.tamanho = a.tamanho + b.tamanho;
    r.digitos = (int*)calloc(r.tamanho, sizeof(int));
    r.sinal = a.sinal * b.sinal;
    
    //Multiplicação tradicional
    for (int i = 0; i < a.tamanho; i++) {
        int carry = 0;
        for (int j = 0; j < b.tamanho; j++) {
            int prod = a.digitos[i] * b.digitos[j] + r.digitos[i + j] + carry;
            r.digitos[i + j] = prod % 10;
            carry = prod / 10;
        }
        r.digitos[i + b.tamanho] += carry;
    }
    
    removerZerosEsquerda(&r);
    return r;
}

//Divisão usando método da chave, Long Division
Numero dividir(Numero a, Numero b) {
    //Verifica divisão por zero
    if (b.tamanho == 1 && b.digitos[0] == 0) {
        printf("Erro: divisão por zero!\n");
        return criarNumero("0");
    }
    
    //Se |a| < |b|, resultado é 0
    if (compararAbsoluto(a, b) < 0) {
        return criarNumero("0");
    }
    
    //Preparar resultado
    Numero quociente;
    quociente.tamanho = a.tamanho;
    quociente.digitos = (int*)calloc(a.tamanho, sizeof(int));
    quociente.sinal = a.sinal * b.sinal;
    
    //Divisor absoluto
    Numero divisor = copiarNumero(b);
    divisor.sinal = 1;
    
    //Resto parcial, começa vazio
    Numero resto_parcial = criarNumero("0");
    
    //Percorre dividendo da esquerda para direita, dígito mais significativo primeiro
    for (int i = a.tamanho - 1; i >= 0; i--) {
        //Adiciona próximo dígito ao resto parcial
        Numero temp;
        temp.tamanho = resto_parcial.tamanho + 1;
        temp.digitos = (int*)malloc(temp.tamanho * sizeof(int));
        temp.sinal = 1;
        
        //Desloca resto_parcial uma posição (multiplica por 10)
        for (int j = 0; j < resto_parcial.tamanho; j++) {
            temp.digitos[j + 1] = resto_parcial.digitos[j];
        }
        temp.digitos[0] = a.digitos[i];
        
        liberarNumero(&resto_parcial);
        resto_parcial = temp;
        removerZerosEsquerda(&resto_parcial);
        
        //Encontra quantas vezes o divisor cabe no resto_parcial
        int digito_quociente = 0;
        
        while (compararAbsoluto(resto_parcial, divisor) >= 0) {
            Numero sub = subtrairAbsoluto(resto_parcial, divisor);
            liberarNumero(&resto_parcial);
            resto_parcial = sub;
            digito_quociente++;
        }
        
        quociente.digitos[i] = digito_quociente;
    }
    
    liberarNumero(&resto_parcial);
    liberarNumero(&divisor);
    
    removerZerosEsquerda(&quociente);
    return quociente;
}

//Módulo usando método da chave
Numero modulo(Numero a, Numero b) {
    if (b.tamanho == 1 && b.digitos[0] == 0) {
        printf("Erro: módulo por zero!\n");
        return criarNumero("0");
    }
    
    // Se |a| < |b|, resto é o próprio a, com sinal ajustado
    if (compararAbsoluto(a, b) < 0) {
        Numero resto = copiarNumero(a);
        //Garante resto positivo
        if (resto.sinal == -1 && b.sinal == 1) {
            Numero temp = somar(resto, b);
            liberarNumero(&resto);
            resto = temp;
        }
        return resto;
    }
    
    // Divisor absoluto
    Numero divisor = copiarNumero(b);
    divisor.sinal = 1;
    
    Numero resto = criarNumero("0");
    
    // Percorre dividendo da esquerda para direita
    for (int i = a.tamanho - 1; i >= 0; i--) {
        // Adiciona próximo dígito ao resto
        Numero temp;
        temp.tamanho = resto.tamanho + 1;
        temp.digitos = (int*)malloc(temp.tamanho * sizeof(int));
        temp.sinal = 1;
        
        for (int j = 0; j < resto.tamanho; j++) {
            temp.digitos[j + 1] = resto.digitos[j];
        }
        temp.digitos[0] = a.digitos[i];
        
        liberarNumero(&resto);
        resto = temp;
        removerZerosEsquerda(&resto);
        
        // Subtrai o divisor quantas vezes couber
        while (compararAbsoluto(resto, divisor) >= 0) {
            Numero sub = subtrairAbsoluto(resto, divisor);
            liberarNumero(&resto);
            resto = sub;
        }
    }
    
    // Aplica regra do sinal para módulo
    if (a.sinal == -1 && resto.tamanho > 0 && !(resto.tamanho == 1 && resto.digitos[0] == 0)) {
        Numero temp = subtrairAbsoluto(divisor, resto);
        liberarNumero(&resto);
        resto = temp;
    }
    
    liberarNumero(&divisor);
    return resto;
}

//Operação personalizada: Fatorial
//Limite: números até 10.000
Numero fatorial(Numero n) {
    // Verifica se é negativo
    if (n.sinal == -1) {
        printf("Erro: fatorial de numero negativo!\n");
        return criarNumero("0");
    }
    
    // Verifica se é muito grande
    if (n.tamanho > 5) {
        printf("Erro: numero muito grande para fatorial (limite: 10.000)!\n");
        return criarNumero("0");
    }
    
    // Converte para inteiro normal
    int valor = 0;
    for (int i = n.tamanho - 1; i >= 0; i--) {
        valor = valor * 10 + n.digitos[i];
    }
    
    if (valor > 10000) {
        printf("Erro: fatorial limitado a 10.000!\n");
        return criarNumero("0");
    }
    
    Numero resultado = criarNumero("1");
    
    for (int i = 2; i <= valor; i++) {
        char buffer[20];
        sprintf(buffer, "%d", i);
        Numero fator = criarNumero(buffer);
        
        Numero temp = multiplicar(resultado, fator);
        liberarNumero(&resultado);
        liberarNumero(&fator);
        resultado = temp;
    }
    
    return resultado;
}