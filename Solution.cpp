//
// Created by 81554 on 2024/2/29.
//

#include "Solution.h"

int Solution::MyBinarySearch(std::vector<int> &nums, int target) {
//    二分查找时间复杂度：logn 空间复杂度：1
//    注意循环不变量：左闭右闭
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) { //左闭右闭（左闭右开：<）
        int mid = (high + low) / 2;
        if (target == nums.at(mid)) {
            return mid;
        } else if (target < nums.at(mid)) {
            high = mid - 1; //左闭右闭（左闭右开：mid）
        } else {
            low = mid + 1; //左闭右闭（左闭右开：mid + 1）
        }
    }
    return -1;
}

int Solution::MySearchInsert(std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size(); //左闭右开
    while (left < right) {
        int middle = (left + right) / 2;
        if (target == nums.at(middle)) {
            return middle;
        } else if (target < nums.at(middle)) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return right; //左闭右闭：right+1
}

std::vector<int> Solution::MySearchRange(std::vector<int> &nums, int target) {
//    我的思路：
//    先用二分法查找target的位置，时间复杂度logn
//    在找到的位置附近查找共有几个target，获取每个target的下标
    int left = 0;
    int right = nums.size(); //左闭右开
    while (left < right) {
        int middle = (left + right) / 2;
        if (target < nums.at(middle)) {
            right = middle;
        } else if (target > nums.at(middle)) {
            left = middle + 1;
        } else {

//            问题：用二分法找到target的一个位置后，如何找到其他target的位置
            int ptr1 = middle;
            int ptr2 = middle;
            while (target == nums.at(ptr1)) {
                --ptr1;
                if (ptr1 == -1) break;
            }
            while (target == nums.at(ptr2)) {
                ++ptr2;
                if (ptr2 == nums.size()) break;
            }
            std::vector<int> result{ptr1 + 1, ptr2 - 1};
            return result;

        }
    }
    return std::vector<int>{-1, -1};
}

int Solution::getRightBorder(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
    while (left <= right) {
        int middle = left + ((right - left) / 2);
        if (nums[middle] > target) {
            right = middle - 1;
        } else { // 寻找右边界，nums[middle] == target的时候更新left
            left = middle + 1;
            rightBorder = left;
        }
    }
    return rightBorder;
}

int Solution::getLeftBorder(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况
    while (left <= right) {
        int middle = left + ((right - left) / 2);
        if (nums[middle] >= target) { // 寻找左边界，nums[middle] == target的时候更新right
            right = middle - 1;
            leftBorder = right;
        } else {
            left = middle + 1;
        }
    }
    return leftBorder;
}

std::vector<int> Solution::AnsSearchRange(std::vector<int>& nums, int target) {
    int leftBorder = Solution::getLeftBorder(nums, target);
    int rightBorder = Solution::getRightBorder(nums, target);
    // 情况一
    if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
    // 情况三
    if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
    // 情况二
    return {-1, -1};
}

int Solution::MySqrt(int x) {
    int left = 0;
    int right = x;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if ((long long)mid * mid < x) {
            left = mid + 1;
        } else if ((long long)mid * mid > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left - 1;
}

bool Solution::isPerfectSquare(int num) {
    int left = 0;
    int right = num;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((long long)mid * mid == num) {
            return true;
        } else if ((long long)mid * mid < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

