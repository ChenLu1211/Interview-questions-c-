#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

/*
3.6 Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
that type). They cannot select which specific animal they would like. Create the data structures to
maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
and dequeueCat.



*/

enum animalType { Dog, Cat };

class Animal {
	
	animalType type;
	time_t insertTime;

public:
	Animal(animalType type)
	{
		this->type = type;
		time(&insertTime);
	}

	time_t getTime()
	{
		return insertTime;
	}

};

class AnimalShelter {

public:
	list<Animal*> dogs;
	list<Animal*> cats;

	void enqueue(animalType type)
	{
		Animal* newA = new Animal(type);
		switch (type)
		{
		case Dog:
			dogs.push_back(newA);
			break;
		case Cat:
			cats.push_back(newA);
			break;
		default:
			throw "error in type";
			break;
		}
	}

	Animal* dequeueAny() {
		Animal* lastDog = NULL; Animal* lastCat = NULL;
		time_t dogT = 0, catT = 0;

		if (dogs.size() || cats.size())
		{
			if (dogs.size() > 0)
			{
				lastDog = dogs.back();
				dogT = lastDog->getTime();
			}

			if (cats.size() > 0)
			{
				lastCat = cats.back();
				catT = lastCat->getTime();
			}

			if (catT > dogT)
			{
				cats.pop_back();
				return lastCat;
			}
			else {
				dogs.pop_back();
				return lastDog;
			}
			return NULL;
		}
	}

	Animal* dequeueDog() {
		if (dogs.size())
		{
			Animal* last = dogs.back();
			dogs.pop_back();
			return last;
		}
		return NULL;
	}

	Animal* dequeueCat() {
		if (cats.size())
		{
			Animal* last = cats.back();
			cats.pop_back();
			return last;
		}
		return NULL;
	}

	~AnimalShelter()
	{
	  for (auto d : dogs)
		{
			free(d);
		}
		for (auto c : cats)
		{
			free(c);
		}
	}

};

int main()
{
	Animal* curr;
	AnimalShelter* shelter = new AnimalShelter;
	shelter->enqueue(animalType(Dog));
	shelter->enqueue(animalType(Dog));
	shelter->enqueue(animalType(Cat));

	curr = shelter->dequeueAny();
	curr = shelter->dequeueDog();
	curr = shelter->dequeueCat();
	curr = shelter->dequeueAny();

	delete shelter;
	return 0;
}
