// Copyright (C) 2020-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#include <vector>

#include "gtest/gtest.h"
#include "hexl/number-theory/bit-reverse.hpp"
#include "hexl/util/compiler.hpp"

namespace intel {
namespace hexl {

#ifdef HEXL_DEBUG
TEST(BitReverse, bad_input) {
  // Nullptr input
  EXPECT_ANY_THROW(BitReverse(nullptr, 4));

  // Non power-of-two sizes
  std::vector<uint64_t> x{1, 2, 3, 4};
  EXPECT_ANY_THROW(BitReverse(x.data(), 0));
  EXPECT_ANY_THROW(BitReverse(x.data(), 7));
}
#endif

TEST(BitReverse, 4) {
  std::vector<uint64_t> x{1, 2, 3, 4};
  std::vector<uint64_t> expected_out{1, 3, 2, 4};

  BitReverse(x.data(), x.size());

  EXPECT_EQ(x, expected_out);
}

TEST(BitReverse, 8) {
  std::vector<uint64_t> x{0, 1, 2, 3, 4, 5, 6, 7};
  std::vector<uint64_t> expected_out{0, 4, 2, 6, 1, 5, 3, 7};

  BitReverse(x.data(), x.size());

  EXPECT_EQ(x, expected_out);
}

}  // namespace hexl
}  // namespace intel