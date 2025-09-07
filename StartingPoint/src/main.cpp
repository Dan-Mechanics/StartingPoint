#include "StartPoint.h"
#include "CircleEditor.h"

/// <summary>
/// https://www.geeksforgeeks.org/cpp/cpp-polymorphism/
/// </summary>
int main() {
    // This way you can easily swap the apps.
    App* appPtr;

   // CircleEditor currApp{};
    StartPoint currApp{};

    appPtr = &currApp;
    return appPtr->run();
}