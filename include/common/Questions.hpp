#ifndef CODINSA_QUALIFICATIONS_QUESTION_HPP
#define CODINSA_QUALIFICATIONS_QUESTION_HPP


#include <memory>
#include <array>
#include <algorithm>
#include <string>


struct Question
{
public:
    Question() = delete;
    Question(const Question&) = default;
    Question(Question&&) = default;
    Question& operator=(const Question&) = default;
    Question& operator=(Question&&) = default;

    Question(std::string name, int year, int number) noexcept;

    virtual ~Question() noexcept = default;

    virtual int Run() const noexcept = 0;

    [[nodiscard]] std::string GetName() const noexcept;
    [[nodiscard]] int GetYear() const noexcept;
    [[nodiscard]] int GetNumber() const noexcept;
private:
    std::string m_name;
    int m_year;
    int m_number;
};

template<std::size_t QuestionsCount>
class QuestionManager
{
public:
    using Questions = std::array<std::unique_ptr<Question>, QuestionsCount>;

    QuestionManager() = default;
    QuestionManager(const QuestionManager&) = delete;
    QuestionManager(QuestionManager&&) = delete;
    QuestionManager& operator=(const QuestionManager&) = delete;
    QuestionManager& operator=(QuestionManager&&) = delete;

    explicit QuestionManager(Questions questions) noexcept;

    [[nodiscard]] Questions& GetQuestions() const noexcept;
    [[nodiscard]] std::pair<int, int> GetMinAndMaxYear() const noexcept;
    [[nodiscard]] std::pair<int, int> GetMinAndMaxNumber(int year) const noexcept;
    [[nodiscard]] Question* GetQuestion(int year, int number) const noexcept;
private:
    Questions m_questions;
};

#include "../../src/common/QuestionManager.inl"


#endif //CODINSA_QUALIFICATIONS_QUESTION_HPP
