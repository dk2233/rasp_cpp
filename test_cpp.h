#ifndef TEST_CPP_H
#define TEST_CPP_H

extern void demo_optional();

extern void temp_add();

// Funkcja obliczająca jakąś wartość (np. nieliniową korektę)
constexpr float calculate_gain(int index) {
    return index * 1.05f + 0.02f; // Przykładowy wzór
}

#endif
