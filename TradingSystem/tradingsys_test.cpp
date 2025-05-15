#include "gmock/gmock.h"
#include "MockDriver.h"
#include "AutoTradingSys.h"
using namespace testing;

TEST(AutoTradingSystem, loginSuccess) {
	MockDriver mockdriver;
	AutoTradingSys tradingsys{ &mockdriver };
	EXPECT_CALL(mockdriver, login("CÁ¶", 123456)).Times(1);
	EXPECT_TRUE(tradingsys.login("CÁ¶", 123456));
}