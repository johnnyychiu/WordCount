/***********************************
* Program code for count()
***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int count(int argc,char *argv[]){ FILE *fp = fopen( argv[1],"r" );
int ch = 0;
if(argc != 2 ){

  printf( "Wrong Number of Argument!\n" );

  return 1;

}else if( fp == NULL){

  printf( "Cannot open the file!\n" );

  return 1;

}else{

  fseek(fp, 0, SEEK_END);
  int size = ftell(fp);
  fseek (fp, 0, SEEK_SET);
  char * wordstring;
  wordstring = malloc (size);
  fread (wordstring, 1, size, fp);  
  // printf("%s", wordstring);
  int i= 0;
  int words = 0;
  int lines = 0;

  for ( i = 0; i < size; i++)
  {
    if(wordstring[i] == ' ' || wordstring[i] == '\n' || wordstring[i] == '\t' ){
      if (wordstring[i] == '\n')
      {
        lines++;
      }
    }else{
      break;
    }
  }  

  for (; i < size - 1; i++)
  {
    if (wordstring[i] == '\n')
    {
      lines++;
    }
    if(wordstring[i] == ' ' || wordstring[i] == '\n' || wordstring[i] == '\t' ){
      if(wordstring[i+1] == ' ' || wordstring[i+1] == '\n' || wordstring[i+1] == '\t' ){
        continue;
      }else{
        words++;
      }
    }else{
    }
  }
  printf("%d %d %d %s\n",lines + 1,words+1,size,argv[1]);

}



fclose(fp);

return 0;
}
