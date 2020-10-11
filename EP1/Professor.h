#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Perfil.h"
#include <string>
#include <iostream>
using namespace std;
class Professor: public Perfil{
public:
    Professor(int numeroUSP, string nome, string email, string departamento);
    ~Professor();
    string getDepartamento();
    void imprimir();
private:
    string departamento;
};

#endif // PROFESSOR_H
