#include "gmock/gmock.h"
#include "MockDriver.h"
#include "AutoTradingSys.h"

TEST(AutoTradingSystem, test1) {
	MockDriver mockdriver;
	AutoTradingSys tradingsys{ &mockdriver };
	

}