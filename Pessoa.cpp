
#include "Pessoa.h"

#include <iostream>
#include <string>

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

// Ainda falta fazer o setCPF e fazer um validador que rejeite menos que 11 numeros.

void Pessoa::setCPF(const std::string &nome)
{
    this->CPF;
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
    std::cout << getNome() << std::endl; 
    std::cout << getCPF() << std::endl; 
    getNascimento().leData();
}


void Pessoa::escreveNome()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Fiz assim pra limpar o buffer em caso da função ser chamada depois de um cin
    
    std::string nome;

    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    setNome(nome);
}

