#include "AutoTradingSys.h"

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
	return 0;
}
void AutoTradingSys::buyNiceTiming(std::string code, int price) {

}
void AutoTradingSys::sellNiceTiming(std::string code, int num) {

}