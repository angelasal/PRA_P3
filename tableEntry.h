#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>
#include <utility>   // std::move

// Clase genérica para representar pares clave -> valor.
// La comparación (== y !=) se hace SOLO por la clave.
template <typename V>
class tableEntry {
public:
    // --- Atributos públicos ---
    std::string key; // elemento clave del par
    V value;         // elemento valor del par

    // --- Constructores ---
    // Constructor con clave y valor
    tableEntry(std::string k, V v)
        : key(std::move(k)), value(std::move(v)) {}

    // Constructor solo con clave (valor por defecto de V)
    explicit tableEntry(std::string k)
        : key(std::move(k)), value() {}

    // Constructor por defecto: clave "" y valor por defecto de V
    tableEntry()
        : key(""), value() {}

    // --- Operadores sobrecargados como friends (globales) ---
    // Comparación por clave: iguales si las claves son iguales
    friend bool operator==(const tableEntry& te1, const tableEntry& te2) {
        return te1.key == te2.key;
    }

    // Comparación por clave: distintos si las claves son distintas
    friend bool operator!=(const tableEntry& te1, const tableEntry& te2) {
        return te1.key != te2.key;
    }

    // Impresión: ('Clave' => Valor)
    friend std::ostream& operator<<(std::ostream& out, const tableEntry& te) {
        out << "('" << te.key << "' => " << te.value << ")";
        return out;
    }
};

#endif // TABLEENTRY_H
