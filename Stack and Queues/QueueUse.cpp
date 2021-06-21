#include <iostream>
//#include "QueueArrayClass.h"
//#include "DynamicQueue.h"
//#include "QueueLLClass.h"
#include <queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();

    cout << q.size() << endl;
    cout << q.empty() << endl;

    /* Queue<int> q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);

    cout << q.front() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl; */
}