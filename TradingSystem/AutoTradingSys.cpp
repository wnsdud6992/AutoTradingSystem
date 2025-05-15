#include "AutoTradingSys.h"
#include "iostream"

AutoTradingSys::AutoTradingSys(IStockerBrockerDriver* driver_, int account) : driver(driver_), userAccount(account)
{
}
bool AutoTradingSys::login(std::string id, int password) {
	return false;
}
void AutoTradingSys::buy(std::string code, int price, int num) {
	if (userAccount < price * num) {
		std::cout << "not enough money.\n";
		throw std::exception();
	}

	driver->buy(code, price ,num);
	userAccount -= price * num;

	if (stockInfo.find(code) != stockInfo.end()) {
		stockInfo[code].second += num;
	}
	else {
		stockInfo.insert({ code, {price, num} });
	}
}
void AutoTradingSys::sell(std::string code, int price, int num) {

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