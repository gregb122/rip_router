//Grzegorz Bielecki 288388

#include "table.h"

int router(){
    return EXIT_FAILURE;
}

int main(int argc, char** argv){
    // if (argc != 2){
    //     fprintf(stderr, "Get %d arguments, only one is requied\n", argc);
    //     exit(EXIT_FAILURE);
    // }

    // return router();
	for(int i = 0; i < 20; i++){
		sleep(2);
		broadcast();
		printf("packet send");
	}
	return 0;
}
