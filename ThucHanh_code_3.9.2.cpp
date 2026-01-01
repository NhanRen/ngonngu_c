#include <cstdio>
#include <cstddef>

static int g_tests = 0;
static int g_fails = 0;

#define TEST_CASE(NAME) \
    do { \ 
        ++g_tests; \
        std::printf("[TEST] %s\n", NAME); \
    } while (0)

#define EXPECT_EQ(A, B) \
    do { \ 
        auto _a = (A); \
        auto _b = (B); \
        if (!((_a) == (_b))) { \ 
            ++g_fails; \
            std::printf("  FAIL: %s == %s (got %d, expect %d)\n", #A, #B, (int)_a, (int)_b); \
        } else { \
            std::printf("  OK  : %s == %s\n", #A, #B); \
        } \
    } while (0)

int add(int a, int b) { return a + b; }

template <typename T, std::size_t N>
struct RingBuffer {
    T buf[N]{};
    std::size_t w = 0, r = 0, c = 0; // write, read, count

    bool push(const T& v) {
        if (c == N) return false;          // đầy
        buf[w] = v; w = (w + 1) % N; ++c;
        return true;
    }
    bool pop(T& out) {
        if (c == 0) return false;          // rỗng
        out = buf[r]; r = (r + 1) % N; --c;
        return true;
    }
};

static void test_add() {
    TEST_CASE("add(a,b) basic");
    EXPECT_EQ(add(2,3), 5);
    EXPECT_EQ(add(-1,1), 0);
    EXPECT_EQ(add(0,0), 0);
}

static void test_ringbuffer() {
    TEST_CASE("RingBuffer<int,2> push/pop");
    RingBuffer<int,2> rb;
    int x;

    EXPECT_EQ(rb.push(10), true);
    EXPECT_EQ(rb.push(20), true);
    EXPECT_EQ(rb.push(30), false);

    EXPECT_EQ(rb.pop(x), true);
    EXPECT_EQ(x, 10);
    EXPECT_EQ(rb.pop(x), true);
    EXPECT_EQ(x, 20);
    EXPECT_EQ(rb.pop(x), false);
}

int main() {
    test_add();
    test_ringbuffer();

    std::printf("\nSummary: %d tests, %d failures\n", g_tests, g_fails);
    return (g_fails == 0) ? 0 : 1;
}

