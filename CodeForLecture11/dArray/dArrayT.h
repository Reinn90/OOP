// dArrayT.h
template<class T>
class dArrayT {
  private:
	T *arr;
	int size;	// The number of the actual numbers
	int capacity; // The capacity of the array
	void resize();
  public:
	dArrayT(int c);
	~dArrayT();
	bool insert(int pos, T val);
	bool remove(int pos);

	T get(int i) {return arr[i];}

	T& operator[] (int i); //operator overloading
//	T operator[] (int i) ; // operator overloading
	int length() const {return size;}
};

template<class T>
dArrayT<T>::dArrayT(int c) {
	capacity = c;
	arr =new T[capacity];
	size = 0;
}

template<class T>
dArrayT<T>::~dArrayT(){
	delete[] arr;
}

template<class T>
bool dArrayT<T>::insert(int pos, T val) { 
	if (pos < 0 || pos > size)
		return false;
	
	if(size + 1 > capacity)
		resize();

	if(pos == size) {
		arr[size++] = val;
    } else {
		int i;
		// move up
	    for(i=size-1;i>=pos;i--)
			arr[i+1] = arr[i];
		
		arr[pos] = val;
		size++;
	}
	return true;
}

template<class T>
bool dArrayT<T>::remove(int pos) {
	if(pos >=0 && pos < size ) {
		//move down
		for(int i=pos+1; i < size;i++)
			arr[i-1] = arr[i];
		size--;
        return true;
	}

	return false; 
}

template<class T>
void dArrayT<T>::resize() { 
	capacity *= 2;
	T* narr = new T[capacity];
	//copy array
	for (int i=0;i<size;++i)
		*(narr+i) = *(arr+i) ;
	delete [] arr;
	arr = narr; 
}


//enable arr[i] to be a l-level variable
template<class T>
T& dArrayT<T>::operator[] (int i) {
	if(i<0 || i>=size) {
		cout << "\n class dArrayT: out of range!";
		exit(1);
	}

	return arr[i];
}


//template<class T>
//T dArrayT<T>::operator[] (int i)  {
//	if(i<0 || i>=size) {
//		cout << "\n class dArrayT: out of range!";
//		exit(1);
//	}
//
//	return arr[i];
//}
