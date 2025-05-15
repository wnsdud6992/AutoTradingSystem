// �� �ҽ��ڵ�� �׸����ǿ��� �����Ǵ� �ҽ��ڵ��̸�, �б��������� �����˴ϴ�.
// �ҽ��ڵ带 ���Ƿ� ������ �� �� �����ϴ�.

#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

class NemoAPI {
public:
	void certification(std::string ID, std::string pass) {
		std::cout << "[NEMO]" << ID << " login GOOD\n";
	}

	void purchasingStock(std::string stockCode, int price, int count) {
		std::cout << "[NEMO]" << stockCode << " buy stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	void sellingStock(std::string stockCode, int price, int count) {
		std::cout << "[NEMO]" << stockCode << " sell stock ( price : " << price << " ) * ( count : " << count << ")\n";
	}

	int getMarketPrice(std::string stockCode, int minute) {
		//minute ms�� ���� ���Ű� �Ǵ� ��� (�ּ� 1 ms)
		if (minute <= 0) minute = 1;
		Sleep(minute);
		std::srand(std::time(NULL));
		int ret = std::rand() % 10 * 100 + 5000;
		return ret;
	}
};