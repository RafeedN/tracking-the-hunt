#include "defs.h"

/*
initGhostList(), 
initGhost(), 
addGhost(), 
addGhostByLikelihood(),
printGhosts(), 
printByLikelihood(), 
printGhost(), 
cleanupGhostData(),
cleanupGhostList()
*/


/*  
  Function: initGhostList()
  Purpose:  initializes GhostList
       in/out: GhostListType
  return: void 
*/
void initGhostList(GhostListType *list){
	list->head = NULL;
	list->tail = NULL;
}

/*  
  Function: initGhost()
  Purpose:  initializes GhostType
       	   in: id, GhostEnumType, RoomType, likelihood
       in/out: GhostType
  return: void 
*/
void initGhost(int id, GhostEnumType gt, RoomType* r, float like, GhostType** ghost){
	
	GhostType* new = (GhostType *) calloc(1, sizeof(GhostType));
	
	new->id = id;
	new->ghostType = gt;
	new->room = r;
	new->likelihood = like;
	
	*ghost = new;
}

/*  
  Function: addGhost()
  Purpose:  adds GhostType to GhostListType
       	   in: GhostType
       in/out: GhostListType
  return: void 
*/
void addGhost(GhostListType *list, GhostType *ghost){
	NodeType* curr = list->head;
	NodeType* new = NULL;
	
	new = calloc(1, sizeof(NodeType));
	new->data = ghost;
	new->next = NULL;
	
	if(curr == NULL){
		list->head = new;
	}else{
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = new;
	}
	
	list->tail = new;

}

/*  
  Function: addGhostByLikelihood()
  Purpose:  adds GhostType to GhostListType by Likelihood
       	   in: GhostType
       in/out: GhostListType
  return: void 
*/
void addGhostByLikelihood(GhostListType *list, GhostType *ghost){
	NodeType* curr = list->head;
	NodeType* prev = NULL;
	NodeType* new = NULL;
	
	
	while(curr != NULL){
		if(curr->data->likelihood <= ghost->likelihood){
			break;
		}
		
		prev = curr;
		curr = curr->next;
	}
	
	new = calloc(1, sizeof(NodeType));
	new->data = ghost;
	new->next = NULL;
	
	if(prev == NULL){
		list->head = new;
		
	}else{
		prev->next = new;
	}
	
	new->next = curr;
	
	if(new->next == NULL){
		list->tail = new;
	}
}

/*  
  Function: cleanupGhostData()
  Purpose:  frees dynamically allocated ghostnode's Data
       in/out: GhostListType
  return: void 
*/
void cleanupGhostData(GhostListType *list){
	NodeType* curr = list->head;
	
	while(curr != NULL){
		free(curr->data);
		curr = curr->next;
	}

}

/*  
  Function: cleanupGhostList()
  Purpose:  frees dynamically allocated ghost nodeTypes
       in/out: GhostListType
  return: void 
*/
void cleanupGhostList(GhostListType *list){
	NodeType* curr = list->head;
	NodeType* temp;
	
	while(curr != NULL){
		temp = curr;
		curr = curr->next;
		free(temp);	
	}
}

/*  
  Function: printGhost()
  Purpose:  Prints ghost
       in: GhostType
  return: void 
*/
void printGhost(GhostType *ghost){
	GhostEnumType temp = ghost->ghostType;
	char res[MAX_STR];
	
	switch (temp){
		case POLTERGEIST: 
			strcpy(res, "POLTERGEIST");
			break;
		case WRAITH:
			strcpy(res, "WRAITH");
			break;
		case PHANTOM:
			strcpy(res, "PHANTOM");
			break;
		case BULLIES:
			strcpy(res, "BULLIES");
			break;
		default: 
			strcpy(res, "OTHER");
			break;
	}

	char *c = (ghost->room == NULL) ? "Unknown" : ghost->room->name;

	printf("%10d  | %20s | %30s | %20.3g \n", ghost->id, res, c, ghost->likelihood);
}

/*  
  Function: printGhosts()
  Purpose:  Prints ghost list
       in: GhostListType
       in: ends(if the head and tail should be printed again in the end or not)
  return: void 
*/
void printGhosts(GhostListType *list, int ends){
	NodeType* curr = list->head;
	printf(" %10s | %20s | %30s | %20s \n", "Id", "GhostEnumType", "Room", "Likeihood");
	if(ends == C_TRUE){
		while(curr != NULL){	
			printGhost(curr->data);
			curr = curr->next;
		}
		printGhost(list->head->data);
		printGhost(list->tail->data);
		
	}else{
		while(curr != NULL){	
			printGhost(curr->data);
			curr = curr->next;	
		}
	}
}

/*  
  Function: printByLikelihood()
  Purpose:  Prints ghost list by likelihood
       in: GhostListType
       in: ends(if the head and tail should be printed again in the end or not)
  return: void 
*/
void printByLikelihood(GhostListType *origList, int ends){
	NodeType* curr = origList->head;
	
	GhostListType* temp;
	temp = (GhostListType*)calloc(1, sizeof(GhostListType));
	initGhostList(temp);
	
	while(curr != NULL){	
		addGhostByLikelihood(temp, curr->data);
		curr = curr->next;
	}
	
	printGhosts(temp, ends);
	
	cleanupGhostList(temp);
	free(temp);
}