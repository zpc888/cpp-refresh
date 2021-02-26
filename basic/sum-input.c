#include <iostream>

using namespace std;

int main() {
    int sum = 0, num_of_int = -1;
    cout << "How many integers: ";
    cin >> num_of_int;
    cout << endl;
    int* values;
    values = (int*) malloc(num_of_int * sizeof(int));
    for (int i=0; i<num_of_int; i++) {
        cout << "\tEnter number #" << (i+1) << " : ";
        cin >> *(values + i);
        cout << endl;
    }
    for (int i=0; i<num_of_int; i++) {
        sum += *(values + i);
    }
    cout << "Sum: " << sum << endl;
    return 0;
}