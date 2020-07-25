#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
  /* Write your code here */

  /* Hints:
   *
   * 1. use argc and argv to access the command
   * line arguments of the program.
   *
   * 2. use getline and fputs functions to
   * read and respectively write a line to a file,
   * and strstr function to check if a string occurs
   * as a substring of other.
   */
  
   if(argc<2)
   {
       FILE * fpw;
       fpw = fopen("result.txt", "w");
       fclose(fpw);
   }
   else
   {
       FILE * fpw;
       fpw = fopen("result.txt", "w");
       FILE * fp;
       char * line = NULL;
       size_t len = 0;
       ssize_t read;
       fp = fopen("covid-confirmed-us-subset.txt", "r");
       if (fp == NULL)
       {
           fclose(fpw);
           exit(EXIT_FAILURE);
       }

       while ((read = getline(&line, &len, fp)) != -1) {
            if (strstr(line, argv[1]) != NULL) {
                fputs(line,fpw);
            }
       }
         
       fclose(fpw);
       fclose(fp);
   }

  exit(EXIT_SUCCESS);
}