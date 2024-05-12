#include "catch.hpp"
#include "Usuario.hpp"

TEST_CASE("Usuario deve saber informar seu primeiro nome") {
	Usuario thiago("Thiago Santos");

	std::string primeiroNome = thiago.recuperaPrimeiroNome();

	REQUIRE("Thiago" == primeiroNome);
}