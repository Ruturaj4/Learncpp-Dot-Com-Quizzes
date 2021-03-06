// struct_advertising.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct Advertising
{
	//number od ads shown
	int adsShown;
	//percentage of ads clicked
	double adsClicked;
	//average earnings from each ads that are clicked
	double avgEarningsPerAd;
};

//outputs everything
void moneyMade(Advertising ad)
{
	std::cout << "Number of ads shown: " << ad.adsShown << "\n";
	std::cout << "Percentage of ads clicked: " << ad.adsClicked << "\n";
	std::cout << "Average earnings per ad: " << ad.avgEarningsPerAd << "\n";
	double dollarsMade = (ad.adsClicked / 100) * ad.adsShown * ad.avgEarningsPerAd;
	std::cout << "I made $" << dollarsMade << " for that day";
}

int main()
{
	using std::cout;
	using std::cin;
	Advertising ad{0, 0.0, 0.0};
	cout << "Please enter the number of ads shown: ";
	cin >> ad.adsShown;
	cout << "Please enter the percentage of ads clicked: ";
	cin >> ad.adsClicked;
	cout << "Please enter the average earnings per ad: ";
	cin >> ad.avgEarningsPerAd;
	moneyMade(ad);
	//To keep cmd open
	int x;
	cin >> x;
    return 0;
}

