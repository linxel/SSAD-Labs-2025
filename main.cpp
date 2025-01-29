#include <iostream>
#include <algorithm>

class Box {
private:
    unsigned int length;
    unsigned int width;
    unsigned int height;

public:
    Box() : length(0), width(0), height(0) {}
    Box(unsigned int l, unsigned int w, unsigned int h) : length(l), width(w), height(h) {}
    Box(const Box& other) : length(other.length), width(other.width), height(other.height) {}
    Box& operator=(const Box& other) {
        if (this != &other) {
            length = other.length;
            width = other.width;
            height = other.height;
        }
        return *this;
    }
    void display() const {
        std::cout << "Length " << length << ", Width " << width << " Height " << height << std::endl;
    }
    unsigned int getVolume() const {
        return length * width * height;
    }
    void scale(unsigned int scaleValue) {
        length *= scaleValue;
        width *= scaleValue;
        height *= scaleValue;
    }
    bool isBigger(const Box& other) const {
        return getVolume() > other.getVolume();
    }
    bool isSmaller(const Box& other) const {
        return getVolume() < other.getVolume();
    }
    Box operator*(unsigned int scaleValue) const {
        return Box(length * scaleValue, width * scaleValue, height * scaleValue);
    }
    bool operator==(const Box& other) const {
        unsigned int sides1[] = {length, width, height};
        unsigned int sides2[] = {other.length, other.width, other.height};

        std::sort(sides1, sides1 + 3);
        std::sort(sides2, sides2 + 3);

        return sides1[0] == sides2[0] && sides1[1] == sides2[1] && sides1[2] == sides2[2];
    }
};

class Cube {
private:
    unsigned int side;

public:
    // Default
    Cube() : side(0) {}
    // Conversion
    Cube(unsigned int s) : side(s) {}
    // Copy
    Cube(const Cube& other) : side(other.side) {}

    // Assignment operator
    Cube& operator=(const Cube& other) {
        if (this != &other) {
            side = other.side;
        }
        return *this;
    }
    void display() const {
        std::cout << "Side: " << side << std::endl;
    }
    unsigned int getVolume() const {
        return side * side * side;
    }
    operator Box() const {
        return Box(side, side, side);
    }
};

int main() {
    // Default
    Box box1;
    box1.display();
    // Conversion
    Box box2(10, 20, 30);
    box2.display();
    // Copy
    Box box3 = box2;
    box3.display();
    // Assignment operator
    Box box4;
    box4 = box2;
    box4.display();
    std::cout << "Volume box2 " << box2.getVolume() << std::endl;
    Box box5 = box2 * 2;
    box5.display();
    std::cout << "box2 > box3 " << (box2.isBigger(box3) ? "Yes" : "No") << std::endl;
    std::cout << "box2 < box3 " << (box2.isSmaller(box3) ? "Yes" : "No") << std::endl;
    Box box6(20, 10, 30);
    std::cout << "box2 = box6 " << (box2 == box6 ? "Yes" : "No") << std::endl;
    Cube cube1(5);
    cube1.display();
    std::cout << "Volume cube1 " << cube1.getVolume() << std::endl;
    Box box7 = cube1;
    box7.display();

    return 0;
}
