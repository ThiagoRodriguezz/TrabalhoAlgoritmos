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

        int getDia() const;
        int getMes() const;
        int getAno() const;

        // Funções da classe

        bool        dataValida();
        bool        dataValida( int dia, int mes, int ano );
        bool        dataEstaDefinida() const;

        std::string mesExtenso();

        static int      diaMes( int mes, int ano );

        void       escreveData();
        void       imprimeData();

        // Funções complementares

        static bool   eBisexto( int ano );
        bool       formataData( const char texto[], char formatado[] );
        bool         textToNum( const char data[] );

};


#endif