#include "gtest/gtest.h"
#include "is_in_check_test.hpp"
#include "get_legal_moves_test.hpp"
#include "generate_FEN_test.hpp"
#include "checkmate_stalemate_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
