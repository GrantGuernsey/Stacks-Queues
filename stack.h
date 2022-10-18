#ifndef STACK
#define STACK

template<typename T>
class Stack {
public:
	//Constructor
	Stack(int size) {
		data = new T*[size];
		max = size;
		start = size;
	}

	//Error handling
	bool isFull(){
		return start <= 0;
	}
	bool isEmpty(){
		return start >= max;
	}

	//Stack methods
	void push(T* value) {
		if (isFull()) throw Overflow();

		start -= 1;
		data[start] = value;

	}
	T* pop() {
		if (isEmpty()) throw Underflow();

		T* retValue = data[start];
		start += 1;
		return retValue;
	}
	T* top() {
		return data[start];
	}
	int length(){
		return max - start;
	}
	void empty(){
		for (int n = 0; n < max; n++){
			delete data[n];
		}
	}

private:
	T** data;
	int start, max;
	
	class Overflow{};
	class Underflow{};
};

#endif