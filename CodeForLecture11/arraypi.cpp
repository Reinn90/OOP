#include<iostream>

using namespace std;

void printArray(int *a, int count)
{
 for(int i=0;i<count;i++)
	cout << a[i] << "  ";
 cout << endl;
}

void printArray(char *a, int count)
{
 for(int i=0;i<count;i++)
	cout << a[i] << "  ";
 cout << endl;
}

int main(){
int array1[5] = {3,1,5,6,2};
char array2[5] = {'3','1','5','6','W'};
printArray(array1, 5);
printArray(array2, 5);
return 0;
}
