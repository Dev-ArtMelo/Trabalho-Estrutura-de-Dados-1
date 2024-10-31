// Arthur Santos Melo - 831540


#include <iostream>
#include <string>

using namespace std;

// Definindo a estrutura 
struct Carro {
    string nome;
    string marca;
    string modelo;
};

// Definindo a classe pilha 
class PilhaCarros {
private:
    static const int capacidade = 100;
    Carro carros[capacidade];
    int topo; // indice do topo da pilha

public:
    PilhaCarros() {
        topo = -1; // Inicializa -1 indicando que a pilha est� vazia
    }

    // Verificar se a pilha esta cheia
    bool cheia() {
        return topo == capacidade - 1;
    }

	// Verificar se a pilha esta vazia
    bool vazia() {
        return topo == -1;
    }
    
    // Adicionar mais um carro na pilha
    void cadastrarCarro(const Carro& carro) {
        if (cheia()) {
            cout << "PILHA CHEIA!!!, nao eh possivel adicionar mais carros." << endl;
            return;
        }
        carros[++topo] = carro;
        cout << "Carro cadastrado com sucesso!" << endl;
    }

    // Exclusao do �ltimo cadastro na pilha
    void deletarCarro() {
        if (vazia()) {
            cout << "Pilha Vazia!! nao ha carros para serem excluidos." << endl;
            return;
        }
        topo--;
        cout << "Ultimo carro cadastrado foi removido com sucesso!" << endl;
    }

    // Listando todos os carros cadastrados na pilha
    void listarCarros() {
        if (vazia()) {
            cout << "Nao existem carros cadastrados." << endl;
            return;
        }
        cout << "Lista de carros cadastrados:" << endl;
        for (int i = topo; i >= 0; i--) {
            cout << "Nome: " << carros[i].nome << ", Marca: " << carros[i].marca << ", Modelo: " << carros[i].modelo << endl;
        }
    }
};

int main() {
    PilhaCarros pilha;

    int opcao;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Cadastrar novo carro" << endl;
        cout << "2. Deletar ultimo carro cadastrado" << endl;
        cout << "3. Listar todos os carros cadastrados" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                Carro novoCarro;
                cout << "Digite o nome do carro: ";
                cin >> novoCarro.nome;
                cout << "Digite a marca do carro: ";
                cin >> novoCarro.marca;
                cout << "Digite o modelo do carro: ";
                cin >> novoCarro.modelo;
                pilha.cadastrarCarro(novoCarro);
                break;
            }
            case 2:
                pilha.deletarCarro();
                break;
            case 3:
                pilha.listarCarros();
                break;
            case 4:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}
