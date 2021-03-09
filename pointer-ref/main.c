#include <iostream>

using namespace std;

int main() {
  // std::cout << "hello world" << std::endl;
  cout << "========= start ===========" << endl;
  cout << "Testing pointer & reference" << endl;
  int *p;
  // int &r;		
  		// compile error: 'r' declared as reference but not initialized
  int i;			// default constructor for object, or default value for primitive types
  int &r = i;

  cout << endl;
  cout << "-- Not initialization" << endl;
  cout << "p = " << p << endl;   
  		// compile warning: 'p' may be used uninitialized in this function [-Wmaybe-uninitialized]
  cout << "*p = " << *p << endl;   
  cout << "r = " << r << endl;
  cout << "&r = " << &r << endl;
  cout << "i = " << i << endl;
  cout << "&i = " << &i << endl;

  cout << endl;
  i = 8;
  p = &i;
  cout << "-- i = 8 and p = &i" << endl;
  cout << "p = " << p << endl;   
  cout << "*p = " << *p << endl;   
  cout << "r = " << r << endl;
  cout << "&r = " << &r << endl;
  cout << "i = " << i << endl;
  cout << "&i = " << &i << endl;

  cout << endl;
  i = 18;
  cout << "-- i = 18" << endl;
  cout << "p = " << p << endl;   
  cout << "*p = " << *p << endl;   
  cout << "r = " << r << endl;
  cout << "&r = " << &r << endl;
  cout << "i = " << i << endl;
  cout << "&i = " << &i << endl;

  cout << endl;
  *p = 25;
  cout << "-- *p = 25" << endl;
  cout << "p = " << p << endl;   
  cout << "*p = " << *p << endl;   
  cout << "r = " << r << endl;
  cout << "&r = " << &r << endl;
  cout << "i = " << i << endl;
  cout << "&i = " << &i << endl;

  cout << endl;
  r = 36;
  cout << "-- r = 36" << endl;
  cout << "p = " << p << endl;   
  cout << "*p = " << *p << endl;   
  cout << "r = " << r << endl;
  cout << "&r = " << &r << endl;
  cout << "i = " << i << endl;
  cout << "&i = " << &i << endl;

  cout << endl;
  int j = *p;
  j = 12;
  cout << "-- j = *p; j = 12;" << endl;
  cout << "j = " << j << endl;   
  cout << "&j = " << &j << endl;   
  cout << "p = " << p << endl;   
  cout << "*p = " << *p << endl;   
  cout << "r = " << r << endl;
  cout << "&r = " << &r << endl;
  cout << "i = " << i << endl;
  cout << "&i = " << &i << endl;

  cout << endl;
  cout << "=========  end  ===========" << endl;
  cout << endl;
  return 1;
}
