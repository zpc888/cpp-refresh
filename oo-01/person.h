#ifndef _MODEL_PERSON_H
#define _MODEL_PERSON_H

#include <string>

using namespace std;

class person {
	private:
		string firstName;
		string lastName;
		int  age;
	
	public:
		person(string fname, string lname, int age);
		string getFirstName();
		string getLastName();
		int getAge();
		string getInfo();
};

#endif
