/**
 * Author: Hair Albeiro Parra Barrera 
 * The following program briefly demonstrates how to use the fork() 
 * to perform a linear serch twice as fast. Notice that the libraries are 
 * necessary and that this will only run on linux / unix systems. 
 * */

#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h> // wil not work in Windows 
#include <unistd.h> 

void forkexample(){
    // Child process because return value zero 
    if(fork() == 0) {
        printf("Hello from Child\n"); 
    }
    else { 
        printf("Hello from parent\n");
    }

}

void forksearch(int * arr, int key) { 
    // get the lenght of the array 
    size_t n = sizeof(arr)/sizeof(arr[0]);

    int process = fork(); //create the parallel process

    if(process == 0) { 
        printf("Child process running\n");
        for(int i= 0; i < n/2; i++) { 
            if(arr[i] == key) { 
                printf("key was found in child process/n"); 
            }
        } 
    } 
    else if( process == 1) { 
        printf("Parent process running\n");
        for(int i = (n/2)+1 ; i < n; i++) { 
            if(arr[i] == key) { 
                printf("key was found in child process\n"); 
            }
        } 
    }
    else { 
        printf("ERROR: Child process could not be created\n"); 
        perror("fork"); 
        exit(EXIT_FAILURE); 
    }

    printf("Key was not found"); 
}

int main() {

    int arr[10] = {1,5,2,3,6,2,8,34,23,100}; 
    forksearch(arr, 100); 

}
