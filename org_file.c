/* I'm using obsidian to write notes
For some reasons when I tried screenshot the video lectures all file name
came back with "Paste image abcxyz". 
This script is to reformat all of those image files to eliminate the spaces
*/

#include <dirent.h> 
#include <stdio.h> 
#include <string.h>
#include <errno.h>

int main(void) {
  DIR *d;
  struct dirent *dir;
  char *old_name, *new_name,*file; 
  d = opendir(".");
 
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      file= dir->d_name; 
      // puts(file);
      
      if (strstr(file, ".png")!=NULL){
        printf("file found : %s\n ",file);
        old_name=file; 

        char* token = strtok (file," _");
        while (token != NULL){
            if (strstr(token,".png")!=NULL){
                new_name=token;
                printf("new name: %s\n",new_name);
                break;
            }
            token = strtok (NULL, " ");
            
        }
        int re=rename(old_name,new_name);
        if (re==0){
            printf("renamed successful!\n");

        }
        else{
            
            printf("Failed to rename file with %s\n",strerror(errno));
            printf("unsucessful\n");
        }

      }
    }
    closedir(d);
  }
  return 0;
}

