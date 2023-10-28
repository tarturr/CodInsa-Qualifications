#include <iostream>
#include <algorithm>
#include "../include/common/Input.hpp"
#include "../include/common/Questions.hpp"
#include "../include/2023/1 - Reception des convives/Answer.hpp"


int main()
{
    constexpr int PROBLEMS_SOLVED{ 1 };

    QuestionManager<PROBLEMS_SOLVED> questions
    {{
        std::make_unique<GuestsReception>("Reception des convives", 2023, 1)
    }};

    std::cout << "==================================================\n\n"
                 "Welcome to the answers of the Cod'Insa Qualifications\n"
                 "made by Tartur! You will be able to choose the correction\n"
                 "you want to test, with your own inputs.\n\n"
                 "Please consider to set a star on this repository\n"
                 "if you liked my programs.\n\n"
                 "==================================================\n" << std::endl;

    auto minMaxYears{ questions.GetMinAndMaxYear() };
    Question* question;

    do
    {
        int year;
        if (!Input(
                year,
                "Which year do you want to choose? ["
                + std::to_string(minMaxYears.first) + "-" + std::to_string(minMaxYears.second) + "]",
                [&minMaxYears](int n) -> bool
                {
                    return n >= minMaxYears.first && n <= minMaxYears.second;
                },
                "This year has not been implemented yet or does not exist."
        ))
        {
            std::cout << "You've decided to stop the program." << std::endl;
            break;
        }

        auto minMaxNumbers{ questions.GetMinAndMaxNumber(year) };
        int number;
        if (!Input(
                "Which year do you want to choose? ["
                + std::to_string(minMaxNumbers.first) + "-" + std::to_string(minMaxNumbers.second) + "]",
                [&minMaxNumbers](int n) -> bool
                {
                    return n >= minMaxNumbers.first && n <= minMaxNumbers.second;
                },
                "This year has not been implemented yet or does not exist."
        ))
        {
            std::cout << "You've decided to stop the program." << std::endl;
            break;
        }

        question = questions.GetQuestion(year, number);

        std::cout << "Let's go for the question N°" << number << " - " << year << " : "
                  << question->GetName() << " !" << std::endl;
    } while (question->run());

    std::cout << "Thank you and goodbye! (Don't forget to give me a star :) !)" << std::endl;
    return EXIT_SUCCESS;
}