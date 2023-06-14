#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

///
/// @brief Padrao para representacao de codigo
///
/// Regras de formato:
///
/// - Formato DDDDDDDDDDX;
/// - D é dígito (0-9);
/// - Ponto eh precedido por letraX é dígito verificador calculado através de algorítmo módulo 11;
///

class Codigo
{

private:
    string codigo;
    void validar(string);

public:
    ///
    /// Armazena o codigo informado caso seja valido
    ///
    /// Lança exceção caso o codigo nao esteja de acordo com as regras de formato
    ///
    /// @param codigo codigo
    ///
    /// @throw invalid_argument
    ///
    void setCodigo(string n);
    ///
    /// Retorna o codigo armazenado
    ///
    /// @return codigo
    ///
    string getCodigo() const;
};

inline string Codigo::getCodigo() const
{
    return codigo;
};

///
/// @brief Padrao para representacao da data
///
/// Regras de formato:
///
/// - Formato DD-MES-ANO;
/// - DD - 01 a 31;
/// - MES - 01 a 12;
/// - ANO - 00 a 99;
/// - Deve ser levado em consideração se ano é ou não é bissexto;

class Data
{

private:
    bool bissexto;
    string data;
    void validar(string);

public:
    /// Armazena a Data informado caso seja valido
    ///
    /// Lança exceção caso a data nao esteja de acordo com as regras de formato
    ///
    /// @param data data
    ///
    /// @throw invalid_argument
    ///
    void setData(string n);
    ///
    /// Retorna a data armazenada
    ///
    /// @return data
    ///
    string getData() const;
};

inline string Data::getData() const
{
    return data;
};

///
/// @brief Padrao para representacao da matricula
///
/// Regras de formato:
///
/// - Formato LLLLDDDD;
/// - L é letra maiúscula (A-Z);
/// - D é dígito (0-9);

class Matricula
{

private:
    string matricula;
    void validar(string);

public:
    ///
    /// Armazena a matricula informada caso seja valido
    ///
    /// Lança exceção caso a matricula nao esteja de acordo com as regras de formato
    ///
    /// @param matricula matricula
    ///
    /// @throw invalid_argument
    ///
    void setMatricula(string n);

    ///
    /// Retorna a matricula armazenada
    ///
    /// @return matricula
    ///
    string getMatricula() const;
};

inline string Matricula::getMatricula() const
{
    return matricula;
};

///
/// @brief Padrao para representacao do nome
///
/// Regras de formato:
///
/// - Nome é composto por prenome e até dois sobrenomes;
/// - Texto (prenome mais sobrenomes e espaços em branco) é composto por total de até 20 caracteres;
/// - Cada caractere é letra (A-Z a-z) ou espaço em branco;
/// - Primeira letra de prenome ou de sobrenome é maiúscula (A-Z) e as outras são minúsculas (a-z);
/// - Não há espaços em branco em sequência
/// - Acentuação pode ser desconsiderada

class Nome
{

private:
    static const long unsigned int LIMITE = 20; // Declara��o para evitar n�meros m�gicos.
    string nome;
    void validar(string);

public:
    ///
    /// Armazena o nome informado caso seja valido
    ///
    /// Lança exceção caso o nome nao esteja de acordo com as regras de formato
    ///
    /// @param nome nome
    ///
    /// @throw invalid_argument
    ///
    void setNome(string n);

    ///
    /// Retorna o nome armazenado
    ///
    /// @return nome
    ///
    string getNome() const;
};

inline string Nome::getNome() const
{
    return nome;
}

///
/// @brief Padrao para representacao da senha
///
/// Regras de formato:
///
/// - Formato XXXXXX;
/// - Cada caractere X é letra maiúscula (A-Z) ou dígito (0-9);
/// - Não pode haver caractere duplicado;
/// - Existem pelo menos duas letras maiúsculas e dois dígitos;

class Senha
{

private:
    static const long unsigned int TAMANHO_MAXIMO = 6;
    string senha;

protected:
    void validar(string);

public:
    ///
    /// Armazena a senha informada caso seja valida
    ///
    /// Lança exceção caso a senha nao esteja de acordo com as regras de formato
    ///
    /// @param senha senha
    ///
    /// @throw invalid_argument
    ///
    void setSenha(string n);

    ///
    /// Retorna a senha armazenada
    ///
    /// @return senha
    ///
    string getSenha() const;
};

inline string Senha::getSenha() const
{
    return senha;
}

///
/// @brief Padrao para representacao do texto
///
/// Regras de formato:
///
/// - 10 a 40 caracteres;
/// - Cada caractere X é letra (A-Z ou a-z), dígito (0-9) ou sinal de pontuação ( . , ; ? ! : - );
/// - Não há espaços em branco em sequência;
/// - Não há sinal de pontuação (. , ; : ? ! -) em sequência;
/// - Acentuação pode ser desconsiderada

class Texto
{

private:
    string texto;

protected:
    void validar(string);

public:
    ///
    /// Armazena o texto informado caso seja valido
    ///
    /// Lança exceção caso o texto nao esteja de acordo com as regras de formato
    ///
    /// @param texto texto
    ///
    /// @throw invalid_argument
    ///
    void setTexto(string n);

    ///
    /// Retorna o texto armazenado
    ///
    /// @return texto
    ///
    string getTexto() const;
};

inline string Texto::getTexto() const
{
    return texto;
}

///
/// @brief Padrao para representacao da disciplina
///
/// Regras de formato:
///
/// -  Disciplinas disponíveis: Arquitetura, Desenvolvimento, Gerenciamento, Implantacao, Requisitos, Teste;

class Disciplina
{

private:
    string disciplina;
    void validar(string);

public:
    ///
    /// Armazena a disciplina informada caso seja valido
    ///
    /// Lança exceção caso a disciplina nao esteja de acordo com as regras de formato
    ///
    /// @param disciplina disciplina
    ///
    /// @throw invalid_argument
    ///
    void setDisciplina(string n);

    ///
    /// Retorna a disciplina armazenada
    ///
    /// @return disciplina
    ///
    string getDisciplina() const;
};

inline string Disciplina::getDisciplina() const
{
    return disciplina;
};

#endif // DOMINIOS_H_INCLUDED