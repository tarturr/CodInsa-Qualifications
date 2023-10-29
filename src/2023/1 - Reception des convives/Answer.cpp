#include "../../../include/2023/1 - Reception des convives/Answer.hpp"
#include "../../../include/common/Input.hpp"

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


int GuestsReception::Run() const noexcept
{
    constexpr std::array<const char*, 7> schools{ "CVL", "HDF", "Lyon", "Rennes", "Rouen", "Strasbourg", "Toulouse" };

    std::vector<float> schoolRatios{ IO::DefaultInput<float>(7) };
    IO::DefaultInputWithOperation<float>(
            [&schoolRatios](int i, float val) { schoolRatios[i] /= val; },
            7
    );

    std::cout << schools[static_cast<int>(std::max_element(schoolRatios.begin(), schoolRatios.end()) - schoolRatios.begin())] << std::endl;
    return EXIT_SUCCESS;
}