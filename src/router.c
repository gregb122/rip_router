//Grzegorz Bielecki 288388

#include <time.h>

#include "table.h"

const SENDAFTER = 5;

int router(int argc, char* argv){
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);
	/* stuff to do! */
	for(;;){
		printf("Idę nasłuchiwać :0\n");
		sleep(4); //TODO here will be receiver waiting for packets
		gettimeofday(&tv2, NULL);	
		double time = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         			  (double) (tv2.tv_sec - tv1.tv_sec);
		printf ("Total time = %f seconds\n", time);		
		if(time > SENDAFTER){
			printf("A tu sobie wyślę hehe! :0\n");
			broadcast();
			gettimeofday(&tv1, NULL);
		}
	}
    return EXIT_FAILURE;
}

int main(int argc, char** argv){
	printf("Tu się zaczynam");
    if (argc < 2){
        fprintf(stderr, "Get %d arguments, minimum is one arg\n", argc - 1);
        exit(EXIT_FAILURE);
    }
	router(argc, argv);
	return 0;
}
