/*
背包问题
有n种物品和一个容量为W的背包，每种物品都有重量wi和价值vi两种属性，在所选物品不超过容量W的情况下，选择若干件物品放入背包使得总价值最大。
*/

#include <iostream>
#include <limits>
#include <algorithm>

// 最大背包容量
const int MAX_SIZE = 100000;

// 0-1背包
int zeroOne() {
    int n, W, w[MAX_SIZE], v[MAX_SIZE], f[MAX_SIZE] = {};
    std::cin >> n >> W;
    for (int i = 1; i <= n; ++i)
        std::cin >> w[i] >> v[i];

    for (int i = 1; i <= n; ++i)
        for (int j = W; j >= w[i]; --j)
            f[j] = std::max(f[j], f[j - w[i]] + v[i]);
    return f[W];
}
// 完全背包
int complete() {
    int n, W, w[MAX_SIZE], v[MAX_SIZE], f[MAX_SIZE] = {};
    std::cin >> n >> W;
    for (int i = 1; i <= n; ++i)
        std::cin >> w[i] >> v[i];

    for (int i = 1; i <= n; ++i)
        for (int j = w[i]; j <= W; ++j)
            f[j] = std::max(f[j], f[j - w[i]] + v[i]);
    return f[W];
}
// 多重背包
int multiple() {
    int n, W, tot = 0, w[MAX_SIZE], v[MAX_SIZE], f[MAX_SIZE] = {};
    std::cin >> n >> W;
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        for (int j = 1; j <= c; j <<= 1) {
            v[++tot] = j * a;
            w[tot] = j * b;
            c -= j;
        }
        if (c) {
            v[++tot] = c * a;
            w[tot] = c * b;
        }
    }

    for (int i = 1; i <= tot; ++i)
        for (int j = W; j >= w[i]; --j)
            f[j] = std::max(f[j], f[j - w[i]] + v[i]);
    return f[W];
}

// 测试
int main() {
    int n;
    std::cin >> n;

    switch (n) {
        case 1:
            std::cout << zeroOne() << '\n';
            break;
        case 2:
            std::cout << complete() << '\n';
            break;
        case 3:
            std::cout << multiple() << '\n';
            break;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}