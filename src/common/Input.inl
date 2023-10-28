#include "../../include/common/Input.hpp"

#include <iostream>
#include <limits>


template<typename Predicate>
bool Input(int& n, std::string_view question, const Predicate& predicate, std::string_view errorMessage)
{
    std::cout << question << "\n>";
    std::string str;

    while (true)
    {
        while (!(std::cin >> str))
        {
            if (std::cin.eof())
            {
                throw std::runtime_error("The input has unexpectedly been closed.");
            }
            else if (std::cin.fail())
            {
                std::cout << "Input error. Try again.\n>" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                std::cout << "Error: " << errorMessage << ".\n>";
            }
        }

        if (str == "exit") return false;

        try
        {
            n = std::stoi(str);
            return true;
        } catch (const std::invalid_argument& ex)
        {
            std::cout << "Please enter a valid number.\n>" << std::endl;
        } catch (const std::out_of_range& ex)
        {
            std::cout << "This number is too large.\n>" << std::endl;
        }
    }
}