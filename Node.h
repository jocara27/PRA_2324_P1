#include <ostream>

template <typename T> 
class Node {
	public:
		T data;
		Node<T>* next;
	public:

		//Constructor del Nodo
		Node(T data, Node<T>* next = nullptr) : data(data), next(next){};
		
		//Sobrecàrrega operador
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
		out<<node.data;
		return out;
		}
};
