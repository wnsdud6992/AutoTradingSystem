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
	EXPECT_CALL(mockdriver, login("C조", 123456)).Times(1);
	EXPECT_TRUE(tradingsys.login("C조", 123456));
}

TEST_F(AutoTradingSystemTest, buySuccess) {
	int prevQuntity= tradingsys.getStockInfo()["Samsung"].second;
	int prevAccount = tradingsys.getAccout();
	EXPECT_CALL(mockdriver, buy("Samsung", 12000, 10)).Times(1);
	
	tradingsys.buy("Samsung", 12000, 10);

	//buy가 잘됐는지 확인하기 (stock 정보)
	int currentQuntity = tradingsys.getStockInfo()["Samsung"].second;
	EXPECT_EQ(prevQuntity + 10, currentQuntity);

	//account 정보도 확인하기 
	int currentAccount = tradingsys.getAccout();
	EXPECT_EQ(prevAccount + 12000 * 10, currentAccount);
}

TEST_F(AutoTradingSystemTest, sellSuccess) {
	tradingsys.buy("Samsung", 12000, 10);

	EXPECT_CALL(mockdriver, sell("Samsung", 11000, 3)).Times(1);
	EXPECT_CALL(mockdriver, sell("Samsung", 10500, 2)).Times(1);
	
	tradingsys.buy("Samsung", 11000, 3);
	tradingsys.buy("Samsung", 10500, 2);


}