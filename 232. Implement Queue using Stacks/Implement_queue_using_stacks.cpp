#include <iostream>
#include <stack>

using namespace std;

class EmptyException
{
};

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        auto out = peek();
        output.pop();
    }

    /** Get the front element. */
    int peek()
    {
        if (!output.empty())
        {
            return output.top();
        }

        else if (!input.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
        else
        {
            throw EmptyException();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        if (input.empty() && output.empty())
            return true;
        return false;
    }

private:
    stack<int> input;
    stack<int> output;
};

int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    return 0;
}