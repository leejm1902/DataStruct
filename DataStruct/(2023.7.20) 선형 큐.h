#pragma once
#include <iostream>
#include <queue>

#define SIZE 5

template <typename T>
class LinearQueue
{
private:
    int front;
    int rear;
    int size;

    T array[SIZE];

public:
    LinearQueue()
    {
        front = 0;
        rear = 0;
        size = 0;
    }

    // Push
    void Push(T data)
    {
        if (IsFull() == true)
        {
            std::cout << "Queue�� ����� ���� á���ϴ�." << std::endl;
        }

        array[rear++] = data;
        size++;
    }

    // Pop
    void Pop()
    {
        if (Empty() == true)
        {
            std::cout << "Queue�� ����ֽ��ϴ�." << std::endl;
            exit(1);
        }

        array[front++] = NULL;
        size--;
    }

    // Size
    int& Size()
    {
        return size;
    }

    // Front
    T& Front()
    {
        return array[front];
    }

    // Back
    T& Back()
    {
        return array[rear - 1];
    }

    // Empty
    bool Empty()
    {
        if (front == rear)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    // IsFull
    bool IsFull()
    {
        if (SIZE <= rear)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
};




int main()
{
#pragma region ���� ť
    // �迭�� ������ �� �����Ͱ� �����Ǿ�
    // �����͸� �������� �ʱ�ȭ�� ���� ������ 
    // ���� �����Ͱ� �ִ� �迭�� �ڸ��� �� �̻� �ٸ� ���� �� �� ���� ������ Queue�Դϴ�.

    LinearQueue<int> linearQueue;

    linearQueue.Push(10);
    linearQueue.Push(20);
    linearQueue.Push(30);
    linearQueue.Push(40);
    linearQueue.Push(50);

    linearQueue.Pop();
    linearQueue.Pop();
    linearQueue.Pop();
    linearQueue.Pop();
    linearQueue.Pop();

    linearQueue.Push(9999);

    std::cout << linearQueue.Size() << std::endl;
    std::cout << linearQueue.Front() << std::endl;
    std::cout << linearQueue.Back() << std::endl;



#pragma endregion






    return 0;
}

