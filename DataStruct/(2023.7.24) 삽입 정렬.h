#pragma once
#include <iostream>

#define SIZE 5

class Component
{
private:
    float x;
    float y;
    int* count;

public:
    // �⺻ ������
    Component()
    {
        x = 10;
        y = 20;
        count = new int;
    }

    // ���� ������
    Component(Component& other)
    {
        std::cout << "���� ������" << std::endl;

        this->x = other.x;
        this->y = other.y;

        // ���� ����
        other.count = new int;
    }

    // �̵� ������
    Component(Component&& other)
    {
        std::cout << "�̵� ������" << std::endl;

        this->x = other.x;
        this->y = other.y;

        this->count = other.count;

        other.count = nullptr;


    }

};

int main()
{

#pragma region ���� ����
    // // �ι�° �ڷ���� �����Ͽ� �� ��(����)�� �ڷ��� ���Ͽ� ������ ��ġ�� ������ ��
    // // �ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ� �����ϴ� �˰����Դϴ�.
    // 
    // // �ð� ���⵵ O(n^2)
    // 
    // int array[SIZE] = { 5, 8, 6, 1, 2 };    
    // int temp = 0;
    // 
    // int j = 0;
    // 
    // // j�� -1���� �������ϴ�.
    // for (int i = 1; i < SIZE; i++)
    // {
    //     temp = array[i]; // temp = 7
    // 
    //     for (j = i - 1; j >= 0; j--)
    //     {
    //         if (array[j] > temp)
    //         {
    //             array[j + 1] = array[j];
    //         }
    // 
    //         else
    //         {
    //             break;
    //         }
    // 
    //     }
    // 
    //     array[j + 1] = temp;
    // }
    // 
    // for (const int& element : array)
    // {
    //     std::cout << element << std::endl;
    // }
#pragma endregion

#pragma region �̵� ������
    // ���� ��ü�� �ּ� �� ���� ���ο� ������Ʈ�� �������� ������Ű�� �������Դϴ�.

    Component component1;

    Component component2 = component1;
    Component component3 = std::move(component1);
#pragma endregion



    return 0;
}

