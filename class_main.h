#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

#include <cstdint>

class class_main {
public:
    uint8_t data_u8;
    uint16_t data_u16;
    uint32_t data_u32;

    class_main();
    // Public method to add values to internal variables
    void addValues(int intValue, float floatValue);

private:
    uint32_t priv_data_u32;
    int intValue_;  // Private integer variable
    float floatValue_;  // Private floating-point variable
};

#endif // EXAMPLE_CLASS_H
/**
### Explanation

1. **Header Guard**:
   - `#ifndef`, `#define`, and `#endif` are used to prevent multiple inclusions of the header file.

2. **Class Declaration**:
   - The class `class_main` is declared with a public method `addValues`.

3. **Private Variables**:
   - Three private variables: `intValue_`, `floatValue_`, and `stringValue_`.

### Implementation File: `example_class.cpp`

Here’s the implementation of the `class_main` methods:

```cpp
#include "example_class.h"
#include <iostream>

// Public method to add values to internal variables
void class_main::addValues(int intValue, float floatValue, std::string stringValue) {
    // Add values to private variables
    intValue_ += intValue;
    floatValue_ += floatValue;
    stringValue_ = stringValue;  // Overwrite the string value

    // Print the updated values for verification
    std::cout << "Updated Int Value: " << intValue_ << std::endl;
    std::cout << "Updated Float Value: " << floatValue_ << std::endl;
    std::cout << "Updated String Value: " << stringValue_ << std::endl;
}
**/
