#include<iostream>

using namespace std;

template <class myType>
void printArray(myType *a, int count)
{
 for(int i=0;i<count;i++)
	cout << a[i] << "  ";

 cout << endl;
}

int main(){

//int array[5] = {3,1,5,6,2};
//char array[5] = {'h','e','l','l','o'};
double array[5] = {1.3,4.2,5.1,5.3,3.0};

printArray(array, 5);

return 0;

}


