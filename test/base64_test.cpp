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

#include "encfs/base64.h"

using namespace encfs;

#include <vector>
#include <string>

TEST(B64StandardEncode, StandardEncode) {
  std::vector<unsigned char> testVector;
  testVector.push_back('H');
  testVector.push_back('e');
  testVector.push_back('l');
  testVector.push_back('l');
  testVector.push_back('o');
  ASSERT_TRUE(B64StandardEncode(testVector) == std::string("SGVsbG8="));

  unsigned char *out = new unsigned char[200];
  bool res = B64StandardDecode(out, (const unsigned char *)"SGVsbG8=", 8);
  ASSERT_TRUE(std::string("Hello") == std::string((char *) out));
  ASSERT_TRUE(res);

  res = B64StandardDecode(out, (const unsigned char *)"Wrong Bullshit", 14);
  ASSERT_FALSE(res);
  res = B64StandardDecode(out, (const unsigned char *)"WrongBullshit", 13);
  ASSERT_TRUE(res);
  delete[](out);
}

