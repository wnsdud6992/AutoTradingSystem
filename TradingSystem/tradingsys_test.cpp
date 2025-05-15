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

    EXPECT_CALL(mockdriver, login("testuser", 1234)).Times(1);
    EXPECT_CALL(mockdriver, getID()).WillOnce(Return("testuser"));
    EXPECT_CALL(mockdriver, getPwd()).WillOnce(Return(1234));

    bool result = tradingsys.login("testuser", 1234);

    EXPECT_TRUE(result);
}

TEST_F(AutoTradingSystemTest, login_fail_empty_id) {
    bool result = tradingsys.login("", 1234);
    EXPECT_FALSE(result);
}

TEST_F(AutoTradingSystemTest, login_fail_empty_pwd) {
    bool result = tradingsys.login("testuser", 0);
    EXPECT_FALSE(result);
}


TEST_F(AutoTradingSystemTest, buySuccess) {
	EXPECT_CALL(mockdriver, buy("Samsung", 12000, 10)).Times(1);
	tradingsys.buy("Samsung", 12000, 10);
}