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

#include "encfs/Interface.h"

using namespace encfs;

#include <vector>
#include <string>
#include <iostream>

/* * *
 * Useful reading to get the meaning of current, revision and age:  
 * https://www.gnu.org/software/libtool/manual/html_node/Libtool-versioning.html
 * and
 * https://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html#Updating-version-info
 * 
 * Current is the interface version, latest supported.
 * Revision is a source code change number.
 * Age defines all the supported interfaces: from current - age till current.
 * 
 * * */

TEST(Interface, ClassTest) {
  Interface i1("superlib", 1, 0, 0);
  Interface iSameAs1("superlib", 1, 0, 0);
  Interface i2("superlib", 2, 0, 1); // version two, revision 0, supports 1
  Interface iZero; // default constructor
  
  
  ASSERT_TRUE(iZero.current() == 0);
  ASSERT_TRUE(iZero.revision() == 0);
  ASSERT_TRUE(iZero.age() == 0);

  ASSERT_TRUE(i1 == iSameAs1);

  ASSERT_TRUE(i2.implements(i1));
  ASSERT_FALSE(i1.implements(i2));
}


TEST(Interface, DiffSumTest) {
  Interface i1("superlib", 1, 50, 90);
  Interface i2("superlib", 2, 0, 0);
  ASSERT_TRUE(i2 > i1);  
}
