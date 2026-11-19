#ifndef DATA_H
#define DATA_H

// Dependencias

#include <iostream>
#include <string>

// Definição da Classe

class Data
{
    private:

        int dia;
        int mes;
        int ano;
    
    public:

        // construtor
        
        Data();
        Data( int dia, int mes, int ano );
        
        // destrutor

        ~Data();
        
        // setters

        bool setDia  (int);
        bool setMes  (int);
        bool setAno  (int);
        bool setData (int dia, int mes, int ano);
        
        // getters

        int getDia();
        int getMes();
        int getAno();

        // Funções complementares

        std::string mesExtenso();
        int             diaMes();
        bool        dataValida();
        void       escreveData();
        void            leData();


};


#endif