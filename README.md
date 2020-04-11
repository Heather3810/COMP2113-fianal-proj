# COMP2113-final-proj
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
Chen Hui Jun (3035533367)；
Yang Zhi Bin (3035447037).
## Basic game rules: 
- The player wake up in an apartment and find out that he or she is trapped and cannot go out without a key. The player explore the apartment's 4 rooms to collect the clue and items which can help him or her go out. 
- Initially, the player has a energy of 20 points, which will decrease by one point when he or she moves from one room to another, it will also increase or decrease by 5-10 points when he or she conducts some quests of the games, for example, helping old Nanny who will reward him or her some random points, feeding cat with drawer key will consume 5 points, opening the drawer which contains the door key will consume 5 point, opening the door to go out will consumes 10 points. 
- He will win the game if he come out of the apartment before running out of the energy. If not, the player will fail this game. 
## features & function: 
- Player can input directions to decide which room he or she wants to explore and input commands to react to the events triggered. input command also include "Help" and "Check" command which give guidance and status display respecitively.
- The player will be created as a class, with attributs name, energy, inventory and location. 
- Players can pick up items and store them in their inventory, these items can be key, cat food, or apple which can increase the energy point.
- Some events are generated randomly. For example, when the play decide to help the old nanny, he or she will be rewarded a random number of apple ranging from 1-2, each apple will increase his or her energy point by 3-5 randomly. 
- Multiple files are used, including the room, item inventory, player's action......
- we will use vector to store game status and update the status when triggering the event. Vectors will store the status of player / inventory / rooms seperately, it will change accordingly after the player triger some command.
