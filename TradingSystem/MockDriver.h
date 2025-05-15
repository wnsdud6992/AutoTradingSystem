#pragma once
#include <string>
#include "IStockerBrockerDriver.h"
#include "gmock/gmock.h"

class MockDriver : public IStockerBrockerDriver {
	MOCK_METHOD(void, login, (std::string, int), (override));
	MOCK_METHOD(void, buy, (std::string, int, int), (override));
	MOCK_METHOD(void, sell, (std::string, int, int), (override));
	MOCK_METHOD(int, getPrice, (std::string), (override));
};
