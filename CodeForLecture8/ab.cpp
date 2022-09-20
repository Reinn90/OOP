class A {
	private: 
		int val;
	public: 
		A(int x) { val=x ;}
};

class B: public A {
	public: 
		B(int x): A(x) { }
//		B(int x) { }	// error
		B() : A(5) { }
//		B() {}		// error
};

//class C: public A {	// error no ctor for C
////public:
////	C():A(1){}
//};

int main() {
	B b(2);
//	 C c;
  return 0;
}
