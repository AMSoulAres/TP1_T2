#include "stubs.h"
#include "entidades.h"
#include "dominios.h"

//--------------------------------------------------------------------------------------------
// Valores usados como gatilhos de erros.

const string StubServicoAutenticacao::INVALIDO = "ABC456";
const string StubServicoUsuario::INVALIDO = "12345";
const string StubServicoProjeto::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementa��es dos m�todos de classes stub.

bool StubServicoAutenticacao::autenticar(Matricula matricula, Senha senha){
    if(senha.getSenha().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoUsuario::cadastrar(Usuario usuario){
    if(usuario.getMatricula().getMatricula().compare(INVALIDO) == 0)
        return false;
    return true;
}
bool StubServicoUsuario::descadastrar(Matricula matricula){
    if(matricula.getMatricula().compare(INVALIDO) == 0)
        return false;
    return true;
}
bool StubServicoUsuario::editar(Usuario usuario){
    if(usuario.getMatricula().getMatricula().compare(INVALIDO) == 0)
        return false;
    return true;
}

Usuario StubServicoUsuario::consultar(Matricula matricula){
    Nome nome;
    Senha senha;
    nome.setNome("Gabriel Amorim");
    senha.setSenha("XLR876");
    Usuario usuario;
    usuario.setNome(nome);
    usuario.setMatricula(matricula);
    usuario.setSenha(senha);

    if(matricula.getMatricula().compare(INVALIDO) == 0)
        return usuario;

    return usuario;
}

bool StubServicoProjeto::cadastrarProjeto(Projeto projeto, Matricula matricula){
    if(projeto.getCodigo().getCodigo().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProjeto::descadastrarProjeto(Codigo codigo){
    if(codigo.getCodigo().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProjeto::editarProjeto(Projeto projeto){
    if(projeto.getCodigo().getCodigo().compare(INVALIDO) == 0)
        return false;
    return true;
}

Projeto StubServicoProjeto::consultarProjeto(Codigo codigo){
        Codigo codigoQualquer;
        Texto nome;
        Texto descricao;
        codigo.setCodigo("02790195137");
        nome.setTexto("Projeto do Guigui e do Robertin");
        descricao.setTexto("Esse projeto tem que funcionar ne!");

        Projeto projeto;
        projeto.setCodigo(codigo);
        projeto.setNome(nome);
        projeto.setTexto(descricao);

    if(codigo.getCodigo().compare(INVALIDO) == 0)
        return projeto;

    return projeto;

}

bool StubServicoProjeto::editarTarefa(Codigo codigo){
    if(codigo.getCodigo().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProjeto::cadastrarTarefa(Tarefa tarefa){
    if(tarefa.getCodigo().getCodigo().compare(INVALIDO) == 0)
        return false;
    return true;
}

bool StubServicoProjeto::descadastrarTarefa(Codigo codigo){
    if(codigo.getCodigo().compare(INVALIDO) == 0)
        return false;
    return true;
}

Tarefa StubServicoProjeto::consultarTarefa(Codigo codigo){
        Tarefa tarefa;
        tarefa.setCodigo(codigo);

    if(codigo.getCodigo().compare(INVALIDO) == 0)
        return tarefa;

    return tarefa;

}
