#include <iostream>
#include <type_traits>
using namespace std;
template <typename T>
typename std::enable_if<true, T>::type
add(T a, T b) {
    return a + b;
}
int main() {
    int x = 4, y = 4;
    cout << "Tong: " << add(x, y) << endl;

    double a = 2.5, b = 3.5;
    cout << "Tong: " << add(a, b) << endl;

    return 0;
}
