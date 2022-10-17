//: C15:ObjectSlicing.cpp
#include <iostream>
#include <string>

using namespace std;

class Pet
{
  string pname;

public:
  Pet(const string &name) : pname(name) {}
  virtual ~Pet() {}
  string name() const { return pname; }

  virtual string description() const
  {
    return "This is " + pname;
  }
};

class Dog : public Pet
{
  string favoriteActivity;

public:
  Dog(const string &name, const string &activity) : Pet(name), favoriteActivity(activity) {}

  string description() const
  {
    return Pet::name() + " likes to " + favoriteActivity;
  }
};

// void describe(Pet p)
// { // Slices the object
//   cout << p.description() << endl;
// }

// void describe(Pet &p)
// { // Not Slices the object
//   cout << p.description() << endl;
// }

void describe(Pet *ptr)
{
  cout << ptr->description() << endl;
}

int main()
{
  Pet p("Alfred");
  Dog d("Fluffy", "sleep");
  // static binding
  //  cout << p.description() << endl;
  //  cout << d.description() << endl;
  //  cout << endl;

  // dynamic binding
  //  test 1: call by value
  // describe(p);

  // test 2: call by reference
  // describe(d);

  // test 3: call by pointer
  describe(&p);

  return 0;
}
