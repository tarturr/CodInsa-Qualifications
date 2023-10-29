#include "../../../include/2023/2 - Decoupe du camembert normand AOP/Answer.hpp"

#include <iostream>


int Input()
{
    std::cout << '>';
    int n;
    std::cin >> n;
    return n;
}

int CamembertCutting::Run() const noexcept
{
    std::cout << (Input() * Input() >= Input() ? "Apero" : "Pas apero") << std::endl;
    return EXIT_SUCCESS;
}