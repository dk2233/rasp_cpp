#include <optional>
#include "cstdint"
#include "hardware/uart.h"
#include "test_cpp.h"


enum class Interface { UART, SPI };

struct SensorData {
    uint32_t value;
};

// C++17: Zwracanie opcjonalnej wartości
std::optional<SensorData> read_internal_temp(bool fail) {
    if (fail) {
        return std::nullopt;
    }
    return SensorData{1234};
}

void demo_optional() {
    auto data = read_internal_temp(false);
    
    if (data.has_value()) {
        volatile uint32_t val = data->value; // Obserwuj dostęp do struktury
    }
}


template <Interface T>
void transmit(uint32_t data) {
    // Kompilator zostawi tylko jedną gałąź, druga w ogóle nie trafi do Flash
    if constexpr (T == Interface::UART) {
        // Kod specyficzny dla UART (np. wpis do rejestru UART0_BASE)
        //UART0_BASE
        *((volatile uint32_t*)UART0_BASE) = data;
                //0x40034000) = data; 
    } else {
        // Kod specyficzny dla SPI
        *((volatile uint32_t*)SPI0_BASE) = data;
    }
}

void demo_constexpr() {
    transmit<Interface::UART>(0xAA);
}
//
