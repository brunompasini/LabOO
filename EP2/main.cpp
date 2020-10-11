#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
using namespace std;

#include "Perfil.h"
#include "Pessoa.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Publicacao.h"
#include "Mensagem.h"
#include "Evento.h"
#include "RedeSocial.h"
#include "PerfilInexistente.h"
#include "PersistenciaDaRede.h"


// Funcao que pergunta para o usuario os dados do perfil a ser criado
void cadastrarPerfil(RedeSocial* rede){
    cout << "Informe os dados do perfil" << endl;
    int nusp;
    string nome;
    string email;
    string prof;
    string departamento;
    cout << "Numero USP: ";
    cin >> nusp;
    cout << "Nome: ";
    cin >> nome;
    cout << "Email: ";
    cin >> email;
    cout << "Professor (s/n): ";
    cin >> prof;
    if (prof == "s"){
        cout << "Departamento: ";
        cin >> departamento;
        rede->adicionar(new Professor(nusp,nome, email, departamento));
    }
    if (prof == "n"){
        rede->adicionar(new Aluno(nusp, nome, email));
    }
}

// instancia disciplinas novas
void cadastrarDisciplina(RedeSocial* rede){
    string sigla;
    string nome;
    cout << "Informe os dados da disciplina" << endl;
    cout << "Sigla: ";
    cin >> sigla;
    cout << "Nome: ";
    cin >> nome;
    cout << "Responsavel: " << endl;
    rede->imprimir();
    cout << "Digite o id ou 0 para cancelar: ";
    unsigned int escolhe;
    cin >> escolhe;
    if (escolhe!=0){
        // checa se eh professor o responsavel
        Professor* responsavel = dynamic_cast<Professor*>(rede->getPerfis()->at(escolhe-1));
        if (responsavel!=NULL){
            rede->adicionar(new Disciplina(sigla, nome, responsavel));
            cout << "Criado com sucesso" << endl;
        }
        else
            cout << "Somente professores podem ser responsaveis por disciplinas" << endl;
    }
}
void logar(RedeSocial* rede){
    cout << "Escolha um perfil: " << endl;
    rede->imprimir();
    unsigned int numero;
    cout << "Digite o id ou 0 para cancelar: ";
    cin >> numero;
    Professor* p1 = dynamic_cast<Professor*>(rede->getPerfis()->at(numero-1));
    Disciplina* d1 = dynamic_cast<Disciplina*>(rede->getPerfis()->at(numero-1));
    if (p1 != NULL){
        p1->imprimir();
    }
    else if (d1 != NULL){
        d1->imprimir();
    }
    else{
        rede->getPerfis()->at(numero)->imprimir();
    }
    int escolha;
    // uso o nome logado para evitar usar rede->getPerfis()[numero]
    Perfil* logado = rede->getPerfis()->at(numero);
    cout << "Escolha uma opcao: " << endl;
    cout << "1) Ver publicacoes feitas \n2) Ver publicacoes recebidas \n3) Fazer publicacao \n4) Seguir perfil \n0) Deslogar" << endl;
    cin >> escolha;
    if (escolha == 1){
        cout << "Publicacoes feitas: " << endl;
        list<Publicacao*>::iterator pubFeitas = logado->getPublicacoesFeitas()->begin();
        while (pubFeitas!=logado->getPublicacoesFeitas()->end()){
            (*pubFeitas)->imprimir();
            pubFeitas++;
        }
    }
    else if (escolha == 2){
        cout << "Publicacoes recebidas: " << endl;
        int contador=1;
        list<Publicacao*>::iterator pubR = logado->getPublicacoesRecebidas()->begin();
        while (pubR!=logado->getPublicacoesRecebidas()->end()){
            cout << contador << ") ";
            (*pubR)->imprimir();
            cout << endl;
        }
        cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
        int numeroMensagem;
        cin >> numeroMensagem;
        if (numeroMensagem!=0){
            numeroMensagem -= 1;
            list<Publicacao*>::iterator it = logado->getPublicacoesRecebidas()->begin();
            advance(it, numeroMensagem);

            (*it)->curtir(logado);
        }
    }
    // cria publicacao
    else if (escolha == 3){
        string evento;
        cout << "Evento (s/n): ";
        cin >> evento;
        string data;
        if (evento == "s"){
            cout << "Data: ";
            cin >> data;
        }
        string texto;
        cout << "Texto: ";
        cin.ignore(100, '\n');
        getline(cin, texto);

        if (evento=="s"){
            logado->publicar(texto, data);
        }
        else{
            logado->publicar(texto);
        }
    }
    else if (escolha == 4 && d1 == NULL){
        cout << "Perfil:" << endl;
        rede->imprimir();
        cout << "Digite o numero ou 0 para cancelar: ";
        int escolherSeguir;
        cin >> escolherSeguir;
        rede->getPerfil(escolherSeguir)->adicionarSeguidor(logado);
        cout << "Adicionado com sucesso" << endl;
    }
}


int main() {
    string nome;
    cout << "Arquivo: ";
    cin >> nome;
    PersistenciaDaRede* per = new PersistenciaDaRede("rede.txt");
    RedeSocial* rede = per->carregar();

    int opcao = -1;
    while (opcao != 0){
        cout << "Escolha uma opcao: " << endl;
        cout << "1) Cadastrar Perfil" << endl;
        cout << "2) Cadastrar Disciplina" << endl;
        cout << "3) Logar" << endl;
        cout << "0) Terminar" << endl;
        cin >> opcao;
        if (opcao == 1)
            cadastrarPerfil(rede);
        else if (opcao == 2)
            cadastrarDisciplina(rede);
        else if (opcao == 3)
            logar(rede);
        else if (opcao == 0){
            string a;
            cout << "Deseja salvar? (s/n) ";
            cin >> a;
            if (a=="s"){
                per->salvar(rede);
            }
        }
    }
    delete rede;
    return 0;
}
