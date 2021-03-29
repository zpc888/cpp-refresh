#include <stdlib.h>
#include <stdio.h>
#include "person.h"

person::person(string fname, string lname, int age) {
	this->firstName = fname;
	this->lastName = lname;
	this->age = age;
}

string person::getFirstName() {
	return this->firstName;
}

string person::getLastName() {
	return this->lastName;
}

int person::getAge() {
	return this->age;
}

string person::getInfo() {
	return firstName + " " + lastName + " age is: " + to_string(age);
}
