#ifndef MESA_HPP
#define MESA_HPP
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//Criação da classe
class mesa{
    private:
        //Atributos
        const int IdMesa;
        const int QtdPessoas;
        time_t TempoChegada;
        time_t TempoEspera;
        static int GeradorId;
        static int MesasEsperando;
        static time_t SomaEspera;

    public:
        //Construtor
        mesa(int);

        //Destrutor
        ~mesa();

        //Métodos
        int getId() const;
        int getPessoas() const;
        time_t getChegada() const;
        time_t getEspera() const;
        static int getMesasEsperando();
        static time_t getSomaEspera();
        const time_t * getPtrChegada() const;
};

    //Inicializações
    int mesa::GeradorId = 0;
    int mesa::MesasEsperando = 0;
    time_t mesa::SomaEspera = 0;

    //Construtor
    mesa::mesa(int cQtdPessoas = 0) : QtdPessoas(cQtdPessoas), TempoChegada(time(nullptr)), IdMesa(++GeradorId){
        MesasEsperando++;
    }

    //Destrutor
    mesa::~mesa(){
        TempoEspera = difftime(time(nullptr), TempoChegada);
        SomaEspera = SomaEspera + TempoEspera;
        MesasEsperando--;
    }

    //Métodos get
    int mesa::getId() const{
        return IdMesa;
    }

    int mesa::getPessoas() const{
        return QtdPessoas;
    }

    time_t mesa::getChegada() const{
        return TempoChegada;
    }

    time_t mesa::getEspera() const{
        return TempoEspera;
    }

    int mesa::getMesasEsperando(){
        return MesasEsperando;
    }

    time_t mesa::getSomaEspera(){
        return SomaEspera;
    }

    const time_t * mesa::getPtrChegada() const{
        return &TempoChegada;
    }

#endif