#include <iostream>
using namespace std;

int* createArray(int size);

int main( )
{
    int* a;

    a = createArray(5);

    cout << "Array a:\n";
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;

    delete[] a;
    return 0;
}

int* createArray(int size)
{
    int* temp = new int[size];

    for (int i =0; i < size; i++)
        temp[i] = 0;

    return temp;
}
