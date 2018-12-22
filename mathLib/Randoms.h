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
		void seed(unsigned int value);

		//If you have previously seeded the value, use this
		void reseed();
	};
}