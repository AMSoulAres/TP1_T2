#include "controladorasapresentacao.h"
#include "dominios.h"
#include "stubs.h"

//--------------------------------------------------------------------------------------------
// Implementa��es de m�todos de classes controladoras.

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar usuario.";
    char texto5[]="3 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de sele��o de servi�o.

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de Usuario.";
    char texto8[]="2 - Selecionar servicos do projeto.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela inicial.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&matricula)){                         // Solicita autentica��o.
                        bool apresentar = true;                                                 // Controle de la�o.
                        while(apresentar){

                            // Apresenta tela de sele��o de servi�o.

                            CLR_SCR;                                                            // Limpa janela.

                            cout << texto6 << endl;                                             // Imprime nome do campo.
                            cout << texto7 << endl;                                             // Imprime nome do campo.
                            cout << texto8 << endl;                                             // Imprime nome do campo.
                            cout << texto9 << endl;                                             // Imprime nome do campo.

                            campo = getch() - 48;                                               // Leitura do campo de entrada e convers�o de ASCII.

                            switch(campo){
                                case 1:cntrApresentacaoUsuario->executar(matricula);
                                        break;
                                case 2: cntrApresentacaoProjeto->executar(matricula);     // Solicita servi�o de produto financeiro.
                                        break;
                                case 3: apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        CLR_SCR;                                                                // Limpa janela.
                        cout << texto10 << endl;                                                // Imprime mensagem.
                        getch();                                                                // Leitura de caracter digitado.
                    }
                    break;
            case 2: cntrApresentacaoUsuario->cadastrar();
                    break;
            case 3: apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Matricula *matricula){

    // Mensagens a serem apresentadas na tela de autentica��o.

    char texto1[]="Digite a matricula : ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    StubServicoAutenticacao stubA;
    Senha senha;                                                                                // Instancia a classe Senha.

    while(true){

        // Apresenta tela de autentica��o.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << " ";                                                                  // Imprime nome do campo.
        cin >> campo1;                                                                          // L� valor do campo.
        cout << texto2 << " ";                                                                  // Imprime nome do campo.
        cin >> campo2;                                                                          // L� valor do campo.

        try{
            matricula->setMatricula(string(campo1));                                                      // Atribui valor ao Matricula.
            senha.setSenha(string(campo2));                                                     // Atribui Valor � senha.
            break;                                                                              // Abandona la�o em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exce��o devido a formato incorreto.
            CLR_SCR;                                                                            // Limpa janela.
            cout << texto3 << endl;                                                             // Informa formato incorreto.
            getch();                                                                            // L� caracter digitado.
        }
    }
    return (cntr->autenticar(*matricula, senha));                                                     // Solicita servi�o de autentica��o.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::executar(Matricula matricula){

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados do usuario.";
    char texto3[]="2 - Editar dados de usuario.";
    char texto4[]="3 - Descadastrar usuario.";
    char texto5[]="4 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela de sela��o de servi�o.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.

        switch(campo){
            case 1: consultarDadosUsuario(matricula);
                    break;
            case 2: editarDadosUsuario(matricula);
                    break;
            case 3: descadastarUsuario(matricula);
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::cadastrar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char textoNome[] = "Nome            :";
    char textoMatricula[] = "Matricula       :";
    char textoSenha[] = "Senha           :";

    char textoFmtErro[]="Dados em formato incorreto. Digite algo.";
    char textoSucesso[]="Sucesso no cadastramento. Digite algo.";
    char textoFalha[]="Falha no cadastramento. Digite algo.";

    char campoNome[20], campoMatricula[80], campoSenha[80];                                       // Cria campos para entrada dos dados.

    int campo;
    // Instancia os dom�nios.

    Nome nome;
    Matricula matricula;
    Senha senha;

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;                                                                    // Imprime solicita��o ao usu�rio.
    cout << textoNome << " ";                                                                     // Imprime nome do campo.
    cin.getline(campoNome, sizeof(campoNome));                                                        // L� valor do campo composto.

    cout << textoMatricula << " ";                                                                     // Imprime nome do campo.
    cin.getline(campoMatricula, sizeof(campoMatricula)); // L� valor do camp

    //cout << "Valor lido" << campoMatricula << " ";
                                                                                 // L� valor do campo.
    cout << textoSenha << " ";                                                                     // Imprime nome do campo.
    cin.getline(campoSenha, sizeof(campoSenha));                                                                             // L� valor do campo.
                                                                          // L� valor do campo.
    //cout << "Valor lido" << campoSenha << " ";

    try{
        nome.setNome(string(campoNome));
        matricula.setMatricula(string(campoMatricula));
        senha.setSenha(string(campoSenha));
    }
    catch(invalid_argument &exp){
        cout << textoFmtErro << endl;
        cout << "1 - Tentar novamente." << endl;                                                                // Informa formato incorreto.
        cout << "2 - Voltar." << endl;                                                                // Informa formato incorreto.
        campo = getch() - 48;                                                                                // Leitura de caracter digitado.

        if(campo == 2);
            return;
    }

    // Instancia e inicializa entidades.

    Usuario usuario;

    usuario.setNome(nome);
    usuario.setMatricula(matricula);
    usuario.setSenha(senha);

    // Cadastra usu�rio e Projeto.

    if(cntrServicoUsuario->cadastrar(usuario)){
            cout << textoSucesso << endl;                                                                    // Informa sucesso.
            getch();
            return;
        }

    cout << textoFalha << endl;                                                                            // Informa falha.
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::consultarDadosUsuario(Matricula matricula){
    char texto[]="Servico consultar dados de usuario nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                      // Imprime nome do campo.
    getch();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::editarDadosUsuario(Matricula matricula){
    char texto[]="Servico editar dados de usuario não implementado. Digite algo.";             // Mensagem a ser apresentada.
    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                      // Imprime nome do campo.
    getch();
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoUsuario::descadastarUsuario(Matricula matricula){
    char texto[]="Servico descadastrar usuário nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                      // Imprime nome do campo.
    getch();
    return false;
}
//--------------------------------------------------------------------------------------------

void CntrApresentacaoProjeto::executar(Matricula matricula){

    // Mensagens a serem apresentadas tela completa de produtos financeiros.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Consultar projeto";
    char texto3[] ="2 - Cadastrar projeto";
    char texto4[] ="3 - Descadastrar projeto.";
    char texto5[] ="4 - Editar Projeto";
    char texto6[] ="5 - Retornar.";

    char campoCodigo[12];

    int campo;
                                                                                      // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de la�o.
    Projeto projeto;
    Codigo codigo;                                                                 // Imprime nome do campo.
    while(apresentar){

        // Apresenta tela completa de produtos financeiros.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;
        cout << texto5<< endl;                                                                 // Imprime nome do campo.                                                                // Imprime nome do campo.
        cout << texto6 << endl;


        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.

        switch(campo){
            case 1: consultarProjeto(codigo);
                    break;
            case 2: cadastrarProjeto(matricula);
                    break;
            case 3: descadastrarProjeto(codigo);
                    break;
            case 4: editarProjeto(projeto);
                    break;
            case 5: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProjeto::consultarProjeto(Codigo Codigo){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    char texto[]="Servico consultar Projeto nao implementado. Digite algo.";                      // Mensagem a ser apresentada.

    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                                      // Imprime nome do campo.
    getch();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProjeto::cadastrarProjeto(Matricula matricula){

        // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char textoNome[] = "Nome            :";
    char textoCodigo[] = "Código       :";
    char textoDescricao[] = "Descrição           :";

    char textoFmtErro[]="Dados em formato incorreto. Digite algo.";
    char textoSucesso[]="Sucesso no cadastramento. Digite algo.";
    char textoFalha[]="Falha no cadastramento. Digite algo.";

    char campoNome[40], campoCodigo[15], campoDescricao[40];                                       // Cria campos para entrada dos dados.

    int campo;
    // Instancia os dom�nios.

    Texto nome;
    Codigo codigo;
    Texto descricao;

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;                                                                    // Imprime solicita��o ao usu�rio.
    cout << textoNome << " ";                                                                     // Imprime nome do campo.
    cin.getline(campoNome,sizeof(campoNome));                                                        // L� valor do campo composto.

    cout << textoCodigo << " ";                                                                     // Imprime nome do campo.
    cin.getline(campoCodigo, sizeof(campoCodigo)); // L� valor do camp

    //cout << "Valor lido" << campoMatricula << " ";
                                                                                 // L� valor do campo.
    cout << textoDescricao << " ";                                                                     // Imprime nome do campo.
    cin.getline(campoDescricao, sizeof(campoDescricao));                                                                             // L� valor do campo.
                                                                          // L� valor do campo.
    //cout << "Valor lido" << campoSenha << " ";

    try{
        nome.setTexto(string(campoNome));
        codigo.setCodigo(string(campoCodigo));
        descricao.setTexto(string(campoDescricao));
    }
    catch(invalid_argument &exp){
        cout << textoFmtErro << endl;
        cout << "1 - Tentar novamente." << endl;                                                                // Informa formato incorreto.
        cout << "2 - Voltar." << endl;                                                                // Informa formato incorreto.
        campo = getch() - 48;                                                                                // Leitura de caracter digitado.

        if(campo == 2);
            return;
    }

    // Instancia e inicializa entidades.

    Projeto projeto;

    projeto.setNome(nome);
    projeto.setCodigo(codigo);
    projeto.setTexto(descricao);

    // Cadastra usu�rio e Projeto.

    if(cntr->cadastrarProjeto(projeto, matricula)){
            cout << textoSucesso << endl;                                                                    // Informa sucesso.
            getch();
            return;
        }

    cout << textoFalha << endl;                                                                            // Informa falha.
    getch();

    return;

}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoProjeto::descadastrarProjeto(Codigo codigo){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    char texto[]="Servico descadastrar projeto nao implementado. Digite algo.";    // Mensagem a ser apresentada.

    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                                      // Imprime nome do campo.
    getch();

}

//--------------------------------------------------------------------------------------------


void CntrApresentacaoProjeto::editarProjeto(Projeto projeto){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir c�digo seguinte pela implementa��o do m�todo.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    char texto[]="Servico editar projeto nao implementado. Digite algo.";                   // Mensagem a ser apresentada.

    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                                      // Imprime nome do campo.
    getch();

}
