#include "CircleEditor.h"
#include "Directions.h"
#include "StartPoint.h"
#include "CircleCollider.h"
#include <iostream>

/// <summary>
/// https://www.geeksforgeeks.org/cpp/cpp-polymorphism/
/// </summary>
int main() {
    // This was my test at some basic bitwise collision layers.
    CircleCollider::test();
    
    // This is the real code. ==============
    const App* appPtr;

    //CircleEditor app{};
    //Directions app{};
    StartPoint app{};

    appPtr = &app;
    return appPtr->run();
}