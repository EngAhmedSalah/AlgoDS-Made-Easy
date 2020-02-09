#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    //Stack Container --- first in last out data structure
    stack<int> st;
    st.push(3);     //st = {3}
    st.push(2);     //st = {3 , 2}
    cout<<"the top of the stack = "<<st.top()<<"\n";  //return the top element of the stack
    st.pop();       //st = {3}
    st.pop();       //st = {}
    cout<<"is empty = "<<st.empty()<<"\n";      //check if stack is empty -- the stack is empty if output = 1 and not empty if output is 0
}
