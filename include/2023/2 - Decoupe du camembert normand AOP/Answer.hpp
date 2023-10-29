#ifndef CODINSA_QUALIFICATIONS_CAMEMBERTCUTTING_ANSWER_HPP
#define CODINSA_QUALIFICATIONS_CAMEMBERTCUTTING_ANSWER_HPP


#include "../../common/Questions.hpp"


struct CamembertCutting : public Question
{
    using Question::Question;
    [[nodiscard]] int Run() const noexcept final;
};


#endif //CODINSA_QUALIFICATIONS_CAMEMBERTCUTTING_ANSWER_HPP
