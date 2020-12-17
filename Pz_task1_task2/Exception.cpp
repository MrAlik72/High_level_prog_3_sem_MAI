#include <iostream>
#include <cstring>
#include <exception>

using namespace std;

template <typename arrays>
class arr {
	int size;
	arrays* ptr_arr;

public:
	arr(int n) {
		size = n;
		ptr_arr = new arrays[size];
		if (ptr_arr == nullptr)
			throw bad_alloc();
			for (int i = 0; i < size; i++)
				ptr_arr[i] = (arrays)(rand() % 100);
	}
	~arr() {
		delete[] ptr_arr;
	}

	arr(const arr& my_array) {
		size = my_array.size;
		ptr_arr = new arrays[size];
		if (ptr_arr == nullptr)
			throw bad_alloc();
		memcpy(ptr_arr, my_array.ptr_arr, size * sizeof(arrays));
	}

	void set(int i, arrays value) {
		if (value < -100 || value > 100)
			throw invalid_argument("Число должно быть между -100 и 100");
		if (i > size || i < 0)
			throw out_of_range("Out of array length");
		ptr_arr[i] = value;
	}

	arrays get(int i) {
		if (i > size || i < 0)
			throw out_of_range("");
		return ptr_arr[i];
		
	}

	int min(const arr& some_arr) {
		return (size - some_arr.size);
	}

	void sum(const arr& some_arr) {
		if (min(some_arr) == 0 || min(some_arr) < 0) {
			for (int i = 0; i < size; i++) {
				ptr_arr[i] += some_arr.ptr_arr[i];
			}
		}
		else {
			for (int j = 0; j < some_arr.size; j++) {
				ptr_arr[j] += some_arr.ptr_arr[j];
			}
		}
	}

	void sub(const arr& some_arr) {
		if (min(some_arr) == 0 || min(some_arr) < 0) {
			for (int i = 0; i < size; i++) {
				ptr_arr[i] -= some_arr.ptr_arr[i];
			}
		}
		else {
			for (int j = 0; j < some_arr.size; j++) {
				ptr_arr[j] -= some_arr.ptr_arr[j];
			}
		}
	}

	void operator = (const arr& some_array) {
		size = some_array.size;
		ptr_arr = new int[size];
		if (ptr_arr == nullptr)
			throw bad_alloc();
		memcpy(ptr_arr, some_array.ptr_arr, size * sizeof(int));
	}

	double distance(const arr& some_array) {
		if (min(some_array) == 0) {
			double distance = 0;
			for (int i = 0; i < size; i++) {
				distance += (some_array.ptr_arr[i] - ptr_arr[i]) * (some_array.ptr_arr[i] - ptr_arr[i]);
			}

			return sqrt(distance);
		}
		return -1;
	}
	template <typename arrays> friend ostream& operator << (ostream& out, const arr<arrays>& my_array);
};

template<typename arrays>
ostream& operator << (ostream& out, const arr<arrays>& my_array) {
	for (int i = 0; i < my_array.size; i++) {
		out << my_array.ptr_arr[i] << ' ';
	}
	return out;
}

int main() {
	arr<int> my_array(10);
	cout << my_array << endl;
	return 0;
}