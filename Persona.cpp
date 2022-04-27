#include<iostream>
#include<string>
using namespace std;

class Persona {
    private:
        string nome;
        string cognome;
        int eta;
        string email;
		int *temperatura;

    public:
        Persona() { //costruttore di default
            temperatura = new int[100];
        }

        Persona(string n, string c, int e, string mail) : nome(n), cognome(c), eta(e), email(mail) {
			temperatura = new int[100];
		} //costruttore "completo"

        Persona(const Persona &p) { //costruttore di copia
            nome = p.nome;
            cognome = p.cognome;
            eta = p.eta;
            email = p.email;
            temperatura = new int[100];
        }
		
		void print(); //funzione inline

        ~Persona() {
            delete[] temperatura;
        }

        /*void print() {
            cout << "Mi chiamo " << nome << " " << cognome << ", ho " << eta << " anni e la mia email e' " << email << endl;
        }*/
};

void Persona::print() { //funzione inline
    cout << "Mi chiamo " << nome << " " << cognome << ", ho " << eta << " anni e la mia email e' " << email << endl;
}

void fun() {
	Persona p("Federico", "Pavone", 19, "fedepavone@gmail.com");
    p.print();
    Persona p1(p);
    p1.print();
    Persona p2();
    //p2.print();

    Persona p3 = p; //altro modo per utilizzare il costruttore di copia
    p3.print();
}

int main() {
	fun();
	cout << "ciao" << endl;
}