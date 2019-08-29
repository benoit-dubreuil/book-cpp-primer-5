#pragma once

#include "A.h"

struct  B
{
	int memI{ 0 };
	A memA{};

	B();
	B(int i);

	friend void swap(B& lhs, B& rhs) noexcept;
};