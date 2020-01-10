#include "FarmacieOnline.h"

FarmacieOnline::FarmacieOnline() : Farmacie(), adresaWeb("http://NULL"), nrVizitatori(0), discount(0) {}

FarmacieOnline::FarmacieOnline(const string& adresaWeb, unsigned int nrVizitatori, float discount) : Farmacie() {
    this->adresaWeb = adresaWeb;
    this->nrVizitatori = nrVizitatori;
    this->discount = discount;
}

FarmacieOnline::FarmacieOnline(const string& denumire, unsigned int nrAngajati, vector<pair<string, int>> profitLunar,
                               const string& adresaWeb, unsigned int nrVizitatori, float discount)
    : Farmacie(denumire, nrAngajati, profitLunar) {
    this->adresaWeb = adresaWeb;
    this->nrVizitatori = nrVizitatori;
    this->discount = discount;
}

FarmacieOnline::~FarmacieOnline() {}

FarmacieOnline::FarmacieOnline(const FarmacieOnline& rhs)
    : FarmacieOnline(rhs.denumire, rhs.nrAngajati, rhs.profitLunar, rhs.adresaWeb, rhs.nrVizitatori, rhs.discount){}

FarmacieOnline& FarmacieOnline::operator=(const FarmacieOnline& rhs) {
    if (this == &rhs)
        return *this;
    denumire = rhs.denumire;
    nrAngajati = rhs.nrAngajati;
    profitLunar = rhs.profitLunar;
    adresaWeb = rhs.adresaWeb;
    nrVizitatori = rhs.nrVizitatori;
    discount = rhs.discount;
    return *this;
}

void FarmacieOnline::write(ostream& out) {
    Farmacie::write(out);
    out<<"Adresa web : "<<adresaWeb<<endl;
    out<<"Vizitatori curenti : "<<nrVizitatori<<endl;
    out<<"Discount : "<<discount<<endl;
}
void FarmacieOnline::read(istream& in) {
    Farmacie::read(in);
    in>>adresaWeb;
    in>>nrVizitatori;
    in>>discount;
}

istream& operator>>(istream& in, FarmacieOnline& fo){
    fo.read(in);
    return in;
}
ostream& operator<<(ostream& out, FarmacieOnline& fo){
    fo.write(out);
    return out;
}
