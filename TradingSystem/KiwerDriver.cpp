#include "KiwerDriver.h"
#include <iostream>

void KiwerDriver::login(std::string id, int password)
{
	api.login(id, std::to_string(password));
}

void KiwerDriver::buy(std::string code, int price, int num)
{
	api.buy(code, num, price);
}

void KiwerDriver::sell(std::string code, int price, int num)
{
	api.sell(code, price, num);
}

int KiwerDriver::getPrice(std::string code)
{
	return api.currentPrice(code);
}
