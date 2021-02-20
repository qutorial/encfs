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

#include "encfs/BlockNameIO.h"

#include "encfs/Interface.h"
#include "encfs/SSL_Cipher.h"

using namespace encfs;

#include <vector>
#include <string>
#include <iostream>

TEST(BlockNameIO, LengthsTest) {

  bool caseInsensitive = false;
  Interface currentInterface = BlockNameIO::CurrentInterface(caseInsensitive);

  // BlockNameIO blockNameIo(currentInterface, cipher, key, blockSize, caseInsensitive);


}
