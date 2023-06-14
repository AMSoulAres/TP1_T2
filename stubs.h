#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declara��es de classes stub.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Matricula, Senha);
};

//--------------------------------------------------------------------------------------------

class StubServicoUsuario:public IServicoUsuario {
    private:
        static const string INVALIDO;
    public:
        bool cadastrar(Usuario);
        Usuario consultar(Matricula);
        bool descadastrar(Matricula);
        bool editar(Usuario);

};

//--------------------------------------------------------------------------------------------

class StubServicoProjeto:public IServicoProjeto {
    private:
        static const string INVALIDO;
    public:
public:
    bool cadastrarProjeto(Projeto, Matricula);
    Projeto consultarProjeto(Codigo);
    bool editarProjeto(Projeto);
    bool descadastrarProjeto(Codigo);

    bool cadastrarTarefa(Tarefa);
    Tarefa consultarTarefa(Codigo);
    bool editarTarefa(Codigo);
    bool descadastrarTarefa(Codigo);

};

#endif // STUBS_H_INCLUDED
