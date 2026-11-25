#ifndef PESSOA_H
#define PESSOA_H


#include "Data.h"

// Dependencias necessarias.

#include <iostream>
#include <string>



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
        void ImprimeCPF() const;

        void escreveNome();
        void escreveCPF();
        void escreveNascimento();
        void escrevePessoa();

        // Funções Complementares

        static bool formataCPF( const std::string &CPF, std::string &formatado);
       

};


#endif