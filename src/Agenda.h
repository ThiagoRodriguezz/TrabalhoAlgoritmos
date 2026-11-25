#ifndef AGENDA_H_
#define AGENDA_H_
#define MAX_P_PESSOAS 30

#include "Pessoa.h"
#include <fstream>


class Agenda
{
    private:
        Pessoa* pessoas[MAX_P_PESSOAS];
        int quantidade;

        // Função Extra de Debug
        bool cadastraDeLinha(const std::string &linha);

    public:
         
        // Construtor

        Agenda();

        // Destrutor

        ~Agenda();

        // Funções da classe

        void menu ();
        bool cadastraPessoa();
        void pessoasCadastradas();
        void listarPessoas();
        bool listarAniversariantes();
        bool pesquisaNome();
        bool pesquisaCPF();
        bool excluirPessoa();
        // bool apagarTodasPessoas();



        // Função Extra de Debug
        int  carregaArquivo(const std::string &caminho);

};


#endif