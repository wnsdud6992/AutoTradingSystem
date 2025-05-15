#pragma once

#include "CurrentPrice.h"

class IStockerBrockerDriver {
public:
	virtual void login(std::string id, int password) = 0;
	virtual void buy(std::string code, int price, int num) = 0;
	virtual void sell(std::string code, int price, int num) = 0;
	virtual int getPrice(std::string code) = 0;
};