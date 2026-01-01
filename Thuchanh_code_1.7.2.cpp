#include <cstdio>
#include <cstdint>

constexpr int square(int x) { return x * x; }
static_assert(square(4) == 16, "square(4) phải bằng 16 (đánh giá tại compile-time)");

static volatile uint32_t GPIO_OUT = 0u; // giả lập thanh ghi output GPIO

struct Led {
    uint32_t mask;        
    explicit constexpr Led(uint8_t pin) : mask(1u << pin) {}

    inline void on()  const { GPIO_OUT |=  mask; } 
    inline void off() const { GPIO_OUT &= ~mask; } 
};

int main() {
    // Dùng constexpr + inline mà không cần cấp phát động/RTTI/exceptions
    Led led13{13};   
    led13.on();
    std::printf("GPIO_OUT after on : 0x%08X\n", (unsigned)GPIO_OUT);

    led13.off();
    std::printf("GPIO_OUT after off: 0x%08X\n", (unsigned)GPIO_OUT);

    int arr[square(3)]; 
    std::printf("arr size = %zu\n", sizeof(arr)/sizeof(arr[0]));
    return 0;
}
