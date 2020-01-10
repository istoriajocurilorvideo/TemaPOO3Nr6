#include "Farmacie.h"
#include "FarmacieOnline.h"
#include "GestionareFarmacii.h"

int main()
{
    srand(time(NULL));
    GestionareFarmacii<Farmacie> *gestiune = new GestionareFarmacii<Farmacie>();
    cout<<gestiune->getId();
    return 0;
}
