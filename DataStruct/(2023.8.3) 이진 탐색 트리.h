#pragma once
#include <iostream>

#pragma region 이진 탐색 트리 (BST)
// 임의의 키를 가진 원소를 삽입, 삭제, 검색하는데 효율적인 트리입니다.

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* Insert(Node* root, int data)
{
    // if root가 nullptr 이라면?
    if (root == nullptr)
    {
        root = new Node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }

    // else if(root의 data보다 작다면?)
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }

    // else(root의 data보다 크다면?)
    else
    {
        root->right = Insert(root->right, data);
    }

    // 주소값을 반환합니다.
    return root;
}

int FindMax(Node* root)
{
    if (root == nullptr)
    {
        std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
        return 0xcccccccc;
    }

    if (root->right == nullptr)
    {
        return root->data;
    }

    else
    {
        return FindMax(root->right);
    }
}

int FindMin(Node* root)
{
    if (root == nullptr)
    {
        std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
        return 0xcccccccc;
    }

    if (root->left == nullptr)
    {
        return root->data;
    }

    else
    {
        return FindMin(root->left);
    }
}

struct Node* MinValueNode(Node* node)
{
    Node* currentNode = node;

    while (currentNode && currentNode->left == nullptr)
    {
        currentNode = currentNode->left;
    }

    return currentNode;
}

Node* DeleteNode(Node* root, int key)
{
    if (root == nullptr)
    {
        std::cout << "현재 데이터가 존재하지 않습니다." << std::endl;
        return root;
    }

    if (key < root->data)
    {
        root->left = DeleteNode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = DeleteNode(root->right, key);
    }

    else
    {
        struct Node* temp;

        if (root->left == nullptr)
        {
            temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == nullptr)
        {
            temp = root->left;
            delete root;
            return temp;
        }

        // 자식 노드가 두개 있는 경우
        temp = MinValueNode(root->right);

        // 삭제할 Node의 데이터를 바꿉니다.
        root->data = temp->data;

        // 노드를 삭제합니다.
        root->right = DeleteNode(root->right, temp->data);
    }

    return root;
}
#pragma endregion


int main()
{

    Node* root = nullptr;

    root = Insert(root, 10);
    root = Insert(root, 5);

    std::cout << FindMax(root) << std::endl;
    std::cout << FindMin(root) << std::endl;



    return 0;
}

