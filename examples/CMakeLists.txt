#  Cinder -- C++ Single Spiking Neuron Simulator
#  Copyright (C) 2015, 2016  Andreas Stöckel, Christoph Jenzen
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.

# CMake version and project metadata
cmake_minimum_required(VERSION 3.2)
project(cinder)

add_executable(izhikevich_cond_alpha
	izhikevich_cond_alpha
)
target_link_libraries(izhikevich_cond_alpha
	cinder
)

add_executable(izhikevich_sweep_constant_current
	izhikevich_sweep_constant_current
)
target_link_libraries(izhikevich_sweep_constant_current
	cinder
)

