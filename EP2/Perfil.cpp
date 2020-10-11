#include "Perfil.h"
#include "Publicacao.h"
#include <iostream>
#include <vector>
#include <list>
using namespace std;

Perfil::Perfil(string nome): nome (nome)
{
    Perfil::ultimoId++;
    id = ultimoId;
}

Perfil::Perfil(int id, string nome): nome (nome), id (id)
{
    //somente usado para persistencia da rede
}

Perfil::~Perfil()
{
    cout << "Destrutor de perfil: " << nome << " - Quantidade de publicacoes feitas: "
    << feitas->size() << endl;
    //deletar posts
    list<Publicacao*>::iterator i = feitas->begin();
    while(!feitas->empty()){
        Publicacao* pub = feitas->front();
        //fazer algo com pub aqui
        feitas->pop_front();
        delete pub;
    }
    cout << "Perfil deletado" << endl;
}

int Perfil::getId()
{
    return id;
}

string Perfil::getNome()
{
    return nome;
}

void Perfil::adicionarSeguidor(Perfil* seguidor)
{
    if(seguidor==this){
        throw new invalid_argument("Voce nao pode seguir a si mesmo");
    }
    vector<Perfil*>::iterator it = seguidores->begin();
    while (it!= seguidores->end()){
        if(it!=seguidores->end()){
            throw new invalid_argument("Voce ja segue esse perfil");
        }
        else{
            seguidores->push_back(seguidor);
        }
    }
}

void Perfil::publicar(string texto)
{
    Mensagem* novaPub = new Mensagem(this,texto);
    feitas->push_back(novaPub);
    if(!seguidores->empty()){
        vector<Perfil*>::iterator i = seguidores->begin();
        while (i!=seguidores->end()){
            (*i)->receber(novaPub);
        }
    }
}

void Perfil::publicar(string texto, string data)
{
    Evento* novoEv  = new Evento(this,texto,data);
    feitas->push_back(novoEv);
    if(!seguidores->empty()){
        vector<Perfil*>::iterator i = seguidores->begin();
        while (i!=seguidores->end()){
            (*i)->receber(novoEv);
        }
    }
}

void Perfil::receber(Publicacao* p)
{
    recebidas->push_back(p);
}

list<Publicacao*>* Perfil::getPublicacoesFeitas()
{
    return feitas;
}

list<Publicacao*>* Perfil::getPublicacoesRecebidas()
{
    return recebidas;
}

vector<Perfil*>* Perfil::getSeguidores()
{
    return seguidores;
}

int Perfil::ultimoId = 0;

int Perfil::getUltimoId()
{
    return Perfil::ultimoId;
}

void Perfil::setUltimoId(int ultimoId)
{
    Perfil::ultimoId = ultimoId;
}
