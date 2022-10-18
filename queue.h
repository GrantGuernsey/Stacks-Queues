#ifndef QUEUE
#define QUEUE

template <typename T>
class Queue {
public:
	//Constructor
	Queue(int size){
		max = size;
		data = new T[size];
	}

	//Error handling
	bool isEmpty() {
		return len <= 0;
	}
	bool isFull() {
		return len >= max;
	}

	//Queue methods
	void enqueue(T in) {
		if (isFull()) throw Error();

		data[last] = in;
		last = (last + 1) % max;
		len += 1;
	}
	T dequeue() {
		if (isEmpty()) throw Error();

		T retVal = data[first];
		first = (first + 1) % max;
		len -= 1;
		return retVal;
	}
	T top() {
		if (isEmpty()) throw Error();
		return data[first];
	}
	int length(){
		return len;
	}
	void empty(){
		for (int n = 0; n < max; n++){
			delete data[n];
		}
	}
	

private:
	T* data;
	int first = 0, last = 0, len = 0, max;
	class Error{};
};

#endif