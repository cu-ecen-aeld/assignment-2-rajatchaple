/*****************************************************************************
 * @file writer.c :
 * @brief : This file creates a file with given path and string as contents
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Sep 3 2021
 *
 *****************************************************************************/
#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <stdlib.h>
/*-----------MACROS-----------*/
#define SYSLOG   //uncomment this to print data using printf
#ifdef SYSLOG
#define LOG_DBG(...) syslog(LOG_DEBUG,__VA_ARGS__)
#define LOG_ERROR(...) syslog(LOG_ERR, __VA_ARGS__)
#else
#define LOG_DBG printf
#define LOG_ERROR printf
#endif

/*----------------------------------------------------------------------------
 * Entrypoint function
 * -------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
  int write_status;
  int file_descriptor;
  int close_status;
  
  openlog("writer", 0, LOG_USER);  //setting up explicitly LOG_USER facility (usually its default set to user)

  
  if(argc != 3)
  {
    LOG_ERROR("Incorrect number of arguments : expected <filepath> <string>\n");
    exit(EXIT_FAILURE);
  }

  LOG_DBG("Writing %s to %s\n", argv[2], argv[1]);
  
 
  //Creating a file
  file_descriptor = creat(argv[1],0777);
  if(file_descriptor == -1)
  {
    LOG_ERROR("file could not be created\n");  
    exit(EXIT_FAILURE);
  }
  
  //Writing a string into a file
  write_status = write (file_descriptor, argv[2], strlen (argv[2]));
  if (write_status == -1)
    LOG_ERROR("File could not be written\n");

  //Closing opened file
  close_status = close(file_descriptor);
  if(close_status == -1)
    LOG_ERROR("File could not be closed\n");

  LOG_DBG("Successful\n");
  closelog();

}

//adding errno for simplicity
