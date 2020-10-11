#ifndef PERFIL_H
#define PERFIL_H
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
#include "Evento.h"
#include "Mensagem.h"
using namespace std;

class Publicacao;
class Perfil{
protected:
    string nome;

    vector<Perfil*>* seguidores = new vector<Perfil*>();
    int quantidadeDeSeguidores = 0;
    list<Publicacao*>* feitas = new list<Publicacao*>();
    //int quantidadeDePublicacoesFeitas = 0;
    list<Publicacao*>* recebidas = new list<Publicacao*>();
    //int quantidadeDePublicacoesRecebidas = 0;

    int id;
    static int ultimoId;

public:
    Perfil(string nome);
    Perfil(int id, string nome);
    virtual ~Perfil();

    static void setUltimoId(int ultimoId);
    static int getUltimoId();

    int getId();
    string getNome();

    virtual void adicionarSeguidor(Perfil* seguidor);

    virtual void publicar(string texto);
    virtual void publicar(string texto, string data);

    virtual void receber(Publicacao* p);
    virtual list<Publicacao*>* getPublicacoesFeitas();
    virtual list<Publicacao*>* getPublicacoesRecebidas();

    virtual vector<Perfil*>* getSeguidores();

    virtual void imprimir()=0;
};


#endif // PERFIL_H
