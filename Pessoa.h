#ifndef PESSOA_H
#define PESSOA_H

// Dependencias necessarias.

#include <iostream>
#include <string>
#include "Data.h"

// Definição da Classe

class Pessoa
{
    private:
        std::string nome;
        std::string CPF;
        Data nascimento;
    public:


        // Construtores e Destrutor

        Pessoa();
        ~Pessoa();

        // Setters 

        void setNome ( const std::string &nome );
        void setCPF ( const std::string &CPF );
        bool setNascimento ( int dia, int mes, int ano );

        // Getters

        std::string getNome () const;
        std::string getCPF () const;
        Data getNascimento() const;

        // Funções da Classe

        void ImprimeNome() const;
        void ImprimePessoa() const;

        void escreveNome();
        void escrevePessoa();

};


#endif