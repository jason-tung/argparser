#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ){
    char ** things = calloc(5, sizeof(char*));
    int ind = 0;
    while(line){
        things[ind] = strsep(&line, " ");
        ind++;
    }
    //printf("hey men: %p", things);
    return things;
}

int main(){
    char line[] = "ls -a -l";
    char ** args = parse_args(line);

    execvp(args[0],args);
    return 0;
}