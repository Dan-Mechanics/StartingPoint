#include "CircleEditor.h"
#include "Directions.h"
#include "StartPoint.h"

// Questions for teacher:
// 1. Do you want me to include x64 folder in there with debug and release or not ?
// 2. General nit-pick questions about all the naming conventions of all of this 
//      because naming conventions are peak.
// 3. Where are the slides for the operands ( banking app ) and friend keyword ? 

/// <summary>
/// https://www.geeksforgeeks.org/cpp/cpp-polymorphism/
/// </summary>
int main() {
    App* appPtr;

    //CircleEditor app{};
    //Directions app{};
    StartPoint app{};

    appPtr = &app;
    return appPtr->run();
}