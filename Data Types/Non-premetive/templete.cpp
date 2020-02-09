/*
	Templates are powerful features of C++ which allows you to write generic programs.
    In simple terms, you can create a single function or a class to work with different data types using templates.
    Templates are often used in larger codebase for the purpose of code reusability and flexibility of the programs.
*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long lld;
const int OO = 1e9;
lld SLL(){lld x; scanf("%lld" , &x); return x;}
int SD(){int x; scanf("%d" , &x); return x;}
template <class Type>           //Example of template function
Type larger(Type x , Type y)
{
     return (x >= y) ? x : y;
}

template <class elemtype>       //Example of template class
class LinkedList
{
public:
    bool isEmpty();
    bool isFull();
    void search(const elemType& searchItem, bool& found);
    void insert(const elemType& newElement);
    void remove(const elemType& removeElement);
    void destroyList();
    void printList();
    LinkedList();
private:
    elemType list[100]; //array to hold the list elements
    int length; //variable to store the number
};
int main()
{
    cout << "Larger integer of 5 and 6 = "<< larger(5, 6) << endl; //compare integers
    cout << "Larger character of A and B = "<< larger('A','B') << endl; //compare characters
    cout << "Line 10: Larger of 5.6 and 3.2 = "<< larger(5.6, 3.2) << endl; //compare doubles
    string str1 = "Hello" ;
    string str2 = "Happy";
    cout << "Larger string of " << str1 << " and "<< str2 << " = " << larger(str1, str2) << endl;//compare strings
}
