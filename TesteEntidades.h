#ifndef TESTEENTIDADES_H_INCLUDED
#define TESTEENTIDADES_H_INCLUDED

#include "Entidades.h"
#include "dominios.h"

class TUUsuario
{
private:
    Usuario *usuario;            // Refer�ncia para unidade em teste.
    int estado;                  // Estado do teste.
    void setUp();                // M�todo para criar unidade em teste.
    void tearDown();             // M�todo para destruir unidade em teste.
    void testarCenarioSucesso(); // Cen�rio de teste.
public:
    const static int SUCESSO = 0; // Defini��o de constante para reportar resultado de teste.
    const static int FALHA = -1;  // Defini��o de constante para reportar resultado de teste.
    int run();                    // M�todo para executar teste.
};

//============================================================================================

class TUProjeto
{
private:
    Projeto *projeto;            // Refer�ncia para unidade em teste.
    int estado;                  // Estado do teste.
    void setUp();                // M�todo para criar unidade em teste.
    void tearDown();             // M�todo para destruir unidade em teste.
    void testarCenarioSucesso(); // Cen�rio de teste.
public:
    const static int SUCESSO = 0; // Defini��o de constante para reportar resultado de teste.
    const static int FALHA = -1;  // Defini��o de constante para reportar resultado de teste.
    int run();                    // M�todo para executar teste.
};

//============================================================================================

class TUTarefa
{
private:
    Tarefa *tarefa;            // Refer�ncia para unidade em teste.
    int estado;                  // Estado do teste.
    void setUp();                // M�todo para criar unidade em teste.
    void tearDown();             // M�todo para destruir unidade em teste.
    void testarCenarioSucesso(); // Cen�rio de teste.
public:
    const static int SUCESSO = 0; // Defini��o de constante para reportar resultado de teste.
    const static int FALHA = -1;  // Defini��o de constante para reportar resultado de teste.
    int run();                    // M�todo para executar teste.
};
#endif // TESTEENTIDADES_H_INCLUDED
