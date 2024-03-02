//
// Created by 81554 on 2024/2/29.
//

#ifndef LEETCODEDEMO_SOLUTION_H
#define LEETCODEDEMO_SOLUTION_H

#include <vector>

class Solution {
public:

//    二分查找

//三种形式
//1.查找元素：等于时直接返回
//2.查找左边界，等于时更新右边界
//3.查找右边界，等于时更新左边界

//    LeetCode 704.二分查找
//    给定一个n个元素有序的（升序）整型数组nums和一个目标值target，写一个函数搜索nums中的target，如果目标值存在返回下标，否则返回-1。
//    输入: nums = [-1,0,3,5,9,12], target = 9
//    输出: 4
//    解释: 9 出现在 nums 中并且下标为 4
    static int MyBinarySearch(std::vector<int>& nums, int target);


//    LeetCode 35. 搜索插入位置
//    给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//    请必须使用时间复杂度为 O(log n) 的算法。
//    示例 1:
//    输入: nums = [1,3,5,6], target = 5
//    输出: 2
    static int MySearchInsert(std::vector<int>& nums, int target);

//    LeetCode 34. 在排序数组中查找元素的第一个和最后一个位置
//    给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//    如果数组中不存在目标值 target，返回 [-1, -1]。
//    你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
//    示例 1：
//    输入：nums = [5,7,7,8,8,10], target = 8
//    输出：[3,4]

//暴力求解时间复杂度超了
//我的解法，很垃圾，用一个二分找target，再遍历target左右，找到所有target
    static std::vector<int> MySearchRange(std::vector<int>& nums, int target);
//    题解：用两个二分法找左右边界
//    寻找target在数组里的左右边界，有如下三种情况：
//    情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
//    情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
//    情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时应该返回{1, 1}
    static std::vector<int> AnsSearchRange(std::vector<int>& nums, int target);
    static int getLeftBorder(std::vector<int>& nums, int target);
    static int getRightBorder(std::vector<int>& nums, int target);


//    LeetCode 69. x 的平方根
//    给你一个非负整数x ，计算并返回x的算术平方根 。
//    由于返回类型是整数，结果只保留整数部分，小数部分将被舍去。
//    注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
//    示例 1：
//    输入：x = 4
//    输出：2


//我的解法：
// 二分法查找左边界，有问题
//用二分法查找右边界
//需要用左闭右闭区间！！否则处理0、1输入时有问题
    static int MySqrt(int x);


//    LeetCode 367. 有效的完全平方数
//    给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
//    完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
//    不能使用任何内置的库函数，如  sqrt 。
//    示例 1：
//    输入：num = 16
//    输出：true
//    解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。


//二分查找，左闭右闭区间
    static bool isPerfectSquare(int num);

};


#endif //LEETCODEDEMO_SOLUTION_H
