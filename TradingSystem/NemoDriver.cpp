#include "NemoDriver.h"
#include <iostream>

void NemoDriver::login(std::string id, int password)
{
	api.certification(id, std::to_string(password));
}

void NemoDriver::buy(std::string code, int price, int num)
{
	api.purchasingStock(code, price, num);
}

void NemoDriver::sell(std::string code, int price, int num)
{
	api.sellingStock(code, price, num);
}

int NemoDriver::getPrice(std::string code)
{
	return api.getMarketPrice(code, 0);
}
