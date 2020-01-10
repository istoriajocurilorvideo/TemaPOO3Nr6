#ifndef FARMACIEONLINE_H
#define FARMACIEONLINE_H
#include "Universal.h"
#include "Farmacie.h"

class FarmacieOnline : public Farmacie
{
    public:
        FarmacieOnline();
        FarmacieOnline(const string& adresaWeb, unsigned int nrVizitatori, float discount);
        FarmacieOnline(const string& denumire, unsigned int nrAngajati, vector<pair<string, int>> profitLunar,
                                const string& adresaWeb, unsigned int nrVizitatori, float discount);
        virtual ~FarmacieOnline();
        FarmacieOnline(const FarmacieOnline& rhs);
        FarmacieOnline& operator=(const FarmacieOnline& rhs);

        friend istream& operator>>(istream& in, FarmacieOnline& fo);
        friend ostream& operator<<(ostream& out, FarmacieOnline& fo);

        string getAdresaWeb() const { return adresaWeb; }
        int getNrVizitatori() const { return nrVizitatori; }
        double getDiscount() const { return discount; }

        void write(ostream& out);
        void read(istream& in);

    protected:
        string adresaWeb;
        unsigned int nrVizitatori;
        float discount;

    private:
};

#endif // FARMACIEONLINE_H
