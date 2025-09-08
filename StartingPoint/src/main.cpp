#include "StartPoint.h"
#include "CircleEditor.h"

#include "bit_utils.h"
#include "Data.h"

/// <summary>
/// https://www.geeksforgeeks.org/cpp/cpp-polymorphism/
/// </summary>
int main() {
    sayHello();
    
    App* appPtr;

    // CircleEditor circleEditor{};
    // StartPoint startPoint{};

    Data data{};

    appPtr = &data;
    return appPtr->run();
}