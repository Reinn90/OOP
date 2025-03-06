class Geometry {
private:
	double length;
	double width;
	double depth;
public:
	double area(double);
	double area(double,double);
	double volume(double,double,double);
};

double Geometry::area(double length) {
	return length*length;
}

double Geometry::area(double length, double width) {
	return length*width;
}

double Geometry::volume(double length, double width, double depth) {
	return length*width*depth;
}


