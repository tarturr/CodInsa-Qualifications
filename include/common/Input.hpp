#ifndef CODINSA_QUALIFICATIONS_INPUT_HPP
#define CODINSA_QUALIFICATIONS_INPUT_HPP

#include <string_view>
#include <functional>
#include <vector>


namespace IO
{
    template<typename T, typename Operation>
    std::vector<T> DefaultInputWithOperation(const Operation& operation, int iterations);
    template<typename T, typename Operation>
    T DefaultInputWithOperation(const Operation& operation);

    template<typename T>
    std::vector<T> DefaultInput(int iterations);
    template<typename T>
    T DefaultInput();

    template<typename Predicate>
    bool Input(int& n, std::string_view question, const Predicate& predicate, std::string_view errorMessage);
}


#include "../../src/common/Input.inl"


#endif //CODINSA_QUALIFICATIONS_INPUT_HPP
