#include <iostream>
#include <cstring>
using namespace std;

class array {
	int size;
	int *ptr_arr;

public:
	array(int n){
		size = n;
		ptr_arr = new int[size];
	}
	~array(){
		delete [] ptr_arr;
	}

	array(const array& my_array){
		size = my_array.size;
		ptr_arr = new int[size];

		memcpy(ptr_arr, my_array.ptr_arr, size*sizeof(int));
	}

	void set(int i, int value){
		if (i > 0 && i < size && value <= 100 && value >= -100)
			ptr_arr[i] = value;
	}

	int get(int i){
		if (i < size)
			return ptr_arr[i];
		return -1;
	}

	int min (const array& some_arr){
		return (size - some_arr.size);
	}

	void sum (const array& some_arr){
		if (min(some_arr) == 0 || min(some_arr) < 0){
			for (int i = 0; i < size; i++){
				ptr_arr[i] += some_arr.ptr_arr[i];
			}
		}
		else {
			for (int j = 0; j < some_arr.size; j++){
				ptr_arr[j] += some_arr.ptr_arr[j];
			}
		}
	}

	void sub (const array& some_arr){
		if (min(some_arr) == 0 || min(some_arr) < 0){
			for (int i = 0; i < size; i++){
				ptr_arr[i] -= some_arr.ptr_arr[i];
			}
		}
		else {
			for (int j = 0; j < some_arr.size; j++){
				ptr_arr[j] -= some_arr.ptr_arr[j];
			}
		}
	}
};

int main (){

	return 0;
}
