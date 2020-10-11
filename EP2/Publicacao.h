#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <string>
#include <iostream>
using namespace std;
class Perfil;
class Publicacao {
protected:
    string texto;
    Perfil* autor;
    int curtidas=0;
public:
    Publicacao(Perfil* autor, string texto);
    virtual ~Publicacao();

    Perfil* getAutor();
    string getTexto();

    virtual void curtir(Perfil* quemCurtiu)=0;
    virtual int getCurtidas();

    virtual void imprimir();
};

#endif // PUBLICACAO_H
