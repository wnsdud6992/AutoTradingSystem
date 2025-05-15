#include "AutoTradingSys.h"
#include <stdexcept>

AutoTradingSys::AutoTradingSys(IStockerBrockerDriver* driver_, int account) : driver(driver_), userAccount(account)
{
}
bool AutoTradingSys::login(std::string id, int password) {
	return false;
}
void AutoTradingSys::buy(std::string code, int price, int num) {

}
void AutoTradingSys::sell(std::string code, int price, int num) {

}
int  AutoTradingSys::getPrice(std::string code) {
	int price  = driver->getPrice(code);
	if (price == 0) {
		throw  std::runtime_error("invaild code, this code is price 0");
	}
	return price;
}
void AutoTradingSys::buyNiceTiming(std::string code, int price) {

}
void AutoTradingSys::sellNiceTiming(std::string code, int num) {

}