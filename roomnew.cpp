#include <iostream>
using namespace std;
struct Room{
public:
	string name,des1,des2;
	bool is_complete;

	string get_name(){
		return name;
	}

	string get_desc(){
		if(is_complete){
			return des2;
		}
		else{
			return des1;
		}
	}
};
