#include <iostream>
#include <string>

#include "src/Pessoa.h"
#include "src/Data.h"
#include "src/Agenda.h"


int main ()
{

    Agenda a;

    int lidas = a.carregaArquivo("pessoas.txt");

    if (lidas >= 0)
        std::cout << lidas << " pessoas carregadas." << std::endl;

    a.menu();
    return 0;
}