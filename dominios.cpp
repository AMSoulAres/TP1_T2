#include <iostream>
#include "Dominios.h"
#include "ctype.h"
#include <regex>

// --------------------------------------------------------------------------
// Implementa��es de m�todos de classe dom�nio.

// --------------------------------------------------------------------------
// M�todo para valida��o de valor.

void Codigo::validar(string codigo)
{
    regex codigo_modelo("^[0-9]{11}$");
    if (!regex_match(codigo, codigo_modelo))
        throw invalid_argument("Argumento invalido.");

    int digitos[11], verificacao, peso, i = 0, somatorio = 0;

    for (char &digito : codigo)
    {
        digitos[i] = digito - 48;
        i += 1;
    }

    i = 0;

    for (peso = 11; peso > 1; peso--)
    {
        somatorio = somatorio + (digitos[i] * peso);
        i++;
    }

    if ((somatorio * 10 % 11 == 1) || (somatorio * 10 % 11 == 0))
        verificacao = 0;
    else
        verificacao = 11 - (somatorio % 11);

    if (verificacao != digitos[10])
        throw invalid_argument("Argumento invalido.");
}

void Codigo::setCodigo(string c)
{
    validar(c);
    codigo = c;
}

void Data::validar(string data)
{
    int ano = stoi(data.substr(6, 2));
    bissexto = false;

    regex data_modelo("^(0[1-9]|[1-2][0-9]|3[0-1])-(0[1-9]|1[0-2])-([0-9][0-9])$");
    if (!regex_match(data, data_modelo))
        throw invalid_argument("Argumento invalido.");

    if ((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0)))
        bissexto = true;
    else
        bissexto = false;

    if (data[3] == '0' && data[4] == '2')
    {
        if (data[0] == '3')
            throw invalid_argument("Argumento invalido.");

        if (!bissexto && data[0] == '2' && data[1] == '9')
        {
            throw invalid_argument("Argumento invalido.");
        }
    }
}

void Data::setData(string x)
{
    validar(x);
    data = x;
}

void Matricula::validar(string matricula)
{
    regex matricula_modelo("^[A-Z]{4}[0-9]{4}$");
    if (!regex_match(matricula, matricula_modelo))
        throw invalid_argument("Argumento invalido.");
}

void Matricula::setMatricula(string m)
{
    validar(m);
    matricula = m;
}


void Nome::validar(string nome)
{
    regex nome_modelo("^([A-Z][a-z]+)( [A-Z][a-z]+)?( [A-Z][a-z]+)?$");
    if (!regex_match(nome, nome_modelo))
        throw invalid_argument("Argumento invalido.");

    if (nome.length() > Nome::LIMITE)
        throw invalid_argument("Argumento invalido.");
}
void Nome::setNome(string n)
{
    validar(n);
    nome = n;
}

void Senha::validar(string senha)
{
    unsigned int i;
    unsigned int j;
    int num_digit = 0;
    int num_letras = 0;
    if (senha.length() != 6)
    {
        throw invalid_argument("Tamanho incorreto");
    }
    for (i = 0; i < senha.length(); i++)
    {
        if (!isdigit(senha[i]))
        {
            if (!(senha[i] >= 'A' && senha[i] <= 'Z'))
            {
                throw invalid_argument("Os caracteres devem ser apenas alfanumericos e maiusculos, incluindo letras e numeros");
            }
        }

        for (j = 0; j < senha.length(); j++)
        {
            if (senha[i] == senha[j] && i != j)
            {
                throw invalid_argument("Nao podem haver caracteres repetidos");
            }
        }
        if (isdigit(senha[i]))
            num_digit++;

        if (senha[i] >= 'A' && senha[i] <= 'Z')
            num_letras++;
    }

    if (num_digit < 2 || num_letras < 2)
        throw invalid_argument("Erro, devem haver ao menos 2 letras e 2 digitos");
}

void Senha::setSenha(string n)
{
    validar(n);
    senha = n;
}

void Texto::validar(string texto)
{
    bool special_char;
    char next;
    unsigned int i;

    if (texto.length() < 10 || texto.length() > 40)
    {
        throw invalid_argument("O tamanho do texto deve estar entre 10 e 40 caracteres.");
    }

    for (i = 0; i < texto.length(); i++)
    {
        if (texto[i] == '.' || texto[i] == ',' || texto[i] == '?' || texto[i] == '!' || texto[i] == ':' || texto[i] == '-')
        {
            {
                special_char = true;
            }
        }

        if (!isalpha(texto[i]))
        {
            if (texto[i] != ' ')
            {
                if (!special_char)
                {
                    throw invalid_argument("Caracteres devem estar no padrao (A-Z ou a-z), dígito (0-9) ou sinal de pontuacao ( . , ; ? ! : - )");
                }
            }
        }
        if (i < texto.length())
        {
            next = texto[i + 1];
            if (texto[i] == ' ' && next == ' ')
            {
                throw invalid_argument("Nao podem haver espacos em branco em sequencia.");
            }
            if (special_char && (next == '.' || next == ',' || next == '?' || next == '!' || next == ':' || next == '-'))
            {
                throw invalid_argument("Nao podem haver sinais de pontuacao em sequencia.");
            }
        }

        special_char = false;
    }
}

void Texto::setTexto(string n)
{
    validar(n);
    texto = n;
}

void Disciplina::validar(string disciplina)
{
    regex disciplina_modelo("^Arquitetura|Desenvolvimento|Gerenciamento|Implantacao|Requisitos|Teste$");
    if (!regex_match(disciplina, disciplina_modelo))
        throw invalid_argument("Argumento invalido.");
}

void Disciplina::setDisciplina(string d)
{
    validar(d);
    disciplina = d;
}
