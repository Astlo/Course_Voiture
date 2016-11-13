/**
 *
**/
#include "Decorator.hpp"

 Decorator::Decorator(IController *ptr_icontroller)
 {
 	this->ptr_icontroller = ptr_icontroller;
 }