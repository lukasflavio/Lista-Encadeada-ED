#include <iostream>
#include "ListaEncadeada.h"

int main()
{
    ListaEncadeada lista;

    int opcao = 0, posicao = 0, valor = 0;

    while (opcao != 8)
    {
        std::cout << "\nEscolha uma ação:\n";
        std::cout << "1 - Inserir elemento\n";
        std::cout << "2 - Verificar se está vazia\n";
        std::cout << "3 - Obter tamanho da lista\n";
        std::cout << "4 - Alterar valor de uma posição\n";
        std::cout << "5 - Obter valor de uma posição\n";
        std::cout << "6 - Remover elemento\n";
        std::cout << "7 - Exibir lista\n";
        std::cout << "8 - Sair\n";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            std::cout << "Digite a posição: ";
            std::cin >> posicao;
            std::cout << "Digite o valor: ";
            std::cin >> valor;
            if (lista.inserir(posicao, valor))
            {
                std::cout << "Elemento inserido com sucesso!\n";
            }
            else
            {
                std::cout << "Erro ao inserir elemento.\n";
            }
            break;
        case 2:
            if (lista.estaVazia())
            {
                std::cout << "A lista está vazia.\n";
            }
            else
            {
                std::cout << "A lista não está vazia.\n";
            }
            break;
        case 3:
            std::cout << "Tamanho da lista: " << lista.obterTamanho() << "\n";
            break;
        case 4:
            std::cout << "Digite a posição: ";
            std::cin >> posicao;
            std::cout << "Digite o novo valor: ";
            std::cin >> valor;
            if (lista.alterarElemento(posicao, valor))
            {
                std::cout << "Valor alterado com sucesso!\n";
            }
            else
            {
                std::cout << "Erro ao alterar valor.\n";
            }
            break;
        case 5:
            std::cout << "Digite a posição: ";
            std::cin >> posicao;
            valor = lista.obterElemento(posicao);
            if (valor != -1)
            {
                std::cout << "Valor na posição " << posicao << ": " << valor << "\n";
            }
            else
            {
                std::cout << "Erro ao obter valor.\n";
            }
            break;
        case 6:
            std::cout << "Digite a posição: ";
            std::cin >> posicao;
            valor = lista.remover(posicao);
            if (valor != -1)
            {
                std::cout << "Elemento removido: " << valor << "\n";
            }
            else
            {
                std::cout << "Erro ao remover elemento.\n";
            }
            break;
        case 7:
            std::cout << "Lista: ";
            lista.exibir();
            break;
        case 8:
            std::cout << "Saindo...\n";
            break;
        default:
            std::cout << "Opção inválida!\n";
            break;
        }
    }

    return 0;
}