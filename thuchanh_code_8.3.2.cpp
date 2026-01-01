#include <iostream>
#include <type_traits>
using namespace std;
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
add(T a, T b) {
    T result = a + b;
    if constexpr (std::is_integral<T>::value) {
        printf("%d + %d = %d\n", a, b, result);
    } 
    else if constexpr (std::is_floating_point<T>::value) {
        printf("%.2f + %.2f = %.2f\n", a, b, result);
    }
    return result;
}
int main() {
    int x = 4, y = 4;
    add(x, y);   // kiểu int → in dạng số nguyên
    double a = 2.5, b = 3.5;
    add(a, b);   // kiểu double → in dạng số thực
    return 0;
}
