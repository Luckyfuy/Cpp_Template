/*
扩展欧几里得算法
用扩展欧几里得算法来求解线性同余方程和乘法逆元
*/

#include <iostream>
#include <limits>

// 扩展欧几里得算法
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y, y = t - a / b * y;
    return d;
}

// 线性同余方程
long long eq(long long a, long long b, long long c, long long &x, long long &y) {
    long long d = exgcd(a, c, x, y);
    if (b % d != 0)
        return -1;
    long long k = b / d, t = c / d;
    x *= k, y *= k;
    return (x % t + t) % t;
}

// 乘法逆元
long long inv(long long a, long long p) {
    long long power = p - 2, res = 1;
    for (; power != 0; power >>= 1, a = (a * a) % p)
        if (power & 1)
            res = (a * res) % p;
    return res;
}

// 测试
int main() {
    std::ios::sync_with_stdio(false);

    long long a, b, c, x, y;
    std::cin >> a >> b >> c;

    std::cout << exgcd(a, b, x, y) << '\n';
    std::cout << x << ' ' << y << '\n';
    std::cout << eq(a, b, c, x, y) << '\n';
    std::cout << x << ' ' << y << '\n';
    std::cout << inv(a, b) << '\n';

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}