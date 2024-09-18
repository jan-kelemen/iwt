add_library(iwtint INTERFACE)

target_sources(iwtint
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/iwtint.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/iwtint_addition.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/iwtint_config.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/iwtint_division.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/iwtint_multiplication.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/iwtint_narrow.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/iwtint_subtraction.hpp
)

target_include_directories(iwtint
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(iwtint
    INTERFACE
        project-options
)

if (IWT_BUILD_TESTS)
    add_executable(iwtint_test)

    target_sources(iwtint_test
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/test/iwtint.t.cpp
    )

    target_link_libraries(iwtint_test
        PRIVATE
            iwtint
        PRIVATE
            Catch2::Catch2WithMain
            project-options
    )

    if (NOT CMAKE_CROSSCOMPILING)
        include(Catch)
        catch_discover_tests(iwtint_test)
    endif()
endif()
