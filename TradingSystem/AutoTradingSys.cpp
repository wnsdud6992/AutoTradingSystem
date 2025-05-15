#include "AutoTradingSys.h"

AutoTradingSys::AutoTradingSys(IStockerBrockerDriver* driver_, int account) : driver(driver_), userAccount(account)
{
}

bool AutoTradingSys::login(std::string id, int password) {
	return false;
}

void AutoTradingSys::buy(std::string code, int price, int num) {
	driver->buy(code, price, num);
	if (stockInfo.find(code) != stockInfo.end()) {
		stockInfo[code].second += num;
	}
	else {
		stockInfo.insert({ code, {price, num} });
	}
	userAccount += price * num;
}

void AutoTradingSys::sell(std::string code, int price, int num) {
	auto stock = stockInfo.find(code);
	if (stock == stockInfo.end()) {
		isSocktFound();
	}
	// stock exist
	if (stockInfo[code].second < num) {
		isStockEnough();
	}
	driver->sell(code, price, num);//mock driver sell
}

void AutoTradingSys::isStockEnough()
{
//	std::cout << "Stock not enough.\n";
	throw std::exception();
}

void AutoTradingSys::isSocktFound()
{
//	std::cout << "Stock not found.\n";
	throw std::exception();
}

int  AutoTradingSys::getPrice(std::string code) {
	return 0;
}

void AutoTradingSys::buyNiceTiming(std::string code, int price) {

}

void AutoTradingSys::sellNiceTiming(std::string code, int num) {

}

int AutoTradingSys::getAccout() {
	return userAccount;
}

std::unordered_map < std::string, std::pair<int, int>> AutoTradingSys::getStockInfo() {
	return stockInfo;
}