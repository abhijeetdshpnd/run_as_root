#include <stdio.h>
#include <iostream> 
#include "string.h"
#include <unistd.h>
#include <cstdlib>

using namespace std; 

int run_cmd(const char *cmd )
{
    setuid(geteuid());
    system(cmd);
    return 0;
}

int main(int argc, char *argv[])
{
   int i;
   string cmd = "sudo ";
   for(i = 1; i < argc; i++)
   {
    cmd = cmd + argv[i];
    cmd = cmd + " ";
   }
   run_cmd(cmd.c_str());
   return 0;
}

