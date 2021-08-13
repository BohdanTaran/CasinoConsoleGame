#include "pch.h"

int main()
{
	// Установка русского языка
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Переменные
	int numUser, randomNum;
	int mb_no, mb_yes, mb_balance;
	int balanceUser, rateUser;
	char numInfo_no[255], numInfo_yes[255], rateBalance[255];

	// Рандомное число
	srand(time(0));

	// Ложим рандомное число в переменную
	randomNum = rand() % 5 + 1;

	// Заголовок программы
	cout << "Приложение: Консольная рулетка" << "\n \n";

	// Ввод баланса пользователя
	againBalance: cout << "Введите свой баланс (Минимальный баланс 10) -> ";
	cin >> balanceUser;

	// Условие для проверки баланса и запрет если баланс меньше чем ноль
	if (balanceUser < 0)
	{
		MessageBoxA(0, "Такого баланса быть не может!", "Информация о балансе!", MB_OK | MB_ICONINFORMATION);
		goto againBalance;
	}
	
	// Запрет ввода баланса если баланс меньше 10
	if (balanceUser < 10)
	{
		MessageBoxA(0, "Минимальный баланс 10!", "Информация о балансе!", MB_OK | MB_ICONINFORMATION);
		goto againBalance;
	}

	// Ввод ставки пользователя
	againRate: cout << "Введите свою ставку (Минимальная ставка 1) -> ";
	cin >> rateUser;

	// Запрет на ставку которая меньше 0
	if (rateUser < 1)
	{
		MessageBoxA(0, "Такой ставки быть не может!", "Информация!", MB_OK | MB_ICONINFORMATION);
		goto againRate;
	}

	// Условие на запрет если ставка больше, чем баланс
	if (rateUser > balanceUser)
	{
		// Основное сообщение для MessageBox
		sprintf_s(rateBalance, "Ставка не может быть больше баланса! %s%u", "\n\nВаш баланс: ", balanceUser);

		MessageBoxA(0, rateBalance, "Информация о балансе!", MB_OK | MB_ICONINFORMATION);
		goto againRate;
	}

	// Ввод числа пользователя
	againNum: cout << "Введите своё число от 1 до 5 -> ";
	cin >> numUser;
	
	// Запрет на ввод всех чисел кроме 1, 2, 3, 4, 5
	if (numUser > 5 || numUser < 1)
	{
		MessageBoxA(0, "Введите число от 1 до 5!", "Информация!", MB_OK | MB_ICONINFORMATION);
		goto againNum;
	}
	
	// Запрет на ввод числа, которое меньше нуля
	if (numUser < 0)
	{
		MessageBoxA(0, "Число не может быть меньше нуля!", "Информация!", MB_OK | MB_ICONINFORMATION);
		goto againNum;
	}

	// Проверка числа и вывод результата если число не совпало
	if (numUser != randomNum)
	{
		// Вычисление баланса
		balanceUser = balanceUser - rateUser;

		// Основное сообщение для MessageBox
		sprintf_s(numInfo_no, "Вы не отгадали число, ваше число было %u%s %u%s", randomNum, "\n\nВаш баланс: ", balanceUser, "\nЖелаете повторить ещё раз?");

		// Вывод сообщения о результате если пользователь не отгадал
		mb_no = MessageBoxA(0, numInfo_no, "Вы проиграли!", MB_YESNO | MB_ICONERROR);

		// Условие если баланс меньше или равен нулю
		if (balanceUser <= 0)
		{
			// Уведомление об нулевом балансе и желании его поплонить
			mb_balance = MessageBoxA(0, "Ваш баланс исчерпан! Желаете пополнить баланс?", "Информация о балансе", MB_YESNO | MB_ICONERROR);

			switch (mb_balance)
			{
			case IDYES:
				goto againBalance;
				break;

			case IDNO:
				cout << '\n';

				// Вывод о завершении
				cout << "Приложение закончило свою работу!" << "\n \n";
				break;
			}
		}

		// Последующие действия пользователя
		switch (mb_no)
		{
		case IDYES:
			randomNum = rand() % 5 + 1;
			goto againRate;
			goto againNum;
			break;

		case IDNO:
			cout << '\n';

			// Вывод о завершении
			cout << "Приложение закончило свою работу!" << "\n \n";
			break;
		}
	}

	// Проверка числа и вывод результата если число совпало
	if (numUser == randomNum)
	{
		// Вычисление баланса
		balanceUser = balanceUser + (rateUser + rateUser);

		// Основное сообщение для MessageBox
		sprintf_s(numInfo_yes, "Вы отгадали число, ваше число было %u%s %u%s", randomNum, "\n\nВаш баланс: ", balanceUser, "\nЖелаете повторить ещё раз?");

		// Вывод сообщения о результате если пользователь отгадал
		mb_yes = MessageBoxA(0, numInfo_yes, "Операция успешна!", MB_YESNO | MB_ICONINFORMATION);

		// Последующие действия пользователя
		switch (mb_yes)
		{
		case IDYES:
			randomNum = rand() % 5 + 1;
			goto againRate;
			goto againNum;
			break;

		case IDNO:		
			cout << '\n';

			// Вывод о завершении
			cout << "Приложение закончило свою работу!" << "\n \n";
			break;
			}	
		}

	// Задержка консоли
	system("pause");

	return 0;
}