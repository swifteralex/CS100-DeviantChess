CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    Board.cpp
    ChessObject.cpp
    Piece.cpp
    tests/unit_tests.cpp
)

ADD_EXECUTABLE(main
    main.cpp
    Board.cpp
    ChessObject.cpp
    Piece.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
