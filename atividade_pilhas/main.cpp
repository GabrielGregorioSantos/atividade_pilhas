#include <iostream>
#include <string>
using namespace std;

struct NoDaPilha {
    char simbolo;
    NoDaPilha* proximo;
};

class Pilha {
private:
    NoDaPilha* topoDaPilha;

public:
    Pilha() {
        topoDaPilha = nullptr;
    }

    ~Pilha() {
        while (!pilhaEstaVazia()) {
            desempilhar();
        }
    }

    bool pilhaEstaVazia() {
        return topoDaPilha == nullptr;
    }

    void empilhar(char novoSimbolo) {
        NoDaPilha* novoNo = new NoDaPilha;
        novoNo->simbolo = novoSimbolo;
        novoNo->proximo = topoDaPilha;
        topoDaPilha = novoNo;
    }

    char desempilhar() {
        if (pilhaEstaVazia()) {
            cout << "Erro: A pilha esta vazia!" << endl;
            return '\0';
        }
        NoDaPilha* noTemporario = topoDaPilha;
        char simboloDesempilhado = topoDaPilha->simbolo;
        topoDaPilha = topoDaPilha->proximo;
        delete noTemporario;
        return simboloDesempilhado;
    }

    char consultarTopo() {
        if (!pilhaEstaVazia()) {
            return topoDaPilha->simbolo;
        } else {
            return '\0';
        }
    }
};

bool validarExpressaoMatematica(const string& expressao) {
    Pilha pilhaDeSimbolos;

    for (char simbolo : expressao) {
        if (simbolo == '(' || simbolo == '[') {
            pilhaDeSimbolos.empilhar(simbolo);
        } else if (simbolo == ')' || simbolo == ']') {
            if (pilhaDeSimbolos.pilhaEstaVazia()) {
                return false;
            }

            char simboloNoTopo = pilhaDeSimbolos.consultarTopo();
            if ((simbolo == ')' && simboloNoTopo == '(') || (simbolo == ']' && simboloNoTopo == '[')) {
                pilhaDeSimbolos.desempilhar();
            } else {
                return false;
            }
        }
    }

    return pilhaDeSimbolos.pilhaEstaVazia();
}

int main() {
    string expressaoMatematica;

    cout << "Digite uma expressao matematica: ";
    cin >> expressaoMatematica;

    if (validarExpressaoMatematica(expressaoMatematica)) {
        cout << "Expressao valida" << endl;
    } else {
        cout << "Expressao invalida" << endl;
    }

    return 0;
}
