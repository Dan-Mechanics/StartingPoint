#include "CircleEditor.h"
#include "BlackScreen.h"

#include <iostream>

int globalInt;

struct myStruct {
    bool a, b, c; // this is smaller because a bool is not one bit. een hele word van data.
    double mD; // random: twee stukken informatie moet lezen om die ene dubble op te halen, word boundries er komen bij
    int* myIntP; // bools vijf bytes of drie.
    bool d;
    short myShort;
    int myInt;
};

/// <summary>
/// https://www.geeksforgeeks.org/cpp/cpp-polymorphism/
/// </summary>
int main() {
    // This way you can "easily" swap the apps.
    App* appPtr;

    CircleEditor circleEditor{};
    BlackScreen blackScreen{};

    appPtr = &circleEditor;


    static int staticInt;
    int stackInt;
    int* myIntPtr = new int(42);

    // get the adress of stuff
    std::cout << &globalInt << std::endl;
    std::cout << &stackInt << std::endl;
    std::cout << &staticInt << std::endl;

    std::cout << myIntPtr << std::endl;
    std::cout << &(*myIntPtr) << std::endl;

    int number = 0x12345678;
    unsigned char* bytes = (unsigned char*)&number;
    for (int i = 0; i < 4; i++) {
        // we have big endian because the big numbers are first,
        // this is important because in networking you send the bytes over but how the bytes are
        // handles is dependant on the "Environment" --> dus daarom is die environment belangrijk om te weten
        // 
        // .
        // 
        std::cout << std::hex << (int)bytes[i] << " ";
    }
    std::cout << std::endl << sizeof(myStruct);
    std::cout << std::endl << offsetof(myStruct, a);
    std::cout << std::endl << offsetof(myStruct, b);
    std::cout << std::endl << offsetof(myStruct, c);
    std::cout << std::endl << offsetof(myStruct, a);
    std::cout << std::endl << offsetof(myStruct, a);
    
    // je wilt liever niet dat je 8 
    // kleiner maken van de data, minder vaak data hoeven te lezen

    return appPtr->run();
}