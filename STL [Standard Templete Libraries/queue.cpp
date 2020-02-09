#include iostream
#include stack
#include queue
using namespace std;
int main()
{
    Queue Container --- first in first out data structure
    queueint que;
    que.push(3);                                        que = {3}
    que.push(2);                                        que = {2 , 3}
    que.push(5);                                        que = {5 , 2 , 3}
    coutqueue back is = que.back()n;         output = 5
    coutqueue front is = que.front()n;       output = 3
    que.pop();                                          que = {5 , 2}
    coutqueue size is = que.size()n ;        output = 2
    que.pop();
    que.pop();
    coutis queue empty   que.empty();            return 1 if the queue is empty and 0 if the queue is not empty
}
