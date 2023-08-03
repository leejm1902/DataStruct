#include <iostream>
#include <vector>

#pragma region 그래프

#pragma endregion


int main()
{

#pragma region 인접 행렬
    // // 그래프의 연결 관계를 이차원 배열로 나타내는 방식입니다.
    // 
    // int buffer[4][4] = { 0, };
    // 
    // int vertex = 0;
    // int edge = 0;
    // 
    // int x, y = 0;
    // 
    // // 1. vertex와 edge 값을 입력합니다.
    // std::cout << "vertex를 입력해주세요." << std::endl;
    // std::cin >> vertex;
    // 
    // std::cout << "edge를 입력해주세요." << std::endl;
    // std::cin >> edge;
    // 
    // // 2. edge만큼 반복해서 x와 y값을 입력할 수 있도록 설정합니다.
    // for (int i = 0; i < edge; i++)
    // {
    //     std::cout << "x의 값을 입력해주세요." << std::endl;
    //     std::cin >> x;
    // 
    //     std::cout << "y의 값을 입력해주세요." << std::endl;
    //     std::cin >> y;
    // 
    //     std::cout << "------------------------------------" << std::endl;
    // 
    //     buffer[x][y] = 1;
    //     buffer[y][x] = 1;
    // }
    // 
    // std::cout << "------------------------------------" << std::endl;
    // 
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         std::cout << buffer[i][j];
    //     }
    // 
    //     std::cout << std::endl;
    // }
#pragma endregion

#pragma region 인접 리스트
    // 그래프의 연결 관계를 vector의 배열(vector<int> data[])로 나타내는 배열입니다.

    int node = 0;
    int edge = 0;

    int x, y = 0;

    // 1. vertex와 edge 값을 입력합니다.
    std::cout << "node를 입력해주세요." << std::endl;
    std::cin >> node;
    
    std::cout << "edge를 입력해주세요." << std::endl;
    std::cin >> edge;

    std::vector<int> data[4];

    for (int i = 0; i < edge; i++)
    {
        std::cout << "x의 값을 입력해주세요." << std::endl;
        std::cin >> x;
        
        std::cout << "y의 값을 입력해주세요." << std::endl;
        std::cin >> y;
        
        std::cout << "------------------------------------" << std::endl;

        data[x].push_back(y);
        data[y].push_back(x);

    }

#pragma endregion




    return 0;
}

