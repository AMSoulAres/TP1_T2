#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
// Adequar as declara��es das interfaces de acordo com as necessidades.
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

// Forward declarations.

class IServicoAutenticacao;
class IServicoUsuario;
class IServicoProjeto;

//--------------------------------------------------------------------------------------------
// Declara��es das interfaces da camada de apresenta��o.

class IApresentacaoAutenticacao
{
public:
    virtual bool autenticar(Matricula *) = 0;
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
    virtual ~IApresentacaoAutenticacao() {}
};

class IApresentacaoUsuario
{
public:
    virtual void executar(Matricula) = 0;
    virtual void cadastrar() = 0;
    virtual void setCntrServicoUsuario(IServicoUsuario*) = 0;
    virtual ~IApresentacaoUsuario() {}
};

class IApresentacaoProjeto
{
public:
    virtual void executar(Matricula) = 0;
    virtual void setCntrServicoProjeto(IServicoProjeto *) = 0;
    virtual ~IApresentacaoProjeto() {}
};

//--------------------------------------------------------------------------------------------
// Declara��es das interfaces da camada de servi�o.

class IServicoAutenticacao
{
public:
    virtual bool autenticar(Matricula, Senha) = 0;
    virtual ~IServicoAutenticacao() {}
};

class IServicoUsuario
{
public:
    virtual bool cadastrar(Usuario) = 0;
    virtual bool descadastrar(Matricula) = 0;
    virtual bool editar(Usuario) = 0;
    virtual Usuario consultar(Matricula) = 0;
    virtual ~IServicoUsuario() {}
};


// Verificar qual tipo deve ser passado para consultar, editar e descadastrar. (Código ou o próprio objeto?)
class IServicoProjeto
{
public:
    virtual bool cadastrarProjeto(Projeto, Matricula) = 0;
    virtual Projeto consultarProjeto(Codigo) = 0;
    virtual bool editarProjeto(Projeto) = 0;
    virtual bool descadastrarProjeto(Codigo) = 0;

    virtual bool cadastrarTarefa(Tarefa) = 0;
    virtual Tarefa consultarTarefa(Codigo) = 0;
    virtual bool editarTarefa(Codigo) = 0;
    virtual bool descadastrarTarefa(Codigo) = 0;
    virtual ~IServicoProjeto() {}
};


#endif // INTERFACES_H_INCLUDED
