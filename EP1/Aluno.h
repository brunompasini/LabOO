#ifndef ALUNO_H
#define ALUNO_H
#include "Perfil.h"
#include <string>
#include <iostream>
using namespace std;

class Aluno: public Perfil{
    public:
        Aluno(string nome);
        virtual ~Aluno();

    protected:

    private:
};

#endif // ALUNO_H
