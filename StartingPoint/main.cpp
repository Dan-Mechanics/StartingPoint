#include "BlackScreen.h"

/// <summary>
/// https://www.geeksforgeeks.org/cpp/cpp-polymorphism/
/// </summary>
int main() {
    // This way you can "easily" swap the apps.
    App* appPtr;

    //CircleEditor circleEditor{};
    BlackScreen blackScreen{};

    appPtr = &blackScreen;

    return appPtr->run();
}