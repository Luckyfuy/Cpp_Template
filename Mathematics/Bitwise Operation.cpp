/*
位运算
利用位运算来实现一些常用操作
*/

#include <iostream>
#include <limits>
#include <format>

// 乘以2^m
int mulTwoPower(int n, int m=1) {
    return n << m;
}
// 除以2^m
int divTwoPower(int n, int m=1) {
    return n >> m;
}

// 判断奇偶性
bool isOdd(int n) {
    return n & 1;
}

// 取两个数的最大值
int max(int a, int b) {
    // 若n为非负数，n >> 31的值为0，否则为-1
    return (b & ((a - b) >> 31)) | (a & (~(a - b) >> 31));
}
// 取两个数的最小值
int min(int a, int b) {
    // 若n为非负数，n >> 31的值为0，否则为-1
    return (a & ((a - b) >> 31)) | (b & (~(a - b) >> 31));
}

// 取绝对值
int iabs(int n) {
    // 若n为非负数，n >> 31的值为0，否则为-1
    return (n ^ (n >> 31)) - (n >> 31);
}

// 判断是否是2的幂
bool isTwoPower(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// 对2^n取余
int modTwoPower(int n, int m) {
    return m & (n - 1);
}

// 判断符号是否相同
bool isSameSign(int a, int b) {
    return (a ^ b) >= 0;
}

// 加法
int add(int a, int b) {
    int sum = 0, carry = 0;
    do {
        sum = a ^ b;
        carry = (a & b) << 1;
        a = sum;
        b = carry;
    } while (carry);
    return sum;
}

// 测试
int main() {
    std::ios::sync_with_stdio(false);

    int a, b;
    std::cin >> a >> b;

    std::cout.setf(std::ios::boolalpha);
    std::cout << std::format("{}\n", mulTwoPower(a, b));
    std::cout << std::format("{}\n", divTwoPower(a, b));
    std::cout << std::format("{} {}\n", isOdd(a), isOdd(b));
    std::cout << std::format("{}\n", max(a, b));
    std::cout << std::format("{}\n", min(a, b));
    std::cout << std::format("{} {}\n", iabs(a), iabs(b));
    std::cout << std::format("{} {}\n", isTwoPower(a), isTwoPower(b));
    std::cout << std::format("{}\n", modTwoPower(a, b));
    std::cout << std::format("{}\n", isSameSign(a, b));
    std::cout << std::format("{}\n", add(a, b));

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}