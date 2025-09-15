#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

//#include <algorithm>
#include <cassert>
#include <complex>
#include <format>
///#include <iostream>
#include <iterator>
#include <string>
//#include <vector>

void log(std::vector<std::string>& colors) {
    auto it = colors.begin();
    while (it != colors.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    std::cout << std::endl;
}

void log(std::vector<int>& colors) {
    auto it = colors.begin();
    while (it != colors.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    std::cout << std::endl;
}

// NOTE: i forgot how lamdas work and i forgot how if_stream thing works and i dont have it on the canvas.

int main() {
    // gebruik functies uit <algorithm> en <functional> om de volgende opdrachten uit te voeren:

    // splits de vector in 2 nieuwe vectoren: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    {
        std::vector<std::string> colors{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        std::sort(colors.begin(), colors.end());

        std::size_t const splitIndex = std::find(colors.begin(), colors.end(), "purple") - colors.begin();
        std::vector<std::string> pre(colors.begin(), colors.begin() + splitIndex);
        std::vector<std::string> post(colors.begin() + splitIndex, colors.end());

        log(pre);
        log(post);
    }

    // maak alle elementen UPPERCASE
    {
        std::vector<std::string> colors{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        
        auto op = [](std::string str) -> std::string { std::transform(str.begin(), str.end(), str.begin(), ::toupper); return str; };
        std::ranges::transform(colors.begin(), colors.end(), colors.begin(), op);

        log(colors);
    }

    // verwijder alle dubbele elementen
    {
        std::vector<std::string> colors{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        std::sort(colors.begin(), colors.end());
        colors.erase(std::unique(colors.begin(), colors.end()), colors.end());

        log(colors);
    }

    // verwijder alle negatieve elementen
    {
        std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        //::sort(numbers.begin(), numbers.end());
       // auto it = std::ranges::find_if(numbers, 0, )

    }

    // bepaal voor alle elementen of ze even of oneven zijn
    {
        std::vector numbers{ 10, 324422, 6, -23, 234, 654, 3, -9, 635 };
        std::ranges::transform(numbers.begin(), numbers.end(), numbers.begin(), [](int num) { num &= 1; return !num; });

        // 1 = EVEN, 0 = ODD
        log(numbers);
    }

    // bepaal de som, het gemiddelde, en het product van alle getallen te berekenen
    {
        std::vector<double> numbers{ 10, 324422.1, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
    }

    return 0;
}
