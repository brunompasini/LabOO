#include "RedeSocial.h"

#include "Perfil.h"
#include "Professor.h"
#include "Disciplina.h"
#include <iostream>
using namespace std;
// construtor
RedeSocial::RedeSocial(int numeroMaximoDePerfis)
{
    perfis = new Perfil* [numeroMaximoDePerfis];
    this->numeroMaximoDePerfis = numeroMaximoDePerfis;
}

// destrutor
RedeSocial::~RedeSocial() {
  cout << "Destrutor de RedeSocial: " << quantidadeDePerfis << " perfis" << endl;
  for(int i=0; i<quantidadeDePerfis; i++){
    delete perfis[i];
  }
  delete[] perfis;
  cout << "RedeSocial deletada " << endl;
}

Perfil** RedeSocial::getPerfis(){
    return perfis;
}
int RedeSocial::getQuantidadeDePerfis(){
    return quantidadeDePerfis;
}
bool RedeSocial::adicionar(Perfil* perfil){
    if (quantidadeDePerfis<numeroMaximoDePerfis)
        perfis[quantidadeDePerfis] = perfil;
        quantidadeDePerfis += 1;
        return true;
    return false;
}

void RedeSocial::imprimir () {
    for(int i=0; i<(this->quantidadeDePerfis); i++){
        cout << i+1 << ") " << perfis[i]->getNome()<<endl;
    }
}
