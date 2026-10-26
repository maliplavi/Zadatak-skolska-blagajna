#include <iostream>
#include <iomanip>

using namespace std;
int CIJENA_ULAZNICE = 5;
int PRAG_POPUSTA = 5;
double STOPA_POPUSTA = 0.1;
int ukupnoUlaznica;
double ukupniPrihod;

bool ispravanUnos(int kolicina){
    if (kolicina < 1 && kolicina > 30){
        cout << "probaj ponovo" << endl;
        return false;
    } else return true;
}
double izracunajIznos(int kolicina){
    double osnovniIznos = kolicina * CIJENA_ULAZNICE;
    double konacniIznos = osnovniIznos;
    if (kolicina > 4) konacniIznos = osnovniIznos - osnovniIznos* STOPA_POPUSTA;
    return konacniIznos;
}
void evidentirajKupnju(int kolicina, double iznos){
    ::ukupnoUlaznica = ::ukupnoUlaznica + kolicina;
    ::ukupniPrihod = ::ukupniPrihod + iznos;
}
void ispisiKupnju(int redniBroj, double iznos){
    cout << "Kupnja " << redniBroj <<": "<<   iznos << "EUR" << endl;

}
void ispisiSazetak(){
    cout << "Ovo je ukupno ulaznica: " << ::ukupnoUlaznica << endl;
    cout << "Ovo je ukupnan prihod: "<< ::ukupniPrihod << " EUR" << endl;
}

int main()
{
    cout << fixed << setprecision(2);

    int kolicina,redniBroj=1;
    double iznos= 0.0;

    int a=3;
    for(int i = 0;a>i;i++){
        cout << "unesi broj ualznica (1-30): " ;
        cin >> kolicina;
        ispravanUnos(kolicina);
        ispisiKupnju(redniBroj, izracunajIznos(kolicina));
        redniBroj++;
        iznos = izracunajIznos(kolicina);
        evidentirajKupnju(kolicina,iznos);

    }

    ispisiSazetak();


    return 0;
}
