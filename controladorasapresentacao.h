#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras e implementa��es de m�todos.

class CntrApresentacaoControle{
    private:
        Matricula matricula;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoUsuario *cntrApresentacaoUsuario;
        IApresentacaoProjeto *cntrApresentacaoProjeto;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoUsuario(IApresentacaoUsuario*);
        void setCntrApresentacaoProjeto(IApresentacaoProjeto*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoUsuario(IApresentacaoUsuario *cntr){
    cntrApresentacaoUsuario = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoProjeto(IApresentacaoProjeto *cntr){
    cntrApresentacaoProjeto = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
    public:
        bool autenticar(Matricula*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoUsuario:public IApresentacaoUsuario{
    private:
        IServicoUsuario *cntrServicoUsuario;
        void consultarDadosUsuario(Matricula);
        void editarDadosUsuario(Matricula);
        bool descadastarUsuario(Matricula);

    public:
        void executar(Matricula);
        void cadastrar();
        void setCntrServicoUsuario(IServicoUsuario*);
};

inline void CntrApresentacaoUsuario::setCntrServicoUsuario(IServicoUsuario *cntr){
    cntrServicoUsuario = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoProjeto:public IApresentacaoProjeto{
    private:
        IServicoProjeto *cntr;

        void cadastrarProjeto(Matricula);
        void descadastrarProjeto(Codigo);
        void consultarProjeto(Codigo);
        void editarProjeto(Projeto);

        // void cadastrarTarefa(Codigo);
        // void descadastrarTarefa(Codigo);
        // void consultarTarefa(Codigo);
        // void editarTarefa(Tarefa);
    public:
        void executar(Matricula);
        void setCntrServicoProjeto(IServicoProjeto*);
};

inline void CntrApresentacaoProjeto::setCntrServicoProjeto(IServicoProjeto *cntr){
    this->cntr = cntr;
}


#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
