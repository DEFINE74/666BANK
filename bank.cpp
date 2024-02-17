#include <iostream> 
#include <cmath> 

using namespace std;

class BankClient {
private:
	double finalMoney;

public:
	double money;
	float percent;
	float time;

	void SetFinalMoney(double money) {
		finalMoney = money;
	}

	double GetFinalMoney() {
		return finalMoney;
	}
};

double InitialDeposit(double finalMoney, float percent, float time) {
	double initialAmount = finalMoney / pow(1 + percent / 100, time / 12);
	return initialAmount;
}
double MoneyEnter(double& enteredMoney) {
	cout << "Введите кол-во денег: " << endl;
	cin >> enteredMoney;
	return enteredMoney;
}
float MonthsEnter(float& months) {
	cout << "Введите кол-во месяцев (до 12): ";
	cin >> months;
	return months;
}
float PercentEnter(float& percents) {
	cout << "Введите кол-во процентов (до 15): ";
	cin >> percents;
	return percents;
}
int main() {
	setlocale(LC_ALL, "ru");
	cout << "IVAN_BANK 1.0\n\n\n\n";
	double desiredMoney;
	float months;
	float moneyPercent = 0;

	desiredMoney = MoneyEnter(desiredMoney);

	while (true) {
		months = MonthsEnter(months);
		if (months < 0 || months > 12) {
			cout << "\nПридерживайтесь установленных рамок!";
			continue;
		}
		else {
			break;
		}
	}

	while (true) {
		moneyPercent = PercentEnter(moneyPercent);
		if (moneyPercent < 0 || moneyPercent > 15) {
			cout << "\nПридерживайтесь установленных рамок!";
			continue;
		}
		else {
			break;
		}
	}

	double initialAmount = InitialDeposit(desiredMoney, moneyPercent, months);

	cout << "Чтобы получить " << desiredMoney << " рублей через " << months << " месяцев с процентной ставкой " << moneyPercent << "%, вам нужно вложить: " << initialAmount << " рублей" << endl;

	return 0;
}
