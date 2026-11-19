#ifndef DATA_H
#define DATA_H

// Dependencias

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

        bool setDia  (int n);
        bool setMes  (int n);
        bool setAno  (int n);
        bool setData (int dia, int mes, int ano);
        
        // getters

        int getDia();
        int getMes();
        int getAno();

        // Funções complementares

        std::string mesExtenso();
        int             diaMes();
        void       escreveData();
        void            leData();
        bool          eBisexto( int ano );
        bool        dataValida();
        bool        dataValida( int dia, int mes, int ano );

};


#endif