#ifndef EVENTO_H
#define EVENTO_H
#include <string>
#include <iostream>
using namespace std;
#include "Publicacao.h"
class Evento: public Publicacao
{
    public:
        Evento(Perfil* autor, string texto, string data);
        virtual ~Evento();

        string getData();
    protected:

    private:
        Perfil* autor;
        string texto;
        string data;
};

#endif // EVENTO_H
