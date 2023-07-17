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
            std::cout << "STACK�� �����Ͱ� ���� á���ϴ�." << std::endl;
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
            std::cout << "STACK�� �����Ͱ� ����ֽ��ϴ�." << std::endl;
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
            std::cout << "STACK�� �����Ͱ� ����ֽ��ϴ�." << std::endl;
            exit(1);
        }

        else
        {
            return buffer[top];
        }
    }

    bool Empty()
    {
        // ����ִٸ� true�� ��ȯ�մϴ�.
        if (top <= -1)
        {
            return true;
        }

        // ������� �ʴٸ� false�� ��ȯ�մϴ�.
        else
        {
            return false;
        }
    }

    bool IsFull()
    {
        // �����Ͱ� �� �������� true

        if (SIZE - 1 <= top)
        {
            return true;
        }

        // �����Ͱ� �� ������ ������ false

        else
        {
            return false;
        }
    }

    ~STACK()
    {
        std::cout << "STACK ����" << std::endl;
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

