#include "../../../include/2023/2 - Decoupe du camembert normand AOP/Answer.hpp"
#include "../../../include/common/Input.hpp"

#include <iostream>


int CamembertCutting::Run() const noexcept
{
    std::cout << (IO::DefaultInput<int>() <= IO::DefaultInput<int>() * IO::DefaultInput<int>() ? "Apero" : "Pas apero") << std::endl;
    return EXIT_SUCCESS;
}