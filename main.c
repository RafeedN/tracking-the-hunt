#include "defs.h"

int main()
{

	BuildingType bd;
	initBuilding(&bd);
	
	
	loadBuildingData(&bd);
	
	
	
	while(1){
		int c;
		printMenu(&c);
		
		if(c == 0){
			break;
		}else if(c == 1){
			printRooms(&bd.rooms);
		}else if(c == 2){
			printGhosts(&bd.ghosts, 0);
		}else if(c == 3){
			printByLikelihood(&bd.ghosts, 0);
		}
	
	}
	
	
	
	cleanupBuilding(&bd);
  return(0);
}

void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print rooms\n");
  printf("  (2) Print ghosts\n");
  printf("  (3) Print ghosts by likelihood\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}