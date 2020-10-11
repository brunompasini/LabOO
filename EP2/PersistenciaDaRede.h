#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H
#include <iostream>
#include <string>
#include <fstream>
#include "Perfil.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "RedeSocial.h"

using namespace std;
class PersistenciaDaRede
{
    public:
        PersistenciaDaRede(string arquivo);
        virtual ~PersistenciaDaRede();

        void salvar(RedeSocial* r);
        RedeSocial* carregar();

    protected:
        string arquivo;

    private:
};

#endif // PERSISTENCIADAREDE_H
