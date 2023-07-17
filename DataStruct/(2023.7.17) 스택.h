#pragma once
#include <iostream>
#include <stack>

#define SIZE 5

template <typename T>
class STACK
{
private:
    int top;
    T buffer[SIZE];

public:

    STACK()
    {
        top = -1;
    }

    void Push(T data)
    {
        if (IsFull())
        {
            std::cout << "STACK에 데이터가 가득 찼습니다." << std::endl;
        }

        else
        {
            buffer[++top] = data;
        }


    }

    T Pop()
    {
        if (Empty())
        {
            std::cout << "STACK에 데이터가 비어있습니다." << std::endl;
        }

        else
        {
            return buffer[top--];
        }
    }

    T Top()
    {
        if (Empty())
        {
            std::cout << "STACK에 데이터가 비어있습니다." << std::endl;
            exit(1);
        }

        else
        {
            return buffer[top];
        }
    }

    bool Empty()
    {
        // 비어있다면 true를 반환합니다.
        if (top <= -1)
        {
            return true;
        }

        // 비어있지 않다면 false를 반환합니다.
        else
        {
            return false;
        }
    }

    bool IsFull()
    {
        // 데이터가 다 차있으면 true

        if (SIZE - 1 <= top)
        {
            return true;
        }

        // 데이터가 다 차있지 않으면 false

        else
        {
            return false;
        }
    }

    ~STACK()
    {
        std::cout << "STACK 해제" << std::endl;
    }
};


int main()
{
    STACK<int> intStack;

    intStack.Push(10);
    intStack.Push(20);
    intStack.Push(30);
    intStack.Push(40);

    while (intStack.Empty() == false)
    {
        std::cout << intStack.Top() << std::endl;
        intStack.Pop();
    }


    return 0;
}

