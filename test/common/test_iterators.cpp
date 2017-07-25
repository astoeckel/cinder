/*
 *  Cinder -- C++ Single Spiking Neuron Simulator
 *  Copyright (C) 2015, 2016  Andreas Stöckel, Christoph Jenzen
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gtest/gtest.h"

#include <cinder/common/iterators.hpp>

namespace cinder {
TEST(iterators, linspace)
{
	Real v = 0.0;
	for (Real x : linspace(0.0, 1.0, 11)) {
		EXPECT_NEAR(v, x, 1e-9);
		v = v + 0.1;
	}
	EXPECT_NEAR(v, 1.1, 1e-9);
}
TEST(iterators, linspace_back)
{
	Real v = 1.0;
	for (Real x : linspace(1.0, 0.0, 11)) {
		EXPECT_NEAR(v, x, 1e-9);
		v = v - 0.1;
	}
	EXPECT_NEAR(v, -0.1, 1e-9);
}
}

