#ifndef RESTAURANTE_HPP
#define RESTAURANTE_HPP
#include <iostream>
#include <string>
#include <ctime>
#include "lista.hpp"
using namespace std;

//Criação da classe restaurante
class restaurante{
    private:
        //Atributos
        list lista;

    public:
        //Construtor
        restaurante();

        //Destrutor
        ~restaurante();

        //Métodos
        void PerfilOperador();
        void AdicionaMesa();
        void RemoveMesa();
        void ExibeMesas();
        void PesquisaMesa();
};

//Protótipos das funções utilizadas na função menu
int getEscolha(int, int);
void ExibeMenu();

/*
# getEscolha #
Função: Coleta um inteiro baseado em um intervalo determinado
Parâmetros: 
    int base - Valor mínimo do intervalo da escolha
    int teto - Valor máximo do intervalo da escolha
Valores de Retorno:
    int - Escolha do usuário
*/
int getEscolha(int base, int teto){
    //Variáveis locais
    int escolha;

    //Coletando e validando a escolha
    cin >> escolha;
    while(escolha < base | escolha > teto){
        cout << "Selecione um valor valido (entre " << base << " e " << teto << "): ";
        cin >> escolha;
    }

    //Retorno da função
    return escolha;
}

/*
# ExibeMenu #
Função: Exibe o menu de opções do perfil de operador
Parâmetros: 
    Nenhum
Valores de Retorno:
    Nenhum
*/
void ExibeMenu(){
    cout << endl;
    cout << "-----------OPERACOES DISPONIVEIS-----------" << endl;
    cout << "1: Menu de operacoes......................." << endl;
    cout << "2: Remover uma mesa........................" << endl;
    cout << "3: Adicionar uma mesa......................" << endl;
    cout << "4: Pesquisar uma mesa pelo ID.............." << endl;
    cout << "5: Exibir todas as mesas registradas......." << endl;
    cout << "6: Apagar todos os registros (reset) ......" << endl;
    cout << "7: Sair...................................." << endl;
}

//Construtor
restaurante::restaurante(){
    lista = Create();
}

//Destrutor
restaurante::~restaurante(){
    Destroy(&lista);
}

/*
# PerfilOperador #
Função: Exibe o menu de ações que podem ser relizadas e as executa
Parâmetros: 
    Nenhum
Valores de Retorno:
    Nenhum
*/
void restaurante::PerfilOperador(){
    //Variáveis locais
    int seletor;

    //Exibindo o menu de ações disponíveis
    ExibeMenu();

    do{
        //Exibindo situação de registros atuais se houver
        if(!(Empty(lista))){
            cout << "Total de mesas registradas: " << lista.first->info->getMesasEsperando() << endl;
        }
        //Coletando a ação escolhida
        cout << endl << "Operacao desejada: ";
        seletor = getEscolha(1, 7);
        //Realizando a ação
        switch (seletor){
        case 1:
            ExibeMenu();
            break;
        case 2:
            RemoveMesa();
            break;
        case 3:
            AdicionaMesa();
            break;
        case 4:
            PesquisaMesa();
            break;
        case 5:
            ExibeMesas();
            break;
        case 6:
            lista.first->info->resetGeradorId();
            Destroy(&lista);
            break;
        default:
            cout << "Encerrando!";
            break;
        }
    }while(seletor != 7);
}

/*
# AdicionaMesa #
Função: Adiciona uma mesa ao restaurante
Parâmetros: 
    Nenhum
Valores de Retorno:
    Nenhum
*/
void restaurante::AdicionaMesa(){
    //Variáveis locais
    int num;

    //Coletando a quantidade de pessoas da mesa
    cout << endl <<"Adicionando uma mesa!" << endl;
    cout << "Informe a quantidade de pessoas da mesa: ";
    cin >> num;

    if(Insert(num, &lista)){                                //Se a inserção for bem sucedida
        cout << "Mesa adicionada!" << endl;
    }
    else{                                                   //Se a inserção não for bem sucedida
        cout << "ERRO: Nao foi possivel adicionar a mesa!" << endl;
    }
}

/*
# RemoveMesa #
Função: Remove uma mesa do restaurante
Parâmetros: 
    Nenhum
Valores de Retorno:
    Nenhum
*/
void restaurante::RemoveMesa(){
    //Variáveis locais
    int ID;

    if(Empty(lista)){
        cout << endl << "ERRO: Nao existem mesas registradas, nao e possivel remover uma mesa" << endl;
    }
    else{
        //Coletando o ID da mesa que será removida
        cout << endl << "Removendo uma mesa!" << endl;
        cout << "Informe o ID da mesa que deseja remover: ";
        cin >> ID;

        if(Remove(ID, &lista)){                                //Se a mesa for removida
            cout << "Mesa removida!" << endl;
        }
        else if(IsItIn(ID, &lista)){                           //Se a mesa não for removida, mas o ID existe
            cout << "ERRO: O ID informado existe, mas nao foi possivel remover a mesa!" << endl;
        }
        else{                                                   //Se a mesa não for removida e o ID não existir
            cout << "ERRO: O ID informado nao existe, nao foi possivel remover a mesa" << endl;
        }
    }
}

/*
# ExibeMesas #
Função: Exibe todas as mesas do restaurante
Parâmetros: 
    Nenhum
Valores de Retorno:
    Nenhum
*/
void restaurante::ExibeMesas(){
    //Variáveis locais
    int ID;

    if(TakeFirst(&ID, &lista)){                 //Se houver mesas
        cout << endl << "Exibindo todas as " << lista.first->info->getMesasEsperando() << " mesas registradas!" << endl;
        do{
            cout << "Mesa ID: " << lista.current->info->getId() << endl;
            cout << "Quantidade de pessoas: " << lista.current->info->getPessoas() << endl;
        }while(TakeNext(&ID, &lista));          //Enquanto houver mesas
    }
    else{                                       //Se não houver mesas
        cout << endl << "Nao existem mesas registradas!" << endl;
    }
}

/*
# PesquisaMesa #
Função: Pesquisa uma mesa
Parâmetros: 
    Nenhum
Valores de Retorno:
    Nenhum
*/
void restaurante::PesquisaMesa(){
    //Variáveis locais
    int ID;

    //Coletando a mesa a ser exibida
    cout << endl << "Pesquisando uma mesa!" << endl;
    cout << "Informe o ID da mesa que deseja pesquisar: ";
    cin >> ID;

    if(Take(ID, &lista)){                                   //Se a mesa existir
        cout << "Mesa ID: " << lista.current->info->getId() << endl;
        cout << "Quantidade de pessoas: " << lista.current->info->getPessoas() << endl;
    }
    else{                                                   //Se a mesa não existir
        cout << "ERRO: O ID informado nao existe, nao foi possivel exibir a mesa!" << endl;
    }
}

#endif