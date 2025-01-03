#ifndef NODE_H
#define NODE_H

#include <ostream>

// Clase genérica Node
template <typename T> 
class Node {
    public:
        // Atributos públicos
        T data;           // Elemento almacenado en el nodo
        Node<T>* next;    // Puntero al siguiente nodo en la secuencia

        // Constructor
        Node(T data, Node<T>* next = nullptr) : data(data), next(next) {} // Constructor con valor y puntero

        // Sobrecarga del operador de salida <<
        friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
            out << node.data; // Imprime el valor del atributo `data`
            return out;
        }
};

#endif // NODE_H

