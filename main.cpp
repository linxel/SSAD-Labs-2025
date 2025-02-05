#include <iostream>
#include <vector>
class Animal
{
protected:
    std::string name;
    int age;

public:
    Animal(const std::string &name, int age)
        : name(name), age(age)
    {}
    virtual void makeSound() const
    {
        std::cout << "Animal sound" << std::endl;
    }
    virtual ~Animal() = default;
};
class LandAnimal: virtual public Animal
{
public:
    LandAnimal(const std::string &name, int age)
        : Animal(name, age)
    {}
    virtual void walk() const
    {
        std::cout << name << " is walking on land." << std::endl;
    }
    void makeSound() const override
    {
        std::cout << name << " makes a land animal sound." << std::endl;
    }
};
class WaterAnimal: virtual public Animal
{
public:
    WaterAnimal(const std::string &name, int age)
        : Animal(name, age)
    {}
    virtual void swim() const
    {
        std::cout << name << " is swimming in water." << std::endl;
    }

    void makeSound() const override
    {
        std::cout << name << " makes a water animal sound." << std::endl;
    }
};
class Lion: public LandAnimal
{
public:
    Lion(const std::string &name, int age)
        : Animal(name, age), LandAnimal(name, age)
    {}

    void walk() const override
    {
        std::cout << name << " the lion is walking majestically." << std::endl;
    }

    void makeSound() const override
    {
        std::cout << name << " says rrrrrr!" << std::endl;
    }
};
class Dolphin: public WaterAnimal
{
public:
    Dolphin(const std::string &name, int age)
        : Animal(name, age), WaterAnimal(name, age)
    {}
    void swim() const override
    {
        std::cout << name << " the dolphin is swimming good." << std::endl;
    }
    void makeSound() const override
    {
        std::cout << name << "says ... idk " << std::endl;
    }
};


class Frog: public LandAnimal, public WaterAnimal
{
public:
    Frog(const std::string &name, int age)
        : Animal(name, age), LandAnimal(name, age), WaterAnimal(name, age)
    {}
    void makeSound() const override
    {
        std::cout << name << " the frog croaks!" << std::endl;
    }
    void walk() const override
    {
        std::cout << name << " the frog is hopping on land." << std::endl;
    }
    void swim() const override
    {
        std::cout << name << " the frog is swimming in water." << std::endl;
    }
};
int main()
{
    std::vector<Animal *> animals;
    Lion lion("lion", 5);
    Dolphin dolphin("dolphin", 10);
    Frog frog("frog", 2);
    animals.push_back(&lion);
    animals.push_back(&dolphin);
    animals.push_back(&frog);
    for (const auto &animal: animals) {
        animal->makeSound();
        if (auto landAnimal = dynamic_cast<LandAnimal *>(animal)) {
            landAnimal->walk();
        }
        if (auto waterAnimal = dynamic_cast<WaterAnimal *>(animal)) {
            waterAnimal->swim();
        }
    }

    return 0;
}
