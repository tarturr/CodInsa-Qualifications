#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


template<typename Operation>
void operate_with_inputs(std::vector<float>& schoolRatios, const Operation& operation)
{
    for (int i = 0; i < 7; i++)
    {
        int n;
        std::cin >> n;
        operation(i, n);
    }
}

int main()
{
    constexpr std::array<const char*, 7> schools{ "CVL", "HDF", "Lyon", "Rennes", "Rouen", "Strasbourg", "Toulouse" };
    std::vector<float> schoolRatios{};

    operate_with_inputs(schoolRatios, [&schoolRatios](int i, int n) { schoolRatios.push_back(n); });
    operate_with_inputs(schoolRatios, [&schoolRatios](int i, int n) { schoolRatios[i] /= static_cast<float>(n); });

    int schoolIndex{ static_cast<int>(std::max_element(schoolRatios.begin(), schoolRatios.end()) - schoolRatios.begin()) };
    std::cout << schools[schoolIndex] << std::endl;

    return EXIT_SUCCESS;
}