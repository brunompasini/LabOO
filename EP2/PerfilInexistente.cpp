#include "PerfilInexistente.h"
#include <iostream>
#include <string>
#include <stdexcept>
PerfilInexistente::PerfilInexistente():
    logic_error ("Perfil Inexistente") {}

PerfilInexistente::~PerfilInexistente()
{
    //dtor
}
