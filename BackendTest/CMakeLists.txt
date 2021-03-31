cmake_minimum_required(VERSION 3.17)
project(BackendTest)

set(CMAKE_CXX_STANDARD 14)

set(MAKE_DOCS OFF)

if(MAKE_DOCS)
    option(BUILD_DOC "Build documentation" ON)

    set(DOXYFILE "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in")
    find_package(Doxygen)
    if (DOXYGEN_FOUND)
        message("Building Docs")

        add_custom_target(
                doc ALL
                COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                COMMENT "Generating API documentation with Doxygen"
                VERBATIM
        )

    else (DOXYGEN_FOUND)
        message("Doxygen need to be installed to generate the documentation")
    endif (DOXYGEN_FOUND)
endif(MAKE_DOCS)

add_executable(BackendTest src/main.cpp src/components/Component.h src/components/Resistor.cpp src/components/Resistor.h src/components/components.h src/components/PowerData.h)