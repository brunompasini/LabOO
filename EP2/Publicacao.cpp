#include "Publicacao.h"
#include "Perfil.h"

Publicacao::Publicacao(Perfil* autor, string texto):
autor (autor), texto (texto){
}

Publicacao::~Publicacao(){
    cout << "Destrutor de publicacao: " << this->texto << endl;
}


string Publicacao::getTexto(){
    return texto;
}


Perfil* Publicacao::getAutor(){
    return autor;
}

void Publicacao::imprimir()
{
    cout << texto << " (" << this->autor->getNome() << ") " << "[" << curtidas << "]" << endl;
}

int Publicacao::getCurtidas()
{
    return curtidas;
}

