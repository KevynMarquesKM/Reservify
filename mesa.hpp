#ifndef MESA_HPP
#define MESA_HPP
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//Criação da classe mesa
class mesa{
    private:
        //Atributos
        const int IdMesa;
        const int QtdPessoas;
        clock_t TempoChegada;
        static int GeradorId;
        static int MesasEsperando;
        static int MediaMinutos;
        static float MediaSegundos;

    public:
        //Construtor
        mesa(int);

        //Destrutor
        ~mesa();

        //Métodos
        int getId() const;
        int getPessoas() const;
        clock_t getChegada() const;
        static int getMesasEsperando();
        static int getMediaMinutos();
        static float getMediaSegundos();
        void resetGeradorId();
};

//Inicializações
int mesa::GeradorId = 0;
int mesa::MesasEsperando = 0;
int mesa::MediaMinutos = 0;
float mesa::MediaSegundos = 0;

//Construtor
mesa::mesa(int cQtdPessoas = 0) : QtdPessoas(cQtdPessoas), TempoChegada(clock()), IdMesa(++GeradorId){
    MesasEsperando++;
}

//Destrutor
mesa::~mesa(){
    //Declarações locais
    int minutos;
    float segundos;
    clock_t diferenca;

    MesasEsperando--;

    diferenca = clock() - TempoChegada;
    segundos = (float)diferenca / CLOCKS_PER_SEC;
    minutos = (int)(segundos / 60);
    segundos -= (minutos) * 60;

    if((getMediaMinutos() == 0) & (getMediaSegundos() == 0)){
        MediaMinutos = minutos;
        MediaSegundos = segundos;
    }
    else{
        if((MediaMinutos + minutos) % 2 == 0){
            MediaMinutos = (MediaMinutos + minutos) / 2;
            MediaSegundos = (MediaSegundos + segundos) / 2;
        }
        else{
            if(((MediaSegundos + segundos) / 2) > 29){
                MediaMinutos = ((MediaMinutos + minutos) / 2);
                MediaSegundos = ((MediaSegundos + segundos) / 2) + 30;
            }
            else{
                MediaMinutos = ((MediaMinutos + minutos) / 2) + 1;
                MediaSegundos = ((MediaSegundos + segundos) / 2) - 30;
            }
        }
    }
}

//Métodos get
int mesa::getId() const{
    return IdMesa;
}

int mesa::getPessoas() const{
    return QtdPessoas;
}

clock_t mesa::getChegada() const{
    return TempoChegada;
}

int mesa::getMesasEsperando(){
    return MesasEsperando;
}

int mesa::getMediaMinutos(){
    return MediaMinutos;
}

float mesa::getMediaSegundos(){
    return MediaSegundos;
}

void mesa::resetGeradorId(){
    GeradorId = 0;
}

#endif