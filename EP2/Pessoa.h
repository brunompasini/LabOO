#ifndef PESSOA_H
#define PESSOA_H

#include "Perfil.h"
using namespace std;
class Pessoa : public Perfil
{
public:
    Pessoa(int numeroUSP, string nome, string email);
    Pessoa(int id, int numeroUSP, string nome, string email);
    virtual ~Pessoa();

    virtual int getNumeroUSP();
    virtual string getEmail();
    void imprimir()=0;

protected:
    string email;
    int numeroUSP;
};

#endif // PESSOA_H
