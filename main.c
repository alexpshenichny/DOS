#include <stdio.h>
#include <stdlib.h>
#include "request.h"
#include <pthread.h>

//READ THREADS

int* threads_read() {

	int* threads = (int*)malloc(sizeof(int));

	char** message = (char**)malloc(sizeof(char*));

	*message = "Threads:\t";

	printf("%s", *message);

	free(message);

	scanf("%d", threads);

	return threads;

}

//READ THREADS

int main() {

	int* threads = threads_read();

	pthread_t *t = (pthread_t*)malloc(*threads * sizeof(pthread_t));

	for(int i = 0; i < *threads; i++) pthread_create(t + i, NULL, request, NULL);

	for(int i = 0; i < *threads; i++) pthread_join(t[i], NULL);

	free(threads);

	free(t);

	return 0;

}
