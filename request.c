#include "request.h"

#define website "http://example.com/"       //website



void* request(void* data) {

CURL *c;

CURLcode* code = (CURLcode*)malloc(sizeof(CURLcode));

c = curl_easy_init();

if(c) {

curl_easy_setopt(c, CURLOPT_VERBOSE, 1L);

curl_easy_setopt(c, CURLOPT_URL, website);

curl_easy_setopt(c, CURLOPT_FOLLOWLOCATION, 1L);

*code = curl_easy_perform(c);

curl_easy_cleanup(c);

}

free(code);

pthread_exit(0);

}
