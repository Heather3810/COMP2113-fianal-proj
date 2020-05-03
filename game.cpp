#include<iostream>
using namespace std;
#include<string>
#include<cstdlib>
#include <ctime>
#include "roomnew.cpp"
#include "item.cpp"

//create the player as a struct.
struct Player{
public:
  int energy;
  Item* inv[10];
  int item_num=0;
  //rm_id is location of the room the player is in.
  Room* rm_id;
  Player(int new_energy,Room * new_rm){
		energy=new_energy;
		rm_id=new_rm;
	}
	//items are stored as the pointer
  Item** get_inv(){
    return inv;
  }

  int get_energy(){
    return energy;
  }
};


int main(){
	//create rooms
	string des1;
	string des2="You have already completed the task here.\n";
	string r1_name = "room1",r2_name= "room2",r3_name= "room3",r4_name= "room4";
	Room r1={r1_name,des1,des2,false};
	r1.des1="You saw a cat with a key in its mouth, you can choose to 'FEED' it. ";
	Room r2={r2_name,des1,des2,false};
	r2.des1="You saw a security door, you can choose to 'INPUT' the password. You saw some catfood on the ground and you got some.";
	Room r3={r3_name,des1,des2,false};
	r3.des1="You saw a nanny fell on the ground, you can choose to 'HELP' her.";
	Room r4={r4_name,des1,des2,false};
	r4.des1="You saw a drawer, you can choose to 'OPEN' it";
	Room room_vec[4]={r1,r2,r3,r4};

	//generate items
	srand((unsigned) time(0));
  	int apple_energy = rand()%5;
	string name_ap="apple",name_key ="key",name_cf = "cat food";
	string des_apple = "You get an apple, which add some energy to you.";
	string des_key = "You can use the key to open the drawer in the ENTRANCE.";
	string des_cf = "You can use the cat food to feed the cat.";
 	Item password = {"password","password can help you open the exit door.",0};
	Item apple={name_ap,des_apple,apple_energy};
	Item key={name_key,des_key,0};
	Item cat_food = {name_cf,des_cf,0};
	Item item_vec[4]={password,apple,key,cat_food};

	//generate player, initially, stand at the entrance.
	Player player(15,&r4);
	//these bool type will store whether this player has already aquire the required item to finish the command.
	bool get_key=false,have_cf = false, get_pwd=false;

	//generate quest
	const char *helpmsg =
  "GUIDANCE   - Shows some available commands.\n"
  "LOOK or L  - Lets you see the room description.\n"
  "INV        - Lists all the items in your inventory.\n"
  "ENERGY     - Check the remaining energy of the player.\n"
  "EXIT       - Moves to the exit room.\n"
  "CATROOM    - Moves to the catroom.\n"
  "ENTRANCE   - Moves to the entrance room.\n"
  "LOBBY   	  - Moves to the lobby room.\n"
  "QUIT       - Ends the game.\n";

  	cout<<"Welcome! You are now trapped in this apartment, you need to explore each room and find a way out. "<<endl;
		cout<<"There are four rooms here, you can get in the room by inputting the room names. In each room, there are events/items that are helpful, you can type in 'LOOK' to explore the room and type in 'INV' to check the items you collected."<<endl;
		cout<<"You have 15 energy points initially, going to the rooms will consume 1 point each time and completing tasks will consume 3 energy each time, ";
		cout<<"Once the energy is used up, you fail. If you can escape the room before used up all the energy, you succeed. You can check your energy by inputting 'ENERGY'."<<endl;
		cout<<"Now you are standing at the ENTRANCE. You can always input 'GUIDANCE' to see the available commands and room name."<<endl;
		cout<<"Enjoy the game!"<<endl;

	while(true){
		if(player.energy<=0){
			cout<<"You are exhausted with no energy left, You fail the game, exiting..."<<endl;
			exit(0);
		}
		string order;
		cin>>order;
		//get help message.
		if(order=="GUIDANCE"){
			cout<<helpmsg;
		}
		else if(order=="QUIT"){
			cout<<"Bye!"<<endl;
			exit(0);
		}
		//look at the description of the room.
		else if(order=="LOOK"||order=="L"){
			cout<<(*(player.rm_id)).get_desc();
		}

		//check the inventory of the player
		else if(order=="INV"){
		 	cout<<"You are carrying:"<<endl;
			int numm=player.item_num;
			if(numm==0){
				cout<<"Nothing"<<endl;
			}else{
				for(int i=0;i<numm;i++){
					cout<<player.inv[i]->get_name()<<", ";
				}
				cout<<endl;
			}

		 }
		else if(order =="ENERGY"){
			cout<<player.get_energy()<<endl;
		}
		//open the drawer to get the password for the exit.
		else if(order=="OPEN"){
			if(player.rm_id == &r4){
				if(!r4.is_complete){
					if(get_key){
						cout<<"You opened the drawer, got the password."<<endl;
						int num=player.item_num;
						player.inv[num] = &password;
						cout<<password.get_info()<<endl;
						r4.is_complete = true;
						player.item_num ++;
						player.energy -=3;
						get_pwd = true;
					}
					else{
						cout<<"You do not have the key."<<endl;
					}
				}
				else{
					cout<<"You have already done that."<<endl;
				}
			}
			else{
				cout<<"You can't do that."<<endl;
			}
		}
		//help the nanny
		else if(order=="HELP"){
			if(player.rm_id == &r3){
				if(!r3.is_complete){
					cout<<"You helped the nanny, she gave you an apple."<<endl;
					int num=player.item_num;
					player.inv[num] = &apple;
					cout<<apple.get_info()<<endl;
					cout<<"The total energy of the apple is ";
					cout<<apple_energy<<endl;
					player.energy += apple_energy;
					r3.is_complete = true;
					player.item_num ++;
					player.energy -=3;
				}
				else{
					cout<<"You have already done that."<<endl;
				}
			}
			else{
				cout<<"You can't do that."<<endl;
			}
		}
		//feed the cat to get the key of the drawer
		else if(order=="FEED"){
			if(player.rm_id == &r1){
				if(!r1.is_complete){
					if(have_cf){
						cout<<"You fed the cat, got the key from the cat."<<endl;
						int num=player.item_num;
						player.inv[num] = &key;
						cout<<key.get_info()<<endl;
						r1.is_complete = true;
						player.item_num ++;
						player.energy -=3;
						get_key=true;
					}
					else{
						cout<<"You do not have the cat food."<<endl;
					}
				}
				else{
					cout<<"You have already done that."<<endl;
				}
			}
			else{
				cout<<"You can't do that."<<endl;
			}
		}
		//input the password to open the exit door.
		else if(order=="INPUT"){
			if(player.rm_id == &r2){
				if(get_pwd){
					if(player.energy>=0){
						cout<<"You input the password, the exit door is opened."<<endl;
						cout<<"The apartment escape is finished, congratulations!"<<endl;
						r2.is_complete = true;
						player.energy -=3;
						exit(0);
					}
					else{
						cout<<"Sorry, you do not have enough energy to input the password. You fail the game."<<endl;
						exit(0);
					}
				}
				else{
					cout<<"You can't do that."<<endl;
				}
			}
			else{
				cout<<"You can't do that."<<endl;
			}
		}

		//enter the catroom.
		else if(order =="CATROOM"){
			if(player.rm_id!=&r1){
				player.rm_id = &r1;
				cout<<"You are in CATROOM now."<<endl;
				cout<<r1.get_desc()<<endl;
				player.energy--;
				get_key = true;

			}
			else{
				cout<<"You have already in cat room now."<<endl;
			}
		}
		//enter the exit.
		else if(order =="EXIT"){
			if(player.rm_id!=&r2){
				player.rm_id = &r2;
				cout<<"You are in EXIT now."<<endl;
				cout<<r2.get_desc();
				player.energy--;
				int num=player.item_num;
				player.inv[num]=&cat_food;
				player.item_num++;
				item_num++;
				have_cf = true;
			}
			else{
				cout<<"You have already at the exit now."<<endl;
			}
		}
		//enter the lobby.
		else if(order =="LOBBY"){
			if(player.rm_id!=&r3){
				player.rm_id = &r3;
				cout<<"You are in LOBBY now."<<endl;
				cout<<r3.get_desc();
				player.energy--;
			}
			else{
				cout<<"You have already in lobby now."<<endl;
			}
		}
		//enter the entrance.
		else if(order =="ENTRANCE"){
			if(player.rm_id!=&r4){
				player.rm_id = &r4;
				cout<<"You are in ENTRANCE now."<<endl;
				cout<<r4.get_desc();
				player.energy--;
			}
			else{
				cout<<"You have already at the entrance now."<<endl;
			}
		}
		//the input command is not in the list.
		else{
			cout<<"You can't do that."<<endl;
		}
	}
}
