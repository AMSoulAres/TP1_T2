#include "TesteDominios.h"

// --------------------------------------------------------------------------
// Implementa��es de m�todos de classe de teste de unidade.

void TUCodigo::setUp()
{
    codigo = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown()
{
    delete codigo;
}

void TUCodigo::testarCenarioSucesso()
{
    try
    {
        codigo->setCodigo("02790195137");
        if (codigo->getCodigo() != "02790195137")
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUCodigo::testarCenarioFalha()
{
    try
    {
        codigo->setCodigo("11111111111");
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (codigo->getCodigo() == "11111111111")
            estado = FALHA;
    }
}

int TUCodigo::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
//----------------------------------------------------------------------------------

void TUSenha::setUp()
{
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown()
{
    delete senha;
}

void TUSenha::testarCenarioSucesso()
{
    try
    {
        senha->setSenha("ABC123");
        if (senha->getSenha() != "ABC123")
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUSenha::testarCenarioFalha()
{
    try
    {
        senha->setSenha("AAA111");
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (senha->getSenha() == "AAA111")
            estado = FALHA;
    }
}

int TUSenha::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

//-------------------------------------------------------------------------------

void TUData::setUp()
{
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown()
{
    delete data;
}

void TUData::testarCenarioSucesso()
{
    try
    {
        data->setData("29-02-24");
        if (data->getData() != "29-02-24")
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUData::testarCenarioFalha()
{
    try
    {
        data->setData("35-21-11");
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (data->getData() == "35-21-11")
            estado = FALHA;
    }
}

int TUData::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

//---------------------------------------------------------------------------------

void TUMatricula::setUp()
{
    matricula = new Matricula();
    estado = SUCESSO;
}

void TUMatricula::tearDown()
{
    delete matricula;
}

void TUMatricula::testarCenarioSucesso()
{
    try
    {
        matricula->setMatricula("AAAA1111");
        if (matricula->getMatricula() != "AAAA1111")
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUMatricula::testarCenarioFalha()
{
    try
    {
        matricula->setMatricula("ABCDEFGH");
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (matricula->getMatricula() == "ABCDEFGH")
            estado = FALHA;
    }
}

int TUMatricula::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUNome::setUp()
{
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown()
{
    delete nome;
}

void TUNome::testarCenarioSucesso()
{
    try
    {
        nome->setNome("Gabriel Amorim");
        if (nome->getNome() != "Gabriel Amorim")
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUNome::testarCenarioFalha()
{
    try
    {
        nome->setNome("Robertin Da Massaaaaaaaaaa");
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (nome->getNome() == "Robertin Da Massaaaaaaaaaa")
            estado = FALHA;
    }
}

int TUNome::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

//=======================================================================================

void TUTexto::setUp()
{
    texto = new Texto();
    estado = SUCESSO;
}

void TUTexto::tearDown()
{
    delete texto;
}

void TUTexto::testarCenarioSucesso()
{
    try
    {
        texto->setTexto("Um texto qualquer, cheio de informacoes");
        if (texto->getTexto() != "Um texto qualquer, cheio de informacoes")
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUTexto::testarCenarioFalha()
{
    try
    {
        texto->setTexto("Cheiao de erro essa parada po   !!");
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (texto->getTexto() == "Cheiao de erro essa parada po   !!")
            estado = FALHA;
    }
}

int TUTexto::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
