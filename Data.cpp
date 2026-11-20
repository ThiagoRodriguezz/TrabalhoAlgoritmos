#include "Data.h"

//Dependencias Necessarias

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>


// Metodos da Classe Data

// Construtores


    Data::Data()
    {
        this->dia = 1;
        this->mes = 1;
        this->ano = 1999;
    }

    Data::Data( int dia, int mes, int ano )
    {

        if ( dataValida(dia, mes, ano))
        {
            setData(dia, mes, ano);
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

    if (!dataValida(dia, mes, ano))
        return false;

    this->dia = dia;
    this->mes = mes;
    this->ano = ano;

    return true;

}

// Getters

int Data::getDia() const
{
    return this->dia;
}

int Data::getMes() const
{
    return this->mes;
}

int Data::getAno() const
{
    return this->ano;
}

// Funções da Classe

bool Data::dataValida()
{
    int dia = this->dia;
    int mes = this->mes;
    int ano = this->ano;

    if (mes < 1 || mes > 12)
        return false;

    if (dia < 1)
        return false;

    if (dia > diaMes(mes, ano))
        return false;

    if (dia == 29 && mes == 2 && !eBisexto(ano))
        return false;

    return true;
}

bool Data::dataValida(int dia, int mes, int ano)
{
    if (mes < 1 || mes > 12)
        return false;

    if (dia < 1)
        return false;

    int diasM[12] = {
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };

    if (eBisexto(ano))
        diasM[1] = 29;

    if (dia > diasM[mes - 1])
        return false;

    return true;
}

std::string Data::mesExtenso()
{


    static const std::string mes[12] {
                            "Janeiro", "Fevereiro", "Março",
                            "Abril",   "Maio",      "Junho", 
                            "Julho",   "Agosto",    "Setembro", 
                            "Outubro", "Novembro",  "Dezembro"
                        };

    if (this->mes < 1 || this->mes > 12)
        return "Mês invalido.";
            
    return mes[this->mes-1];
}

int Data::diaMes(int mes, int ano)
{
    if (mes < 1 || mes > 12)
        return 0;

    int diasM[12] = {
        31, 28, 31,
        30, 31, 30,
        31, 31, 30,
        31, 30, 31
    };

    int mesAlvo = diasM[mes - 1];

    if (eBisexto(ano) && mes == 2)
    {
        mesAlvo = 29;
    }

    return mesAlvo;
}

void Data::escreveData()
{
    int dia, mes, ano;
    bool valido = false;

    char texto[50];
    char formatado[50];

    do 
    {

        std::cout << "Entre com a data no formato [dd/mm/aaaa]: ";
        std::cin.getline(texto, 50);

        if ( formataData(texto, formatado) && textToNum(formatado) )
        {
            valido = true;
        }
        else
        {
            std::cout<< "ERRO. Data ou Formato invalido.\nInsira novamente."<< std::endl;
        }


    } while ( !valido );

}


void Data::leData()
{
    std::cout << "" << getDia() << "/" << "" << getMes() << "/" << getAno() << std::endl;
}


// Funções complementares

bool Data::eBisexto( int ano )
{
    bool bisexto = false;

    if ( (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0) )
    {
        bisexto = true;
    }

    return bisexto;
}

bool Data::formataData(const char texto[], char formatado[])
{
    int posFinal = strlen(texto);

    if (posFinal > 11 || posFinal < 5)
        return false;

    char *posPB = nullptr;

    int posicaoBarra1 = 0;
    int posicaoBarra2 = 0;

    // Procura a primeira barra
    posPB = (char*)strchr(texto, '/');

    if (posPB == nullptr)
        return false;

    posicaoBarra1 = posPB - texto;

    // Verifica o tamanho do dia
    if (posicaoBarra1 < 1 || posicaoBarra1 > 2)
        return false;

    // Procura a segunda barra
    posPB = (char*)strchr(posPB + 1, '/');

    if (posPB == nullptr)
        return false;

    posicaoBarra2 = posPB - texto;

    // Verifica o tamanho do mês
    int tamMes = posicaoBarra2 - posicaoBarra1 - 1;

    if (tamMes < 1 || tamMes > 2)
        return false;

    // Verifica se dia e mês possuem apenas dígitos
    for (int i = 0; i < posicaoBarra1; i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(texto[i])))
            return false;
    }

    for (int i = posicaoBarra1 + 1; i < posicaoBarra2; i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(texto[i])))
            return false;
    }

    // Formata o dia

    int pos = 0;

    if (posicaoBarra1 == 1)
        formatado[pos++] = '0';

    for (int i = 0; i < posicaoBarra1; i++)
    {
        formatado[pos++] = texto[i];
    }

    formatado[pos++] = '/';

    // Formata o mês

    if (tamMes == 1)
        formatado[pos++] = '0';

    for (int i = posicaoBarra1 + 1; i < posicaoBarra2; i++)
    {
        formatado[pos++] = texto[i];
    }

    formatado[pos++] = '/';

    // Verifica se o ano é negativo

    int inicioAno = posicaoBarra2 + 1;

    if (texto[inicioAno] == '-')
    {
        formatado[pos++] = '-';
        inicioAno++;
    }

    // Verifica quantidade de dígitos do ano

    int tamAno = posFinal - inicioAno;

    if (tamAno < 1 || tamAno > 4)
        return false;

    // Verifica se o ano possui somente dígitos

    for (int i = inicioAno; i < posFinal; i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(texto[i])))
            return false;
    }

    // Copia o ano

    for (int i = inicioAno; i < posFinal; i++)
    {
        formatado[pos++] = texto[i];
    }

    formatado[pos] = '\0';

    return true;
}

bool Data::textToNum(const char data[])
{
    int dia, mes, ano = 0;

    dia = (data[0] - '0') * 10 + (data[1] - '0');
    mes = (data[3] - '0') * 10 + (data[4] - '0');

    int inicioAno = 6;
    int sinal = 1;

    if (data[inicioAno] == '-')
    {
        sinal = -1;
        inicioAno++;
    }

    for (int i = inicioAno; data[i] != '\0'; i++)
    {
        ano = ano * 10 + (data[i] - '0');
    }

    ano *= sinal;

    if (!dataValida(dia, mes, ano))
        return false;

    return setData(dia, mes, ano);
}

