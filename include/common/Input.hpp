#ifndef CODINSA_QUALIFICATIONS_INPUT_HPP
#define CODINSA_QUALIFICATIONS_INPUT_HPP


#include <string_view>
#include <functional>


template<typename Predicate>
int Input(std::string_view question, const Predicate& predicate, std::string_view errorMessage);

#include "../../src/common/Input.inl"


#endif //CODINSA_QUALIFICATIONS_INPUT_HPP
