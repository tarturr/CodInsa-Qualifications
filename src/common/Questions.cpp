#include "../../include/common/Questions.hpp"


int Question::GetYear() const noexcept
{
    return m_year;
}

int Question::GetNumber() const noexcept
{
    return m_number;
}

Question::Question(std::string name, int year, int number) noexcept
    : m_name(std::move(name)), m_year(year), m_number(number)
{
}

std::string Question::GetName() const noexcept
{
    return m_name;
}
