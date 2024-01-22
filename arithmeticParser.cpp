#include "arithmeticParser.h"


arithmeticParser::arithmeticParser() {

}
int arithmeticParser::prioritet(char operacija) {
    if (operacija == '*' || operacija == '/') {
        return 2;
    }
    else if (operacija == '+' || operacija == '-') {
        return 1;
    }
    else {
        return 0; // Ostali znakovi koji nisu operatori
    }
}

bool arithmeticParser::jeOperator(char znak) {
    return (znak == '+' || znak == '-' || znak == '*' || znak == '/');
}

int arithmeticParser::izracunajRezultat(const std::string& izraz) {
    std::stack<double> brojevi;
    std::stack<char> operacije;

    for (size_t i = 0; i < izraz.length(); ++i) {
        if (isdigit(izraz[i]) || (izraz[i] == '-' && (i == 0 || izraz[i - 1] == '('))) {
            bool negativan = (izraz[i] == '-');
            if (negativan) {
                ++i; // Preskoči znak minus
            }

            double broj = 0;
            while (i < izraz.length() && (isdigit(izraz[i]) || izraz[i] == '.')) {
                broj = broj * 10 + (izraz[i] - '0');
                ++i;
            }
            --i;  // Vrati se unazad za jedan korak kako bi se izbeglo preskakanje sledećeg znaka

            if (negativan) {
                broj = -broj; // Ako je broj negativan, promeni znak
            }

            brojevi.push(broj);
        }
        else if (jeOperator(izraz[i])) {
            while (!operacije.empty() && prioritet(operacije.top()) >= prioritet(izraz[i])) {
                double drugiBroj = brojevi.top();
                brojevi.pop();
                double prviBroj = brojevi.top();
                brojevi.pop();
                char operacija = operacije.top();
                operacije.pop();

                switch (operacija) {
                case '+':
                    brojevi.push(prviBroj + drugiBroj);
                    break;
                case '-':
                    brojevi.push(prviBroj - drugiBroj);
                    break;
                case '*':
                    brojevi.push(prviBroj * drugiBroj);
                    break;
                case '/':
                    if (drugiBroj != 0) {
                        brojevi.push(prviBroj / drugiBroj);
                    }
                    else {
                        //cerr << "Deljenje nulom nije dozvoljeno." << endl;
                        return 0.0;
                    }
                    break;
                default:
                    //cerr << "Nepoznata operacija: " << operacija << endl;
                    return 0.0;
                }
            }
            operacije.push(izraz[i]);
        }
        else if (izraz[i] == '(') {
            operacije.push('(');
        }
        else if (izraz[i] == ')') {
            while (!operacije.empty() && operacije.top() != '(') {
                double drugiBroj = brojevi.top();
                brojevi.pop();
                double prviBroj = brojevi.top();
                brojevi.pop();
                char operacija = operacije.top();
                operacije.pop();

                switch (operacija) {
                case '+':
                    brojevi.push(prviBroj + drugiBroj);
                    break;
                case '-':
                    brojevi.push(prviBroj - drugiBroj);
                    break;
                case '*':
                    brojevi.push(prviBroj * drugiBroj);
                    break;
                case '/':
                    if (drugiBroj != 0) {
                        brojevi.push(prviBroj / drugiBroj);
                    }
                    else {
                        ////cerr << "Deljenje nulom nije dozvoljeno." << endl;
                        return 0.0;
                    }
                    break;
                default:
                    //cerr << "Nepoznata operacija: " << operacija << endl;
                    return 0.0;
                }
            }
            if (!operacije.empty() && operacije.top() == '(') {
                operacije.pop(); // Skini otvorenu zatvorenu zagradu
            }
            else {
                //cerr << "Greska: Neispravno uparene zagrade." << endl;
                return 0.0;
            }
        }
        else if (izraz[i] == ' ') {
            continue;
        }
        else {
            //cerr << "Nepoznat znak u izrazu: " << izraz[i] << endl;
            return 0.0;
        }
    }

    while (!operacije.empty()) {
        double drugiBroj = brojevi.top();
        brojevi.pop();
        double prviBroj = brojevi.top();
        brojevi.pop();
        char operacija = operacije.top();
        operacije.pop();

        switch (operacija) {
        case '+':
            brojevi.push(prviBroj + drugiBroj);
            break;
        case '-':
            brojevi.push(prviBroj - drugiBroj);
            break;
        case '*':
            brojevi.push(prviBroj * drugiBroj);
            break;
        case '/':
            if (drugiBroj != 0) {
                brojevi.push(prviBroj / drugiBroj);
            }
            else {
                //cerr << "Deljenje nulom nije dozvoljeno." << endl;
                return 0.0;
            }
            break;
        default:
            //cerr << "Nepoznata operacija: " << operacija << endl;
            return 0.0;
        }
    }

    if (!brojevi.empty()) {
        return brojevi.top();
    }
    else {
        //cerr << "Nema rezultata." << endl;
        return 0.0;
    }
}
// Funkcija koja vraća kvadrat rezultata
double arithmeticParser::kvadratRezultata(double rezultat) {
    return pow(rezultat, 2);
}

// Funkcija koja vraća koren rezultata
double arithmeticParser::korenRezultata(double rezultat) {
    if (rezultat >= 0) {
        return sqrt(rezultat);
    }
    else {
        //cerr << "Koren negativnog broja nije realan broj." << endl;
        return 0.0;
    }
}
//int main() {
//    std::string izraz;
//    cout << "Unesite aritmeticki izraz: ";
//    getline(cin, izraz);
//
//    double rezultat = izracunajRezultat(izraz);
//    cout << "Rezultat: " << rezultat << endl;
//
//    // Računanje i ispis kvadrata rezultata
//    double rezultatKvadrat = kvadratRezultata(rezultat);
//    cout << "Kvadrat rezultata: " << rezultatKvadrat << endl;
//
//    // Računanje i ispis korena rezultata
//    double rezultatKoren = korenRezultata(rezultat);
//    cout << "Koren rezultata: " << rezultatKoren << endl;
//
//    const double unaprijedDefiniraniPostotak = 1;
//    double procenatRezultata = ((% * rezultat);
//    cout << "Procenat rezultata: " << procenatRezultata << endl;
//
//
//    return 0;
//}