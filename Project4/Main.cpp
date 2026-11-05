#include <iostream>

// 1. 使用引用的版本
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// 2. 重载该函数：使用指针的版本
// 因为参数类型从 int& 变成了 int*，所以构成了函数重载
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x, y;

    // 输入两个整数
    if (std::cin >> x >> y) {
        // 输出交换前的结果（注意对齐格式，和示例保持一致）
        std::cout << "Before swap: x=" << x << ", y=" << y << std::endl;

        // 调用引用版本进行交换
        // 注意：这里加上 :: 是为了防止和 C++ 标准库自带的 std::swap 产生冲突（二义性）
        ::swap(x, y);

        // 另一种方式（指针版本重载的测试，题目没强制要求调用，但可以用来测试）：
        // swap(&x, &y);

        // 输出交换后的结果
        std::cout << "After  swap: x=" << x << ", y=" << y << std::endl;
    }

    return 0;
}