#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>

using namespace std;

/// @brief Padrao para representacao de usuario:
///
/// Usuario contem entidades Nome, Matricula e Senha.
class Usuario
{
private:
    Nome nome; // Declarar cada atributo da classe.
    Matricula matricula;
    Senha senha;

public:
    /// - Armazena o nome do Usuario caso seja valido
    ///
    /// - Caso o nome seja invalido ele lança exceção
    ///
    /// - @param Nome nome
    ///
    /// - @throw invalid argument
    ///
    void setNome(const Nome &nome); // Declarar m�todo set para cada atributo.
    ///
    /// - Retorna o nome
    ///
    /// - @return nome
    ///
    Nome getNome() const;
    ///
    /// - Armazena a matricula do Usuario caso seja valido
    ///
    /// - Caso a matricula seja invalido eh lancada exceção
    ///
    /// - @param Matricula matricula
    ///
    /// - @throw invalid argument
    void setMatricula(const Matricula &matricula); // Declarar m�todo set para cada atributo.
    ///
    /// - Retorna a matricula
    ///
    /// - @return matricula
    ///
    Matricula getMatricula() const; // Declarar m�todo get para cada atributo.
    ///
    /// - Armazena a senha do Usuario caso seja valido
    ///
    /// - Caso a senha seja invalida é lançada exceção
    ///
    /// - @param Senha senha
    ///
    /// - @throw invalid argument
    ///
    void setSenha(const Senha &senha); // Declarar m�todo set para cada atributo.
    ///
    /// - Retorna a senha
    ///
    /// - @return senha
    ///
    Senha getSenha() const; // Declarar m�todo get para cada atributo.
};

inline void Usuario::setNome(const Nome &nome)
{
    this->nome = nome;
}

inline Nome Usuario::getNome() const
{
    return nome;
}

inline void Usuario::setMatricula(const Matricula &matricula)
{
    this->matricula = matricula;
}

inline Matricula Usuario::getMatricula() const
{
    return matricula;
}

inline void Usuario::setSenha(const Senha &senha)
{
    this->senha = senha;
}

inline Senha Usuario::getSenha() const
{
    return senha;
}

//==========================================================================

/// @brief Padrao para representacao de projeto
///
/// Avaliacao contem nome, codigo, descricao
class Projeto
{

private:
    Texto nome;
    Codigo codigo;
    Texto descricao;

public:
    ///
    /// - Armazena o nome do Projeto caso seja valido
    ///
    /// - Caso o nome seja invalido eh lancada exceção
    ///
    /// - @param Texto nome
    ///
    /// - @throw invalid argument
    ///
    void setNome(const Texto &nome);
    ///
    /// - Retorna o nome
    ///
    /// - @return nome
    ///
    Texto getNome() const;
    ///
    /// - Armazena o codigo do Projeto caso seja valido
    ///
    /// - Caso o codigo seja invalido eh lancada exceção
    ///
    /// - @param Codigo codigo
    ///
    /// - @throw invalid argument
    ///
    void setCodigo(const Codigo &codigo);
    ///
    /// - Retorna o codigo
    ///
    /// - @return codigo
    ///
    Codigo getCodigo() const;
    ///
    /// - Armazena o texto do Projeto caso seja valido
    ///
    /// - Caso o texto seja invalido ele lança exceção
    ///
    /// - @param Texto descricao
    ///
    /// - @throw invalid argument
    ///
    void setTexto(const Texto &descricao);
    ///
    /// - Retorna o descricao
    ///
    /// - @return descricao
    ///
    Texto getTexto() const;
};

inline void Projeto::setNome(const Texto &nome)
{
    this->nome = nome;
}

inline Texto Projeto::getNome() const
{
    return nome;
}

inline void Projeto::setCodigo(const Codigo &codigo)
{
    this->codigo = codigo;
}

inline Codigo Projeto::getCodigo() const
{
    return codigo;
}

inline void Projeto::setTexto(const Texto &descricao)
{
    this->descricao = descricao;
}

inline Texto Projeto::getTexto() const
{
    return descricao;
}

//==================================================================================

/// @brief Padrao para representacao de tarefa
///
/// Tarefa contem nome, codigo, inicio, termino e disciplina
class Tarefa
{

private:
    Texto nome;
    Codigo codigo;
    Data inicio;
    Data termino;
    Disciplina disciplina;

public:
    ///
    /// - Armazena o nome da Tarefa caso seja valido
    ///
    /// - Caso o nome seja invalido eh lancada exceção
    ///
    /// - @param Texto nome
    ///
    /// - @throw invalid argument
    void setNome(const Texto &nome);
    ///
    /// - Retorna o nome
    ///
    /// - @return nome
    ///
    Texto getNome() const;
    ///
    /// - Armazena o codigo de Tarefa caso seja valido
    ///
    /// - Caso o codigo seja invalido eh lancada exceção
    ///
    /// - @param Codigo codigo
    ///
    /// - @throw invalid argument
    void setCodigo(const Codigo &codigo);
    ///
    /// - Retorna o codigo
    ///
    /// - @return codigo
    ///
    Codigo getCodigo() const;
    ///
    /// - Armazena o o inicio da data em Tarefa caso seja valido
    ///
    /// - Caso o inicio da data seja invalido eh lancada exceção
    ///
    /// - @param Data inicio
    ///
    /// - @throw invalid argument
    void setInicio(const Data &inicio);
    ///
    /// - Retorna o inicio
    ///
    /// - @return inicio
    ///
    Data getInicio() const;
    ///
    /// - Armazena o termino da data em Tarefa caso seja valido
    ///
    /// - Caso o termino da data seja invalido eh lancada exceção
    ///
    /// - @param Data termino
    ///
    /// - @throw invalid argument
    void setTermino(const Data &termino);
    ///
    /// - Retorna o termino
    ///
    /// - @return termino
    ///
    Data getTermino() const;
    ///
    /// - Armazena a disciplica de Tarefa caso seja valido
    ///
    /// - Caso a disciplina seja invalida eh lancada exceção
    ///
    /// - @param Disciplina disciplina
    ///
    /// - @throw invalid argument
    void setDisciplina(const Disciplina &disciplina);
    ///
    /// - Retorna o disciplina
    ///
    /// - @return disciplina
    ///
    Disciplina getDisciplina() const;
};

inline void Tarefa::setNome(const Texto &nome)
{
    this->nome = nome;
}

inline Texto Tarefa::getNome() const
{
    return nome;
}

inline void Tarefa::setCodigo(const Codigo &codigo)
{
    this->codigo = codigo;
}

inline Codigo Tarefa::getCodigo() const
{
    return codigo;
}

inline void Tarefa::setInicio(const Data &inicio)
{
    this->inicio = inicio;
}

inline Data Tarefa::getInicio() const
{
    return inicio;
}

inline void Tarefa::setTermino(const Data &termino)
{
    this->termino = termino;
}

inline Data Tarefa::getTermino() const
{
    return termino;
}

inline void Tarefa::setDisciplina(const Disciplina &disciplina)
{
    this->disciplina = disciplina;
}

inline Disciplina Tarefa::getDisciplina() const
{
    return disciplina;
}

#endif // ENTIDADES_H_INCLUDED