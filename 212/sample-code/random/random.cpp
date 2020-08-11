#include "random.h"

// assume rand is seeded for this function is called
// returns a string with two initials
string initialsRandom()
{
	string initials = "";
	initials += alphabet[rand()%26];
	initials += alphabet[rand()%26];

	return initials;
}