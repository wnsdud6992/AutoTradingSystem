#pragma once
#include "IStockerBrockerDriver.h"

class AutoTradingSys {
public:
	AutoTradingSys(IStockerBrockerDriver* driver_);

	bool login(std::string id, int password);
	std::string getID();
	int getPwd();
	void buy(std::string code, int price, int num);
	void sell(std::string code, int price, int num);
	int getPrice(std::string code);

	void buyNiceTiming(std::string code, int price);
	void sellNiceTiming(std::string code, int num);


private:
	IStockerBrockerDriver* driver;
	std::string id;
	int pwd;
	std::unordered_map < std::string, std::pair<int, int>> stockInfo; // key : stock code   value : {price, num}
};