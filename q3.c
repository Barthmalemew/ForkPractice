#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int n = atoi(argv[1]);

    pid_t p = fork();

    //child process
    if(p == 0)
    {
        while(n != 1){
    
            if(n % 2 == 0)
            {
                printf("%d, ", n);
                n /= 2;
            }
            else if(n % 2 != 0) 
            {
                printf("%d, ", n);
                n = (3 * n) + 1;
            }
        }
        printf("%d\n" , 1); 
    }
    //parent process
    else if(p > 0)
    {
        wait(0); 
    }
    else
    {
        //error
    }
    return 0;
}
