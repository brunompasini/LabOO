#include "Perfil.h"
#include "Publicacao.h"
#include "Evento.h"
#include <iostream>

using namespace std;

Perfil::Perfil(int numeroUSP, string nome, string email):
numeroUSP (numeroUSP), nome (nome), email (email){
}

Perfil::~Perfil(){
    cout << "Destrutor de perfil: " << nome << " - Quantidade de publicacoes feitas: "
    << quantidadeDePublicacoesFeitas << endl;

    //deletar posts
    for(int i=0; i<quantidadeDePublicacoesFeitas; i++){
        delete feitas[i];
    }
    cout << "Perfil deletado" << endl;
}

int Perfil::getNumeroUSP()
{
    return numeroUSP;
}

string Perfil::getNome()
{
    return nome;
}

string Perfil::getEmail()
{
    return email;
}

bool Perfil::adicionarSeguidor(Perfil* seguidor) {
    if (quantidadeDeSeguidores<MAXIMO_SEGUIDORES) {
        this->seguidores[quantidadeDeSeguidores] = seguidor;
        quantidadeDeSeguidores += 1;
        recebidas[quantidadeDePublicacoesRecebidas] = new Publicacao(this,"Novo Seguidor: "+seguidor->getNome());
        this->quantidadeDePublicacoesRecebidas += 1;
        return true;
    }
    return false;
}

bool Perfil::publicar(string texto) {
    if (quantidadeDePublicacoesFeitas<MAXIMO_PUBLICACOES){
            feitas[quantidadeDePublicacoesFeitas] = new Publicacao(this, texto);
            if (quantidadeDeSeguidores != 0){
                for(int i=0; i< quantidadeDeSeguidores; i++){
                   seguidores[i]->receber(feitas[quantidadeDePublicacoesFeitas]);
                }
            }
            this->quantidadeDePublicacoesFeitas += 1;
            return true;

    }
    return false;
}


bool Perfil::publicar(string texto, string data)
{
    if (quantidadeDePublicacoesFeitas<MAXIMO_PUBLICACOES){
            feitas[quantidadeDePublicacoesFeitas] = new Evento(this, texto, data);
            if (quantidadeDeSeguidores != 0){
                for(int i=0; i< quantidadeDeSeguidores; i++){
                   seguidores[i]->receber(feitas[quantidadeDePublicacoesFeitas]);
                }
            }
            this->quantidadeDePublicacoesFeitas += 1;
            return true;

    }
    return false;
}



bool Perfil::receber(Publicacao* p){
        if (quantidadeDePublicacoesRecebidas< MAXIMO_PUBLICACOES){
            recebidas[quantidadeDePublicacoesRecebidas] = p;
            this->quantidadeDePublicacoesRecebidas += 1;
            return true;
        }
    return false;
}

Publicacao** Perfil::getPublicacoesFeitas()
{
    return feitas;
}

int Perfil::getQuantidadeDePublicacoesFeitas()
{
    return quantidadeDePublicacoesFeitas;
}

Publicacao** Perfil::getPublicacoesRecebidas()
{
    return recebidas;
}

int Perfil::getQuantidadeDePublicacoesRecebidas()
{
    return quantidadeDePublicacoesRecebidas;
}

Perfil** Perfil::getSeguidores()
{
    return seguidores;
}

int Perfil::getQuantidadeDeSeguidores()
{
    return quantidadeDeSeguidores;
}

void Perfil::imprimir() {
    cout << numeroUSP << " - " << nome << endl;
    cout << "Seguidores: " << quantidadeDeSeguidores << endl;
    cout << "---" << endl;
}

