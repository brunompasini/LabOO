#include "Aluno.h"

Aluno::Aluno(int numeroUSP, string nome, string email): Pessoa(numeroUSP,nome,email)
{
}

Aluno::Aluno(int id, int numeroUSP, string nome, string email): Pessoa(id,numeroUSP,nome,email)
{
}

Aluno::~Aluno()
{
}

void Aluno::imprimir()
{
    cout << numeroUSP << " - " << nome << endl;
}
