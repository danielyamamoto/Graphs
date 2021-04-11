#pragma once

#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <boost/functional/hash.hpp> // brew install boost

// https://stackoverflow.com/questions/9127207/hash-table-why-deletion-is-difficult-in-open-addressing-scheme

using namespace std;

template <class T>
class HashTable {
public:
    HashTable(size_t);
    ~HashTable();
    bool add(string, T);
    T get(string);

private:
    struct Pair {
        string key;
        T value;
    };

    size_t size;
    shared_ptr<Pair> *pairs;
    size_t hashCode(string);
};

#endif // HASH_TABLE