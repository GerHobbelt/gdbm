/* gdbmerrno.c - convert gdbm errors into english. */

/* This file is part of GDBM, the GNU data base manager.
   Copyright (C) 1993, 2007, 2011  Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

/* Include system configuration before all else. */
#include "autoconf.h"

#include "gdbmerrno.h"

/* this is not static so that applications may access the array if they
   like. it must be in the same order as the error codes! */

const char * const gdbm_errlist[_GDBM_MAX_ERRNO+1] = {
  "No error",                    /* GDBM_NO_ERROR               */
  "Malloc error",		 /* GDBM_MALLOC_ERROR       	*/
  "Block size error",		 /* GDBM_BLOCK_SIZE_ERROR   	*/
  "File open error",		 /* GDBM_FILE_OPEN_ERROR    	*/
  "File write error",		 /* GDBM_FILE_WRITE_ERROR   	*/
  "File seek error",		 /* GDBM_FILE_SEEK_ERROR    	*/
  "File read error",		 /* GDBM_FILE_READ_ERROR    	*/
  "Bad magic number",		 /* GDBM_BAD_MAGIC_NUMBER   	*/
  "Empty database",		 /* GDBM_EMPTY_DATABASE     	*/
  "Can't be reader",		 /* GDBM_CANT_BE_READER     	*/
  "Can't be writer",		 /* GDBM_CANT_BE_WRITER     	*/
  "Reader can't delete",	 /* GDBM_READER_CANT_DELETE 	*/
  "Reader can't store",		 /* GDBM_READER_CANT_STORE  	*/
  "Reader can't reorganize",	 /* GDBM_READER_CANT_REORGANIZE */
  "Unknown update",		 /* GDBM_UNKNOWN_UPDATE     	*/
  "Item not found",		 /* GDBM_ITEM_NOT_FOUND     	*/
  "Reorganize failed",		 /* GDBM_REORGANIZE_FAILED  	*/
  "Cannot replace",		 /* GDBM_CANNOT_REPLACE     	*/
  "Illegal data",		 /* GDBM_ILLEGAL_DATA       	*/
  "Option already set",		 /* GDBM_OPT_ALREADY_SET    	*/
  "Illegal option",		 /* GDBM_OPT_ILLEGAL        	*/
  "Byte-swapped file",		 /* GDBM_BYTE_SWAPPED       	*/
  "Wrong file offset",		 /* GDBM_BAD_FILE_OFFSET    	*/
  "Bad file flags"		 /* GDBM_BAD_OPEN_FLAGS     	*/
};

const char *
gdbm_strerror(gdbm_error error)
{
  if(((int)error < _GDBM_MIN_ERRNO) || ((int)error > _GDBM_MAX_ERRNO))
    {
      return("Unknown error");
    }
  else
    {
      return(gdbm_errlist[(int)error]);
    }
}
