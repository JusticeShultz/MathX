#include "Randoms.h"

namespace MathX
{
	void Random::seed(unsigned int value)
	{
		Seed = value;

		//Square it.
		Seed = Seed * Seed;

		//Parse the seed down to 6 characters.
		std::string temp = std::to_string(Seed);

		//Make sure the seed is the required size.
		while (temp.size() < 9)
		{
			//If it's not then square it and set it until it is.
			Seed = Seed * Seed;
			temp = std::to_string(Seed);
		}

		//Prune the seed down to 9 digits.
		while (temp.size() > 9) temp.pop_back();

		//Prune the front 3 digits of the seed.
		std::string temp2;

		//Push forward the last 6 digits.
		for (int i = 2; i < temp.size(); ++i)
		{
			temp2.push_back(temp[i]);
		}

		//Set the seed to the result.
		Seed = std::stoi(temp2);
	};

	void Random::reseed()
	{
		//Square it.
		Seed = Seed * Seed;

		//Parse the seed down to 6 characters.
		std::string temp = std::to_string(Seed);

		//Prune the seed down to 9 digits.
		while (temp.size() > 9) temp.pop_back();

		//Prune the front 3 digits of the seed.
		std::string temp2;

		//Push forward the last 6 digits.
		for (int i = 2; i < temp.size(); ++i)
		{
			temp2.push_back(temp[i]);
		}

		//Set the seed to the result.
		Seed = std::stoi(temp2);
	};
}