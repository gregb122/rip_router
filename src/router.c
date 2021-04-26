//Grzegorz Bielecki 288388

#include "table.h"

// int router(){
//     return EXIT_FAILURE;
// }

int main(int argc, char** argv){
	printf("Tu się zaczynam\n");
    // if (argc != 2){
    //     fprintf(stderr, "Get %d arguments, only one is requied\n", argc);
    //     exit(EXIT_FAILURE);
    // }

    // return router();
	for(int i = 0; i < 5; i++){
		printf("zaraz wyślę!!\n");
		broadcast();
		sleep(1);
		printf("packet send\n\n");
	}
	return 0;
}
