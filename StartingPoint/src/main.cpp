#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

template <typename T>
void log(const std::vector<T>& vec) {
    for (auto& element : vec) std::cout << element << std::endl;

    std::cout << std::endl;
}

/// <summary>
/// I THINK FEEDBACK FOR THIS WOULD BE USEFUL.
/// IT'S CONFUSING BECAUSE THERE ARE SO MANY WAYS
/// TO SOLVE THE PROBLEMS.
/// </summary>
int main() {
    // gebruik functies uit <algorithm> en <functional> om de volgende opdrachten uit te voeren:

    // splits de vector in 2 nieuwe vectoren: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    {
        const std::vector<std::string> colors{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        std::sort(colors.begin(), colors.end());

        // CAN THIS BE MADE EVEN MORE CONCISE?
        const auto splitIndex = std::find(colors.begin(), colors.end(), "purple") - colors.begin();
        const std::vector<std::string> pre(colors.begin(), colors.begin() + splitIndex);
        const std::vector<std::string> post(colors.begin() + splitIndex, colors.end());

        log(pre);
        log(post);
    }

    // maak alle elementen UPPERCASE
    {
        std::vector<std::string> colors{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        
        // YOU CAN USE A LAMBDA HERE OR INLINE IT.
        std::ranges::transform(colors.begin(), colors.end(), colors.begin(), [](auto& str) {
            std::transform(str.begin(), str.end(), str.begin(), ::toupper);
            return str; }
        );

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
            numbers.end(), [](const auto num) { return num < 0; }));
        
        log(numbers);
    }

    // bepaal voor alle elementen of ze even of oneven zijn
    {
        std::vector<int> numbers{ 10, 324422, 6, -23, 234, 654, 3, -9, 635 };
        std::ranges::transform(numbers.begin(), numbers.end(), numbers.begin(),
            [](auto num) { num &= 1; return !num; });

        // 1 = EVEN, 0 = ODD.
        log(numbers);
    }

    // bepaal de som, het gemiddelde, en het product van alle getallen te berekenen
    {
        const std::vector<double> numbers{ 10, 324422.1, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        
        const auto sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
        const auto av = sum / numbers.size();
        const auto product = std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>());

        std::cout << sum << " " << av << " " << product << std::endl;
    }

    return 0;
}
