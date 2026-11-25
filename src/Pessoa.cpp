#include "Pessoa.h"

//Dependencias Necessarias

#include <iostream>
#include <string>

// Metodos da Classe Pessoa

// Construtor

Pessoa::Pessoa() : nome(""), CPF("")
{
}

// Destrutor

Pessoa::~Pessoa()
{
}

// Setters

void Pessoa::setNome(const std::string &nome)
{
    this->nome = nome;
}


void Pessoa::setCPF(const std::string &CPF)
{
    this->CPF = CPF;
}

bool Pessoa::setNascimento( int dia, int mes, int ano )
{
    return this->nascimento.setData(dia, mes, ano);
}

// Getters

std::string Pessoa::getNome() const
{
    return this->nome;
}

std::string Pessoa::getCPF() const
{
    return this->CPF;
}

Data Pessoa::getNascimento() const
{
    return this->nascimento;
}

// Funções da Classe

void Pessoa::ImprimeNome() const
{

    std::cout << getNome() << std::endl; 

}

void Pessoa::ImprimePessoa() const
{

    std::cout << std::endl; 

    std::cout << "Nome: " << getNome() << std::endl; 
    std::cout << "CPF: " << getCPF() << std::endl; 
    std::cout << "Data de Nascimento: "; getNascimento().imprimeData();

    std::cout << std::endl; 
}


void Pessoa::escreveNome()
{
    std::string nome;
    bool valido = false;
    
    do 
    {
        std::cout << "Nome: ";
        std::getline(std::cin, nome);

            if ( nome.empty())
            {
                std::cout << "O nome nao pode ser vazio!\n";
                std::cout<< "Insira novamente."<< std::endl;
            }
            else
            {
                setNome(nome);
                valido = true;
            }

    } while( !valido );

}

void Pessoa::escreveCPF()
{
    std::string formatado = "";
    std::string CPF = "";

    bool valido = false;

    do 
    {
        std::cout << "CPF: ";
        std::getline(std::cin, CPF);

        if ( formataCPF(CPF, formatado) )
        {
            setCPF(formatado);
            valido = true;
        }
        else
        {
            std::cout<< "Insira novamente.\n"<< std::endl;
        }


    } while (!valido);

}

void Pessoa::escreveNascimento()
{
    this->nascimento.escreveData();
}

void Pessoa::escrevePessoa()
{
    escreveNome();
    escreveCPF();
    escreveNascimento();
}

// Funções Complementares

bool Pessoa::formataCPF(const std::string &texto, std::string &formatado)
{
    std::string digitos = "";
    bool valido = true;

    int tamanho = texto.size();  

    for (int i = 0; i < tamanho && valido; i++)
    {
        char c = texto[i];

        if (std::isdigit(static_cast<unsigned char>(c)))
            {
                digitos = digitos + c;
            }
        else if (c != '.' && c != '-')
            {
                valido = false;
            }
    }

    if ( valido && digitos.size() == 11)
    {
        formatado = digitos;
        return true;
    }

    std::cout<< "\nErro: CPF invalido." << std::endl;
    return false;
}