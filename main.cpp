//Bibliotecas
#include <iostream>
#include <string>
#include <ctime>
#include "lista.hpp"
//#include "C:\Users\UFSCar\Documents\Codigos\AED\mesa.hpp"
using namespace std;

//Função main
int main(){
    //Variáveis locais
    list lista;
    int IdTake;

    if(Insert(5, &lista)){
        cout << "Inserido!" << endl;
    }
    else{
        cout << "Nao inserido!" << endl;
    }

    if(Insert(7, &lista)){
        cout << "Inserido!" << endl;
    }
    else{
        cout << "Nao inserido!" << endl;
    }

    if(Insert(9, &lista)){
        cout << "Inserido!" << endl;
    }
    else{
        cout << "Nao inserido!" << endl;
    }

    TakeFirst(&IdTake, &lista);
    cout << "Dados do primeiro elemento" << endl << "ID: " << lista.current->info->getId() << endl << "Pessoas: " << lista.current->info->getPessoas();
    TakeNext(&IdTake, &lista);
    cout << endl << "Dados do segundo elemento" << endl << "ID: " << lista.current->info->getId() << endl << "Pessoas: " << lista.current->info->getPessoas();

    if(Remove(2, &lista)){
        cout << endl << "Removido!" << endl;
    }
    else{
        cout << "Nao removido!" << endl;
    }

    TakeFirst(&IdTake, &lista);
    cout << "Dados do primeiro elemento" << endl << "ID: " << lista.first->info->getId() << endl << "Pessoas: " << lista.first->info->getPessoas();
    TakeNext(&IdTake, &lista);
    cout << endl << "Dados do segundo elemento" << endl << "ID: " << lista.first->next->info->getId() << endl << "Pessoas: " << lista.first->next->info->getPessoas();

    //Finalização do programa
    return 0;
}