#include <iostream>
#include<cmath>
using namespace std;
class Polygon 
{
public:
    virtual double area() = 0;              //Pure virtual function for area
    virtual double perimeter() = 0;         //Pure virtual function for perimeter
};
class Triangle : public Polygon 
{
private:
    double side_1, side_2, side_3;
public:
    Triangle(double s1, double s2, double s3) 
    {
        side_1 = s1;
        side_2 = s2;
        side_3 = s3; 
    }

    double area() override 
    {
        double s = (side_1 + side_2 + side_3) / 2;
        return sqrt(s * (s - side_1) * (s - side_2) * (s - side_3));    //Heron formula
    }
    double perimeter() override 
    {
        return side_1 + side_2 + side_3;     //Sum of sides
    }
};
class IsoscelesTriangle : public Polygon 
{
private:
    double base, height;
public:
    IsoscelesTriangle(double b, double h) 
    {
        base = b;
        height = h; 
    }
    double area() override 
    {
        return (base * height) / 2;     //Area of isosceles triangle
    }

    double perimeter() override 
    {
        double side = sqrt((base / 2) * (base / 2) + height * height); 
        return base + 2 * side;       //Sum of sides
    }
};
class EquilateralTriangle : public Polygon 
{
private:
    double side;
public:
    EquilateralTriangle(double s) 
    {
        side = s; 
    }

    double area() override 
    {
        return (sqrt(3) / 4) * side * side;      //Area formula for equilateral triangle
    }
    double perimeter() override 
    {
        return 3 * side;       //Perimeter of equilateral triangle
    }
};
class Rectangle : public Polygon 
{
private:
    double width, height;
public:
    Rectangle(double w, double h) 
    {
        width = w;
        height = h; 
    }

    double area() override 
    {
        return width * height;     //Area of rectangle
    }

    double perimeter() override {
        return 2 * (width + height);     //Perimeter of rectangle
    }
};
class Square : public Polygon 
{
private:
    double side;
public:
    Square(double s) 
    {
            side = s; 
    }

    double area() override 
    {
        return side * side;     //Area of square
    }

    double perimeter() override 
    {
        return 4 * side;      //Perimeter of square
    }
};
class Pentagon : public Polygon 
{
private:
    double side;
public:
    Pentagon(double s) 
    {
        side = s;
    }
    double area() override 
    {
        return (sqrt(5 * (5 + 2 * sqrt(5))) / 4) * side * side;     //Area formula for regular pentagon
    }
    double perimeter() override 
    {
        return 5 * side; // Perimeter of pentagon
    }
};
class Hexagon : public Polygon 
{
private:
    double side;
public:
    Hexagon(double s) 
    {
        side = s;
    }

    double area() override 
    {
        return (3 * sqrt(3) / 2) * side * side;    //Area formula for regular hexagon
    }

    double perimeter() override 
    {
        return 6 * side;       //Perimeter of hexagon
    }
};
class Octagon : public Polygon 
{
private:
    double side;
public:
    Octagon(double s) 
    {
        side = s; 
    }
    double area() override 
    {
        return 2 * (1 + sqrt(2)) * side * side;       //Area formula for regular octagon
    }

    double perimeter() override 
    {
        return 8 * side;     //Perimeter of octagon
    }
};
int main() 
{
    int choice;
    cout << "\n****POLYGON WITH DIFFERENT SHAPES****\n";
    cout << "1. Triangle"<<endl;
    cout << "2. Isosceles Triangle"<<endl;
    cout << "3. Equilateral Triangle"<<endl;
    cout << "4. Rectangle"<<endl;
    cout << "5. Square"<<endl;
    cout << "6. Pentagon"<<endl;
    cout << "7. Hexagon"<<endl;
    cout << "8. Octagon"<<endl;
    cout << "Enter your choice :";
    cin >> choice;
    Polygon* polygon = nullptr;      //Pointer to Polygon to add new 
    switch (choice) 
    {
        case 1: 
        {
            double s1, s2, s3;
            cout << "Enter the lengths of the three sides: ";
            cin >> s1 >> s2 >> s3;
            polygon = new Triangle(s1, s2, s3);
            break;
        }
        case 2: 
        {
            double base, height;
            cout << "Enter the base and height: ";
            cin >> base >> height;
            polygon = new IsoscelesTriangle(base, height);
            break;
        }
        case 3: 
        {
            double side;
            cout << "Enter the length of a side: ";
            cin >> side;
            polygon = new EquilateralTriangle(side);
            break;
        }
        case 4: 
        {
            double width, height;
            cout << "Enter the width and height: ";
            cin >> width >> height;
            polygon = new Rectangle(width, height);
            break;
        }
        case 5: 
        {
            double side;
            cout << "Enter the length of a side: ";
            cin >> side;
            polygon = new Square(side);
            break;
        }
        case 6: 
        {
            double side;
            cout << "Enter the length of a side: ";
            cin >> side;
            polygon = new Pentagon(side);
            break;
        }
        case 7: 
        {
            double side;
            cout << "Enter the length of a side: ";
            cin >> side;
            polygon = new Hexagon(side);
            break;
        }
        case 8: 
        {
            double side;
            cout << "Enter the length of a side: ";
            cin >> side;
            polygon = new Octagon(side);
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }
    cout << "Area: " << polygon->area() << endl;        //Display area
    cout << "Perimeter: " << polygon->perimeter() << endl;       //Display perimeter
    delete polygon;
    return 0;
}
