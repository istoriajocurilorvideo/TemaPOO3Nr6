#include "Farmacie.h"

Farmacie::Farmacie() : denumire("Default"), nrAngajati(0){}

Farmacie::Farmacie(const string& denumire, unsigned int nrAngajati, vector<pair<string, int>> profitLunar)
{
    this->denumire = denumire;
    this->nrAngajati = nrAngajati;
    this->profitLunar = profitLunar;
}

Farmacie::~Farmacie()
{
    profitLunar.clear();
}

Farmacie::Farmacie(const Farmacie& rhs) : denumire(rhs.denumire), nrAngajati(rhs.nrAngajati), profitLunar(rhs.profitLunar){}

Farmacie& Farmacie::operator=(const Farmacie& rhs)
{
    if (this == &rhs) return *this;
    denumire = rhs.denumire;
    nrAngajati = rhs.nrAngajati;
    profitLunar = rhs.profitLunar;
    return *this;
}

void Farmacie::write(ostream& out){
    out<<"Farmacia "<<denumire<<" cu "<<nrAngajati<<" angajati"<<endl;
    if(profitLunar.empty()) out<<"Momentan profitul lunar nu este disponibil" <<endl;
    else{
        pair<string, int> temp;
        out<<"Profitul lunar este :"<<endl;
        for(vector<pair<string, int>>::iterator it = profitLunar.begin(); it != profitLunar.end(); it++){
            temp = *it;
            cout<<temp.first<<" : "<<temp.second<<endl;
        }
    }
}
void Farmacie::read(istream& in){
    in>>denumire;
    in>>nrAngajati;
    unsigned int nr_profituri;
    in>>nr_profituri;
    pair<string, int> temp;
    for(unsigned int index = 0; index < nr_profituri; index++){
        in>>temp.first>>temp.second;
        profitLunar.push_back(temp);
    }
}

istream& operator>>(istream& in, Farmacie& f){
    cout<<"Citire date farmacie"<<endl;
    f.read(in);
    return in;
}

ostream& operator<<(ostream& out, Farmacie& f){
    cout<<"Afisare date farmicie";
    f.write(out);
    return out;
}
