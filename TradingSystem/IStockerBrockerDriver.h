#pragma once
#include <string>
#include <unordered_map>
class IStockerBrockerDriver {
public:
	virtual bool login(std::string id, int password) = 0;
	virtual std::string getID() = 0;
	virtual int getPwd() = 0;
	virtual void buy(std::string code, int price, int num) = 0;
	virtual void sell(std::string code, int price, int num) = 0;
	virtual int getPrice(std::string code) = 0;
};