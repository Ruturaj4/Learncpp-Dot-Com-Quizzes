// friendFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Humidity;

class Temperature
{
	int m_temp;
public:
	Temperature(int temp = 0)
	{
		m_temp = temp;
	}
	friend void weather(const Temperature &temperature, const Humidity &humidity);
};

class Humidity
{
	int m_humidity;
public:
	Humidity(int humidity = 0)
	{
		m_humidity = humidity;
	}
	friend void weather(const Temperature &temperature, const Humidity &humidity);
};

void weather(const Temperature &temperature, const Humidity &humidity)
{
	std::cout << "The temperature is: " << temperature.m_temp << " and the humidity is: " << humidity.m_humidity << '\n';
}

int main()
{
	Humidity humidity{ 10 };
	Temperature temperature{ 40 };
	weather(temperature, humidity);
	//To keep the cmd open
	while (true);
	return 0;
}