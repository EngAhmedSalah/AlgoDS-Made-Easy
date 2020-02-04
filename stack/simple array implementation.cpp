#include <bits/stdc++.h>
using namespace std;
#define MaxSize 10
class ArrayStack
{
private:

    int topV , capacity , *arr;
public:

    ArrayStack()
    {
        this -> topV = -1;
        this -> capacity = MaxSize;
        this -> arr = (int*) malloc (this -> capacity * sizeof(int));   //will allocate memory blocks for the array
    }
    int top()
    {
        if(this->isempty())
            return INT_MIN;
        return  arr[topV];
    }
    bool isempty()
    {
        return this->topV == -1;
    }
    void push(int x)
    {
        if(this -> topV == this -> capacity - 1)
            puts("Stack Overflow");
        else
            arr[++topV] = x;
    }
    void pop()
    {
        if(this->isempty())
            puts("Stack is empty");
        else
            arr[topV--];
    }
    void DeleteStack()
    {
        free(arr);
    }
};
int main()
{
    ArrayStack o;
    o.push(2);
    o.push(3);
    cout<<o.top();  //will get 3
    o.pop();
    cout<<o.top();  //will get 2
    o.pop();
    cout<<o.top();  //will get Minimum negative value because the stack is empty
    cout<<o.isempty();  //will get true because the stack is empty
}
