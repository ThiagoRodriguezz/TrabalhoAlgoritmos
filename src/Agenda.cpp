
#include "Agenda.h"
#include "Pessoa.h"
#include <limits>

//Dependencias Necessarias

#include <iostream>
#include <string>

// Construtores 

Agenda::Agenda()
{

    this->quantidade = 0;

    for ( int i = 0; i < quantidade; i++ )
    {
        pessoas[i] = nullptr;
    }
}


Agenda::~Agenda()
{
    for (int i = 0; i < quantidade; i++)
    {
        delete pessoas[i];
    }
}


// Funções da Classe

void Agenda::menu()
{

   int x;
    
    do 
    {
        std::cout << std::endl;
        std::cout << "0 - Sair do programa." << std::endl;
        std::cout << "1 - Cadastrar uma pessoa." << std::endl;
        std::cout << "2 - Listar todas as pessoas." << std::endl;
        std::cout << "3 - Listar aniversariantes do mês." << std::endl;
        std::cout << "4 - Pesquisar por nome." << std::endl;
        std::cout << "5 - Pesquisar por CPF." << std::endl;
        std::cout << "6 - Excluir pessoa." << std::endl;
        std::cout << "7 - Apagar todas as pessoas cadastradas." << std::endl;

        
        std::cout<< "\nOpção: ";
        std::cin >> x;
        std::cout << std::endl;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(x)
        {
            case 1: Agenda::cadastraPessoa(); break;
            case 2: Agenda::listarPessoas(); break;
            case 3: Agenda::listarAniversariantes(); break;
            case 4: Agenda::pesquisaNome(); break;
            case 5: Agenda::pesquisaCPF(); break;
            case 6: Agenda::excluirPessoa(); break;
            // case 7: Agenda::apagarTodasPessoas(); break;
            case 0: break;

            default: 
                std::cout <<"Valor diferente das opcoes [0,7] - " << x << "."<< std::endl;
        }

    }while ( x != 0 );
    
}


bool Agenda::cadastraPessoa()
{

    if ( quantidade >= MAX_P_PESSOAS )
    {
        std::cout << "Numero maximo de pessoas ja cadastrado." << std::endl; 
        return false;
    }

    Pessoa *p = new Pessoa();
    p->escrevePessoa();

    pessoas[quantidade] = p;
    quantidade++;
    return true;
}

void Agenda::pessoasCadastradas()
{
    if ( quantidade == 0 )
    {
        std::cout << "Nenhuma pessoa cadastrada." << std::endl;
        return;
    }

    for ( int i = 0; i < quantidade; i++ )
    {
        printf("[%d] - ", i+1);
        pessoas[i]->ImprimeNome();
    }

    std::cout << std::endl;


}

void Agenda::listarPessoas()
{

    if ( quantidade == 0 )
    {
        std::cout << "Nenhuma pessoa cadastrada." << std::endl;
        return;
    }

    for ( int i = 0; i < quantidade; i++)
    {
        pessoas[i]->ImprimePessoa();
    }

    std::cout << "Aperte ENTER para terminar...";
    getchar();
}

bool Agenda::listarAniversariantes()
{

    if ( quantidade == 0 )
    {
        std::cout << "Nenhuma pessoa cadastrada." << std::endl;
        return false;
    }

    int mes = 0;    
    bool valido = false;

    while (!valido)
    {
        std::cout << "Mes [1-12]: ";

        if (std::cin >> mes && mes >= 1 && mes <= 12)
        {
            valido = true;
        }
        else
        {
            std::cout << "Entrada invalida." << std::endl;
            std::cin.clear();                  // 1) tira o cin do estado de erro
            std::cin.ignore(1000, '\n');       // 2) descarta o que sobrou na linha
        }
    }

    std::cin.ignore(1000, '\n');

    bool anivesariantes = false;
    for ( int i = 0; i < quantidade; i++)
    {
        if ( pessoas[i]->getNascimento().getMes() == mes )
        {
            pessoas[i]->ImprimePessoa();
            anivesariantes = true;
        } 
    }

    if ( !anivesariantes )
    {
        std::cout << "\nNão existem aniversariantes cadastrados nesse mês\n" << std::endl;
    }
   
    std::cout << "Aperte ENTER para terminar...";
    getchar();

    return anivesariantes;
}

 bool Agenda::pesquisaNome()
 {

    if ( quantidade == 0 )
    {
        std::cout << "Nenhuma pessoa cadastrada." << std::endl;
        return false;
    }

    bool encontrado = false;
    std::string nome;
    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    for ( int i = 0; i < quantidade; i++)
    {
        if ( pessoas[i]->getNome() == nome )
        {
            pessoas[i]->ImprimePessoa();
            encontrado = true;
        } 
    }

    if ( !encontrado )
    {
        std::cout << "\nNão existem pessoas cadastradas com esse nome\n" << std::endl;
    }
   
    std::cout << "Aperte ENTER para terminar...";
    getchar();
    return encontrado;

 }

 bool Agenda::pesquisaCPF()
 {

    if ( quantidade == 0 )
    {
        std::cout << "Nenhuma pessoa cadastrada." << std::endl;
        return false;
    }

    bool encontrado = false;
    std::string CPF;
    std::string CPF_FORMATADO;

    std::cout << "CPF: ";
    std::getline(std::cin, CPF);

    if (!Pessoa::formataCPF(CPF, CPF_FORMATADO))
    {
        std::cout << "CPF invalido.\n" << std::endl;
        return false;
    }

    for ( int i = 0; i < quantidade; i++)
    {

        if ( pessoas[i]->getCPF() == CPF_FORMATADO )
        {
            pessoas[i]->ImprimePessoa();
            encontrado = true;
        } 
    }

    std::cout << "Aperte ENTER para terminar...";
    getchar();
    return encontrado;

 }

bool Agenda::excluirPessoa()
{


    if ( quantidade == 0 )
    {
        std::cout << "Nenhuma pessoa cadastrada." << std::endl;
        return false;
    }

    
    pessoasCadastradas();

    int indice = 0;
    std::cout << "\nQual pessoa voce deseja excluir? ";

    if ( scanf("%d", &indice) != 1 )
    {
        std::cout << "Valor invalido." << std::endl;
        return false;
    }

    if ( indice > quantidade || indice < 1 )
    {
        std::cout << "Indice invalido." << std::endl;
        return false;
    }

    
    delete pessoas[indice-1];

    for ( int i = indice - 1; i < quantidade; i++ )
    {
        pessoas[i] = pessoas[i+1];
    }

    pessoas[quantidade] = nullptr;
    quantidade--;

    std::cout << "Aperte ENTER para terminar...";
    getchar();
    
    return true;
}

// bool Agenda::apagarTodasPessoas()
// {

    

// }




// Função extra de debug

int Agenda::carregaArquivo(const std::string &caminho)
{
    std::ifstream arq(caminho.c_str());

    if (!arq.is_open())
    {
        std::cout << "Nao foi possivel abrir " << caminho << std::endl;
        return -1;
    }

    std::string linha;
    int cadastradas = 0;
    int numLinha = 0;

    while (quantidade < MAX_P_PESSOAS && std::getline(arq, linha))
    {
        numLinha++;

        if (!linha.empty() && linha.back() == '\r')   // arquivo salvo com CRLF
            linha.pop_back();

        if (!linha.empty())
        {
            if (cadastraDeLinha(linha))
                cadastradas++;
            else
                std::cout << "Linha " << numLinha << " ignorada: " << linha << std::endl;
        }
    }

    if (quantidade >= MAX_P_PESSOAS)
        std::cout << "Agenda cheia, o resto do arquivo nao foi lido." << std::endl;

    return cadastradas;
}

bool Agenda::cadastraDeLinha(const std::string &linha)
{
    int p1 = linha.find(';');
    int p2 = -1;

    if (p1 != -1)
        p2 = linha.find(';', p1 + 1);

    if (p1 == -1 || p2 == -1)
        return false;

    std::string nome    = linha.substr(0, p1);
    std::string cpfTxt  = linha.substr(p1 + 1, p2 - p1 - 1);
    std::string dataTxt = linha.substr(p2 + 1);

    std::string cpf;
    Data d;
    char formatado[50];

    bool ok = !nome.empty()
           && Pessoa::formataCPF(cpfTxt, cpf)
           && d.formataData(dataTxt.c_str(), formatado)
           && d.textToNum(formatado);

    if (ok)
    {
        Pessoa* p = new Pessoa();

        p->setNome(nome);
        p->setCPF(cpf);
        p->setNascimento(d.getDia(), d.getMes(), d.getAno());

        pessoas[quantidade] = p;
        quantidade++;
    }

    return ok;
}