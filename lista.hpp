#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>
#include <string>
#include <ctime>
#include "mesa.hpp"
using namespace std;

//Criação do tipo nó
typedef struct node{
    mesa *info;
    node *next;
} node;

//Criação do tipo lista
typedef struct{
    node *first;
    node *current;
} list;

//Protótipos
list Create(); //OK
bool Empty(list); //OK
bool IsItIn(int, list *); //OK
bool Insert(int, list *); //OK
bool Remove(int, list *); //OK
bool TakeFirst(int *, list *); //OK
bool TakeNext(int *, list *); //OK
bool Take(int, list *); //OK
bool Destroy(list *); //OK

/*
# Create #
Função: Criar uma lista com o campo first apontando para NULL
Parâmetros: 
    Nenhum
Valor de Retorno: 
    list list - Uma lista inicializada
*/
list Create(){
    //Vairáveis locais
    list list;

    //Inicializando a lista
    list.first = NULL;

    //Retorno da função
    return list;
}

/*
# Empty #
Função: Verifica se uma lista está vazia
Parâmetros: 
    list list - Lista que será verificada
Valores de Retorno:
    bool true - Se a lista estiver vazia
    bool false - Se a lista não estiver vazia
*/
bool Empty(list list){
    //Verificando conteúdo da lista
    if(list.first == NULL){
        //Retorno da função
        return true;
    }
    else{
        //Retorno da função
        return false;
    }
}

/*
# IsItIn #
Função: Verifica se uma mesa está na lista
Parâmetros: 
    int id - Id da mesa que será buscada
    list *list - Ponteiro para a lista que será usada na busca
Valores de Retorno:
    bool true - Se houver uma mesa com o id procurado na lista
    bool false - Se não houver uma mesa com o id procurado na lista
*/
bool IsItIn(int id, list *list){
    //Variáveis locais
    int IdTake;

    if(TakeFirst(&IdTake, list)){
        do{
            if(IdTake == id){
                //Retorno da função
                return true;
            }
        }while(TakeNext(&IdTake, list));
        //Retorno da função
        return false;
    }
    else{
        //Retorno da função
        return false;
    }
}

/*
# Insert #
Função: Insere uma mesa na lista
Parâmetros: 
    int qtd - Quantidade de pessoas da mesa que será inserida
    list *list - Ponteiro para a lista que será usada na inserção
Valores de Retorno:
    bool true - Se a inserção ocorrer
    bool false - Se a inserção não ocorrer
*/
bool Insert(int qtd, list *list){
    //Variáveis locais
    node *Paux;

    //Alocando um nó
    Paux = new node;

    //Verificando se a alocação foi bem sucedida
    if(Paux == NULL){
        //Retorno da função
        return false;
    }
    else{
        //O campo info de Paux aponta para uma nova mesa com a quantidade de pessoas informada
        Paux->info = new mesa(qtd);
        //O campo next de Paux passa a apontar para o primeiro elemento da lista
        Paux->next = list->first;
        //O primeiro elemento da lista passa a ser Paux
        list->first = Paux;
        //Retorno da função
        return true;
    }
}

/*
# Remove #
Função: Remove uma mesa da lista
Parâmetros: 
    int id - Id da mesa que será removida
    list *list - Ponteiro para a lista que será usada na remoção
Valores de Retorno:
    bool true - Se a remoção ocorrer
    bool false - Se a remoção não ocorrer
*/
bool Remove(int id, list *list){
    //Variáveis locais
    node *Paux;
    int IdTake;

    //Verificando conteúdo da lista
    if(IsItIn(id, list)){
        if(TakeFirst(&IdTake, list)){
            if(IdTake == id){
                //Paux passa a apontar para o primeiro elemento da lista
                Paux = list->first;
                //O primeiro elemento da lista passa a ser o segundo elemento da lista
                list->first = list->first->next;
                //Deleta a mesa
                delete Paux->info;
                //Deleta Paux
                delete Paux;
                //Retorno da função
                return true;
            }
            else{
                while(IdTake != id){
                    //Paux passa a apontar para o campo current
                    Paux = list->current;
                    //O campo current passa a apontar para o próximo elemento da lista
                    TakeNext(&IdTake, list);
                }
                //O campo next de Paux passa a apontar para o campo next do campo current
                Paux->next = list->current->next;
                //Paux passa a apontar para o campo current
                Paux = list->current;
                //Deleta a mesa
                delete Paux->info;
                //Deleta Paux
                delete Paux;
                //Retorno da função
                return true;
            }
        }
        else{
            //Retorno da função
            return false;
        }
    }
    else{
        //Retorno da função
        return false;
    }
}

/*
# TakeFirst #
Função: Faz com que o campo current de uma lista aponte para a primeira mesa da lista
Parâmetros: 
    int *id - Variável que receberá o Id da primeira mesa da lista
    list *list - Ponteiro para a lista que será usada
Valores de Retorno:
    bool true - Se a função ocorrer de forma bem sucedida
    bool false - Se a função ocorrer de forma mal sucedida
*/
bool TakeFirst(int *id, list *list){
    //Verificando conteúdo da lista
    if(Empty(*list)){
        //Retorno da função
        return false;
    }
    else{
        //O campo current passa a apontar para o primeiro elemento da lista
        list->current = list->first;
        //id recebe o id da mesa apontada pelo campo current
        *id = list->current->info->getId();
        //Retorno da função
        return true;
    }
}

/*
# TakeNext #
Função: Faz com que o campo current de uma lista aponte para a próxima mesa da lista em relação a si mesmo
Parâmetros: 
    int *id - Variável que receberá o Id da nova mesa apontada pelo campo current
    list *list - Ponteiro para a lista que será usada
Valores de Retorno:
    bool true - Se a função ocorrer de forma bem sucedida
    bool false - Se a função ocorrer de forma mal sucedida
*/
bool TakeNext(int *id, list *list){
    //Verificando conteúdo da lista
    if(Empty(*list)){
        //Retorno da função
        return false;
    }
    else{
        //Verificando conteúdo do próximo nó em relação ao campo current
        if(list->current->next == NULL){
            //Retorno da função
            return false;
        }
        else{
            //O campo current passa a apontar para o próximo elemento da lista
            list->current = list->current->next;
            //id recebe o id da mesa apontada pelo campo current
            *id = list->current->info->getId();
            //Retorno da função
            return true;
        }
    }
}

/*
# Take #
Função: Faz com que o campo current de uma lista aponte para a mesa com o Id buscado
Parâmetros: 
    int id - Id da mesa que será buscada
    list *list - Ponteiro para a lista que será usada
Valores de Retorno:
    bool true - Se a função ocorrer de forma bem sucedida
    bool false - Se a função ocorrer de forma mal sucedida
*/
bool Take(int id, list *list){
    //Verificando conteúdo da lista
    if(IsItIn(id, list)){
        return true;
    }
    else{
        //Retorno da função
        return false;
    }
}

/*
# Destroy #
Função: Remove todas as mesas de uma lista
Parâmetros: 
    list *list - Ponteiro para a lista que será usada
Valores de Retorno:
    bool true - Se a função ocorrer de forma bem sucedida
    bool false - Se a função ocorrer de forma mal sucedida
*/
bool Destroy(list *list){
    //Remove todos os elementos até ela não possuir mais elemento algum
    while(!Empty(*list)){
        if(Remove(list->first->info->getId(), list)){
            ;
        }
        else{
            return false;
        }
    }
    //Retorno da função
        return true;
}

#endif