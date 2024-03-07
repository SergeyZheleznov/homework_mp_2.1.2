//Очередь клиентов
//Вам нужно создать приложение, которое имитирует очередь в окошко.Для этого нужно создать два потока, работающие с одной разделяемой переменной.
//Первый поток имитирует клиента : раз в секунду он обращается к счётчику клиентов и увеличивает его на 1. Максимальное количество клиентов должно быть параметризировано.
//Второй поток имитирует операциониста : раз в 2 секунды он обращается к счётчику клиентов и уменьшает его на 1. «Операционист» работает до последнего клиента.


#include <iostream>
#include <thread>
#include <windows.h>
#include <chrono>
#include <vector>

using namespace std::chrono_literals;

int x = 0;

namespace {
	void func1()
	{
		std::cout << "Начальное количество клиентов в очереди1  " << x << std::endl;
		double t1 = 0;
		std::cout << "Время на часах1 в секундах   " << t1 << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			
			std::this_thread::sleep_for(1000ms);
			
			t1 = t1 + 1;
			std::cout << "Время на часах1 в секундах   " << t1 << std::endl;
			std::cout << "количество подошедших клиентов1  " << i + 1 << std::endl;
			x = x + 1;
			std::cout << "Количество клиентов1 в очереди в данный момент " << x << std::endl;
		}
	}

	void func2()
	{
		std::cout << "Начальное количество клиентов в очереди2  " << x << std::endl;
		double t2 = 0;
		std::cout << "Время на часах2 в секундах   " << t2 << std::endl;
		std::this_thread::sleep_for(500ms);
		t2 = t2 + 0.5;
		std::cout << "Время на часах2 в секундах   " << t2 << std::endl;
		for (int i = 1; i <= 10; ++i)
		{
			std::this_thread::sleep_for(2000ms);
			t2 = t2 + 2;
			std::cout << "Время на часах2 в секундах   " << t2 << std::endl;
			std::cout << "количество клиентов2, обслуженных кассиром  " << i << std::endl;
			x = x - 1;
			std::cout << "Количество клиентов2 в очереди в данный момент (у кассира) " << x << std::endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	std::thread t1(func1);
	std::thread t2(func2);
	t1.join();
	t2.join();

	return 0;
}