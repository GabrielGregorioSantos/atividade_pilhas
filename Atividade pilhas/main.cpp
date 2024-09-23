#include <iostream>
#include <cstring> // Para usar strlen

using namespace std;

// Defini��o da estrutura da pilha
struct Pilha {
    char elementos[100]; // Array para armazenar elementos da pilha
    int topo; // �ndice do topo da pilha

    // Construtor para inicializar a pilha
    Pilha() {
        topo = -1; // Inicializa o topo como -1 (pilha vazia)
    }

    // M�todo para verificar se a pilha est� vazia
    bool vazia() {
        return topo == -1;
    }

    // M�todo para adicionar um elemento � pilha
    void empilhar(char elemento) {
        if (topo < 99) { // Verifica se h� espa�o na pilha
            elementos[++topo] = elemento; // Adiciona o elemento e atualiza o topo
        }
    }

    // M�todo para remover o elemento do topo da pilha
    char desempilhar() {
        if (!vazia()) {
            return elementos[topo--]; // Retorna o elemento do topo e atualiza o topo
        }
        return '\0'; // Retorna nulo se a pilha estiver vazia
    }
};

// Fun��o para validar a express�o
bool validarExpressao(const char* expressao) {
    Pilha pilha; // Cria uma pilha para armazenar par�nteses e colchetes

    // Itera sobre cada caractere da express�o
    for (int i = 0; i < strlen(expressao); i++) {
        char caractere = expressao[i];

        // Se encontrar um caractere de abertura, empilha
        if (caractere == '(' || caractere == '[') {
            pilha.empilhar(caractere);
        }
        // Se encontrar um caractere de fechamento
        else if (caractere == ')' || caractere == ']') {
            // Se a pilha estiver vazia, a express�o � inv�lida
            if (pilha.vazia()) return false;
            char topo = pilha.desempilhar(); // Desempilha o elemento do topo

            // Verifica se o fechamento corresponde � abertura
            if ((caractere == ')' && topo != '(') || (caractere == ']' && topo != '[')) {
                return false; // Se n�o corresponder, a express�o � inv�lida
            }
        }
    }
    // A express�o � v�lida se a pilha estiver vazia no final
    return pilha.vazia();
}

// Fun��o principal
int main() {
    char expressao[100]; // Array para armazenar a express�o do usu�rio

    // Solicita ao usu�rio que insira uma express�o
    cout << "Digite uma expressao matematica: ";
    cin.getline(expressao, 100); // L� a express�o

    // Valida a express�o e exibe o resultado
    if (validarExpressao(expressao)) {
        cout << "Expressao valida" << endl; // Express�o v�lida
    } else {
        cout << "Expressao invalida" << endl; // Express�o inv�lida
    }

    return 0; // Indica que o programa foi executado com sucesso
}
