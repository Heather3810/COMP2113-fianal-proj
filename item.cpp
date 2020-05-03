#include <iostream>
using namespace std;
struct Item{
public:
	string name,info;
	int energy;

	string get_name(){
		return name;
	}
	string get_info(){
		return info;
	}
	int get_energy(){
		return energy;
	}
};
