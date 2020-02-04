/*
this approach will use the (array doubling technique) so , if the stack is full , we will reallocate the size by the double size
it is simply create a new array with the capacity = old capacity * 2 then copy the values from old array to the new array
*/
#include <bits/stdc++.h>
using namespace std;
#define MaxSize 2
class ArrayStack
{
private:

    int topV , capacity , *arr;
public:

    ArrayStack()
    {
        this->topV = -1;
        this ->capacity = MaxSize;
        this -> arr = (int*) malloc(this -> capacity * sizeof(int));
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
    bool isfull()
    {
        return this -> topV == this -> capacity - 1;
    }
    void push(int x)
    {
        if(isfull())
            DoublingStack();
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
    void DoublingStack()
    {
        this -> capacity *= 2;
        this -> arr = (int*) realloc(this -> arr , this -> capacity * sizeof (int));
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
    o.push(5);
    o.push(6);  //won't get Stack Overflow
    cout<<o.top();  //will get 6
    o.pop();
    cout<<o.top();  //will get 5
    o.pop();
    cout<<o.top();  //will get Minimum negative value because the stack is empty
    cout<<o.isempty();  //will get true because the stack is empty
}
