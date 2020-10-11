#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "Perfil.h"
#include "Professor.h"
#include <string>
#include <iostream>
class Disciplina : public Perfil
{
    public:
        Disciplina(string sigla, string nome, Professor* responsavel);
        virtual ~Disciplina();

        Professor* getResponsavel();
        string getSigla();

        void imprimir();

    protected:
        string sigla;
        string nome;
        Professor* responsavel;
};

#endif // DISCIPLINA_H
