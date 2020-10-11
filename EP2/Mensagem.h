#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

using namespace std;

#include "Perfil.h"
#include "Publicacao.h"

class Mensagem: public Publicacao{
public:
        Mensagem(Perfil* autor, string texto);
        virtual ~Mensagem();

        virtual void imprimir();
        virtual void curtir(Perfil* quemCurtiu);

    protected:

    private:
};

#endif // MENSAGEM_H
