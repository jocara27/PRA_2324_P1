#include <iostream>
#include "List.h"
#include "Node.h"
#include <stdexcept>



// Clase ListLinked
template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first; // Puntero al primer nodo de la lista
    int n;


public:
    // Constructor
    ListLinked(){
       first = nullptr;
       n = 0;
    }

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next; // Guardar el nodo siguiente
            delete first;      // Liberar el nodo actual
            first = aux;       // Avanzar al siguiente nodo
        }
    }

    // Sobrecarga del operador []
    T operator[](int pos) const {
        if (pos < 0) {
            throw std::out_of_range("Índice fuera de rango: negativo.");
        }
        Node<T>* current = first;
        int i = 0;
        while (current != nullptr && i < pos) {
            current = current->next;
            ++i;
        }
        if (current == nullptr) {
            throw std::out_of_range("Índice fuera de rango.");
        }
        return current->data;
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        out << "Lista --> [";
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr) {
                out << "/ ";
            }
            current = current->next;
        }
        out << "]";
        return out;
    }
///METODOS HEREDADOS DE LA CLASE LIST
    // Inserta el elemento e en la posición pos
    void insert(int pos, T e) override{
        if (pos < 0 || (pos > 0 && first == nullptr)) {
            throw std::out_of_range("Índice fuera de rango.");
        }

        if (pos == 0) {
            prepend(e);
            return;
        }

        Node<T>* current = first;
        for (int i = 0; i < pos - 1; ++i) {
            if (current == nullptr || current->next == nullptr) {
                throw std::out_of_range("Índice fuera de rango.");
            }
            current = current->next;
        }

        current->next = new Node<T>(e, current->next);
    }

    // Inserta el elemento e al final de la lista
    void append(T e) override{
        if (first == nullptr) {
            first = new Node<T>(e);
        } else {
            Node<T>* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node<T>(e);
        }
    }

    // Inserta el elemento e al principio de la lista
    void prepend(T e) override{
        // Añade un elemento al principio de la lista y actualiza el puntero first
        first = new Node<T>(e, first);
    }

    // Elimina y devuelve el elemento en la posición pos
    T remove(int pos) override{
        if (pos < 0 || first == nullptr) {
            throw std::out_of_range("Índice fuera de rango.");
        }

        if (pos == 0) {
            Node<T>* toDelete = first;
            T data = toDelete->data;
            first = first->next;
            delete toDelete;
            return data;
        }

        Node<T>* current = first;
        for (int i = 0; i < pos - 1; ++i) {
            if (current == nullptr || current->next == nullptr) {
                throw std::out_of_range("Índice fuera de rango.");
            }
            current = current->next;
        }

        Node<T>* toDelete = current->next;
        if (toDelete == nullptr) {
            throw std::out_of_range("Índice fuera de rango.");
        }
        T data = toDelete->data;
        current->next = toDelete->next;
        delete toDelete;
        return data;
    }

    // Devuelve el elemento en la posición pos
    T get(int pos) override{
        return (*this)[pos];
    }

    // Devuelve la posición del elemento e o -1 si no se encuentra
    int search(T e) override{
        Node<T>* current = first;
        int i = 0;
        while (current != nullptr) {
            if (current->data == e) {
                return i;
            }
            current = current->next;
            ++i;
        }
        return -1;
    }

    // Indica si la lista está vacía
    bool empty() override{
        return first == nullptr;
    }

    // Devuelve el número de elementos de la lista
    int size() override{
        int count = 0;
        Node<T>* current = first;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }
};
