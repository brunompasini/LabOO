#ifndef REDESOCIAL_H
#define REDESOCIAL_H
#include "Perfil.h"
#include "Publicacao.h"
#include <iostream>
#include <string>
class RedeSocial {
public:
    RedeSocial (int numeroMaximoDePerfis);
    virtual ~RedeSocial();

    int getQuantidadeDePerfis();
    Perfil** getPerfis();

    bool adicionar(Perfil* p);
    virtual void imprimir();
    //void imprimirEstatisticas();

private:
    Perfil** perfis;
    int quantidadeDePerfis =0;
    int numeroMaximoDePerfis;
};

#endif
