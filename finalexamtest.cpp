class one {
public:
  void print() const;
  //Outputs the values of x and y
protected:
  void setData(int u, int v);
  //Postcondition: x = u; y = v;
private:
  int x;
  int y;
};

class two: public one {
public:
  void setData(int a, int b, int c);
  //Postcondition: x = a; y = b; z = c;
void print() const;
  //Outputs the values of x, y, and z
private:
  int z;
};