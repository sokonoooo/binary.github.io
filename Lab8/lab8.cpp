#include <iostream>
#include <cmath>
using namespace std;

// 🟦 Shape классын тодорхойлолт
class Shape {
protected:
    string name;
    static int objectCount; // бүх Shape объектын тоо

public:
    Shape(string n) : name(n) {
        objectCount++;
    }

    virtual ~Shape() {
        objectCount--;
    }


    static void setObjectCount(int count) {
        objectCount = count;
    }

    static int getObjectCount() {
        return objectCount;
    }

    // Хийсвэр функцууд
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

    virtual void print() {
        cout << "Shape: " << name << endl;
        cout << "Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

// Статик хувьсагчийн анхны утга
int Shape::objectCount = 0;

// 🟦 2DShape класс
class TwoD : public Shape {
protected:
    double x, y;
public:
    TwoD(string n, double xCoord, double yCoord) : Shape(n), x(xCoord), y(yCoord) {}
};

// 🟢 Circle класс
class Circle : public TwoD {
private:
    double radius;
public:
    Circle(double xCoord, double yCoord, double r) : TwoD("Circle", xCoord, yCoord), radius(r) {}

    double getArea() override {
        return M_PI * radius * radius;
    }

    double getPerimeter() override {
        return 2 * M_PI * radius;
    }

    void print() override {
        Shape::print();
        cout << "  Center: (" << x << ", " << y << "), Radius: " << radius << endl;
    }
};

// 🟡 Square класс
class Square : public TwoD {
private:
    double side;
    double x2, y2, x3, y3, x4, y4;
public:
    Square(double xCoord, double yCoord, double s) : TwoD("Square", xCoord, yCoord), side(s) {
        x2 = x + side; y2 = y;
        x3 = x; y3 = y - side;
        x4 = x + side; y4 = y - side;
    }

    double getArea() override {
        return side * side;
    }

    double getPerimeter() override {
        return 4 * side;
    }

    void print() override {
        Shape::print();
        cout << "  Vertices: " << endl;
        cout << "    Top Left: (" << x << ", " << y << ")" << endl;
        cout << "    Top Right: (" << x2 << ", " << y2 << ")" << endl;
        cout << "    Bottom Left: (" << x3 << ", " << y3 << ")" << endl;
        cout << "    Bottom Right: (" << x4 << ", " << y4 << ")" << endl;
    }
};

// 🔺 Triangle класс
class Triangle : public TwoD {
private:
    double side;
    double x2, y2, x3, y3;
public:
    Triangle(double xCoord, double yCoord, double s) : TwoD("Triangle", xCoord, yCoord), side(s) {
        x2 = x - side / 2; y2 = y - sqrt(3) / 2 * side;
        x3 = x + side / 2; y3 = y - sqrt(3) / 2 * side;
    }

    double getArea() override {
        return (sqrt(3) / 4) * side * side;
    }

    double getPerimeter() override {
        return 3 * side;
    }

    void print() override {
        Shape::print();
        cout << "  Vertices: " << endl;
        cout << "    Top: (" << x << ", " << y << ")" << endl;
        cout << "    Left: (" << x2 << ", " << y2 << ")" << endl;
        cout << "    Right: (" << x3 << ", " << y3 << ")" << endl;
    }
};

// 🔄 Bubble sort функц
void bubbleSort(Shape* shapes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (shapes[j]->getArea() > shapes[j + 1]->getArea()) {
                swap(shapes[j], shapes[j + 1]);
            }
        }
    }
}

// 🔚 main функц
int main() {
    // Дүрсүүд үүсгэх
    Circle c(0, 0, 5);
    Square s(1, 1, 4);
    Triangle t(2, 2, 3);
    Circle c2(0, 0, 2);
    Square s2(1, 1, 6);
    Triangle t2(3, 3, 5);

    Shape* shapes[6] = { &c, &c2, &s, &s2, &t, &t2 };

    // Талбайгаар нь эрэмбэлнэ
    bubbleSort(shapes, 6);

    cout << "Sorted shapes by area:" << endl;
    for (int i = 0; i < 6; i++) {
        shapes[i]->print();
    }

    // Нийт объектын тоо хэвлэх
    cout << "\nTotal number of Shape objects: " << Shape::getObjectCount() << endl;

    // Жишээ болгон утгыг өөрчилж үзэх
    Shape::setObjectCount(100);
    cout << "Manually set count to 100. New count: " << Shape::getObjectCount() << endl;
    cout<<"end"<<endl;
//ghghghhhhhg
//commentttt shuuuu
    return 0;
}
//mickka comm biciw haha
