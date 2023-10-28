cmake_minimum_required(VERSION 3.13)
project(CodInsa-Qualifications)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES "src/2023/1 - Reception des convives/Answer.cpp"
        src/Main.cpp
        src/common/Questions.cpp
        src/common/Input.inl)

add_executable(CodInsa-Qualifications ${SOURCE_FILES})