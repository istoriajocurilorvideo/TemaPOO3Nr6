#ifndef FARMACIE_H
#define FARMACIE_H
#include "Universal.h"

class Farmacie
{
    public:
        Farmacie();
        Farmacie(const string& denumire, unsigned int nrAngajati, vector<pair<string, int>> profitLunar);
        virtual ~Farmacie();
        Farmacie(const Farmacie& other);
        Farmacie& operator=(const Farmacie& other);

        virtual void write(ostream& out);
        virtual void read(istream& in);

        friend istream& operator>>(istream& in, Farmacie& f);
        friend ostream& operator<<(ostream& out, Farmacie& f);

        string getDenumire() const { return denumire; }
        unsigned int getNrAngajati() const  { return nrAngajati; }
        vector<pair<string, int>> getProfit() const { return profitLunar; }

    protected:
        string denumire;
        unsigned int nrAngajati;
        vector< pair<string, int> > profitLunar;
};

#endif // FARMACIE_H
