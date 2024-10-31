#include <ostream>

#include "List.h"

template <typename T>
class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE;
		void resize (int new_size){
			T* newarr = new T[new_size];
			for (int i = 0; i < n; i++){
				newarr[i] = arr[i];
			}
			delete[] arr;
			arr = newarr;
			max = new_size;
		}


	public:
		ListArray(){
			n = 0;
			arr = new int [max];
		}
		
		~ListArray(){
			delete[]arr;
		}

		T operator[](int pos){
			if (pos < 0 || pos > n - 1){
				throw std::out_of_range ("L'operador està en una posició no vàlida");
			}
			return arr[pos];

		}

		friend std::ostream&operator<<(std::ostream &out, const ListArray<T> &list){
			out << "{";
			return out;
		}

		void insert (int pos, T e) override{
			if (n== max){
				throw std::out_of_range ("L'array està ple");
			}

			if (pos > n || pos <0){
				throw std::out_of_range ("No es pot insertar l'element en la posició dessitjada");
			}

			for (int i = n; i > pos; i--){
				arr[i] = arr[i-1];
			}

			arr[pos] = e;
		        n++;
		}

		void append (T e){
			insert (n,e);
		}

		void preppend(T e){
			if (n== max){
				resize(max *2);
			}

			for (int i = n; i>0; i--){
				arr[i] = arr[i-1];
		        }

			arr[0] = e;
			n++;
		}
		int size()override{
			return n;
	        }


};
