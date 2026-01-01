#include <cstdio>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int result_int = add(3, 4);
    float result_float = add(11.1f, 19.1f);

    printf("result_int = %d\n", result_int);
    printf("result_float = %.2f\n", result_float);

    return 0;
}
