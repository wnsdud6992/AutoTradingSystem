#include "gmock/gmock.h"
#include "MockDriver.h"
#include "AutoTradingSys.h"
using namespace testing;

class AutoTradingSystemTest : public Test {
public:
	MockDriver mockdriver;
	AutoTradingSys tradingsys{ &mockdriver };
};

TEST_F(AutoTradingSystemTest, loginSuccess) {
	EXPECT_CALL(mockdriver, login("CÁ¶", 123456)).Times(1);
	EXPECT_TRUE(tradingsys.login("CÁ¶", 123456));
}

TEST_F(AutoTradingSystemTest, buySuccess) {
	EXPECT_CALL(mockdriver, buy("Samsung", 12000, 10)).Times(1);
	tradingsys.buy("Samsung", 12000, 10);
}