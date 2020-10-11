#include "Disciplina.h"

Disciplina::Disciplina(string sigla, string nome, Professor* responsavel): Perfil (nome)
{
    this->sigla = sigla;
    this->responsavel = responsavel;
    this->adicionarSeguidor(responsavel);
}

Disciplina::Disciplina(int id, string sigla, string nome, Professor* responsavel) : Perfil(nome)
{
    this->sigla = sigla;
    this->responsavel = responsavel;
    this->id = id;

    this->adicionarSeguidor(responsavel);
}

Disciplina::~Disciplina()
{
    //dtor
}
void Disciplina::imprimir()
{
    cout << "----------------" << endl;
    cout << sigla << " - ";
    cout << nome << endl;
    cout << "Seguidores: " << quantidadeDeSeguidores << endl;
    cout << "---" << endl;
}
Professor* Disciplina::getResponsavel()
{
    return responsavel;
}

string Disciplina::getSigla()
{
    return sigla;
}
