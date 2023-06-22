# Tracking The Hunt
## Project Context
 Tracking the Hunt is a project focused on managing a ghost database in the **C language** within the **Ubuntu Linux environment**. The goal of the project is to develop a program that allows users to track the estimated likelihood of different ghosts being present in various rooms of a building. The program utilizes different **data structures**, such as **arrays** and **linked lists**, to **store** and **manipulate** the ghost and room data.
	
 The context of the game revolves around a team of ghost “hunters” tracking evidence of ghosts. With the ability to track evidence, the team can make better guesses about the types of ghosts present in the building. The project simulates a proof-of-concept for managing the estimated likelihood of different ghost types in each room.
## Project Learning Goals Achieved
* Writing a program in C that **manipulates collections** using **encapsulated functionality**. 
* Implementing different kinds of collections, including an **array of pointers** and a **singly linked list** with a tail. 
* Practicing writing code that manages **multiple pointers** to the same data.
## Data Types
1. **RoomArrayType**: A static array containing many rooms
2. **RoomType**: Holds information about a single room which includes the id, name, and a GhostList.
3. **NodeType**: Works with the GhostListType structure to implement a singly linked list. Holds GhostType data and a next pointer.
4. **GhostListType**: A singly linked list that holds NodeType elements which point to GhostTypes.
5. **GhostType**: Holds information on a single ghost which includes id, room pointer, GhostEnumType, and likelihood.
6. **BuildingType**: An array of rooms(RoomArrayType) and a list of ghosts(GhostListType).
7. **GhostEnumType**: POLTERGEIST, WRAITH, PHANTOM, BULLIES, OTHER.
## Run
```c
$ gcc -Wall -std=c99 -o main main.c ghost.c building.c room.c defs.h -g
$ ./main
```
## Functionality
 - Print Rooms
 - Print Ghosts
 - Print Ghosts by Likelihood

 ![ss1](/imgs/ss1.png)
 ![ss2](/imgs/ss2.png)
 ![ss3](/imgs/ss3.PNG)
 ![ss4](/imgs/ss4.PNG)
 ![ss5](/imgs/ss5.PNG)
## Possible Errors That Can Occur
- **Segmentation faults**: When the program tries to access memory it should not, such as trying to access memory that has been freed or writing to a read-only memory.
- **Memory Leaks**: When you do not allocate or deallocate memory properly.

I was successful in managing the memory of this project and did not get these errors.
![ss6](/imgs/ss6.PNG)

