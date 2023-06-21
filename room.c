#include "defs.h"

/*
 initRoomArray(), 
 initRoom(), 
 addRoom(), 
 printRooms(), 
 cleanupRoomArray()
*/

/*  
  Function: initRoomArray()
  Purpose:  initializes RoomArrayType
       in/out: RoomArrayType
  return: void 
*/
void initRoomArray(RoomArrayType *arr){
 	arr->size = 0;
}

/*  
  Function: initRoom()
  Purpose:  initializes RoomType
       in: id, name
       in/out: RoomType
  return: void 
*/
void initRoom(int id, char *name, RoomType **room){
	RoomType* new;
	new = (RoomType*)calloc(1, sizeof(RoomType));
	
	new->id = id;
	strcpy(new->name, name);
	
	GhostListType* list;
	list = (GhostListType*)calloc(1, sizeof(GhostListType));
	initGhostList(list);
	
	new->ghosts = list;
	
	*room = new;
	
}

/*  
  Function: addRoom()
  Purpose:  adds RoomType to RoomArrayType
       in: RoomType
       in/out: RoomArrayType
  return: void 
*/
void addRoom(RoomArrayType *arr, RoomType *r){
		arr->size += 1;
		arr->elements[arr->size - 1] = r;
}


/*  
  Function: cleanupRoomArray()
  Purpose:  frees up the dynamically allocated room, room's ghost list and its nodes
       in/out: RoomArrayType
  return: void 
*/
void cleanupRoomArray(RoomArrayType *arr){
	for(int x = 0; x < arr->size; x++){
 		cleanupGhostList(arr->elements[x]->ghosts);
 		free(arr->elements[x]->ghosts);
 		free(arr->elements[x]);
 	}
}

/*  
  Function: printRooms()
  Purpose:  prints all the rooms and their corresponding ghostlists
       in: RoomArrayType
  return: void 
*/
void printRooms(RoomArrayType *arr){
 
 

printf("___________________________________________________________________________________________\n");
 	for(int x = 0; x < arr->size; x++){
 		
 	
 	
 		printf("Id: %7d | Room: %s \n",  arr->elements[x]->id, arr->elements[x]->name);
 		//printf("%10d| %20s \n", arr->elements[x]->id, arr->elements[x]->name);
 		if(arr->elements[x]->ghosts->head != NULL){
 			printf("%10s's GhostList: \n ", arr->elements[x]->name);
 			printf("-----------------------------------------------\n");
 			printGhosts(arr->elements[x]->ghosts, C_FALSE);
 		}else{
 			printf("The %s does not have any ghosts \n ", arr->elements[x]->name);
 		}
 		
 		//printf("\n");
 		printf("___________________________________________________________________________________________\n");
 	}
 
 }