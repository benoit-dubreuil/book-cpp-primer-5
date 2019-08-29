#pragma once

struct  A
{
	int memI{ 0 };

	A();
	A(int i);

	friend void swap(A& lhs, A& rhs) noexcept;
};

