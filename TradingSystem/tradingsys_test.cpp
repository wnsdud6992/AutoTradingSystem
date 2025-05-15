#include "gmock/gmock.h"
#include "MockDriver.h"
#include "AutoTradingSys.h"
using namespace testing;

class AutoTradingSystemTest : public Test {
public:
	NiceMock<MockDriver> mockdriver;
	NiceMock<AutoTradingSys> tradingsys{ &mockdriver, initAccount };
private:
	const int initAccount = 1'000'000;
};

TEST_F(AutoTradingSystemTest, DISABLED_loginSuccess) {
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
	EXPECT_CALL(mockdriver, sell("samsung",_,_)).Times(1);
	tradingsys.buy("samsung", 12000, 10);
	tradingsys.sell("samsung", 11000, 3);
}

TEST_F(AutoTradingSystemTest, sellFailBecuseOfNoCode) {
	EXPECT_THROW(tradingsys.sell("samsung", 11000, 3), std::exception);
}

TEST_F(AutoTradingSystemTest, sellFailBecuseOfNotEnoughQuantity) {
	tradingsys.buy("samsung", 12000, 10);
	
	EXPECT_THROW(tradingsys.sell("samsung", 11000, 11), std::exception);
}

