#pragma once

#include <random>

const int TIME_START = 0;    // Time doors are open
const int TIME_OFFICE = 10;  // Time ticket office is open to hand out tickets
const int TIME_END = 50;     // Time no more customers are allowed into the line
const int GROUP_SIZE = 5;    // Maximum size of group buying tickets

struct customer
{
	int arrival;
	int number;
};
