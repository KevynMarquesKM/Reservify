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
        int tela;

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
        void ExibeTempoMedioEspera();
        void LimpaTela(int);
        void setTela();
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
    cout << "             OPERACOES DISPONIVEIS             " << endl;
    cout << "1:  Menu de operacoes..........................." << endl;
    cout << "2:  Remover uma mesa............................" << endl;
    cout << "3:  Adicionar uma mesa.........................." << endl;
    cout << "4:  Pesquisar uma mesa pelo ID.................." << endl;
    cout << "5:  Exibir tempo medio de espera................" << endl;
    cout << "6:  Exibir todas as mesas registradas..........." << endl;
    cout << "7:  Exibir total de mesas registradas..........." << endl;
    cout << "8:  Apagar todos os registros (reset) .........." << endl;
    cout << "9:  Configuracoes de exibicao..................." << endl;
    cout << "10: Sair........................................" << endl;
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
    int diov;
    clock_t tempoF, tempoC;

    //Exibindo o menu de ações disponíveis
    ExibeMenu();

    //Inicializando a configuração da exibição
    tela = 0;

    do{
        //Coletando a ação escolhida
        cout << "________________________________________________";
        cout << endl << "Operacao desejada: ";
        seletor = getEscolha(1, 10);
        //Realizando a ação
        switch (seletor){
        case 1:
            LimpaTela(seletor);
            ExibeMenu();
            break;
        case 2:
            LimpaTela(seletor);
            RemoveMesa();
            break;
        case 3:
            LimpaTela(seletor);
            AdicionaMesa();
            break;
        case 4:
            LimpaTela(seletor);
            PesquisaMesa();
            break;
        case 5:
            LimpaTela(seletor);
            ExibeTempoMedioEspera();
            break;
        case 6:
            LimpaTela(seletor);
            ExibeMesas();
            break;
        case 7:
            LimpaTela(seletor);
            cout << endl << "Total de mesas registradas: " << lista.first->info->getMesasEsperando() << endl;
            break;
        case 8:
            LimpaTela(seletor);
            cout << "Reset realizado!" << endl;
            lista.first->info->resetGeradorId();
            Destroy(&lista);
            break;
        case 9:
            LimpaTela(seletor);
            setTela();
            break;
        default:
            diov = system("cls");
            (void)diov;
            Destroy(&lista);
            cout << endl << "Encerrando em 3!";
            tempoF = time(nullptr);

            do{
                tempoC = time(nullptr);
            }while(tempoC - tempoF < 1.5);

            diov = system("cls");
            (void)diov;
            cout << endl << "Encerrando em 2!";
            do{
                tempoC = time(nullptr);
            }while(tempoC - tempoF < 3);

            diov = system("cls");
            (void)diov;
            cout << endl << "Encerrando em 1!";
            do{
                tempoC = time(nullptr);
            }while(tempoC - tempoF < 4);

            diov = system("cls");
            (void)diov;
            cout << endl << "Encerrando em 0!";
            do{
                tempoC = time(nullptr);
            }while(tempoC - tempoF < 4.25);
            diov = system("cls");
            (void)diov;
            break;
        }
    }while(seletor != 10);
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
    string nome;

    //Coletando a quantidade de pessoas da mesa e o nome da comanda
    cout << endl <<"Adicionando uma mesa!" << endl;
    cout << "Informe a quantidade de pessoas da mesa: ";
    cin >> num;
    cout << "Informe o nome a ser vinculado a mesa: ";
    cin >> nome;

    if(Insert(num, nome, &lista)){                                //Se a inserção for bem sucedida
        cout << "Mesa adicionada!" << endl;
        cout << "Data do registro: " << lista.first->info->getDataChegada()->tm_mday;
        cout << "/" << lista.first->info->getDataChegada()->tm_mon + 1;
        cout << "/" << lista.first->info->getDataChegada()->tm_year + 1900;
        cout << " as " << lista.first->info->getDataChegada()->tm_hour;
        cout << ":" << lista.first->info->getDataChegada()->tm_min;
        cout << "!" << endl;
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
    int minutos;
    int verifica;
    float segundos;
    clock_t tempo;
    clock_t diferenca;

    if(Empty(lista)){
        cout << endl << "ERRO: Nao existem mesas registradas, nao e possivel remover uma mesa!" << endl;
    }
    else{
        //Coletando o ID da mesa que será removida
        cout << endl << "Removendo uma mesa!" << endl;
        cout << "Informe o ID da mesa que deseja remover: ";
        cin >> ID;

        //Coletando o tempo de espera da mesa que está sendo removida
        Take(ID, &lista);
        tempo = lista.current->info->getChegada();

        if(IsItIn(ID, &lista)){                                     //Se a mesa existir
            cout << "Deseja mesmo remover essa mesa (0 - nao / 1 - sim)? ";
            verifica = getEscolha(0, 1);
            if(verifica){
                if(Remove(ID, &lista)){                                 //Se a mesa for removida
                cout << "Mesa removida!" << endl;
                cout << "Nome vinculado a mesa: " << lista.current->info->getNome() << "!" << endl;
                cout << "Data do registro: " << lista.current->info->getDataChegada()->tm_mday;
                cout << "/" << lista.current->info->getDataChegada()->tm_mon + 1;
                cout << "/" << lista.current->info->getDataChegada()->tm_year + 1900;
                cout << " as " << lista.current->info->getDataChegada()->tm_hour;
                cout << ":" << lista.current->info->getDataChegada()->tm_min;
                cout << "!" << endl;
                cout << "Tempo de espera da mesa: ";
                diferenca = clock() - tempo;
                segundos = (float)diferenca / CLOCKS_PER_SEC;
                minutos = (int)(segundos / 60);
                segundos -= (minutos) * 60;
                if(minutos == 0){
                    printf("%.0f segundos!\n", segundos);
                }
                else if(minutos == 1){
                    printf("%d minuto e %.0f segundos!\n", minutos, segundos);
                }
                else{
                    printf("%d minutos e %.0f segundos!\n", minutos, segundos);
                }
                }
                else{                                                   //Se a mesa não for removida e o ID não existir
                    cout << "ERRO: Nao foi possivel remover a mesa!" << endl;
                }
            }
            else{
                cout << "Operacao cancelada!" << endl;
            }
        }
        else{
            cout << "ERRO: O ID informado nao existe, nao foi possivel remover a mesa!" << endl;
        }
    }
}

/*
else if(IsItIn(ID, &lista)){                           //Se a mesa não for removida, mas o ID existe
            cout << "ERRO: O ID informado existe, mas nao foi possivel remover a mesa!" << endl;
        }
*/

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
    int minutos;
    float segundos;
    clock_t tempo;
    clock_t diferenca;

    if(TakeFirst(&ID, &lista)){                 //Se houver mesas
        cout << endl << "Exibindo todas as " << lista.first->info->getMesasEsperando() << " mesas registradas!" << endl;
        do{
            cout << endl << "Mesa ID: " << lista.current->info->getId() << endl;
            cout << "Nome vinculado a mesa: " << lista.current->info->getNome() << "!" << endl;
            cout << "Quantidade de pessoas: " << lista.current->info->getPessoas() << endl;
            cout << "Tempo de espera da mesa: ";
            tempo = lista.current->info->getChegada();
            diferenca = clock() - tempo;
            segundos = (float)diferenca / CLOCKS_PER_SEC;
            minutos = (int)(segundos / 60);
            segundos -= (minutos) * 60;
            if(minutos == 0){
                printf("%.0f segundos!\n", segundos);
            }
            else if(minutos == 1){
                printf("%d minuto e %.0f segundos!\n", minutos, segundos);
            }
            else{
                printf("%d minutos e %.0f segundos!\n", minutos, segundos);
            }
            cout << "Data do registro: " << lista.current->info->getDataChegada()->tm_mday;
            cout << "/" << lista.current->info->getDataChegada()->tm_mon + 1;
            cout << "/" << lista.current->info->getDataChegada()->tm_year + 1900;
            cout << " as " << lista.current->info->getDataChegada()->tm_hour;
            cout << ":" << lista.current->info->getDataChegada()->tm_min;
            cout << "!" << endl;
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
    int minutos;
    float segundos;
    clock_t tempo;
    clock_t diferenca;

    //Coletando a mesa a ser exibida
    cout << endl << "Pesquisando uma mesa!" << endl;
    cout << "Informe o ID da mesa que deseja pesquisar: ";
    cin >> ID;

    if(Take(ID, &lista)){                                   //Se a mesa existir
        cout << "Mesa ID: " << lista.current->info->getId() << endl;
        cout << "Quantidade de pessoas: " << lista.current->info->getPessoas() << endl;
        cout << "Tempo de espera da mesa: ";
        tempo = lista.current->info->getChegada();
        diferenca = clock() - tempo;
        segundos = (float)diferenca / CLOCKS_PER_SEC;
        minutos = (int)(segundos / 60);
        segundos -= (minutos) * 60;
        if(minutos == 0){
            printf("%.0f segundos!\n", segundos);
        }
        else if(minutos == 1){
            printf("%d minuto e %.0f segundos!\n", minutos, segundos);
        }
        else{
            printf("%d minutos e %.0f segundos!\n", minutos, segundos);
        }
    }
    else{                                                   //Se a mesa não existir
        cout << "ERRO: O ID informado nao existe, nao foi possivel exibir a mesa!" << endl;
    }
}

/*
# ExibeTempoMedioEspera #
Função: Exibe o tempo médio de espera
Parâmetros: 
    Nenhum
Valores de Retorno:
    Nenhum
*/
void restaurante::ExibeTempoMedioEspera(){
    if(lista.current->info->getMediaSegundos() == 0){
        cout << endl << "Tempo medio de espera indefinido!" << endl;
    }
    else if(lista.current->info->getMediaMinutos() == 0){
        printf("\nTempo medio de espera: %.0f segundos!\n", lista.current->info->getMediaSegundos());
    }
    else{
        printf("\nTempo medio de espera: %d minutos e %.0f segundos!\n", lista.current->info->getMediaMinutos(), lista.current->info->getMediaSegundos());
    }
}

/*
# LimpaTela #
Função: Limpa o console de acordo com a escolha do usuário
Parâmetros: 
    int seletor - Operação selecionada
Valores de Retorno:
    Nenhum
*/
void restaurante::LimpaTela(int seletor){
    //Declarações locais
    int diov;

    if(tela == 1 && seletor == 1){
        diov = system("cls");
        (void)diov;
    }
    else if(tela == 2 && seletor != 2){
        diov = system("cls");
        (void)diov;
    }
}

/*
# setTela #
Função: Adiciona uma mesa ao restaurante
Parâmetros: 
    Nenhum
Valores de Retorno:
    Nenhum
*/
void restaurante::setTela(){
    //Coletando a opção do usuário
    cout << endl << "Configuracoes de exibicao!" << endl;
    cout << endl << "0: Nunca limpar a tela..........................";
    cout << endl << "1: Limpar a tela somente apos exibir o menu.....";
    cout << endl << "2: Limpar a tela apos toda operacao............." << endl;

    cout << endl << "Informe a configuracao desejada: ";
    tela = getEscolha(0, 2);

    cout << endl << "Exibicao configurada!" << endl;
}

#endif