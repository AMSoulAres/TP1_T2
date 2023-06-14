#ifndef TESTEDOMINIOS_H_INCLUDED
#define TESTEDOMINIOS_H_INCLUDED

// Incluir cabe�alhos.

#include "dominios.h"

// --------------------------------------------------------------------------
// Exemplo de declara��o de classe para teste de unidade de classe dom�nio.

class TUCodigo
{
private:
    Codigo *codigo;              // Refer�ncia para unidade em teste.
    int estado;                  // Estado do teste.
    void setUp();                // M�todo para criar unidade em teste.
    void tearDown();             // M�todo para destruir unidade em teste.
    void testarCenarioSucesso(); // Cen�rio de teste.
    void testarCenarioFalha();   // Cen�rio de teste.

public:
    const static int SUCESSO = 0; // Defini��o de constante para reportar resultado de teste.
    const static int FALHA = -1;  // Defini��o de constante para reportar resultado de teste.
    int run();                    // M�todo para executar teste.
};

//=============================================================================================
class TUSenha
{
private:
    Senha *senha;              // Refer�ncia para unidade em teste.
    int estado;                  // Estado do teste.
    void setUp();                // M�todo para criar unidade em teste.
    void tearDown();             // M�todo para destruir unidade em teste.
    void testarCenarioSucesso(); // Cen�rio de teste.
    void testarCenarioFalha();   // Cen�rio de teste.

public:
    const static int SUCESSO = 0; // Defini��o de constante para reportar resultado de teste.
    const static int FALHA = -1;  // Defini��o de constante para reportar resultado de teste.
    int run();                    // M�todo para executar teste.
};

//=========================================================================================================

class TUData
{
private:
    Data *data;                  // Refer�ncia para unidade em teste.
    int estado;                  // Estado do teste.
    void setUp();                // M�todo para criar unidade em teste.
    void tearDown();             // M�todo para destruir unidade em teste.
    void testarCenarioSucesso(); // Cen�rio de teste.
    void testarCenarioFalha();   // Cen�rio de teste.

public:
    const static int SUCESSO = 0; // Defini��o de constante para reportar resultado de teste.
    const static int FALHA = -1;  // Defini��o de constante para reportar resultado de teste.
    int run();                    // M�todo para executar teste.
};
//========================================================================================================

class TUMatricula
{
private:
    Matricula *matricula;                  // Refer�ncia para unidade em teste.
    int estado;                  // Estado do teste.
    void setUp();                // M�todo para criar unidade em teste.
    void tearDown();             // M�todo para destruir unidade em teste.
    void testarCenarioSucesso(); // Cen�rio de teste.
    void testarCenarioFalha();   // Cen�rio de teste.

public:
    const static int SUCESSO = 0; // Defini��o de constante para reportar resultado de teste.
    const static int FALHA = -1;  // Defini��o de constante para reportar resultado de teste.
    int run();                    // M�todo para executar teste.
};

//==========================================================================================================

class TUNome
{
private:
    Nome *nome;        // Refer�ncia para unidade em teste.
    int estado;                  // Estado do teste.
    void setUp();                // M�todo para criar unidade em teste.
    void tearDown();             // M�todo para destruir unidade em teste.
    void testarCenarioSucesso(); // Cen�rio de teste.
    void testarCenarioFalha();   // Cen�rio de teste.

public:
    const static int SUCESSO = 0; // Defini��o de constante para reportar resultado de teste.
    const static int FALHA = -1;  // Defini��o de constante para reportar resultado de teste.
    int run();                    // M�todo para executar teste.
};

//============================================================================================================

class TUTexto
{
private:
    Texto *texto;                // Refer�ncia para unidade em teste.
    int estado;                  // Estado do teste.
    void setUp();                // M�todo para criar unidade em teste.
    void tearDown();             // M�todo para destruir unidade em teste.
    void testarCenarioSucesso(); // Cen�rio de teste.
    void testarCenarioFalha();   // Cen�rio de teste.

public:
    const static int SUCESSO = 0; // Defini��o de constante para reportar resultado de teste.
    const static int FALHA = -1;  // Defini��o de constante para reportar resultado de teste.
    int run();                    // M�todo para executar teste.
};

// --------------------------------------------------------------------------

#endif // TESTEDOMINIOS_H_INCLUDED
