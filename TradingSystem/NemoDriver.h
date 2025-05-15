#pragma once
#include "IStockerBrockerDriver.h"
#include "nemo_api.cpp"

class NemoDriver : public IStockerBrockerDriver {
public:
	// IStockerBrockerDriver을(를) 통해 상속됨
	void login(std::string id, int password) override;
	void buy(std::string code, int price, int num) override;
	void sell(std::string code, int price, int num) override;
	int getPrice(std::string code) override;

private:
	NemoAPI api;
};