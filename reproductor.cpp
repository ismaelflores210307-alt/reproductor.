#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct Cancion {
    string nombre;
    string artista;
    string duracion;
    Cancion* siguiente;
    Cancion* anterior;
};

class Playlist {
private:
    Cancion* inicio;
    Cancion* fin;

public:
    Playlist() {
        inicio = nullptr;
        fin = nullptr;
    }

    void agregarCancion(string nombre, string artista, string duracion) {
        Cancion* nueva = new Cancion();
        nueva->nombre = nombre;
        nueva->artista = artista;
        nueva->duracion = duracion;

        if (inicio == nullptr) {
            inicio = nueva;
            fin = nueva;
            nueva->siguiente = nueva;
            nueva->anterior = nueva;
        } else {
            nueva->siguiente = inicio;
            nueva->anterior = fin;
            fin->siguiente = nueva;
            inicio->anterior = nueva;
            fin = nueva;
        }
        cout << "Cancion agregada exitosamente.\n";
    }

    void mostrarLista() {
        if (inicio == nullptr) {
            cout << "La lista esta vacia.\n";
            return;
        }
        Cancion* actual = inicio;
        do {
            cout << "Nombre: " << actual->nombre
                 << " | Artista: " << actual->artista
                 << " | Duracion: " << actual->duracion << endl;
            actual = actual->siguiente;
        } while (actual != inicio);
    }

    void reproducir() {
        if (inicio == nullptr) {
            cout << "La lista esta vacia.\n";
            return;
        }
        Cancion* actual = inicio;
        int tecla;
        
        cout << "Modo reproduccion (-> siguiente, <- anterior, ESC salir)\n";
        while (true) {
            cout << "\nReproduciendo: " << actual->nombre
                 << " - " << actual->artista
                 << " (" << actual->duracion << ")" << endl;

            tecla = _getch();

            if (tecla == 27) { 
                cout << "Saliendo del modo reproduccion...\n";
                break;
            } else if (tecla == 75) {
                actual = actual->anterior;
            } else if (tecla == 77) {
                actual = actual->siguiente;
            }
        }
    }
};

int main() {
    Playlist lista;
    int opcion;
    string nombre, artista, duracion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar cancion\n";
        cout << "2. Mostrar lista completa\n";
        cout << "3. Reproducir playlist\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre de la cancion: ";
                getline(cin, nombre);
                cout << "Ingrese artista: ";
                getline(cin, artista);
                cout << "Ingrese duracion: ";
                getline(cin, duracion);
                lista.agregarCancion(nombre, artista, duracion);
                break;
            case 2:
                lista.mostrarLista();
                break;
            case 3:
                lista.reproducir();
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);

    return 0;
}
