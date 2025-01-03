#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
    private:
        Node<T>* first; // Puntero al primer nodo de la lista
        int n;          // Número de elementos en la lista

    public:
        // Constructor
        ListLinked() : first(nullptr), n(0) {}

        // Destructor
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first->next; // Guardar el siguiente nodo
                delete first;               // Liberar el nodo actual
                first = aux;                // Actualizar el puntero `first`
            }
        }

        // Sobrecarga del operador []
        T operator[](int pos) const {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }

            Node<T>* current = first;
            for (int i = 0; i < pos; ++i) {
                current = current->next; // Avanzar al siguiente nodo
            }
            return current->data; // Devolver el dato en la posición indicada
        }

        // Sobrecarga del operador <<
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            Node<T>* current = list.first;
            out << "[";
            while (current != nullptr) {
                out << current->data;
                if (current->next != nullptr) {
                    out << ", "; // Separador entre elementos
                }
                current = current->next;
            }
            out << "]";
            return out;
        }

        // Otros métodos de la interfaz List<T> se deben implementar aquí
        // (por ejemplo, agregar elementos, eliminar elementos, etc.)
};

#endif // LISTLINKED_H


