#include "CircleEditor.h"
#include "Directions.h"
#include "StartPoint.h"
#include "CircleCollider.h"
#include <iostream>

// Questions for teacher:
// 1. Do you want me to include x64 folder in there with debug and release or not ? <-------------
// 2. General nit-pick questions about all the naming conventions of all of this 
//      because naming conventions are peak.
// 3. Where are the slides for the operands ( banking app ) and friend keyword ? <-------------

// Note to self: friend operators are useful for implementing
// operators for fields that are normally inaccessible. 
// Does this mean you can make operators for classes that you
// yourself did not make ?

/// <summary>
/// https://www.geeksforgeeks.org/cpp/cpp-polymorphism/
/// </summary>
int main() {
    CircleCollider groundCircle{ 0.5f, Layer::GROUND };
    CircleCollider triggerCircle{ 0.5f, Layer::TRIGGER };

    // Something can be both.
    CircleCollider mixedCircle{ 0.5f, Layer::GROUND | Layer::WATER };

    std::cout << (groundCircle.checkInteraction(triggerCircle.layer) ? "True" : "False") << std::endl;
    std::cout << (groundCircle.checkInteraction(mixedCircle.layer) ? "True" : "False") << std::endl;

    // =============================

    App* appPtr;

    //CircleEditor app{};
    //Directions app{};
    
    StartPoint app{};
    appPtr = &app;

    return appPtr->run();
}