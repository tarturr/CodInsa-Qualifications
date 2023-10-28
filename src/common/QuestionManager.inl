#include <vector>


template<std::size_t QuestionsCount>
QuestionManager<QuestionsCount>::Questions &QuestionManager<QuestionsCount>::GetQuestions() const noexcept
{
    return m_questions;
}

template<std::size_t QuestionsCount>
QuestionManager<QuestionsCount>::QuestionManager(QuestionManager<QuestionsCount>::Questions questions) noexcept
{
    for (int i{ 0 }; i < QuestionsCount; i++)
    {
        m_questions[i] = std::move(questions[i]);
    }
}

template<std::size_t QuestionsCount>
std::pair<int, int> QuestionManager<QuestionsCount>::GetMinAndMaxYear() const noexcept
{
    std::array<int, QuestionsCount> allYears{};

    for (int i{ 0 }; i < QuestionsCount; i++)
    {
        allYears[i] = m_questions[i]->GetYear();
    }

    return {
        *std::min_element(allYears.begin(), allYears.end()),
        *std::max_element(allYears.begin(), allYears.end())
    };
}

template<std::size_t QuestionsCount>
std::pair<int, int> QuestionManager<QuestionsCount>::GetMinAndMaxNumber(int year) const noexcept
{
    std::vector<int> allQuestionNumbers{};

    for (const auto& question : m_questions)
    {
        if (question->GetYear() == year)
        {
            allQuestionNumbers.push_back(question->GetNumber());
        }
    }

    return {
        *std::min_element(allQuestionNumbers.begin(), allQuestionNumbers.end()),
        *std::max_element(allQuestionNumbers.begin(), allQuestionNumbers.end())
    };
}

template<std::size_t QuestionsCount>
Question* QuestionManager<QuestionsCount>::GetQuestion(int year, int number) const noexcept
{
    Question* found{ nullptr };

    for (const auto& question : m_questions)
    {
        if (question->GetYear() == year && question->GetNumber() == number)
            found = question.get();
    }

    return found;
}