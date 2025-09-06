#include "StartPoint.h"

#define IMGUI_DEFINE_MATH_OPERATORS // Access to math operators
#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "imdrawlist_party.cpp"

StartPoint::StartPoint() = default;

/// <summary>
/// https://github.com/aaronvark/SFML-ImGui_StartPoint/blob/main/src/main.cpp
/// </summary>
int StartPoint::run() const {
    sf::RenderWindow window;
    window.create(sf::VideoMode({ 1280, 720 }), "My window");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    if (!ImGui::SFML::Init(window))
        return -1;

    // This is more useful than you would think.
    std::cout << ImGui::GetVersion() << std::endl;

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        // Event Polling
        while (const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);

            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Update
        ImGui::SFML::Update(window, deltaClock.restart());
        FxTestBed();
        ImGui::ShowDemoWindow();
        FxTestBed2();

        // Render
        window.clear();

        ImGui::SFML::Render(window);

        window.display();
    }

    return 0;
}