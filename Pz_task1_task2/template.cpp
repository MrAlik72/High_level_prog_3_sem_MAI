#include <iostream>
#include <cstring>
#include <exception>

using namespace std;

template <typename arrays>
class array {
	int size;
	arrays *ptr_arr;

public:
	array(int n){
		size = n;
		ptr_arr = new arrays[size];
	}
	~array(){
		delete [] ptr_arr;
	}

	array(const array& my_array){
		size = my_array.size;
		ptr_arr = new arrays[size];

		memcpy(ptr_arr, my_array.ptr_arr, size*sizeof(arrays));
	}

	void set(int i, arrays value){
		if (i > 0 && i < size && value <= 100 && value >= -100)
			ptr_arr[i] = value;
	}

	arrays get(int i){
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
