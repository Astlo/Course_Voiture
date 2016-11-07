/* 

*/

#ifndef DECORATOR_HPP
#define DECORATOR_HPP
#pragma once

#include "IController.hpp"

class Decorator : public IController
{
	public:
		Decorator(IController *ptr_icontroller);
	protected:
		IController *ptr_icontroller;
}; // class Decorator
/**************************************************************************** */

#endif // DECORATOR_HPP