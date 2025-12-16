
#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>
#include <utility>

template <typename V>
class TableEntry {
public:
    std::string key;
    V value;

    TableEntry(std::string key, V value){
        this->key = std::move(key);
        this->value = value;
    }
    // Constructor solo con clave (V)
    explicit TableEntry(std::string key){
        this->key = std::move(key);
        value = V();
    }
    // Constructor clave "" y valor por defecto V
    TableEntry() {
        key = "";
        value = V();
    }


    // si las claves son iguales
    friend bool operator==(const TableEntry& te1, const TableEntry& te2) {
        return te1.key == te2.key;
    }

    // si las claves son distintas
    friend bool operator!=(const TableEntry& te1, const TableEntry& te2) {
        return te1.key != te2.key;
    }

    friend bool operator<(const TableEntry& te1, const TableEntry& te2) {
        return te1.key < te2.key;
    }

    friend bool operator>(const TableEntry& te1, const TableEntry& te2) {
        return te1.key > te2.key;
    }

    // impresión
    friend std::ostream& operator<<(std::ostream& out, const TableEntry& te) {
        out << "('" << te.key << "' => " << te.value << ")";
        return out;
    }
};

#endif 
