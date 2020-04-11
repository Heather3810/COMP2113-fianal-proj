# COMP2113-final-projest
## This repo contains:
- A brief identification of the team members.
- A game description with basic game rules.
- A list of features / functions that you plan to implement, vis-a-vis each of the items 1 to 5 listed under coding requirements above.
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
- The player wakes up in a random room of an apartment and find out that he or she is trapped and cannot go out without a key. The player explores the apartment's 4 rooms to collect the clue and items which can help him or her go out. 
- Initially, the player has an energy of 20 points, which will decrease by one point when he or she moves from one room to another, it will also increase or decrease by 5-10 points when he or she conducts some quests of the games, for example, helping old Nanny who will reward him or her some random points, feeding a cat with drawer key will consume 5 points, opening the drawer which contains the door key will consume 5 points, opening the door to go out will consume 10 points. 
- He will win the game if he comes out of the apartment before running out of the energy. If not, the player will fail this game. 
## features & function: 
- Input and Output: 
  - The player can input directions based on the map printed on the terminal to decide which room he or she wants to explore. when the player enters a new room, the status about the location of the player class will change accordingly.
  - Input commands to react to the events triggered according to the guidance of printed on the terminal when entering the room, he or she can enter the same room many times but the guidance will be different if the play has already implemented the guided Quest. If the player has already implemented the Quest, the guidance of the room will be "after command instruction". Otherwise, it will be "before command instruction". The player can directly move to another room without any Quest implemented.
  - Input commands also include "Help", "Check Energy", "Check Inv" command which gives guidance, energy point display, and inventory display respectively.

- Class: 
  - The player will be created as a class, with attributes: name, energy, inventory, and location. 
  - The 4 rooms will be created as a class with attributes: name, map, before command instruction, after command instruction. The gudiance in the room will instruct the player to input different command and acquire different items.
  - The items obtained from rooms will be created as a class with attributes: name, energy point (negative or positive).

- Random Generation:
  - The player wakes up in a random room among these 4 rooms.
  - When the play decides to help the old nanny, he or she will be rewarded a random number of apple ranging from 1-2, each apple will increase his or her energy point by 3-5 randomly. 

- Inventory: 
  - Players can get items from the "Quest" command and store them in their inventory, these items can be keys, cat food, or apples which can increase the energy point.

- Files:
  - Multiple files are used, including the main file, room, item inventory, player's action......

- Data Structure Storage:
  - we will use vectors to store game status and update the status when triggering the event. Vectors will store the status of player/inventory/rooms separately, it will change accordingly after the player trigger some command.
