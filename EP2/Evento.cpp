#include "Evento.h"
#include "Perfil.h"


Evento::Evento(Perfil* autor, string texto, string data): Publicacao (autor, texto)
{
    this->data = data;
}

Evento::~Evento()
{
}

string Evento::getData()
{
    return data;
}

void Evento::imprimir()
{
    cout << "Mensagem de: " << autor->getNome() << endl;
    cout << texto << endl;
}

void Evento::curtir(Perfil* quemCurtiu)
{
    curtidas++;
}
