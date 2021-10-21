#include <iostream>
#include <algorithm>
using namespace std;

/*
3.4 Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.

push - always enter elemets to first stack (s1)
pop / top - if the second stack(s2) is empty, move all elements from s1 to s2
	pop/top from s2.

*/

struct Queue {
protected:
	stack<int> s1;
	stack<int> s2;

public:
	void dequeue() {

		if (s2.size() > 0) {
			s2.pop();
		}
		else if (s1.size() > 0) {
			while (s1.size() > 0)
			{
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
		}
		else{
			cout << "Error - Empty Queue" << endl;
		}
	}

	void peek()
	{
		if (s2.size() > 0) {
			cout<< s2.top();
		}
		else if (s1.size() > 0) {
			while (s1.size() > 0)
			{
				s2.push(s1.top());
				s1.pop();
			}
			cout<< s2.top();
		}
		else {
			cout << "Error - Empty Queue" << endl;
		}
	}

	void enqueue(int data)
	{
		s1.push(data);
	}

};
