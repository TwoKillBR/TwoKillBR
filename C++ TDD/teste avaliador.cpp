#include "catch.hpp"
#include "Avaliador.hpp"


Leilao emOrdemCrescente() {
	Lance primeiroLance(Usuario("Thiago Santos"), 1000);
	Lance segundoLance(Usuario("Bitelo Junior"), 2000);
	Leilao leilao("Fiat 147 0Km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);
	
	return leilao;
}

Leilao emOrdemDeCrescente() {
	Lance primeiroLance(Usuario("Thiago Santos"), 2000);
	Lance segundoLance(Usuario("Bitelo Junior"), 1000);
	Leilao leilao("Fiat 147 0Km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);
	
	return leilao;
}

TEST_CASE("Avaliador") {

	// Preparando ambiente
	Avaliador leiloeiro;
	SECTION("Leilões com ordem") {
		Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDeCrescente());

		SECTION("Deve recuperar maior lance de leilão") {

			// Executando o codigo a ser testado
			leiloeiro.avalia(leilao);

			// Verificando se tudo deu certo
			REQUIRE(2000 == leiloeiro.recuperaMaiorValor());

		}

		SECTION("Deve recuperar menor lance de leilão") {

			// Executando o codigo a ser testado
			leiloeiro.avalia(leilao);

			// Verificando se tudo deu certo
			REQUIRE(1000 == leiloeiro.recuperaMenorValor());
		}
	}
	SECTION("Deve recuperar os 3 maiores lances") {
		// Preparando ambiente
		Lance primeiroLance(Usuario("Thiago Santos"), 1000);
		Lance segundoLance(Usuario("Bitelo Junior"), 2000);
		Lance terceiroLance(Usuario("Roberval Almeida"), 1500);
		Lance quartoLance(Usuario("Tião Betoneira"), 2500);
		Leilao leilao("Fiat 147 0Km");
		leilao.recebeLance(primeiroLance);
		leilao.recebeLance(segundoLance);
		leilao.recebeLance(terceiroLance);
		leilao.recebeLance(quartoLance);

		// Executando o codigo a ser testado
		leiloeiro.avalia(leilao);

		// Verificando se tudo deu certo
		auto maiores3Lances = leiloeiro.recupera3MaioresLances();
		REQUIRE(3 == maiores3Lances.size());
		REQUIRE(2500 == maiores3Lances[0].recuperaValor());
		REQUIRE(2000 == maiores3Lances[1].recuperaValor());
		REQUIRE(1500 == maiores3Lances[2].recuperaValor());
	}
}



