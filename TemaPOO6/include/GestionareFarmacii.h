#ifndef GESTIONAREFARMACII_H
#define GESTIONAREFARMACII_H
#include "Universal.h"
#include "FarmacieOnline.h"

string getRandId(unsigned int length);

template <class Type>
class GestionareFarmacii
{
    public:
        GestionareFarmacii() : index(0) {};
        GestionareFarmacii(vector<Type*> vec);
        ~GestionareFarmacii();
        GestionareFarmacii(const GestionareFarmacii& other);
        GestionareFarmacii& operator= (const GestionareFarmacii& other);
        GestionareFarmacii& operator += (Type& rhs);
        string getId() const { return id; }
        unsigned int currentIndex() const { return index; }
        string getFarmType(unsigned int index);
        friend istream& operator>>(istream& in, FarmacieOnline& fo);
        friend ostream& operator<<(ostream& out, FarmacieOnline& fo);

    protected:

    private:
        const string id = getRandId(4);
        unsigned int index = 0;
        Type **listFarm = nullptr;
};

template <>
class GestionareFarmacii <FarmacieOnline*>
{
    public:
        GestionareFarmacii() : index(0) {};
        virtual ~GestionareFarmacii() { delete[] listFarm;};
        GestionareFarmacii(const GestionareFarmacii& other) {
            index = other.index;
            listFarm = other.listFarm;
        };
        GestionareFarmacii& operator=(const GestionareFarmacii& other){
            if (this == &rhs) return *this;
            index = rhs.index;
            listFarm = rhs.listFarm;
            return *this;
        }
        GestionareFarmacii& operator +=(const GestionareFarmacii& rhs){
            FarmacieOnline *temp;
            try{
                tempList = new FarmacieOnline * [index + 1];
                memcpy(tempList, listFarm, sizeof(FarmacieOnline*) * index);
                tempList[++index] = &rhs;
                listFarm = tempList;

            }catch(bad_alloc& e){
                cerr << "bad alloc caught" << e.what() <<endl;
            }
            return *this;
        }
        string getId() const { return id; }
        friend istream& operator>>(istream& in, GestionareFarmacii& fo){
            in>>fo.index;
            try
            {
                fo.listFarm = new FarmacieOnline*[fo.index];
                for(int i=0;i<fo.index;i++)
                {
                    FarmacieOnline* temp = new FarmacieOnline;
                    temp->read(in);
                    fl.listFarm[i] = static_cast<FarmacieOnline*>(temp);
                }
            }
            catch(bad_alloc& e)
            {
                cout<<e.what();
            }
            return in;
        }
        friend ostream& operator<<(ostream& out, GestionareFarmacii& fo){}
    protected:

    private:
        unsigned int getNrTotalVizitatori() {
                total=0;
                    for(int i=0;i<index;i++) total+=listFarm[i]->getNrVizitatori();
                return total;
        };
        const string id = getRandId(4);
        unsigned int index = 0;
        FarmacieOnline **listFarm;

};
#endif // GESTIONAREFARMACII_H
