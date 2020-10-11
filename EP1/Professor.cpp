#include "Professor.h"
#include "Perfil.h"
#include <string>
#include <iostream>
using namespace std;

Professor::Professor(int numeroUSP, string nome, string email, string departamento) : Perfil(numeroUSP, nome, email)
{
    this->departamento = departamento;
}


Professor::~Professor()
{
    cout << "Professor destruido" << endl;
}

string Professor::getDepartamento()
{
    return departamento;
}


void Professor::imprimir(){
    cout << numeroUSP << " - " << nome << endl;
    cout << "Departamento " << departamento << endl;
    cout << "Seguidores: " << quantidadeDeSeguidores << endl;
    cout << "---" << endl;
}

