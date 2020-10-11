#include "PersistenciaDaRede.h"
#include <fstream>
using namespace std;
PersistenciaDaRede::PersistenciaDaRede(string arquivo)
{
    this->arquivo = arquivo;
}

PersistenciaDaRede::~PersistenciaDaRede()
{
    //dtor
}

void PersistenciaDaRede::salvar(RedeSocial* r)
{
    ofstream output;
    output.open(arquivo);
    if (output.fail()){
        cout << "Erro ao Salvar" <<endl;
    }

    //analisar os perfis da rede
    int estat[] = {0,0,0}; // vetor para guardar numero de cada tipo de perfil na ordem [aluno, prof, disc]
    for(unsigned int i=0;i< r->getPerfis()->size();i++){
        Aluno *a1 = dynamic_cast<Aluno*>(r->getPerfis()->at(i));
        Professor *p1 = dynamic_cast<Professor*>(r->getPerfis()->at(i));
        if (a1 != NULL){
            estat[0]++;
        }
        else if (p1 != NULL){
            estat[1]++;
        }
        estat[2]++;
    }
    output << Perfil::getUltimoId() << endl;
    output << estat[0] << endl;
    //for (unsigned int j=0; j< r->getPerfis()->size(); j++){
      //  Aluno* alun
    //}




    for(unsigned int o=1; o<= r->getPerfis()->size();o++){
        Pessoa* a = dynamic_cast<Pessoa*>(r->getPerfil(o));
        output << a->getId() << " " << a->getNumeroUSP() << " " << a->getNome() << " " << a->getEmail() << endl;
        }
    output.close();
}
RedeSocial* PersistenciaDaRede::carregar()
{
    ifstream entrada;
    entrada.open(arquivo);
    if (entrada.fail()){
        cout << "Erro ao Carregar" << endl;
    }
    RedeSocial* r = new RedeSocial();

    int ultimo;
    entrada >> ultimo;
    int qtd;
    entrada >> qtd;
    //ler todos os alunos
    for (int i=0;i<qtd;i++){
        int id;
        string nome;
        int numeroUSP;
        string email;
        entrada >> id >> numeroUSP >> nome >> email;
        Aluno* a = new Aluno(id,numeroUSP,nome,email);
        r->adicionar(a);
    }
        //ler todos os profs
    qtd = 0;
    entrada >> qtd;
    for (int j=0;j<qtd;j++){
        int id;
        string nome;
        int numeroUSP;
        string email;
        string departamento;
        entrada >> id >> numeroUSP >> nome >> email >> departamento;
        Professor* p = new Professor(id,numeroUSP,nome,email,departamento);
        r->adicionar(p);
    }
        //ler todos as disciplinas
    qtd = 0;
    entrada >> qtd;
    for (int k=0;k<qtd;k++){
        int id;
        string nome;
        int resp;
        string sigla;
        entrada >> id >> sigla >> nome >> resp;
        Professor* responsavel = dynamic_cast<Professor*>(r->getPerfil(resp));
        Disciplina* d = new Disciplina(id,sigla,nome,responsavel);
        r->adicionar(d);
    }
    //agora o que cada uma segue
    while(!entrada.eof()){
        int ido, dor;
        entrada >> ido >> dor;
        Perfil* seguido = r->getPerfil(ido);
        Perfil* seguidor = r->getPerfil(dor);
        seguido->adicionarSeguidor(seguidor);
    }

    entrada.close();
    return r;
}



