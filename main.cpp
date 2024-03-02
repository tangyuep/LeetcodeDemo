#include <iostream>
#include "Solution.h"

int main() {
    // 输入数组
//    int n, target;
//    std::cout << "输入目标元素：";
//    std::cin >> target;
//    std::cout << "输入数组的大小：";
//    std::cin >> n;
//    std::vector<int> myVector(n);
//    std::cout << "输入数组元素（用空格分隔）：" << std::endl;
//    for (int i = 0; i < n; ++i) {
//        std::cin >> myVector[i];
//    }

    //输入整型
    int n;
    std::cout << "输入要计算的数：";
    std::cin >> n;

    //算法
//    auto result = Solution::MyBinarySearch(myVector, target);
//    auto result = Solution::MySearchInsert(myVector, target);
//    auto result = Solution::MySearchRange(myVector, target);
//    auto result = Solution::AnsSearchRange(myVector, target);

    auto result = Solution::MySqrt(n);

    //输出
//    for (auto i : result) {
//        std::cout << i << std::endl;
//    }

    std::cout << "结果是：" << result << std::endl;
    return 0;
}
