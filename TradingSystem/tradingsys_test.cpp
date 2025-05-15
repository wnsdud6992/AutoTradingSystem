#include "gmock/gmock.h"
#include "MockDriver.h"
#include "AutoTradingSys.h"
using namespace testing;

class AutoTradingSystemTest : public Test {
public:
	MockDriver mockdriver;
	AutoTradingSys tradingsys{ &mockdriver, initAccount };
private:
	const int initAccount = 1'000'000;
};

TEST_F(AutoTradingSystemTest, loginSuccess) {
	EXPECT_CALL(mockdriver, login("CÁ¶", 123456)).Times(1);
	EXPECT_TRUE(tradingsys.login("CÁ¶", 123456));
}

TEST_F(AutoTradingSystemTest, buySuccess) {
	EXPECT_CALL(mockdriver, buy("Samsung", 12000, 10)).Times(1);
	tradingsys.buy("Samsung", 12000, 10);
}

TEST_F(AutoTradingSystemTest, sellSuccess) {
	tradingsys.buy("Samsung", 12000, 10);

	EXPECT_CALL(mockdriver, sell("Samsung", 11000, 3)).Times(1);
	EXPECT_CALL(mockdriver, sell("Samsung", 10500, 2)).Times(1);
	tradingsys.buy("Samsung", 11000, 3);
	tradingsys.buy("Samsung", 10500, 2);
}

TEST_F(AutoTradingSystemTest, getPriceSuccess) {
	EXPECT_CALL(mockdriver, getPrice("Samsung")).Times(1)
	 .WillRepeatedly(Return(12000));
	EXPECT_EQ(12000, mockdriver.getPrice("Samsung"));
}