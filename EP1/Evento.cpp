#include "Evento.h"



Evento::Evento(Perfil* autor, string texto, string data): Publicacao (autor, texto)
{
    this->data = data;
}

Evento::~Evento()
{
    cout << "Evento: " << texto << data << " destruido" << endl;
}


string Evento::getData()
{
    return data;
}
