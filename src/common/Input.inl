#include "../../include/common/Input.hpp"

#include <iostream>
#include <limits>
#include <string>


namespace IO
{
    template<typename T, typename Operation>
    std::vector<T> DefaultInputWithOperation(const Operation &operation, int iterations)
    {
        std::vector<T> nums{};

        for (int i{ 0 }; i < iterations; i++)
        {
            if (!static_cast<bool>(i)) std::cout << '>';
            T var;
            std::cin >> var;
            operation(i, var);
            nums.emplace_back(std::move(var));
        }

        return nums;
    }

    template<typename T, typename Operation>
    T DefaultInputWithOperation(const Operation &operation)
    {
        return DefaultInputWithOperation<T>(operation, 1)[0];
    }

    template<typename T>
    std::vector<T> DefaultInput(int iterations)
    {
        return DefaultInputWithOperation<T>([](int i, const T&) {}, iterations);
    }

    template<typename T>
    T DefaultInput()
    {
        return DefaultInputWithOperation<T>([](int i, const T&) {});
    }

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
            }

            if (str == "exit") return false;

            try
            {
                n = std::stoi(str);

                if (predicate(n))
                    return true;

                std::cout << "Error: " << errorMessage << ".\n>";
            } catch (const std::invalid_argument& ex)
            {
                std::cout << "Please enter a valid number.\n>" << std::endl;
            } catch (const std::out_of_range& ex)
            {
                std::cout << "This number is too large.\n>" << std::endl;
            }
        }
    }
}