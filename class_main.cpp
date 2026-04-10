#include "class_main.h"

// Public method to add values to internal variables
// class_main
void class_main::addValues(int intValue, float floatValue) {
        // Add values to private variables
        intValue_ += intValue;
        floatValue_ += floatValue;

        // Print the updated values for verification
        //std::cout << "Updated Int Value: " << intValue_ << std::endl;
        //std::cout << "Updated Float Value: " << floatValue_ << std::endl;
        //std::cout << "Updated String Value: " << stringValue_ << std::endl;
}


class_main::class_main() : data_u8{0}, data_u16{0}, data_u32{0},
                               intValue_(0), floatValue_(0.0f) {
    // You can add any initialization code here if needed
}
