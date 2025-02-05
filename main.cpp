#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string& name, int age) : name(name), age(age) {}
    virtual void makeSound() const = 0;
    std::string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    virtual ~Animal() {}
};

class LandAnimal : public Animal {
public:
    LandAnimal(const std::string& name, int age) : Animal(name, age) {}
    void walk() const {
        std::cout << name << " is walking on land." << std::endl;
    }
    void makeSound() const override {
        std::cout << "Land animal " << name << " makes a land sound!" << std::endl;
    }
};

class WaterAnimal : public Animal {
public:
    WaterAnimal(const std::string& name, int age) : Animal(name, age) {}
    void swim() const {
        std::cout << name << " is swimming in water." << std::endl;
    }
    void makeSound() const override {
        std::cout << "Water animal " << name << " makes a water sound!" << std::endl;
    }
};

class Cow : public LandAnimal {
public:
    Cow(const std::string& name, int age) : LandAnimal(name, age) {}
    void makeSound() const override {
        std::cout << "Cow " << name << " says: mooooo" << std::endl;
    }
};

class Cat : public LandAnimal {
public:
    Cat(const std::string& name, int age) : LandAnimal(name, age) {}
    void makeSound() const override {
        std::cout << "Cat " << name << " says: meow" << std::endl;
    }
};

class Dog : public LandAnimal {
public:
    Dog(const std::string& name, int age) : LandAnimal(name, age) {}
    void makeSound() const override {
        std::cout << "Dog " << name << " says: woof" << std::endl;
    }
};

class Dolphin : public WaterAnimal {
public:
    Dolphin(const std::string& name, int age) : WaterAnimal(name, age) {}
    void makeSound() const override {
        std::cout << "Dolphin " << name << " says: idk what dolphin says" << std::endl;
    }
};

class Crocodile : public WaterAnimal {
public:
    Crocodile(const std::string& name, int age) : WaterAnimal(name, age) {}
    void makeSound() const override {
        std::cout << "Crocodile " << name << " says: shhhh am am" << std::endl;
    }
};

int main() {
    Cow cow("cow", 5);
    Cat cat("cat", 10);
    Dog dog("dog", 3);
    Dolphin dolphin("dolphin", 7);
    Crocodile crocodile("crocodile", 12);

    cow.makeSound();
    cow.walk();

    cat.makeSound();
    cat.walk();

    dog.makeSound();
    dog.walk();

    dolphin.makeSound();
    dolphin.swim();

    crocodile.makeSound();
    crocodile.swim();

    return 0;
}
