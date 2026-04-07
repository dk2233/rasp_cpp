#include <array>
#include <stdio.h>
#include <pico/stdlib.h>
#include "test_cpp.h"

// Template function to add two numbers of any numeric type
template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T, size_t size>
T* create_array() {
    T* arr = new T[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
    return arr;
}


// Magia: Generator tablicy w czasie kompilacji
template <size_t N>
struct GainTable {
    std::array<float, N> values;

    constexpr GainTable() : values{} {
        for (size_t i = 0; i < N; ++i) {
            values[i] = calculate_gain(i);
        }
    }
};

// Cała ta tablica zostanie obliczona przez kompilator!
// W pamięci Flash Twojego Pico wylądują gotowe liczby.
static constexpr auto my_table = GainTable<64>();

void temp_add() {
    // Using the template function with different types
    printf("10 + 20 = %d \n,",add(10, 20));       // Integer addition
    printf("3.5 + 4.7 = %f\n",add(3.5f, 4.7f)); // Floating-point addition
                                                //
                                                
                                            
    int* myArray = create_array<int,20>();

    delete[] myArray;


    float gain = my_table.values[10]; // Natychmiastowy dostęp
}
