#include<iostream>
#include<string>

using namespace std;

int main() {
string s;
cout << "Input a string whatever you like" << endl;


// cin >> s;
// cout << s << endl;


getline(cin, s);
cout << s << endl;

return 0;
}
