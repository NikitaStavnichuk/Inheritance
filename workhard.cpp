#include <windows.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

class circle
{
protected:
	const double PI = 3.141592;
	double radius;
	double calcsquarering(double radius)
	{
		return(PI * radius * radius);
	}
	circle()
	{
		radius = 0;
	}
public:
	circle(double _radius) : radius(_radius) {}
	double getcalcsquarering()
	{
		return(calcsquarering(radius));
	}
};

class cylinder : private circle
{
private:
	double height;
	double calcvolume(double radius, double height)
	{
		return (calcsquarering(radius) * height);
	}
	double calcfullsquarering(double radius, double height)
	{
		return (2 * PI * radius * height + 2 * calcsquarering(radius));
	}
public:
	cylinder(double _height, double _radius) : height(_height)
	{
		radius = _radius;
	}
	double getcalcvolume()
	{
		return(calcvolume(radius, height));
	}
	double getcalcfullsquarering()
	{
		return (calcfullsquarering(radius, height));
	}
};

double check_input(string buff, double result)
{
	cin >> buff;
	try
	{
		result = stof(buff);
	}
	catch (invalid_argument)
	{
		printf("Incorrect value entered! Only numbers must be entered. Exit...\n");
		exit(0);
	}
	catch (out_of_range)
	{
		printf("Entered incorrect value! The number is too large. Exit...\n");
		exit(0);
	}
	catch (...)
	{
		printf("Unknown error! Exit...\n");
		exit(0);
	}
	if (result > 0)
	{
		return result;
	}
	else
	{
		printf("Try again! Exit...\n");
		exit(0);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string r1, r2, h1, h2, menu_buff;

	double radius1 = 0, radius2 = 0, height1 = 0, height2 = 0;
	int menu = 0;

	cout << "Enter the radius of the first circle:" << endl;
	radius1 = check_input(r1, radius1);
	circle firstcircle(radius1);
	cout << "Enter the radius of the second circle:" << endl;
	radius2 = check_input(r2, radius2);
	circle secondcircle(radius2);
	cout << "Enter the height of the first cylinder:" << endl;
	height1 = check_input(h1, height1);
	cylinder firstcylinder(height1, radius1);
	cout << "Enter the height of the second cylinder:" << endl;
	height2 = check_input(h2, height2);
	cylinder secondcylinder(height2, radius2);

	system("cls");

	while (true)
	{
		cout << "Choose what the program should do:" << endl << endl;
		cout << "(1) - Determine the area of the first circle;" << endl << endl;
		cout << "(2) - Determine the area of the second circle;" << endl << endl;
		cout << "(3) - Determine the area of the circle formed by two concentric circles;" << endl << endl;
		cout << "(4) - Determine the cylinder volume at the base of which is the first circle;" << endl << endl;
		cout << "(5) - Determine the cylinder volume at the base of which is the second circle;" << endl << endl;
		cout << "(6) - Find the side of the square having an area that coincides with the full area of the cylinder, at the base of which is the first circle;" << endl << endl;
		cout << "(7) - Find the side of the square having an area that coincides with the full area of the cylinder, at the base of which is the second circle;" << endl << endl;
		cout << "(8) - Display the input values of geometric figures" << endl << endl;
		cout << "(9) - Exit." << endl << endl;
		menu = check_input(menu_buff, menu);
		if (menu < 10)
		{
			switch (menu)
			{
			case 1:
				system("cls");
				cout << firstcircle.getcalcsquarering() << endl;
				break;
			case 2:
				system("cls");
				cout << secondcircle.getcalcsquarering() << endl;
				break;
			case 3:
				system("cls");
				cout << fabs(firstcircle.getcalcsquarering() - secondcircle.getcalcsquarering()) << endl;
				break;
			case 4:
				system("cls");
				cout << firstcylinder.getcalcvolume() << endl;
				break;
			case 5:
				system("cls");
				cout << secondcylinder.getcalcvolume() << endl;
				break;
			case 6:
				system("cls");
				cout << sqrt(firstcylinder.getcalcfullsquarering()) << endl;
				break;
			case 7:
				system("cls");
				cout << sqrt(secondcylinder.getcalcfullsquarering()) << endl;
				break;
			case 8:
				system("cls");
				cout << "The radius of first circle is equals " << radius1 << ";" << endl;
				cout << "The radius of second circle is equals " << radius2 << ";" << endl;
				cout << "The height of the first cylinder is equal " << height1 << ";" << endl;
				cout << "The height of the second cylinder is equal " << height2 << "." << endl << endl;
				break;
			case 9:
				system("cls");
				printf("Exit...\n");
				return(0);
			}
		}
		else 
		{
			system("cls");
			cout << "The menu entry is not valid! Try again." << endl;
			cout << "Remember to enter numbers from 1 to 9 correctly." << endl << endl;
		}
	}
}