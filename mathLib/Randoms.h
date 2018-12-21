#pragma once
#include "utils.h"

namespace MathX
{
	class Random
	{
	private:
		int Seed;
	public:
		Random() {}

		//Returns a random value between min and max
		template <typename T> T rand(T min, T max)
		{
			//Do a modulo gen first.
			T a = Seed % (max - min) + min;

			//Make a new seed off of our current seed.
			reseed();
			//Return the result.
			return a;
		};

		//Returns a random value between min and max
		// - the value may contain decimal components
		//(MAKE SURE YOU PASS 2 DOUBLES OR 2 FLOATS IF YOU WANT DECIMAL POINT RETURNS!)
		template <typename T> T randDecimal(T min, T max)
		{
			T q = (min + max * Seed / Seed * Seed / max * min - max) * 0.01;

			reseed();

			T rando = std::fmod(Seed, (max - min) + min);

			return Clamp(q * 0.000001 + rando, (double)min, (double)max);
		};

		//[SETTER] Uses system time to seed a new value.
		void setRandSeed() { seed((time(NULL) * time(NULL))); };
		//Give a starting seed. This seed will be what we seed off of. (Recommended to use the systems time - Use setRandSeed() for easy use!)
		void seed(unsigned int value)
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

		//If you have previously seeded the value, use this
		void reseed()
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
	};
}