#ifndef PERFIL_H
#define PERFIL_H
#include <string>
#define MAXIMO_PUBLICACOES 20
#define MAXIMO_SEGUIDORES 20

using namespace std;
class Publicacao;
class Perfil {
protected:
    int numeroUSP;
    string nome;
    string email;

    Perfil* seguidores[MAXIMO_SEGUIDORES];
    int quantidadeDeSeguidores = 0;
    Publicacao* feitas[MAXIMO_PUBLICACOES];
    int quantidadeDePublicacoesFeitas = 0;
    Publicacao* recebidas[MAXIMO_PUBLICACOES];
    int quantidadeDePublicacoesRecebidas = 0;


public:
    Perfil(int numeroUSP, string nome, string email);
    virtual ~Perfil();

    int getNumeroUSP();
    string getNome();
    string getEmail();

    virtual bool adicionarSeguidor(Perfil* seguidor);
    virtual bool publicar(string texto);
    virtual bool publicar(string texto, string data);

    virtual bool receber(Publicacao* p);
    virtual Publicacao** getPublicacoesFeitas();
    virtual int getQuantidadeDePublicacoesFeitas();

    virtual Publicacao** getPublicacoesRecebidas();
    virtual int getQuantidadeDePublicacoesRecebidas();

    virtual Perfil** getSeguidores();
    virtual int getQuantidadeDeSeguidores();

    virtual void imprimir();
};


#endif // PERFIL_H
