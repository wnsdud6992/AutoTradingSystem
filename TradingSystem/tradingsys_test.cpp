#include "gmock/gmock.h"
#include "MockDriver.h"
#include "AutoTradingSys.h"
using namespace testing;

class AutoTradingSystemTest : public Test {
private:
	const int initAccount = 1'000'000;

public:
	MockDriver mockdriver;
	AutoTradingSys tradingsys{ &mockdriver, initAccount };
};

TEST_F(AutoTradingSystemTest, buySuccess) {
	int prevQuntity= tradingsys.getStockInfo()["Samsung"].second;
	int prevAccount = tradingsys.getAccout();
	EXPECT_CALL(mockdriver, buy("Samsung", 12000, 10)).Times(1);
	
	tradingsys.buy("Samsung", 12000, 10);

	int currentQuntity = tradingsys.getStockInfo()["Samsung"].second;
	EXPECT_EQ(prevQuntity + 10, currentQuntity);

	int currentAccount = tradingsys.getAccout();
	EXPECT_EQ(prevAccount - 12000 * 10, currentAccount);
}

TEST_F(AutoTradingSystemTest, buyNotCalledWhenInsufficientFunds) {	
	EXPECT_THROW(tradingsys.buy("Samsung", 13000, 1000), std::exception);
}