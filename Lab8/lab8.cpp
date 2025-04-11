//Soko
#include <iostream>
#include <cmath>
using namespace std;

// Shape классын тодорхойлолт
class Shape {
protected:
    string name;
    static int objectCount; // бүх Shape объектын тоо

public:
    Shape(string n) : name(n) {
        this->objectCount++;
    }

    virtual ~Shape() {
        this->objectCount--; // Объект устах үед тоо буурна
    }

    static void setObjectCount(int count) {
        Shape::objectCount = count;
    }

    static int getObjectCount() {
        return Shape::objectCount;
    }

    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

    virtual void print() {
        cout << "Shape: " << this->name << endl;
        cout << "Area: " << this->getArea() << ", Perimeter: " << this->getPerimeter() << endl;
    }
};

// Статик хувьсагчийн анхны утга
int Shape::objectCount = 0;

//zulaaa
// 2DShape
class TwoD : public Shape {
protected:
    double x, y;
public:
    TwoD(string n, double xCoord, double yCoord) : Shape(n), x(xCoord), y(yCoord) {}

    // Жинхэнэ хийсвэр функц дахин зарлаж байна
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};
//end

// Circle
class Circle : public TwoD {
private:
    double radius;
public:
    Circle(double xCoord, double yCoord, double r) : TwoD("Circle", xCoord, yCoord), radius(r) {}
    
    double getArea() { 
        return M_PI * this->radius * this->radius; 
    }

    double getPerimeter() { 
        return 2 * M_PI * this->radius; 
    }

    void print() {
        this->Shape::print();
        cout << "  Center: (" << this->x << ", " << this->y << "), Radius: " << this->radius << endl;
    }
};


// Square
class Square : public TwoD {
private:
    double side;
    double x2, y2, x3, y3, x4, y4;
public:
    Square(double xCoord, double yCoord, double s) : TwoD("Square", xCoord, yCoord), side(s) {
        this->x2 = this->x + this->side; this->y2 = this->y;
        this->x3 = this->x; this->y3 = this->y - this->side;
        this->x4 = this->x + this->side; this->y4 = this->y - this->side;
    }

    double getArea() { 
        return this->side * this->side; 
    }

    double getPerimeter() { 
        return 4 * this->side; 
    }

    void print() {
        this->Shape::print();
        cout << "  Vertices: " << endl;
        cout << "    Top Left: (" << this->x << ", " << this->y << ")" << endl;
        cout << "    Top Right: (" << this->x2 << ", " << this->y2 << ")" << endl;
        cout << "    Bottom Left: (" << this->x3 << ", " << this->y3 << ")" << endl;
        cout << "    Bottom Right: (" << this->x4 << ", " << this->y4 << ")" << endl;
    }
};


// Triangle
class Triangle : public TwoD {
private:
    double side;
    double x2, y2, x3, y3;
public:
    Triangle(double xCoord, double yCoord, double s) : TwoD("Triangle", xCoord, yCoord), side(s) {
        this->x2 = this->x - this->side / 2; this->y2 = this->y - sqrt(3) / 2 * this->side;
        this->x3 = this->x + this->side / 2; this->y3 = this->y - sqrt(3) / 2 * this->side;
    }

    double getArea() { 
        return (sqrt(3) / 4) * this->side * this->side; 
    }

    double getPerimeter() { 
        return 3 * this->side; 
    }

    void print() {
        this->Shape::print();
        cout << "  Vertices: " << endl;
        cout << "    Top: (" << this->x << ", " << this->y << ")" << endl;
        cout << "    Left: (" << this->x2 << ", " << this->y2 << ")" << endl;
        cout << "    Right: (" << this->x3 << ", " << this->y3 << ")" << endl;
    }
};


// Bubble sort
void bubbleSort(Shape* shapes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (shapes[j]->getArea() > shapes[j + 1]->getArea()) {
                swap(shapes[j], shapes[j + 1]);
            }
        }
    }
}

int main() {
    // Объектууд үүсгэнэ
    Circle c(0, 0, 5);
    Square s(1, 1, 4);
    Triangle t(2, 2, 3);
    Circle c2(0, 0, 2);
    Square s2(1, 1, 6);
    Triangle t2(3, 3, 5);

    Shape* shapes[6] = { &c, &c2, &s, &s2, &t, &t2 };

    bubbleSort(shapes, 6);

    cout << "Sorted shapes by area:" << endl;
    for (int i = 0; i < 6; i++) {
        shapes[i]->print();
    }

    // Статик функц ашиглан нийт тоог хэвлэнэ
    cout << "\nTotal number of Shape objects: " << Shape::getObjectCount() << endl;

    // Жишээ болгож утга оноож болно
    Shape::setObjectCount(100);
    cout << "Manually set count to 100. New count: " << Shape::getObjectCount() << endl;

//ghghghhhhhg
//commentttt shuuuu
    return 0;
}
//mickka comm biciw haha
