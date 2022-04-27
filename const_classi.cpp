#include<iostream>
using namespace std;

class Persona {
    string nome;
    string cognome;

    public:
        Persona(string n, string c) : nome(n), cognome(c) {}

        string getNome() const {
            return this->nome;
        }
};

int main() {

    Persona p("nome1", "cognome1");
    string x = p.getNome();

    x = "Marco";

    cout << x << endl;
}