#include <iostream>
#include <queue>
#include <string>
#include <stack>

using namespace std;

void printQ(string title, queue<int> q) {
    cout << title;
    while (!q.empty()) {
        cout << "\t";
        cout << q.front();
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    for (int i=1; i<=20; i++) {
        q.push(i);
    }
    printQ("Original Queue: ", q);
    queue<int> scrambled;
    int fetchSize = 1;
    while (!q.empty()) {
        if (fetchSize % 2 == 0) {
            // need to reverse
            stack<int> reversed;
            for (int j=0; j<fetchSize && !q.empty(); j++) {
                reversed.push(q.front());
                q.pop();    
            }
            while (!reversed.empty()) {
                scrambled.push(reversed.top());
                reversed.pop();
            }
        } else {
            // no need to reverse
            for (int j=0; j<fetchSize && !q.empty(); j++) {
                scrambled.push(q.front());
                q.pop();    
            }
        }
        fetchSize ++;
    }
    while (!scrambled.empty()) {
        q.push(scrambled.front());
        scrambled.pop();
    }
    printQ("ScrambledQueue: ", q);
   return 0;
}