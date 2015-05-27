#include<iostream>
#include<stack>

using namespace std;

template<class T>
class MyQueue
{
 public:
    void push(T &t)
    {
        in.push(t);
    }

    T front()
    {
        if( out.empty())
        {
            if( in.size() == 0 )
            {
                throw;
            }
            while( !in.empty() )
            {
                out.push(in.top());
                in.pop();
            }

        }
        return out.top();
    }

    void pop()
    {
        if( out.empty() )
        {
            while( !in.empty() )
            {
                out.push(in.top());
                in.pop();
            }
        }

        if( !out.empty() )
        {
            out.pop();
        }
    }

 private:
    stack<T> in;
    stack<T> out;
};

int main()
{
    MyQueue<int> mq;
    int i = 0;

    for( i = 0;i < 10;i++)
    {
        mq.push(i);
    }

    for( i = 0;i<10;i++)
    {
        cout << mq.front() << endl;
        mq.pop();
    }

    return 0;
}
