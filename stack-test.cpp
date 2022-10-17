#include "stack.h"
#include <iostream>

using namespace std;

void print(Stack<int> test) {
    for(std::vector<int>::iterator it = test.begin(); it != test.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Stack<int> test;
    cout << "empty " << test.empty() << endl;
    test.push(1);
    cout << "is empty " << test.empty() << endl;
    cout << "size " << test.size() << endl;
    test.push(2);
    test.push(3);
    print(test);
    test.pop();
    print(test);
    test.pop();
    test.pop();
    test.push(15);
    cout << test.top() << endl;
    test.push(10);
    cout << test.top() << endl;
    test.pop();
    cout << test.top() << endl;
    // cout << "is now empty" << endl;
    // test.pop();
    return 0;
}
