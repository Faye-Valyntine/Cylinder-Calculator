#include <iostream>
#include <iomanip>
using namespace std;

// Create base class
class circleType
{
public:
    double radius;
    double pi = 3.14159265358979323846;
};

// Create derived class
class cylinderType : public circleType
{
public:
    double height;
    double shipPerLit;
    double paintPerSq;
    double vol();
    double area();
    double convertVolume();
    double convertArea();
    double shippingCost();
    double paintingCost();
};

// Define member functions for calculations

// Calc volume of cylinder
double cylinderType::vol()
{
    double v = height * pi * (radius * radius);
    return v;
}

// Calc surface area of cylinder
double cylinderType::area()
{
    double a = (2 * pi * radius * height) + (2 * pi * (radius * radius));
    return a;
}

// Convert volume to liters
double cylinderType::convertVolume()
{
    double cv = (vol() / 1728) * 28.32;
    return cv;
}

// Convert surface area to square feet
double cylinderType::convertArea()
{
    double ca = (area() / 144);
    return ca;
}

// Calc shipping cost of container
double cylinderType::shippingCost()
{
    double sc = convertVolume() * shipPerLit;
    return sc;
}

// Calc painting cost of container
double cylinderType::paintingCost()
{
    double pc = convertArea() * paintPerSq;
    return pc;
}

int main()
{
    // Create object
    cylinderType user;

    cout << "Cylinder Container Shipping/Painting Calculator" << endl;
    cout << "Enter dimensions in inches" << endl;
    cout << "-------------------------------" << endl;

    // Set loop to allow user to make multiple calculations
    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
    {
        // Ask user for data
        cout << "Enter height of cylinder: ";
        cin >> user.height;

        cout << "Enter radius of base: ";
        cin >> user.radius;

        cout << "Enter shipping cost per liter: ";
        cin >> user.shipPerLit;

        cout << "Enter paint cost per square foot (enter 0 if customer doesn't want their container painted): ";
        cin >> user.paintPerSq;

        // Set decimal place to 2 and display total costs
        cout << fixed << showpoint << setprecision(2) << endl;
        cout << "Volume:\t\t" << user.vol() << " cubic inches / " << user.convertVolume() << " liters" << endl;
        cout << "Surface area:\t" << user.area() << " square inches / " << user.convertArea() << " square feet" << endl;
        cout << "Shipping cost:\t$" << user.shippingCost() << endl;
        cout << "Painting cost:\t$" << user.paintingCost() << "\n" << endl;

        // Ask user to break or continue loop
        cout << "Would you like to calculate another container? (y/n): ";
        cin >> choice;
        cout << "\n";
    }
    cout << "Bye!";
}
