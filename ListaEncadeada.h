#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <iostream>

class ListaEncadeada {
public:
    // Construtor e Destrutor
    ListaEncadeada();
    ~ListaEncadeada();

    // Métodos públicos
    bool estaVazia() const;
    int obterTamanho() const;
    int obterElemento(int posicao) const;
    bool alterarElemento(int posicao, int valor);
    bool inserir(int posicao, int valor);
    bool inserirInicio(int valor);
    bool inserirFim(int valor);
    int remover(int posicao);
    void exibir() const;

private:
    // Estrutura do nó
    struct Nodo {
        int valor;
        Nodo* proximo;
        Nodo(int v) : valor(v), proximo(nullptr) {}
    };

    Nodo* inicio; // Ponteiro para o início da lista
    int tamanho;  // Tamanho da lista

    // Métodos privados
    bool inserirMeio(int posicao, int valor);
    void removerInicio();
    void removerMeio(int posicao);
};

#endif