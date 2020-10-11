#include "Disciplina.h"

Disciplina::Disciplina(string sigla, string nome, Professor* responsavel): Perfil (0,nome,"")
{
    this->sigla = sigla;
    this->responsavel = responsavel;
    this->adicionarSeguidor(responsavel);
}
Disciplina::~Disciplina()
{
    //dtor
}
void Disciplina::imprimir()
{
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
