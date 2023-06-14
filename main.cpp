#include <string.h>
#include <stdexcept>
#include <iostream>

#include "dominios.h"
#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "stubs.h"

using namespace std;

int main()
{
    // Declarar poteiros e instanciar controladoras.

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoUsuario *cntrApresentacaoUsuario;
    IApresentacaoProjeto *cntrApresentacaoProjeto;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoUsuario = new CntrApresentacaoUsuario();
    cntrApresentacaoProjeto = new CntrApresentacaoProjeto();

    // Instanciar stubs.

    IServicoAutenticacao *stubServicoAutenticacao;
    IServicoUsuario *stubServicoUsuario;
    IServicoProjeto *stubServicoProjeto;

    stubServicoAutenticacao = new StubServicoAutenticacao();
    stubServicoUsuario = new StubServicoUsuario();
    stubServicoProjeto = new StubServicoProjeto();

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoUsuario(cntrApresentacaoUsuario);
    cntrApresentacaoControle->setCntrApresentacaoProjeto(cntrApresentacaoProjeto);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

    cntrApresentacaoUsuario->setCntrServicoUsuario(stubServicoUsuario);

    cntrApresentacaoProjeto->setCntrServicoProjeto(stubServicoProjeto);

    cntrApresentacaoControle->executar();                                           // Solicitar servi�o.

    return 0;
}

