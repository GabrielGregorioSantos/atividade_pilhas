#include <iostream>
#include <cstring> // Para usar strlen

using namespace std;

// Definição da estrutura da pilha
struct Pilha {
    char elementos[100]; // Array para armazenar elementos da pilha
    int topo; // Índice do topo da pilha

    // Construtor para inicializar a pilha
    Pilha() {
        topo = -1; // Inicializa o topo como -1 (pilha vazia)
    }

    // Método para verificar se a pilha está vazia
    bool vazia() {
        return topo == -1;
    }

    // Método para adicionar um elemento à pilha
    void empilhar(char elemento) {
        if (topo < 99) { // Verifica se há espaço na pilha
            elementos[++topo] = elemento; // Adiciona o elemento e atualiza o topo
        }
    }

    // Método para remover o elemento do topo da pilha
    char desempilhar() {
        if (!vazia()) {
            return elementos[topo--]; // Retorna o elemento do topo e atualiza o topo
        }
        return '\0'; // Retorna nulo se a pilha estiver vazia
    }
};

// Função para validar a expressão
bool validarExpressao(const char* expressao) {
    Pilha pilha; // Cria uma pilha para armazenar parênteses e colchetes

    // Itera sobre cada caractere da expressão
    for (int i = 0; i < strlen(expressao); i++) {
        char caractere = expressao[i];

        // Se encontrar um caractere de abertura, empilha
        if (caractere == '(' || caractere == '[') {
            pilha.empilhar(caractere);
        }
        // Se encontrar um caractere de fechamento
        else if (caractere == ')' || caractere == ']') {
            // Se a pilha estiver vazia, a expressão é inválida
            if (pilha.vazia()) return false;
            char topo = pilha.desempilhar(); // Desempilha o elemento do topo

            // Verifica se o fechamento corresponde à abertura
            if ((caractere == ')' && topo != '(') || (caractere == ']' && topo != '[')) {
                return false; // Se não corresponder, a expressão é inválida
            }
        }
    }
    // A expressão é válida se a pilha estiver vazia no final
    return pilha.vazia();
}

// Função principal
int main() {
    char expressao[100]; // Array para armazenar a expressão do usuário

    // Solicita ao usuário que insira uma expressão
    cout << "Digite uma expressao matematica: ";
    cin.getline(expressao, 100); // Lê a expressão

    // Valida a expressão e exibe o resultado
    if (validarExpressao(expressao)) {
        cout << "Expressao valida" << endl; // Expressão válida
    } else {
        cout << "Expressao invalida" << endl; // Expressão inválida
    }

    return 0; // Indica que o programa foi executado com sucesso
}
