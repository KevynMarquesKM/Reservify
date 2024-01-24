//Bibliotecas
#include <iostream>
#include <string>
#include <ctime>
#include "restaurante.hpp"
using namespace std;

//Função main
int main(){
    //Variáveis locais
    clock_t tempo;
    clock_t tempoC;
    restaurante rest;

    tempo = time(nullptr);

    system("cls");

    cout << endl;
    cout << "  BBBBB   EEEEE  M     M     VV   VV  III  N     N   DDDD   OOO  " << endl;
    cout << "  B    B  E      MM   MM      V   V    I   N N   N   D   D O   O " << endl;
    cout << "  BBBBB   EEEE   M M M M  ==   V V     I   N  N  N   D   D O   O " << endl;
    cout << "  B    B  E      M  M  M        V      I   N   N N   D   D O   O " << endl;
    cout << "  BBBBB   EEEEE  M     M        V     III  N     N   DDDD   OOO  " << endl;
    cout << "" << endl;
    cout << "                        AAAAA   OOO  " << endl;
    cout << "                       A     A O   O " << endl;
    cout << "                       AAAAAAA O   O " << endl;
    cout << "                       A     A O   O " << endl;
    cout << "                       A     A  OOO  " << endl;
    cout << "" << endl;
    cout << "  RRRR    EEEEE  SSSS   EEEEE  RRRR    VV   VV  III  FFFFF  Y   Y " << endl;
    cout << "  R   R   E      S      E      R   R    V   V    I   F       Y Y  " << endl;
    cout << "  RRRR    EEEE    SSS   EEEE   RRRR      V V     I   FFF      Y   " << endl;
    cout << "  R  R    E          S  E      R  R       V      I   F        Y   " << endl;
    cout << "  R   R   EEEEE  SSSS   EEEEE  R   R      V     III  F        Y   " << endl;
    cout << "" << endl;
    do{
        tempoC = time(nullptr);
    }while(tempoC - tempo < 5);
    system("cls");

    rest.PerfilOperador();

    //Finalização do programa
    return 0;
}