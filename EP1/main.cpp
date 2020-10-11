#include <iostream>
#include <string>


#define MAXIMO_PUBLICACOES 20
#define MAXIMO_SEGUIDORES 20
using namespace std;
#include "Perfil.h"
#include "RedeSocial.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Aluno.h"


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
    cin.ignore(100, '\n');
    getline(cin, nome);
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
        rede->adicionar(new Perfil(nusp, nome, email));
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
    cin.ignore(100, '\n');
    getline(cin, nome);
    cout << "Responsavel: " << endl;
    rede->imprimir();
    cout << "Digite o numero ou 0 para cancelar: ";
    int escolhe;
    cin >> escolhe;
    if (escolhe!=0){
        escolhe -= 1;
        // checa se eh professor o responsavel
        Professor* responsavel = dynamic_cast<Professor*>(rede->getPerfis()[escolhe]);
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
    int numero;
    cout << "Digite o numero ou 0 para cancelar: ";
    cin >> numero;
    numero -= 1;
    Professor* p1 = dynamic_cast<Professor*>(rede->getPerfis()[numero]);
    Disciplina* d1 = dynamic_cast<Disciplina*>(rede->getPerfis()[numero]);
    if (p1 != NULL){
        p1->imprimir();
    }
    else if (d1 != NULL){
        d1->imprimir();
    }
    else{
        rede->getPerfis()[numero]->imprimir();
    }
    int escolha;
    // uso o nome logado para evitar usar rede->getPerfis()[numero]
    Perfil* logado = rede->getPerfis()[numero];
    cout << "Escolha uma opcao: " << endl;
    cout << "1) Ver publicacoes feitas \n2) Ver publicacoes recebidas \n3) Fazer publicacao \n4) Seguir perfil \n0) Deslogar" << endl;
    cin >> escolha;
    if (escolha == 1){
        cout << "Publicacoes feitas: " << endl;
        for(int i=0; i<(logado->getQuantidadeDePublicacoesFeitas()); i++){
            logado->getPublicacoesFeitas()[i]->imprimir();
        }
    }
    else if (escolha == 2){
        cout << "Publicacoes recebidas: " << endl;
        for (int i=0; i<(logado->getQuantidadeDePublicacoesRecebidas());i++){
            cout << i+1 <<") ";
            logado->getPublicacoesRecebidas()[i]->imprimir();
        }
        cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
        int numeroMensagem;
        cin >> numeroMensagem;
        if (numeroMensagem!=0){
            numeroMensagem -=1;
            logado->getPublicacoesRecebidas()[numeroMensagem]->curtir(logado);
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
        escolherSeguir-=1;
        if (rede->getPerfis()[escolherSeguir]->adicionarSeguidor(logado)){
            cout << "Adicionado com sucesso" << endl;
        }
        else{
            cout << "Não foi possivel adicionar" << endl;
        }
    }
}


int main() {
    int tamanhoDaRede;
    cout << "Tamanho da rede: ";
    cin >> tamanhoDaRede;
    RedeSocial * rede = new RedeSocial(tamanhoDaRede);

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
    }
    delete rede;
    return 0;
}
