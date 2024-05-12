#pragma once
#include <string>
#include "Usuario.hpp"

class Lance
{
private:
	Usuario usuario;
	float valor;
public:
	Lance(Usuario usuario, float valor);
	float recuperaValor() const;
	std::string recuperaNomeDeUsuario() const;
};

