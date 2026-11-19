#include "Data.h"

//Dependencias Necessarias

#include <iostream>
#include <string>

// Metodos da Classe Data

// Construtores


    Data::Data()
    {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }

    Data::Data( int dia, int mes, int ano )
    {

        if ( dataValida(dia, mes, ano))
        {
            setData(dia, mes, ano);
        }
        else
        {
            escreveData();
        }

    }

// Destrutor

    Data::~Data()
    {
    }

// Setters

bool Data::setDia(int dia)
{
    bool valido = false;
    
    if ( dia > 0 && dia <= 31 )
    {   
        this->dia = dia;
        valido = true;
    }

    return valido;
     
}


bool Data::setMes(int mes)
{
    bool valido = false;
    
    if ( mes > 0 && mes <= 12 )
    {   
        this->mes = mes;
        valido = true;
    }

    return valido;

}

bool Data::setAno(int ano)
{
    this->ano = ano;
    return true;
}

bool Data::setData( int dia, int mes, int ano )
{

    bool valido = false;
    
    if ( setDia(dia) && setMes(mes) && setAno(ano))
    {
        valido = true;
    }

    return valido;

}

// Getters

int Data::getDia()
{
    return this->dia;
}

int Data::getMes()
{
    return this->mes;
}

int Data::getAno()
{
    return this->ano;
}

// Funções Complementares

std::string Data::mesExtenso()
{

    std::string mes[12] {
                            "Janeiro", "Fevereiro", "Março",
                            "Abril",   "Maio",      "Junho", 
                            "Julho",   "Agosto",    "Setembro", 
                            "Outubro", "Novembro",  "Dezembro"
                        };

    return mes[this->mes-1];
}

int Data::diaMes ()
{

    int mes = getMes();
    int ano = getAno();

    int diasM[12] = { 
                      31, 28, 31, 
                      30, 31, 30,
                      31, 31, 30, 
                      31, 30, 31 
                    };
    

    int mesAlvo = diasM[mes-1];


    if ( eBisexto(ano) && mes == 2 )
    {
        mesAlvo = 29; 
    }

    return mesAlvo;
        
}

// RESOLVER O ESCREVE DATA PROVAVELMENTE VAI TER Q TRATAR COMO STRING E TAMBEM RESOLVER O DATA VALIDA

void Data::escreveData()
{
    int dia, mes, ano;
    bool valida;

    do {
        std::cout << "Entre com a data no formato [dd/mm/aaaa]: ";

        valida = (std::scanf("%d/%d/%d", &dia, &mes, &ano) == 3)
                 && dataValida(dia, mes, ano);

        // descarta o resto da linha 
        int c;
        while ((c = std::getchar()) != '\n' && c != EOF);

        if (!valida)
        {
            std::cout << "\nERRO: Data invalida.\nInsira novamente.\n\n";
        }
    } while (!valida);

    setData(dia, mes, ano);
}

void Data::leData()
{
    std::cout << "" << getDia() << "/" << "" << getMes() << "/" << getAno() << std::endl;
}

// Inicio da função de validação de data dd/mm/yyyy..

bool Data::eBisexto( int ano )
{
    bool bisexto = false;

    if ( (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0) )
    {
        bisexto = true;
    }

    return bisexto;
}


bool Data::dataValida()
{ 

    int dia = this->dia; 
    int mes = this->mes;
    int ano = this->ano;

    bool valido = true;

    if ( dia < 1 || dia > 31 )
    {
        valido = false;
    }
    
    if ( mes < 1 || mes > 12 )
    {
        valido = false;
    }

    if ( dia == 29 && mes == 2 && !eBisexto(ano))
    {
        valido = false;
    }

    if ( valido && dia > diaMes() )
    {
        valido = false;
    }


    return valido;
 
}

bool Data::dataValida(int dia, int mes, int ano)
{ 

    bool valido = true;

    if ( dia < 1 || dia > 31 )
    {
        valido = false;
    }
    
    if ( mes < 1 || mes > 12 )
    {
        valido = false;
    }

    if ( dia == 29 && mes == 2 && !eBisexto(ano))
    {
        valido = false;
    }

    if ( valido && dia > diaMes() )
    {
        valido = false;
    }


    return valido;
 
}

// Fim das funções de validação de data dd/mm/yyyy.