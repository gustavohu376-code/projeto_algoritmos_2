#include <iostream>
#include <string>

#define MAX 10

using namespace std;

struct Cliente {
    string nome;
    int telefone;
    int id_cliente;
};

struct Filme {
    int codigo;
    string titulo;
    string genero;
    int ano;
};

// Procedimento para exibir um menu de instruções
void mostrarMenu() {
    cout << "\n#################### MENU ####################\n";
    cout << "1 - Para cadastrar um Cliente.\n";
    cout << "2 - Para cadastrar um Filme.\n";
    cout << "3 - Para mostrar os Clientes cadastrados\n";
    cout << "4 - Para mostrar os Filmes cadastrados\n";
    cout << "7 - Para sair\n";
    cout << "##############################################\n\n";
    cout << "Digite sua opcao: ";
}

// Procedimento para cadastrar o cliente
void cadCliente(Cliente vet[], int i) {

    cout << "Digite o ID do cliente: ";
    cin >> vet[i].id_cliente;

    cin.ignore();

    cout << "Digite o nome do cliente: ";
    getline(cin, vet[i].nome);

    cout << "Digite o Telefone do cliente: ";
    cin >> vet[i].telefone;
}

// Procedimento para cadastrar o filme
void cadFilme(Filme vet[], int i) {

    cout << "Digite o Codigo do filme: ";
    cin >> vet[i].codigo;

    cin.ignore();

    cout << "Digite o Titulo do Filme: ";
    getline(cin, vet[i].titulo);

    cout << "Digite o Genero do Filme: ";
    cin >> vet[i].genero;

    cout << "Digite o Ano do Filme: ";
    cin >> vet[i].genero;
}

void mostrarClientes(Cliente vet[], int n) {

    cout << "\nClientes cadastrados: \n";

    for(int i = 0; i < n; i++) {

        cout << "----------------------------------------\n";
        cout << "Id do Cliente: " << vet[i].id_cliente << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Telefone: " << vet[i].telefone << endl;

    }

    cout << "----------------------------------------\n";
}

void mostrarFilmes(Filme vet[], int n) {

    cout << "\nFilmes cadastrados: \n";

    for(int i = 0; i < n; i++) {

        cout << "----------------------------------------\n";
        cout << "Codigo do FIlme: " << vet[i].codigo << endl;
        cout << "Titulo: " << vet[i].titulo << endl;
        cout << "Genero: " << vet[i].genero << endl;
        cout << "Ano: " << vet[i].ano << endl;

    }

    cout << "----------------------------------------\n";
}

int main() {

    Cliente listaCliente[MAX];
    Filme listaFilme[MAX];

    int contClientes = 0;

    int opcao;

    int contFilmes;



    while(true) {
        mostrarMenu();
        cin >> opcao;

        if(opcao == 7) {
            break;
        }

        switch(opcao) {

            case 1:
                cadCliente(listaCliente, contClientes);
                contClientes++;
                break;

            case 2:
                cadFilme(listaFilme, contFilmes);
                contFilmes++;
                break;


            case 3:
                mostrarClientes(listaCliente, contClientes);
                break;

            case 4:
                mostrarFilmes(listaFilme, contFilmes);
                break;


            default:
                cout << "Opcao invalida.\n\n";
                break;
        }
    }

    return 0;
}
