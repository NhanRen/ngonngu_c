#include <cstdio>
#include <cstddef>

template <typename T, std::size_t N>
struct RingBuffer {
    T data[N]{};
    std::size_t w = 0, r = 0, c = 0; // write, read, count

    bool push(const T& v) {
        if (c == N) return false;        // hết chỗ
        data[w] = v;                     // ghi
        w = (w + 1) % N;                 // vòng tròn
        ++c;
        return true;
    }
    bool pop(T& out) {
        if (c == 0) return false;        // rỗng
        out = data[r];
        r = (r + 1) % N;
        --c;
        return true;
    }
    bool empty() const { return c == 0; }
    bool full()  const { return c == N; }
};

int main() {
    
    RingBuffer<int, 2> rb;

    std::printf("Push 1: %s\n", rb.push(1) ? "ok" : "full");
    std::printf("Push 2: %s\n", rb.push(2) ? "ok" : "full");
    std::printf("Push 3 (should fail): %s\n", rb.push(3) ? "ok" : "full");

    int x;
    if (rb.pop(x)) std::printf("Pop -> %d\n", x); else std::printf("Pop -> empty\n");
    if (rb.pop(x)) std::printf("Pop -> %d\n", x); else std::printf("Pop -> empty\n");
    if (rb.pop(x)) std::printf("Pop -> %d\n", x); else std::printf("Pop -> empty\n");

    return 0;
}
