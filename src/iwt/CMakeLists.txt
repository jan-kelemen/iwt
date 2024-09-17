add_executable(iwt)

target_sources(iwt
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/iwt.m.cpp
)

target_link_libraries(iwt
    PRIVATE
        project-options
)

if (IWT_BUILD_TESTS)
    add_executable(iwt_test)

    target_sources(iwt_test
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/test/iwt.t.cpp
    )

    target_link_libraries(iwt_test
        PRIVATE
            Catch2::Catch2WithMain
            project-options
    )

    if (NOT CMAKE_CROSSCOMPILING)
        include(Catch)
        catch_discover_tests(iwt_test)
    endif()
endif()
