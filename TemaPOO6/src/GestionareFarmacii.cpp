#include "GestionareFarmacii.h"

/*
template <class Type>
GestionareFarmacii<Type>::GestionareFarmacii(){}
*/

template <class Type>
GestionareFarmacii<Type>::GestionareFarmacii(vector<Type*> vec){
    index = vec.size();
    if(listFarm != nullptr) {
        delete[] listFarm;
    }
    listFarm = new Type * [index];
    vector<Type*>::iterator it;
    unsigned int index;
    for(it = vec.begin(), index = 0; it != vec.end(); it++, index++) listFarm[index] = *it;
}

template <class Type>
GestionareFarmacii<Type>::~GestionareFarmacii()
{
    delete[] listFarm;
}

template <class Type>
GestionareFarmacii<Type>::GestionareFarmacii(const GestionareFarmacii<Type>& other)
{
    index = other.index;
    listFarm = other.listFarm;
}

template <class Type>
GestionareFarmacii<Type>& GestionareFarmacii<Type>::operator=(const GestionareFarmacii<Type>& rhs)
{
    if (this == &rhs) return *this;
    index = rhs.index;
    listFarm = rhs.listFarm;
    return *this;
}

template <class Type>
GestionareFarmacii<Type>& GestionareFarmacii<Type>::operator+=(Type& rhs)
{
    Type **tempList;
    try{
        tempList = new Type * [index + 1];
        memcpy(tempList, listFarm, sizeof(Type*) * index);
        tempList[++index] = &rhs;
        listFarm = tempList;

    }catch(bad_alloc& e){
        cerr << "bad alloc caught" << e.what() <<endl;
    }
    return *this;
}

string getRandId(unsigned int length){
    string temp;
    unsigned short digit;
    for(unsigned int index; index < length; index++){
        digit = rand() % 10;
        temp += to_string(digit);
    }
    return temp;
}

template <class Type>
string GestionareFarmacii<Type>::getFarmType(unsigned int index){
    string answer;
    if(listFarm == nullptr) answer = "null";
    else{
        const type_info& cur = typeid(listFarm[index]);
        answer = cur.name();
    }
    return answer;
}

template class GestionareFarmacii<Farmacie*>;
template class GestionareFarmacii<FarmacieOnline*>;
