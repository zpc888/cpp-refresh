#include <iostream>

using namespace std;

/* 
   nested comment is // not valid /* nested 
 */
// /* here is ok /* nested */ */ before // means all after is a comment

int main() {
  cout << "Please enter 2 numbers: " << endl;
  int v1 = 0;
  int v2 = 0;

  // cin is not ok for docker container run since by then 
  // the console is host one, not container's
  cin >> v1 >> v2;

  cout << "sum of " << v1 << " and " << v2 
       << " is " << v1 + v2 << endl;

  cout << "------------------" << left << endl;
  cout << "/*";
  cout << endl;
  cout << "*/";
  cout << endl;
//  cout << /* "*/" */;
  cout << endl;
  cout << /* "*/" /*  "/*"    */;
  cout << endl;
  return 0;
}
