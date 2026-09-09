add_executable(Lab1CPPAboveAverage above_average.cpp)
target_include_directories(Lab1CPPAboveAverage PRIVATE ../LibraryCPP)
target_link_libraries(Lab1CPPAboveAverage PRIVATE LibraryCPP)
target_compile_features(Lab1CPPAboveAverage PRIVATE cxx_std_17)

add_executable(Lab1CPPMaxFiveSum max_five_sum.cpp)
target_include_directories(Lab1CPPMaxFiveSum PRIVATE ../LibraryCPP)
target_link_libraries(Lab1CPPMaxFiveSum PRIVATE LibraryCPP)
target_compile_features(Lab1CPPMaxFiveSum PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(Lab1CPPAboveAverage PRIVATE /utf-8)
    target_compile_options(Lab1CPPMaxFiveSum PRIVATE /utf-8)
endif()

add_test(
    NAME TestAboveAverageMixed
    COMMAND Lab1CPPAboveAverage
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/above_average_mixed_input.txt"
)
set_property(
    TEST TestAboveAverageMixed
    PROPERTY PASS_REGULAR_EXPRESSION "4 2 4 6 8"
)

add_test(
    NAME TestAboveAverageEqual
    COMMAND Lab1CPPAboveAverage
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/above_average_equal_input.txt"
)
set_property(
    TEST TestAboveAverageEqual
    PROPERTY PASS_REGULAR_EXPRESSION "0"
)

add_test(
    NAME TestAboveAverageLimits
    COMMAND Lab1CPPAboveAverage
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/above_average_limits_input.txt"
)
set_property(
    TEST TestAboveAverageLimits
    PROPERTY PASS_REGULAR_EXPRESSION "4 4 5 6 7"
)

add_test(
    NAME TestAboveAverageInvalidSize
    COMMAND Lab1CPPAboveAverage
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/above_average_invalid_input.txt"
)
set_property(TEST TestAboveAverageInvalidSize PROPERTY WILL_FAIL TRUE)

add_test(
    NAME TestMaxFiveMiddle
    COMMAND Lab1CPPMaxFiveSum
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/max_five_middle_input.txt"
)
set_property(
    TEST TestMaxFiveMiddle
    PROPERTY PASS_REGULAR_EXPRESSION "1 2 3 4 5"
)

add_test(
    NAME TestMaxFiveNegative
    COMMAND Lab1CPPMaxFiveSum
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/max_five_negative_input.txt"
)
set_property(
    TEST TestMaxFiveNegative
    PROPERTY PASS_REGULAR_EXPRESSION "-5 -4 -3 -2 -1"
)

add_test(
    NAME TestMaxFiveTie
    COMMAND Lab1CPPMaxFiveSum
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/max_five_tie_input.txt"
)
set_property(
    TEST TestMaxFiveTie
    PROPERTY PASS_REGULAR_EXPRESSION "1 2 3 4 5"
)

add_test(
    NAME TestMaxFiveTooShort
    COMMAND Lab1CPPMaxFiveSum
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/max_five_too_short_input.txt"
)
set_property(TEST TestMaxFiveTooShort PROPERTY WILL_FAIL TRUE)
