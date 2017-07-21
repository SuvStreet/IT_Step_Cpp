#include<string>
#include<iostream>

class System {
	class Core {
		friend class System;
		size_t core;
		std::string getPrintCore();
	public:
		Core () {}
		size_t setSystemCore();
		void getValueCore(const size_t);
		~Core() {}

		//int getValueStatic() const { return value + 11; }
		int getValueStatic(const System* system) const { return system->value + 11; }
	};
	std::string system;
	Core myCore;
	//const static int value = 100;
	int value = 100;
public:
	System() {}
	std::string printSystem();
	std::string setSystem();
	void getValueSystem(const std::string);

	std::string getValueCoreSystem() { return myCore.getPrintCore(); }
	//int getValueStaticCoreSystem() { return myCore.getValueStatic(); }
	int getValueStaticCoreSystem() { return myCore.getValueStatic(this); }
	~System() {}
};
