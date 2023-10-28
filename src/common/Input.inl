#include "../../include/common/Input.hpp"

#include <iostream>
#include <limits>


template<typename Predicate>
int Input(std::string_view question, const Predicate& predicate, std::string_view errorMessage)
{
    std::cout << question << "\n>";
    int n;

    while (!(std::cin >> n) || !predicate(n))
    {
        if (std::cin.eof())
        {
            throw std::runtime_error("The input has unexpectedly been closed.");
        }
        else if (std::cin.fail())
        {
            std::cout << "Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cout << "Error: " << errorMessage << ".\n>";
        }
    }

    return n;
}