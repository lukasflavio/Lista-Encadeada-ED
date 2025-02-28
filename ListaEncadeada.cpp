#include "ListaEncadeada.h"


ListaEncadeada::ListaEncadeada() : inicio(nullptr), tamanho(0) {}


ListaEncadeada::~ListaEncadeada() {
    while (!estaVazia()) {
        removerInicio();
    }
}


bool ListaEncadeada::estaVazia() const {
    return tamanho == 0;
}


int ListaEncadeada::obterTamanho() const {
    return tamanho;
}


int ListaEncadeada::obterElemento(int posicao) const {
    if (posicao < 1 || posicao > tamanho || estaVazia()) {
        return -1;  // Retorna -1 para indicar erro
    }

    Nodo* atual = inicio;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    return atual->valor;
}


bool ListaEncadeada::alterarElemento(int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho || estaVazia()) {
        return false;
    }

    Nodo* atual = inicio;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    atual->valor = valor;
    return true;
}


bool ListaEncadeada::inserirInicio(int valor) {
    Nodo* novoNodo = new Nodo(valor);
    novoNodo->proximo = inicio;
    inicio = novoNodo;
    tamanho++;
    return true;
}


bool ListaEncadeada::inserirFim(int valor) {
    if (estaVazia()) {
        return inserirInicio(valor);
    }

    Nodo* novoNodo = new Nodo(valor);
    Nodo* atual = inicio;
    while (atual->proximo != nullptr) {
        atual = atual->proximo;
    }
    atual->proximo = novoNodo;
    tamanho++;
    return true;
}


bool ListaEncadeada::inserirMeio(int posicao, int valor) {
    Nodo* novoNodo = new Nodo(valor);
    Nodo* atual = inicio;

    for (int i = 1; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    novoNodo->proximo = atual->proximo;
    atual->proximo = novoNodo;
    tamanho++;
    return true;
}


bool ListaEncadeada::inserir(int posicao, int valor) {
    if (posicao < 1 || posicao > tamanho + 1) {
        return false;
    }

    if (posicao == 1) {
        return inserirInicio(valor);
    } else if (posicao == tamanho + 1) {
        return inserirFim(valor);
    } else {
        return inserirMeio(posicao, valor);
    }
}


void ListaEncadeada::removerInicio() {
    if (estaVazia()) {
        return;
    }

    Nodo* temp = inicio;
    inicio = inicio->proximo;
    delete temp;
    tamanho--;
}


void ListaEncadeada::removerMeio(int posicao) {
    Nodo* atual = inicio;
    Nodo* anterior = nullptr;

    for (int i = 1; i < posicao; i++) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = atual->proximo;
    delete atual;
    tamanho--;
}


int ListaEncadeada::remover(int posicao) {
    if (posicao < 1 || posicao > tamanho || estaVazia()) {
        return -1;  // Retorna -1 para indicar erro
    }

    int valorRemovido;

    if (posicao == 1) {
        valorRemovido = inicio->valor;
        removerInicio();
    } else {
        Nodo* atual = inicio;
        for (int i = 1; i < posicao; i++) {
            atual = atual->proximo;
        }
        valorRemovido = atual->valor;
        removerMeio(posicao);
    }

    return valorRemovido;
}


void ListaEncadeada::exibir() const {
    Nodo* atual = inicio;
    while (atual != nullptr) {
        std::cout << atual->valor;
        if (atual->proximo != nullptr) {
            std::cout << " -> ";
        }
        atual = atual->proximo;
    }
    std::cout << std::endl;
}
