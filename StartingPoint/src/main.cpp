// ====================
// NOTE (15 SEP): 
// i forgot how lamdas work 
// and i forgot how if_stream thing works and i dont have it on the canvas.
// 
// would like it if this was feedbacked in the class but no must.
// ====================

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
#include <complex>
#include <format>
#include <iterator>
#include <string>
#include <numeric>

template <typename T>
void log(const std::vector<T>& vec) {
    for (auto& element : vec) std::cout << element << std::endl;

    std::cout << std::endl;
}

int main() {
    // gebruik functies uit <algorithm> en <functional> om de volgende opdrachten uit te voeren:

    // splits de vector in 2 nieuwe vectoren: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    {
        std::vector<std::string> colors{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        std::sort(colors.begin(), colors.end());

        const std::size_t splitIndex = std::find(colors.begin(), colors.end(), "purple") - colors.begin();
        const std::vector<std::string> pre(colors.begin(), colors.begin() + splitIndex);
        const std::vector<std::string> post(colors.begin() + splitIndex, colors.end());

        log(pre);
        log(post);
    }

    // maak alle elementen UPPERCASE
    {
        std::vector<std::string> colors{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        
        const auto lambda = [](std::string str) { 
            std::transform(str.begin(), str.end(), str.begin(), ::toupper);
            return str; };

        std::ranges::transform(colors.begin(), colors.end(), colors.begin(), lambda);

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
        
        numbers.erase(std::remove_if(numbers.begin(),
            numbers.end(), [](const double num) { return num < 0; }));
        
        log(numbers);
    }

    // bepaal voor alle elementen of ze even of oneven zijn
    {
        std::vector numbers{ 10, 324422, 6, -23, 234, 654, 3, -9, 635 };
        std::ranges::transform(numbers.begin(), numbers.end(), numbers.begin(),
            [](int num) { num &= 1; return !num; });

        // 1 = EVEN, 0 = ODD
        log(numbers);
    }

    // bepaal de som, het gemiddelde, en het product van alle getallen te berekenen
    {
        const std::vector<double> numbers{ 10, 324422.1, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        const double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
        const double av = sum / numbers.size();
        const double product = std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>());

        std::cout << sum << " " << av << " " << product << std::endl;
    }

    return 0;
}
