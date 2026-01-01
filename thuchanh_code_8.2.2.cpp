#include <iostream>
#include <type_traits>
using namespace std;
struct point {
    int x;
    int y;
    // overload toán tử + : lấy max thay vì cộng
    point operator+(const point& other) const {
        return { (x > other.x ? x : other.x),
                 (y > other.y ? y : other.y) };
    }
};

template <typename T>
T add(T a, T b) {
    return a + b;
}
int main() {
    point a{4, 4};
    point b{2, 3};

    auto c = add(a, b);

    cout << "c.x = " << c.x << ", c.y = " << c.y << endl;

    static_assert(is_same_v<decltype(c), point>);

    return 0;
}
