int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger,int flag);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger,int flag);

void freeAll(LinkedList* pArrayListPassenger);


int calculate_NewId(LinkedList* pArrayListPassenger);
int calulate_ForcedId(char* path);

