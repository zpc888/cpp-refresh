#include <stdlib.h>
#include <iostream>
#include "person.h"

int main() {
	person * p = new person("David", "Smith", 18);
	cout << "firstName=" << p->getFirstName() << std::endl;
	cout << "lastName=" << p->getLastName() << std::endl;
	cout << "age=" << p->getAge() << std::endl;
	cout << "info=" << p->getInfo() << std::endl;
	delete p;
}
