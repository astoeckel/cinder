/*
 *  Cinder -- C++ Single Spiking Neuron Simulator
 *  Copyright (C) 2017  Andreas Stöckel
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

/**
 * @file array_utils.hpp
 *
 * Utilities for compile-time constant std::array instances.
 *
 * @author Andreas Stöckel
 */

#pragma once

#ifndef CINDER_COMMON_ITERATORS_HPP
#define CINDER_COMMON_ITERATORS_HPP

#include <iterator>

#include <cinder/common/types.hpp>

namespace cinder {

class LinearIterator : public std::iterator<std::input_iterator_tag, Real> {
private:
	Real m_v0, m_v, m_s;
	size_t m_i;

public:
	using iterator = LinearIterator;

	LinearIterator(Real v0, Real s) : m_v0(v0), m_v(v0), m_s(s), m_i(0) {}
	LinearIterator(size_t i) : m_i(i) {}

	iterator &operator++()
	{
		++m_i;
		m_v = m_v0 + m_i * m_s;
		return *this;
	}

	iterator operator++(int)
	{
		iterator it = *this;
		++(*this);
		return it;
	}

	iterator &operator--()
	{
		--m_i;
		m_v = m_v0 + m_i * m_s;
		return *this;
	}

	iterator operator--(int)
	{
		iterator it = *this;
		--(*this);
		return it;
	}

	value_type operator*() const { return m_v; }

	pointer operator->() { return &m_v; }

	friend bool operator==(const iterator &lhs, const iterator &rhs)
	{
		return lhs.m_i == rhs.m_i;
	}

	friend bool operator!=(const iterator &lhs, const iterator &rhs)
	{
		return lhs.m_i != rhs.m_i;
	}

	friend bool operator<(const iterator &lhs, const iterator &rhs)
	{
		return lhs.m_i < rhs.m_i;
	}

	friend bool operator>(const iterator &lhs, const iterator &rhs)
	{
		return lhs.m_i > rhs.m_i;
	}

	friend bool operator<=(const iterator &lhs, const iterator &rhs)
	{
		return lhs.m_i <= rhs.m_i;
	}

	friend bool operator>=(const iterator &lhs, const iterator &rhs)
	{
		return lhs.m_i >= rhs.m_i;
	}

	friend void swap(iterator &lhs, iterator &rhs)
	{
		std::swap(lhs.m_v0, rhs.m_v0);
		std::swap(lhs.m_v, rhs.m_v);
		std::swap(lhs.m_s, rhs.m_s);
		std::swap(lhs.m_i, rhs.m_i);
	}
};

struct Linspace {
	Real min, max;
	size_t steps;

	Linspace(Real min, Real max, size_t steps)
	    : min(min), max(max), steps(steps)
	{
	}

	LinearIterator begin() const
	{
		return LinearIterator(min, (max - min) / (steps - 1));
	}

	LinearIterator end() const { return LinearIterator(steps); }
};

Linspace linspace(Real min, Real max, size_t steps)
{
	return Linspace(min, max, steps);
}
}

#endif /* CINDER_COMMON_ITERATORS_HPP */
