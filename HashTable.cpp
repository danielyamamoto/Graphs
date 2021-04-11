#include "HashTable.h"

template <class T>
HashTable<T>::HashTable(size_t s) {
    size = s;
    pairs = new shared_ptr<Pair>[size];
}

template <class T>
HashTable<T>::~HashTable() {
    delete[] pairs;
}

template <typename T>
size_t HashTable<T>::hashCode(string s) {
    boost::hash<std::string> string_hash;
    return string_hash(s);
}

template <class T>
bool HashTable<T>::add(string key, T value) {
    size_t t = hashCode(key);
    int pos = t % size;
    int pos1 = pos;
    while(pairs[pos] != nullptr) { 
        pos++;
        pos %= size;
        if(pos == pos1) {
            return false;
        }
    }
    pairs[pos]= make_shared<Pair>(Pair{key, value});    
    return true;
}

template <class T>
T HashTable<T>::get(string k) {
    size_t t = hashCode(k);
    int pos = t % size;

    if(pairs[pos] == nullptr) {
        throw "No existe la llave";
    }
    
    while(pairs[pos] != nullptr) {
        if(pairs[pos]->key == k)
            return pairs[pos]->value;
        pos++;
        pos %= size;
    }

    throw "No existe la llave"; 
}