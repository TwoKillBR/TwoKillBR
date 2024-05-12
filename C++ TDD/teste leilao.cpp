#include "catch.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"

TEST_CASE("Leilão não deve receber lances consecutivos do mesmo usuario") {

	// Preparando ambiente
	Leilao leilao("Fiat 147 0Km");
	Usuario thiago("Thiago Santos");

	Lance primeiroLance(thiago, 1000);
	Lance segundoLance(thiago, 1500);

	// Executando o codigo a ser testado
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);

	// Verificando se tudo deu certo
	REQUIRE(1 == leilao.recuperaLances().size());
	REQUIRE(1000 == leilao.recuperaLances()[0].recuperaValor());
}
