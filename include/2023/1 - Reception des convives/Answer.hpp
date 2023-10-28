#ifndef CODINSA_QUALIFICATIONS_ANSWER_HPP
#define CODINSA_QUALIFICATIONS_ANSWER_HPP


#include "../../common/Questions.hpp"


struct GuestsReception : public Question
{
    using Question::Question;
    [[nodiscard]] int run() const noexcept final;
};


#endif //CODINSA_QUALIFICATIONS_ANSWER_HPP