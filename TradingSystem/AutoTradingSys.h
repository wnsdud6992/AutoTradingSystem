#pragma once
#include "IStockerBrockerDriver.h"

class AutoTradingSys {
public:
	AutoTradingSys(IStockerBrockerDriver* driver_, int account);

	bool login(std::string id, int password);
	void buy(std::string code, int price, int num);
	void sell(std::string code, int price, int num);
	int getPrice(std::string code);

	void buyNiceTiming(std::string code, int price);
	void sellNiceTiming(std::string code, int num);

	int getAccout();
	std::unordered_map < std::string, std::pair<int, int>> getStockInfo();

private:
	IStockerBrockerDriver* driver;
	std::string id;
	std::unordered_map < std::string, std::pair<int, int>> stockInfo; // key : stock code   value : {price, num}

	int userAccount = 0;
};