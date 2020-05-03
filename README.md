# COMP2113-final-project
## This Readme.md contains:
- A brief identification of the team members.
- A game description with basic game rules.
- A list of features / functions that you plan to implement, vis-a-vis each of the items 1 to 5 listed under coding requirements above.
- Any non-standard C/C++ libraries, if any, that are used in your work, and what features/functions in your game are supported by these libraries.
- Compilation and execution instructions. Simply put, this serves like a manual to your program.
## Code Requirement. Your implementation should encompass the following coding elements:
- Generation of random game sets or events
- Data structures for storing game status
- Dynamic memory management
- File input/output (e.g., for loading/saving game status)
- Program codes in multiple files
- Proper indentation and naming styles
- In-code documentation
## Team members: 
Chen Hui Jun (3035533367)；Yang Zhi Bin (3035447037).
## Basic game rules: 
- The player wakes up in a random room of the entrance of an apartment and finds out that he or she is trapped and cannot go out without a password to the exit. The player explores the apartment's 4 rooms to collect the clue and items which can help him or her go out. 
- Initially, the player has an energy of 15 points, which will decrease by one point when he or she moves from one room to another, it will also decrease 3 points when he or she conducts some quests of the games, but helping old Nanny who will reward him or her an apple which contains random amount of energy ranging from 0-4.
- He will win the game if he comes out of the apartment before running out of the energy. If not, the player will fail this game. 
## features & function: 
- Input and Output: 
  - The player can input room name based on the guidance printed on the terminal to decide which room he or she wants to explore. when the player enters a new room, the status about the location of the player class will change accordingly.
  - Input commands to react to the Quest triggered according to the guidance printed on the terminal when entering the room, he or she can enter the same room many times but the guidance will be different if the play has already implemented the guided Quest. If the player has already implemented the Quest, the guidance of the room will be "after command instruction". Otherwise, it will be "before command instruction". The player can directly move to another room without any Quest implemented.
  - Input commands also include general commands: "GUIDANCE", "ENERGY", "LOOK", "INV" command which gives guidance, energy point display, room discription and inventory display respectively.

- Struct: 
  - The player will be created as a Struct, with attributes: energy, inventory, item_num, and rm_id(location). 
  - The 4 rooms will be created as Structs with attributes: name, before command instruction, after command instruction, is_complete. The gudiance in the room will instruct the player to input different command and acquire different items.
  - The items obtained from rooms will be created as Structs with attributes: name, information, energy point.

- Random Generation:
  - When the play decides to help the old nanny in Lobby, he or she will be rewarded a apple with a random amount of energy ranging from 0-4.

- Inventory: 
  - Players can get items from the "HELP", "FEED", "OPEN" command and store them in their inventory, these items can be keys, cat food, or apples.

- Files:
  - Multiple files are used, including the game.cpp (which is main file), room.cpp, item.cpp.

- Data Structure Storage:
  - we will use array to store items in the inventory of player.

## Non-standard C/C++ libraries
- cstdlib, ctime: create the random amounts of energy of the apple.
- string: use the string data type in the game.

## Compilation and execution instructions
Player are trapped in the rooms , player needs to explore each room and find a way out. 
There are four rooms created, player can get in the room by inputting the room names. In each room, there are events/items that are helpful , player can type in 'LOOK' to explore the room and see if there is any task to complete. Also, player can type in 'INV' to check the collected items.
Player have 15 energy points initially, going to the rooms will consume 1 point each time and completing tasks will consume 3 energy each time, Once the energy is used up, the game is over. If player can escape the room before used up all the energy, player succeed and the game is finished. Player can check your energy by inputting 'ENERGY'.
Player can always input 'GUIDANCE' to see the available commands and room name.


