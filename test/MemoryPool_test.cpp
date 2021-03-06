/*****************************************************************************
 * Author:   Valient Gough <vgough@pobox.com>
 *
 *****************************************************************************
 * Copyright (c) 2002-2004, Valient Gough
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* * *
 * 
 *     Further development: Zaur Molotnikov
 *  Original author of encfs: Valient Gough
 *  List of contributors: https://github.com/qutorial/encfs/graphs/contributors
 * 
 * */


#include "gtest/gtest.h"

#include "encfs/MemoryPool.h"

using namespace encfs;

TEST(MemoryPool, Allocate) {
  auto block = MemoryPool::allocate(1024);
  ASSERT_TRUE(block.data != nullptr);
  ASSERT_TRUE(block.internalData != nullptr);
  MemoryPool::release(block);
}

TEST(MemoryPool, ReleaseDeletesContents) {
  const int blockSize = 2048;
  auto block = MemoryPool::allocate(blockSize);
  MemoryPool::release(block);
  char testblock [blockSize];
  memset(testblock, 0, blockSize);
  ASSERT_TRUE(memcmp(block.data, testblock, blockSize) == 0);
}
