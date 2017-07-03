#include "Math.h"
#include <iostream>
void MATH_H_TEST() {


	std::cout << "distance({10.f, 10.f}, {20.f, 20.f}) == 14.142(" << Math::distance({ 10.f, 10.f }, { 20.f, 20.f }) << ")\n";
	std::cout << "normalizedVector({10.f, 10.f}, {20.f, 20.f}) == 14.142(" << Math::distance({ 10.f, 10.f }, { 20.f, 20.f }) << ")\n";
}
