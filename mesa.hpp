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
        const string Nome;
        clock_t TempoChegada;
        tm * DataChegada;
        static int GeradorId;
        static int MesasEsperando;
        static int MediaMinutos;
        static float MediaSegundos;

    public:
        //Construtor
        mesa(int, string);

        //Destrutor
        ~mesa();

        //Métodos
        int getId() const;
        int getPessoas() const;
        string getNome() const;
        clock_t getChegada() const;
        tm * getDataChegada() const;
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
mesa::mesa(int cQtdPessoas = 0, string cNome = "Indefinido") : QtdPessoas(cQtdPessoas), TempoChegada(clock()), IdMesa(++GeradorId), Nome(cNome){
    time_t tempo = time(0);

    MesasEsperando++;
    DataChegada = localtime(&tempo);
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
        MediaSegundos = (MediaSegundos + segundos + MediaMinutos * 60 + minutos * 60) / 2;
        MediaMinutos = (int)((MediaSegundos) / 60);
        MediaSegundos = MediaSegundos - (MediaMinutos * 60);
    }
}

//Métodos get
int mesa::getId() const{
    return IdMesa;
}

int mesa::getPessoas() const{
    return QtdPessoas;
}

string mesa::getNome() const{
    return Nome;
}

clock_t mesa::getChegada() const{
    return TempoChegada;
}

tm * mesa::getDataChegada() const{
    return DataChegada;
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