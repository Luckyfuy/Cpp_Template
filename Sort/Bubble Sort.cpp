/*
冒泡排序
通过交换相邻两个数字来排序
*/

#include <iostream>
#include <limits>
#include <vector>
#include <utility>

// 冒泡排序
template<class type>
void bubbleSort(std::vector<type> &num) {
    // 记录最后一次交换的位置
    int index = 0;
    // 无序数列的边界，每次比较到这里为止
    int border = num.size() - 1;

    for (int i = 0; i < int(num.size()); ++i) {
        // 有序标记，每轮初始化为true
        bool is_sorted = true;

        for (int j = 0; j < border; ++j) {
            // 若数字比后一位数字大，则交换两个数字
            if (num[j] > num[j + 1]) {
                std::swap(num[j], num[j + 1]);

                // 因为有元素交换，所以标记变为false
                is_sorted = false;
                // 更新最后交换的位置
                index = j;
            }
        }

        // 更新无序数列的边界
        border = index;
        // 若已经有序，则停止排序
        if (is_sorted)
            return;
    }
}

// 测试
int main() {
    std::ios::sync_with_stdio(false);

    int n;
    std::vector<int> num;
    while (std::cin >> n)
        num.push_back(n);

    bubbleSort(num);

    for (int i: num)
        std::cout << i << ' ';
    std::cout << '\n';

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}