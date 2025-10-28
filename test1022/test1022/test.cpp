#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

#include"stack.h"

#include"queue.h"

//int main()
//{
//	//stack<int> s;
//	//s.push(1);
//	//s.push(2);
//	//s.push(3);
//	//s.push(4);
//
//	//s.pop();
//	//s.pop();
//
//	//while (!s.empty())
//	//{
//	//	cout << s.top() << endl;
//	//	s.pop();
//	//}
//	//cout << endl;
//
//	queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	q.pop();
//	q.pop();
//
//	while (!q.empty())
//	{
//		cout << q.front() << endl;
//		q.pop();//对头出，队尾插
//	}
//	cout << endl;
//
//	return 0;
//}

//namespace wh
//{
//	class MinStack {
//	public:
//		MinStack() {
//
//		}
//
//		void push(int val) {
//			_st.push(val);
//			if(_minst.empty() || val <= _minst.top())
//			{
//				_minst.push(val);
//			}
//		}
//
//		void pop() {
//			if (_st.top() == _minst.top())
//				_minst.pop();
//
//			_st.pop();
//		}
//
//		int top() {
//			return _st.top();
//		}
//
//		int getMin() {
//			return _minst.top();
//		}
//	private:
//		stack<int> _st;
//		stack<int> _minst;
//	};
//
//	/**
//	 * Your MinStack object will be instantiated and called as such:
//	 * MinStack* obj = new MinStack();
//	 * obj->push(val);
//	 * obj->pop();
//	 * int param_3 = obj->top();
//	 * int param_4 = obj->getMin();
//	 */
//}
//
//int main()
//{
//	wh::MinStack minst;
//	minst.push(1);
//	minst.push(2);
//	minst.push(3);
//	minst.push(2);
//	minst.push(5);
//
//	return 0;
//}


int main()
{
	wh::stack<int, vector<int>> st1;
	wh::stack<int, list<int>> st2;
	st2.push(1);
	st2.push(2);

	cout << st2.top() << " ";
	st2.pop();

	st2.push(3);
	st2.push(4);

	while (!st2.empty())
	{
		cout << st2.top() << " ";
		st2.pop();
	}
	return 0;
}