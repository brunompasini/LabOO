#include "Mensagem.h"


Mensagem::Mensagem(Perfil* autor, string texto): Publicacao(autor,texto)
{

}

Mensagem::~Mensagem()
{
    //dtor
}

void Mensagem::imprimir()
{
    cout << "Mensagem de: " << autor->getNome() << endl;
    cout << texto << endl;
}

void Mensagem::curtir(Perfil* quemCurtiu)
{
    if (autor == quemCurtiu){
        throw new invalid_argument ("Voce nao pode curtir a sua propria mensagem");
    }
}
