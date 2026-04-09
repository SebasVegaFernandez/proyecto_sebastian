#include <iostream>
#include <string>

using namespace std;

//------------------------------- pilas ------------------
#define MAX 100

class Pila {
private:
	string elementos[MAX];
	int tope;
public:
	Pila() {
		tope = -1;
	}

	void push(string valor) {
		if (tope == MAX - 1) {
			cout << "Error la pila esta llena. " << endl;
		}
		else {
			tope++;
			elementos[tope] = valor;
		}
	}
	int mostrar() {
		if (tope == -1) {
			cout << "Error la pila esta vacia" << endl;
			return 0;
		}
		else {
			for (int i=tope; i >=0; i--){
			cout << elementos[i] << endl;
			}
		}
	}
};

//Nodo

struct nodo {
	string nombre;
	string telefono;
	string correo;
	nodo* siguiente;

};

//Lista enlazada y sus herramientas

void insertarinicio(nodo*& lista, string nomb, string tele, string corr) {
	nodo* nuevo = new nodo();
	nuevo->nombre = nomb;
	nuevo->telefono = tele;
	nuevo->correo = corr;
	nuevo->siguiente = lista;
	lista = nuevo;
}
void mostrarlista(nodo* lista) {
	nodo* actual = lista;
	cout << "---------------------------" << endl;
	while (actual != NULL) {
		cout << "nombre:" << actual->nombre << " -> ";
		cout << "telefono:" << actual->telefono << " -> ";
		cout << "correo:" << actual->correo << " | " << endl;
		cout << "---------------------------" << endl;
		actual = actual->siguiente;
	}
	cout << "NULL" << endl;
}
bool buscar(nodo* lista, string nombre) {
	int H = 0;
	nodo* actual = lista;
	while (actual != NULL) {
		if (actual->nombre == nombre) {
			cout << "contacto encontrado" << endl;
			cout << actual->nombre << " - ";
				cout << actual->telefono << " - ";
				cout << actual->correo << endl;
			return true;
		}
		actual = actual->siguiente;
	}
	cout << "no encontrado" << endl;
	return false;
}
void eliminar(nodo*& lista, string nombre){
	if (lista == NULL){
		cout << "lista vacia" << endl;
		return;
	}
	nodo* aux = lista;
	nodo* anterior = NULL;

	while (aux != NULL && aux->nombre != nombre){
		anterior = aux;
		aux = aux->siguiente;
	}
	if (aux == NULL){
		cout << "datos no encontrados" << endl;
		return;
	}
	if (anterior == NULL) {
		lista = aux->siguiente;
	}
	else {
		anterior->siguiente = aux->siguiente;
	}
	delete aux;
}

class colasimple {
private:
	string nombre[MAX];
	string telefono[MAX];
	string correo[MAX];
	int frente;
	int final;
public:
	colasimple() {
		frente = -1;
		final = -1;
	}

	bool isempty() {
		return (frente == -1 || frente > final);
	}

	bool lleno() {
		return(final == MAX - 1);
	}
	void enqueue(string nom, string tel, string cor) {
		if (lleno()) {
			cout << "la cola esta llena, no se puede insertar mas contactos" << endl;
			return;
		}
		if (frente == -1) {
			frente = 0;
		}
		final++;
		nombre[final] = nom;
		telefono[final] = tel;
		correo[final] = cor;
	}
};

int main()
{
	colasimple cola;
	nodo* lista = NULL;
	Pila pila;

	int seleccion = 0;

	do {
		cout << "------------ MENU ------------" << endl;
		cout << "1. agregar un contacto" << endl;
		cout << "2. listado de todos los contactos" << endl;
		cout << "3. buscar por nombre" << endl;
		cout << "4. eliminar por nombre" << endl;
		cout << "5. historial de acciones" << endl;
		cout << "6. agregar datos nuevos" << endl;
		cout << "0. salir" << endl;
		cin >> seleccion;
		switch (seleccion) {
		case 1: {
			int cantidad = 0;
			string nombre, telefono, correo;

			cout << "digite un numero para el tamano de la lista: " << endl;
			cin >> cantidad;
			cout << "inserte los contactos: " << endl;
			for (int l = 0; l < cantidad; l++) {

				cout << "digite el nombre: ";
				cin >> nombre;

				cout << "digite el telefono: ";
				cin >> telefono;

				cout << "digite el correo: ";
				cin >> correo;

				cout << "---------------------------" << endl;

				insertarinicio(lista, nombre, telefono, correo);
				pila.push("contacto agregado: " + nombre + " - " + telefono + " - " + correo);
			}
			break;
		}
		case 2: {
			cout << "El contenido de la lista es: " << endl;
			mostrarlista(lista);
			pila.push("lista de contactos revisada");
			break;
		}
		case 3: {
			string nombre;
			cout << "digite el nombre de lo que desea buscar: " << endl;
			cin >> nombre;
			buscar(lista, nombre);
			pila.push("contacto buscado con el nombre de " + nombre);
			break;
		}
		case 4: {
			string nombre;
			cout << "digite el nombre del dato que desea eliminar" << endl;
			cin >> nombre;
			eliminar(lista, nombre);
			pila.push("contacto eliminado a nombre de " + nombre);
			break;
		}
		case 5: {
			pila.mostrar();
			break;
		}
		case 6: {
			int limite;
			string nombre, telefono, correo;
			cout << "digite la cantidad de contactos que agregara" << endl;
			cin >> limite;
			cout << "digite los contactos que desea agregar a la lista" << endl;
			for (int l = 0; l <= limite; l++) {
				cout << "digite el nombre" << endl;
				cin >> nombre;
				cout << "digite el telefono" << endl;
				cin >> telefono;
				cout << "digite el correo" << endl;
				cin >> correo;
				cola.enqueue(nombre, telefono, correo);
				insertarinicio(lista, nombre, telefono, correo);
				pila.push("contacto extra agregado en cola: " + nombre + " - "+ telefono +" - "+ correo);
			}
			cout << "datos ingresados correctamente a la cola y luego lista" << endl;
			break;
		}
		}
	} while (seleccion != 0);
}
