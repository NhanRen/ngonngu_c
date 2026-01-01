#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
add(T a, T b) {
    return a + b;
}

int main() {
    int x = 4, y = 4;
    cout << "Tong so nguyen: " << add(x, y) << endl;

    double a = 2.5, b = 3.5;
    cout << "Tong so thuc: " << add(a, b) << endl;

    // string s1 = "Hello", s2 = "World";
    // cout << add(s1, s2);  // 

    return 0;
}
