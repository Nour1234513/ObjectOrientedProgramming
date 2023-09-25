#include <string>
#include <iostream>
#include <cassert>
#include <lstack.h>
using namespace std;

void testaStringStack(){
    LStack<string> stack;
    stack.pushBack("one");
    stack.pushBack("two");
    stack.pushBack("three");
    cout << stack.top() << endl;
    assert( stack.top() == "three" );
    stack.pop();
    cout << stack.top() << endl;
    assert( stack.top() == "two" );
    stack.pop();
    cout << stack.top() << endl;
    assert( stack.top() == "one" );
    assert( stack.size() == 1 );
}
void ingangTillStacktest(){
    cout << "testaStack" << endl;
    testaStringStack();
    cout << "test lyckades" << endl;
}
