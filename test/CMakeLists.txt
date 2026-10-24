add_executable(qt-plus-test
    source/CUnitTests.cpp
    source/CUnitTests.h
)

set_target_properties(qt-plus-test PROPERTIES DEBUG_POSTFIX "d")

target_link_libraries(qt-plus-test PRIVATE
    qt-plus
    Qt6::Test
)
