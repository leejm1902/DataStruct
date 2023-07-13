#pragma once
#include <iostream>

// 1. 노드 만들기
struct NODE
{
    int data;
    NODE* next;
};

void AddNode(NODE* target, int data)
{
    // 1. NODE 생성
    NODE* newNode = new NODE;

    // 2. 새로운 노드의 data 값을 저장합니다.
    newNode->data = data;

    // 3. 새로운 노드의 next 포인터에 nullptr을 가지고 있는 포인터를 저장합니다.
    newNode->next = target->next;

    // 4. 이전 노드의 다음 주소에 새로운 노드의 주소를 저장합니다.
    target->next = newNode;

}

void ShowNode(NODE* targetPtr)
{
    NODE* currentPtr = targetPtr;

    while (currentPtr != nullptr)
    {
        currentPtr = currentPtr->next;

        if (currentPtr != nullptr)
        {
            std::cout << currentPtr->data << std::endl;
        }
    }
}

void RemoveNode(NODE* target)
{
    // 1. 삭제할 노드의 포인터를 저장할 변수
    NODE* deletePtr = target->next;

    // 2. target 노드의 Next를 삭제되는 노드의 다음 주소로 가리키게 합니다.
    target->next = deletePtr->next;

    // 3. 해당 노드를 삭제합니다.
    delete deletePtr;
}

void ReleaseNode(NODE* target)
{
    NODE* curPtr = target;

    while (curPtr != nullptr)
    {
        NODE* nextPtr = curPtr->next;

        delete curPtr;

        curPtr = nextPtr;
    }
}



int main()
{
    // 단일 연결 리스트
    /*
    // dummy 노드
    NODE* dummy = new NODE;

    // node1 노드
    NODE* node1 = new NODE;
    dummy->next = node1;
    node1->data = 10;

    // node2 노드
    NODE* node2 = new NODE;
    node1->next = node2;

    node2->data = 20;
    node2->next = nullptr;

    NODE* currentPtr = dummy;

    ShowNode(dummy);

    delete dummy;
    delete node1;
    delete node2;
    */

    // 단일 연결 리스트(함수)

    NODE* dummy = new NODE;

    dummy->next = nullptr;

    AddNode(dummy, 10);
    AddNode(dummy, 20);
    AddNode(dummy, 30);

    RemoveNode(dummy->next);
    // dummy->next


    ShowNode(dummy);

    ReleaseNode(dummy);



    return 0;
}

