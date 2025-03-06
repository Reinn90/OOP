#include <iostream>
#include<string>
using namespace std;

class Instrument {
public:
	void play() const {
		cout << what() << " is playing" << endl;
	}
	virtual string what() const = 0;
	// string what() const {return "Nothing";}

	virtual ~Instrument() {
	}
};

class Wind: public Instrument {
public:
	string what() const {
		return "Wind";
	}
};

class Percussion: public Instrument {
public:
	string what() const {
		return "Percussion";
	}
};

class Stringed: public Instrument {
public:
	string what() const {
		return "Stringed";
	}
};

class Brass: public Wind {
public:
	string what() const {
		return "Brass";
	}
};

class Woodwind: public Wind {
public:
	string what() const {
		return "Woodwind";
	}
};

void tune(Wind& i) {
	i.play();
}

int main() {
	Wind flute;
	Percussion drum;
	Stringed violin;
	Brass flugelhorn;
	Woodwind recorder;

	tune(flute);
	// tune(drum); // only derived classes from Wind allowed in the class
	// tune(violin);
	tune(flugelhorn);
	tune(recorder);


	drum.play();
	violin.play();
	return 0;
}
