
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "/Users/angelasal/Library/CloudStorage/OneDrive-UPV/PRA/PRA_P1/ListLinked.h" // Ajusta la ruta según tu proyecto

template <typename V>
class HashTable : public Dict<V> {
private:
    int n;   // número de elementos
    int max; // tamaño de la tabla
    ListLinked<TableEntry<V>>* table; // array dinámico de listas

    // Función hash: suma ASCII % max
    int h(std::string key) {
        int sum = 0;
        for (char c : key) sum += int(c);
        return sum % max;
    }

public:
    // Constructor
    HashTable(int size) : n(0), max(size) {
        table = new ListLinked<TableEntry<V>>[max];
    }

    // Destructor
    ~HashTable() {
        delete[] table;
    }

    // Devuelve capacidad total
    int capacity() {
        return max;
    }

    // Inserta clave-valor
    void insert(std::string key, V value) override {
        int idx = h(key);
        TableEntry<V> entry(key, value);
        if (table[idx].search(entry) != -1) {
            throw std::runtime_error("Clave ya existe: " + key);
        }
        table[idx].append(entry);
        n++;
    }

    // Busca valor por clave
    V search(std::string key) override {
        int idx = h(key);
        TableEntry<V> entry(key);
        int pos = table[idx].search(entry);
        if (pos == -1) throw std::runtime_error("Clave no encontrada: " + key);
        return table[idx].get(pos).value;
    }

    // Elimina clave y devuelve valor
    V remove(std::string key) override {
        int idx = h(key);
        TableEntry<V> entry(key);
        int pos = table[idx].search(entry);
        if (pos == -1) throw std::runtime_error("Clave no encontrada: " + key);
        V val = table[idx].get(pos).value;
        table[idx].remove(pos);
        n--;
        return val;
    }

    // Número de elementos
    int entries() override {
        return n;
    }

    // Sobrecarga []
    V operator {
        return search(key);
    }

    // Imprimir tabla hash
    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& ht) {
        for (int i = 0; i < ht.max; i++) {
            out << "[" << i << "]: ";
            for (int j = 0; j < ht.table[i].size(); j++) {
                out << ht.table[i].get(j) << " ";
            }
            out << "\n";
        }
        return out;
    }
};

#endif
