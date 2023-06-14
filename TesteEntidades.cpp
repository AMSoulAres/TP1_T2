#include "TesteEntidades.h"

void TUUsuario::setUp()
{
    usuario = new Usuario();
    estado = SUCESSO;
}

void TUUsuario::tearDown()
{
    delete usuario;
}

void TUUsuario::testarCenarioSucesso()
{
    Nome nome;
    nome.setNome("Gabriel Amorim");
    usuario->setNome(nome);
    if (usuario->getNome().getNome() != "Gabriel Amorim")
        estado = FALHA;
    Matricula matricula;
    matricula.setMatricula("ABCD1234");
    usuario->setMatricula(matricula);
    if (usuario->getMatricula().getMatricula() != "ABCD1234")
        estado = FALHA;
    Senha senha;
    senha.setSenha("XLR876");
    usuario->setSenha(senha);
    if (usuario->getSenha().getSenha() != "XLR876")
        estado = FALHA;
}

int TUUsuario::run()
{
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

//==========================================================================

void TUProjeto::setUp()
{
    projeto = new Projeto();
    estado = SUCESSO;
}

void TUProjeto::tearDown()
{
    delete projeto;
}

void TUProjeto::testarCenarioSucesso()
{
    Texto nome;
    nome.setTexto("Projeto do Guigui e do Robertin");
    projeto->setNome(nome);
    if (projeto->getNome().getTexto() != "Projeto do Guigui e do Robertin")
        estado = FALHA;

    Codigo codigo;
    codigo.setCodigo("02790195137");
    projeto->setCodigo(codigo);
    if (projeto->getCodigo().getCodigo() != "02790195137")
        estado = FALHA;

    Texto descricao;
    descricao.setTexto("Esse projeto tem que funcionar ne!");
    projeto->setTexto(descricao);
    if (projeto->getTexto().getTexto() != "Esse projeto tem que funcionar ne!")
        estado = FALHA;
}

int TUProjeto::run()
{
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

//==================================================================================================

void TUTarefa::setUp()
{
    tarefa = new Tarefa();
    estado = SUCESSO;
}

void TUTarefa::tearDown()
{
    delete tarefa;
}

void TUTarefa::testarCenarioSucesso()
{
    Texto nome;
    nome.setTexto("tarefa do Guigui e do Robertin");
    tarefa->setNome(nome);
    if (tarefa->getNome().getTexto() != "tarefa do Guigui e do Robertin")
        estado = FALHA;

    Codigo codigo;
    codigo.setCodigo("02790195137");
    tarefa->setCodigo(codigo);
    if (tarefa->getCodigo().getCodigo() != "02790195137")
        estado = FALHA;

    Data inicio;
    inicio.setData("22-03-22");
    tarefa->setInicio(inicio);
    if (tarefa->getInicio().getData() != "22-03-22")
        estado = FALHA;

    Data termino;
    termino.setData("29-03-22");
    tarefa->setTermino(termino);
    if (tarefa->getTermino().getData() != "29-03-22")
        estado = FALHA;

    Disciplina disciplina;
    disciplina.setDisciplina("Implantacao");
    tarefa->setDisciplina(disciplina);
    if (tarefa->getDisciplina().getDisciplina() != "Implantacao")
        estado = FALHA;
}

int TUTarefa::run()
{
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

