// Aggregation and composition
#include <iostream>
#include <vector> // for tires, doors, headlights
using namespace std;

// composition: every part of the car is essential for the car to function. If we destroy the car, all parts will be destroyed as well. The lifetime of the parts is managed by the car class.
class Engine
{
protected:
	int horsePower;
	string model;
public:
	Engine(int hp, string m) : horsePower(hp), model(m) {}
	~Engine() {}
	void Show()
	{
		cout << "Engine model: " << model << ", Horsepower: " << horsePower << endl;
	}
};

class Door
{
	protected:
		string material;
public:
	Door(string m) : material(m) {}
	~Door() {}
	void Show()
	{
		cout << "Door material: " << material << endl;
	}
};

class Body
{
	protected:
		string color;
public:
	Body(string c) : color(c) {}
	~Body() {}
	void Show()
	{
		cout << "Body color: " << color << endl;
	}
};

class Tire
{
	protected:
		string type;
public:
	Tire(string t) : type(t) {}
	~Tire() {}
	void Show()
	{
		cout << "Tire type: " << type << endl;
	}
};

class Gearbox
{
	protected:
		string type;
public:
	Gearbox(string t) : type(t) {}
	~Gearbox() {}
	void Show()
	{
		cout << "Gearbox type: " << type << endl;
	}
};

class Headlight
{
	protected:
		string type;
public:
	Headlight(string t) : type(t) {}
	~Headlight() {}
	void Show()
	{
		cout << "Headlight type: " << type << endl;
	}
};

// aggregation: the driver is not an essential part of the car. The car can function without a driver, and the driver can exist independently of the car. The lifetime of the driver is not managed by the car class.
class Driver
{
protected:
	int age;
	string name;
	string surname;
	int experience;
public:
	Driver(int a, string n, string s, int e) : age(a), name(n), surname(s), experience(e) {}
	~Driver() {}
	void Show()
	{
		cout << "Driver name: " << name << " " << surname << ", Age: " << age << ", Experience: " << experience << " years" << endl;
	}
};

class Car
{
protected:
	string brand;
	string model;
	Engine* engine;
	vector<Door*> doors;
	Body* body;
	vector<Tire*> tires;
	Gearbox* gearbox;
	vector<Headlight*> headlights;
	Driver* driver;
public:
	// A driver should be addable via constructor or AddDriver method.
	Car() : engine(nullptr), body(nullptr), gearbox(nullptr), driver(nullptr) {}
	// adding driver via constructor
	Car(string b, string m, Engine* e, vector<Door*> d, Body* bo, vector<Tire*> t, Gearbox* g, vector<Headlight*> h, Driver* dr = nullptr) : brand(b), model(m), engine(e), doors(d), body(bo), tires(t), gearbox(g), headlights(h), driver(dr) {}
	~Car() 
	{
		if (engine) delete engine;
		for (auto door : doors) delete door;
		if (body) delete body;
		for (auto tire : tires) delete tire;
		if (gearbox) delete gearbox;
		for (auto headlight : headlights) delete headlight;
	}
	void Show()
	{
		if (engine) engine->Show();
		for (auto door : doors) door->Show();
		if (body) body->Show();
		for (auto tire : tires) tire->Show();
		if (gearbox) gearbox->Show();
		for (auto headlight : headlights) headlight->Show();
		if (driver) driver->Show();
	}
	void AddDriver(Driver* dr)
	{
		driver = dr;
	}
};

int main()
{
	Car* car = new Car("Toyota", "Camry",
		new Engine(200, "V6"),
		{ new Door("Metal"), new Door("Metal"), new Door("Metal"), new Door("Metal") },
		new Body("Red"),
		{ new Tire("All-season"), new Tire("All-season"), new Tire("All-season"), new Tire("All-season") },
		new Gearbox("Automatic"),
		{ new Headlight("LED"), new Headlight("LED") });

	Driver* driver = new Driver(30, "Vadim", "Karasik", 10);
	car->AddDriver(driver);

	Car* car2 = new Car("Honda", "Civic",
		new Engine(150, "I4"),
		{ new Door("Metal"), new Door("Metal"), new Door("Metal"), new Door("Metal") },
		new Body("Blue"),
		{ new Tire("All-season"), new Tire("All-season"), new Tire("All-season"), new Tire("All-season") },
		new Gearbox("Manual"),
		{ new Headlight("Halogen"), new Headlight("Halogen") },
		new Driver(45, "Alexei", "Navalny", 16));

	car->Show();
	car2->Show();

	delete car;
	delete driver;
	delete car2;
}
