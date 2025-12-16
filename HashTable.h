#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "ListLinked.h"

template <typename V>
class HashTable : public dict<V> {
    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;

        int h(std::string key) {
            int sum = 0;
            for (int i = 0; i < (int)key.size(); i++) {
                sum += int(key.at(i));
            }
            return sum % max;
        }

    public:
        // Constructor y destructor
        HashTable(int size) {
            max = size;
            n = 0;
            table = new ListLinked<TableEntry<V>>[max];
        }

        ~HashTable() {
            delete[] table;
        }


        int capacity() {
            return max;
        }

        friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]\n";
            out << "==============\n\n";

            for (int i = 0; i < th.max; i++) {
                out << "== Cubeta " << i << " ==\n\n";
                out << th.table[i] << "\n";
            }

            out << "==============\n";
            return out;
        }

        V operator[](std::string key) {
            return search(key);
        }


        void insert(std::string key, V value) override {
            int pos = h(key);
            // recorrer lista para ver si ya existe
            for (int i = 0; i < table[pos].size(); i++) {
                if (table[pos].get(i).key == key) {
                    throw std::runtime_error("Key '" + key + "' already exists!");
                }
            }
            table[pos].append(TableEntry<V>(key, value));
            n++;
        }

        V search(std::string key) override {
            int pos = h(key);
            for (int i = 0; i < table[pos].size(); i++) {
                if (table[pos].get(i).key == key) {
                    return table[pos].get(i).value;
                }
            }
            throw std::runtime_error("Key '" + key + "' not found!");
        }

        V remove(std::string key) override {
            int pos = h(key);
            for (int i = 0; i < table[pos].size(); i++) {
                if (table[pos].get(i).key == key) {
                    V v = table[pos].get(i).value;
                    table[pos].remove(i);
                    n--;
                    return v;
                }
            }
            throw std::runtime_error("Key '" + key + "' not found!");
        }

        int entries() override {
            return n;
        }
};

#endif
