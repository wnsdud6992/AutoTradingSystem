#include "AutoTradingSys.h"
AutoTradingSys::AutoTradingSys(IStockerBrockerDriver* driver_) : driver(driver_)
{
}
bool AutoTradingSys::login(std::string id, int password) {
	if (id.empty() || password <= 0)
		return false;

	driver->login(id, password);

	if (driver->getID() == id && driver->getPwd() == password) {
		return true;
	}
	return false;
}
std::string AutoTradingSys::getID() {
	return this->id;
}
int AutoTradingSys::getPwd() {
	return this->pwd;
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