#include "Pessoa.h"

Pessoa::Pessoa(int numeroUSP, string nome, string email):Perfil(nome),
numeroUSP (numeroUSP), email (email)
{
}

Pessoa::Pessoa(int id, int numeroUSP, string nome, string email):Perfil(id,nome),
numeroUSP (numeroUSP),email (email)
{
}

Pessoa::~Pessoa()
{
}

int Pessoa::getNumeroUSP()
{
    return numeroUSP;
}

string Pessoa::getEmail()
{
    return email;
}
