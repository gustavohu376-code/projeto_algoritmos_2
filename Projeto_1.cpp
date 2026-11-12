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
    int id_cliente;
};

// Menu
void mostrarMenu() {
    cout << "\n#################### MENU ####################\n";
    cout << "1 - Cadastrar Cliente\n";
    cout << "2 - Cadastrar Filme\n";
    cout << "3 - Mostrar Clientes\n";
    cout << "4 - Mostrar Filmes\n";
    cout << "5 - Buscar Filmes por Cliente\n";
    cout << "6 - Relatorio Geral\n";
    cout << "7 - Sair\n";
    cout << "##############################################\n";
    cout << "Digite sua opcao: ";
}

// Buscar cliente pelo ID
int buscarCliente(Cliente vet[], int n, int id) {

    for(int i = 0; i < n; i++) {

        if(vet[i].id_cliente == id) {
            return i;
        }
    }

    return -1;
}

// Cadastrar cliente
bool cadCliente(Cliente vet[], int i, int n) {

    int id;

    cout << "Digite o ID do cliente: ";
    cin >> id;

    if(buscarCliente(vet, n, id) != -1) {
        cout << "Esse ID ja esta cadastrado!\n";
        return false;
    }

    vet[i].id_cliente = id;

    cin.ignore();

    cout << "Digite o nome do cliente: ";
    getline(cin, vet[i].nome);

    cout << "Digite o telefone do cliente: ";
    cin >> vet[i].telefone;

    cout << "Cliente cadastrado com sucesso!\n";

    return true;
}

// Cadastrar filme
bool cadFilme(Filme vet[], int i, Cliente clientes[], int n) {

    int id;

    cout << "Digite o codigo do filme: ";
    cin >> vet[i].codigo;

    cin.ignore();

    cout << "Digite o titulo do filme: ";
    getline(cin, vet[i].titulo);

    cout << "Digite o genero do filme: ";
    getline(cin, vet[i].genero);

    cout << "Digite o ano do filme: ";
    cin >> vet[i].ano;

    cout << "Digite o ID do cliente que alugou o filme: ";
    cin >> id;

    if(buscarCliente(clientes, n, id) == -1) {
        cout << "Cliente nao encontrado! Filme nao cadastrado.\n";
        return false;
    }

    vet[i].id_cliente = id;

    cout << "Filme cadastrado com sucesso!\n";

    return true;
}

// Mostrar clientes
void mostrarClientes(Cliente vet[], int n) {

    cout << "\nClientes cadastrados:\n";

    for(int i = 0; i < n; i++) {

        cout << "----------------------------------------\n";
        cout << "ID: " << vet[i].id_cliente << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Telefone: " << vet[i].telefone << endl;
    }

    cout << "----------------------------------------\n";
}

// Mostrar filmes
void mostrarFilmes(Filme vet[], int n, Cliente clientes[], int totalClientes) {

    cout << "\nFilmes cadastrados:\n";

    for(int i = 0; i < n; i++) {

        cout << "----------------------------------------\n";
        cout << "Codigo: " << vet[i].codigo << endl;
        cout << "Titulo: " << vet[i].titulo << endl;
        cout << "Genero: " << vet[i].genero << endl;
        cout << "Ano: " << vet[i].ano << endl;

        int pos = buscarCliente(clientes, totalClientes, vet[i].id_cliente);

        if(pos != -1) {
            cout << "Alugado para: " << clientes[pos].nome << endl;
        }
    }

    cout << "----------------------------------------\n";
}

// Buscar filmes por cliente
void buscarFilmesCliente(Filme filmes[], int n, Cliente clientes[], int totalClientes) {

    int id;
    int quantidade = 0;

    cout << "Digite o ID do cliente: ";
    cin >> id;

    int pos = buscarCliente(clientes, totalClientes, id);

    if(pos == -1) {
        cout << "Cliente nao encontrado!\n";
        return;
    }

    cout << "\nFilmes alugados por: " << clientes[pos].nome << endl;

    for(int i = 0; i < n; i++) {

        if(filmes[i].id_cliente == id) {

            cout << "----------------------------------------\n";
            cout << "Titulo: " << filmes[i].titulo << endl;
            cout << "Genero: " << filmes[i].genero << endl;
            cout << "Ano: " << filmes[i].ano << endl;

            quantidade++;
        }
    }

    if(quantidade == 0) {
        cout << "Esse cliente nao possui filmes alugados.\n";
    }
}

// Relatorio geral
void relatorioGeral(Cliente clientes[], int totalClientes, Filme filmes[], int totalFilmes) {

    cout << "\n######## RELATORIO GERAL ########\n";

    for(int i = 0; i < totalClientes; i++) {

        int quantidade = 0;

        for(int j = 0; j < totalFilmes; j++) {

            if(filmes[j].id_cliente == clientes[i].id_cliente) {
                quantidade++;
            }
        }

        cout << "Cliente: " << clientes[i].nome << endl;
        cout << "ID: " << clientes[i].id_cliente << endl;
        cout << "Filmes alugados: " << quantidade << endl;
        cout << "----------------------------------------\n";
    }
}

// Programa principal
int main() {

    Cliente listaCliente[MAX];
    Filme listaFilme[MAX];

    int contClientes = 0;
    int contFilmes = 0;

    int opcao;

    while(true) {

        mostrarMenu();
        cin >> opcao;

        if(opcao == 7) {
            break;
        }

        switch(opcao) {

            case 1:

                if(contClientes < MAX) {

                    if(cadCliente(listaCliente, contClientes, contClientes)) {
                        contClientes++;
                    }

                } else {
                    cout << "Limite de clientes atingido!\n";
                }

                break;

            case 2:

                if(contFilmes < MAX) {

                    if(contClientes == 0) {
                        cout << "Cadastre um cliente primeiro!\n";
                    } else {

                        if(cadFilme(listaFilme, contFilmes, listaCliente, contClientes)) {
                            contFilmes++;
                        }
                    }

                } else {
                    cout << "Limite de filmes atingido!\n";
                }

                break;

            case 3:
                mostrarClientes(listaCliente, contClientes);
                break;

            case 4:
                mostrarFilmes(listaFilme, contFilmes, listaCliente, contClientes);
                break;

            case 5:
                buscarFilmesCliente(listaFilme, contFilmes, listaCliente, contClientes);
                break;

            case 6:
                relatorioGeral(listaCliente, contClientes, listaFilme, contFilmes);
                break;

            default:
                cout << "Opcao invalida!\n";
                break;
        }
    }

    cout << "Programa encerrado!\n";

    return 0;
}
