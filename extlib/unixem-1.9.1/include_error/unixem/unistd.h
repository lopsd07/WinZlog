/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/unistd.h
 *
 * Purpose: Declaration of various UNIX standard functions.
 *
 * Created: 1st November 2003
 * Updated: 13th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2003-2010, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file unixem/unistd.h
 *
 * Contains standard limits and declarations.
 */

#ifndef SYNSOFT_UNIXEM_INCL_UNIXEM_H_UNISTD
#define SYNSOFT_UNIXEM_INCL_UNIXEM_H_UNISTD

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_UNISTD_MAJOR       3
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_UNISTD_MINOR       0
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_UNISTD_REVISION    1
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_UNISTD_EDIT        43
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/unixem.h>
#include <stddef.h>     /* for size_t */
#include <sys/types.h>  /* for mode_t */

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup unixem Synesis Software UNIX Emulation for Win32
 * \brief The UNIX emulation library
 */

/** \weakgroup unixem_unistd unistd.h
 * \ingroup UNIXem unixem
 * \brief Standard limits and declarations
 * @{
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WIN32
# error This file is only currently defined for compilation on Win32 systems
#endif /* _WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * Constants and definitions
 */

#if 0
# ifndef PATH_MAX
#  define PATH_MAX   (260)   /*!< The maximum number of characters (including null terminator) in a directory entry name */
# endif /* !PATH_MAX */
#endif /* 0 */

enum
{
        UNIXEM_PC_LINK_MAX                  /*!< The maximum number of links to the file. */
    ,   UNIXEM_PC_MAX_CANON                 /*!< Maximum number of bytes in canonical input line. Applicable only to terminal devices. */
    ,   UNIXEM_PC_MAX_INPUT                 /*!< Maximum number of bytes allowed in an input queue. Applicable only to terminal devices. */
    ,   UNIXEM_PC_NAME_MAX                  /*!< Maximum number of bytes in a file name, not including a nul terminator. This number can range from 14 through 255. This value is applicable only to a directory file. */
    ,   UNIXEM_PC_PATH_MAX                  /*!< Maximum number of bytes in a path name, including a nul terminator. */
    ,   UNIXEM_PC_PIPE_BUF                  /*!< Maximum number of bytes guaranteed to be written atomically. This value is applicable only to a first-in-first-out (FIFO). */
    ,   UNIXEM_PC_CHOWN_RESTRICTED          /*!< Returns 0 if the use of the chown subroutine is restricted to a process with appropriate privileges, and if the chown subroutine is restricted to changing the group ID of a file only to the effective group ID of the process or to one of its supplementary group IDs. */
    ,   UNIXEM_PC_NO_TRUNC                  /*!< Returns 0 if long component names are truncated. This value is applicable only to a directory file. */
    ,   UNIXEM_PC_VDISABLE                  /*!< This is always 0. No disabling character is defined. This value is applicable only to a terminal device. */
    ,   UNIXEM_PC_AIX_DISK_PARTITION        /*!< Determines the physical partition size of the disk. Note: The _PC_AIX_DISK_PARTITION variable is available only to the root user. */
    ,   UNIXEM_PC_AIX_DISK_SIZE             /*!< Determines the disk size in megabytes. Note: The _PC_AIX_DISK_SIZE variable is available only to the root user. Note: The _PC_FILESIZEBITS and PC_SYNC_IO flags apply to AIX 4.3 and later releases. */
    ,   UNIXEM_PC_FILESIZEBITS              /*!< Returns the minimum number of bits required to hold the file system's maximum file size as a signed integer. The smallest value returned is 32. */
    ,   UNIXEM_PC_SYNC_IO                   /*!< Returns -1 if the file system does not support the Synchronized Input and Output option. Any value other than -1 is returned if the file system supports the option. */

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define UNIXEM_PC_LINK_MAX                 UNIXEM_PC_LINK_MAX
# define UNIXEM_PC_MAX_CANON                UNIXEM_PC_MAX_CANON
# define UNIXEM_PC_MAX_INPUT                UNIXEM_PC_MAX_INPUT
# define UNIXEM_PC_NAME_MAX                 UNIXEM_PC_NAME_MAX
# define UNIXEM_PC_PATH_MAX                 UNIXEM_PC_PATH_MAX
# define UNIXEM_PC_PIPE_BUF                 UNIXEM_PC_PIPE_BUF
# define UNIXEM_PC_CHOWN_RESTRICTED         UNIXEM_PC_CHOWN_RESTRICTED
# define UNIXEM_PC_NO_TRUNC                 UNIXEM_PC_NO_TRUNC
# define UNIXEM_PC_VDISABLE                 UNIXEM_PC_VDISABLE
# define UNIXEM_PC_AIX_DISK_PARTITION       UNIXEM_PC_AIX_DISK_PARTITION
# define UNIXEM_PC_AIX_DISK_SIZE            UNIXEM_PC_AIX_DISK_SIZE
# define UNIXEM_PC_FILESIZEBITS             UNIXEM_PC_FILESIZEBITS
# define UNIXEM_PC_SYNC_IO                  UNIXEM_PC_SYNC_IO
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */
};

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** Process-identifier type */
typedef int         unixem_pid_t;

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** Creates a hardlink.
 *
 * This function creates a link from \c originalFile to \c linkName.
 *
 * \param originalFile Path of the original file
 * \param linkName Path of the link
 *
 * \return O on success, or -1 if there is an error
 *
 * \note Hardlink support is only available on Windows 2000 and later, and only
 *        works within a single drive.
 */
int unixem_link(
    char const* originalFile
,   char const* linkName
);

/** Unlinks a file or directory
 *
 * \param path The path of the file or directory to unlink
 *
 * \return O on success, or -1 if there is an error
 */
int unixem_unlink(char const* path);


/** Change the current working directory.
 *
 * This function changes the current working directory to the directory
 * specified by dirName. dirName must refer to an existing directory.
 *
 * \param dirName Path of new working directory
 * \return O on success, or -1 if there is an error
 */
int unixem_chdir(char const* dirName);


/** Get the current working directory
 *
 * This function gets the full path of the current working directory
 * and stores it in buffer.
 *
 * \param buffer Storage location for the current working directory
 * \param max_len Maximum length of path (in characters)
 * \return buffer on success, or NULL to indicate error.
 */
char* unixem_getcwd(
    char*   buffer
,   size_t  max_len
);


/** Creates the given directory
 *
 * This function creates the named directory.
 *
 * \param dirName Path of directory to remove
 * \param mode The access permissions of the directory
 *
 * \return O on success, or -1 if there is an error
 */
int unixem_mkdir(
    char const* dirName
,   unsigned    mode
);


/** Removes the given directory
 *
 * This function removes the named directory.
 *
 * \param dirName Path of directory to remove
 * \return O on success, or -1 if there is an error
 */
int unixem_rmdir(char const* dirName);


/** Closes a file
 *
 * \param handle The handle of the file to be closed
 * \return 0 on success, or -1 if there is an error
 */
int unixem_close(int handle);


/* * Creates a pipe
 *
 * \param handles An array of two handles. handles[0] will be set to the
 * read stream. handles[1] will be set to the write stream
 * \return 0 on success, or -1 if there is an error
 */
/* int pipe(int handles[2]); */

/** Returns the size, in bytes, of the page size
 */
int unixem_getpagesize(void);

/** Provides access to various system limits not available at compile time
 */
long unixem_pathconf(
    char const* path
,   int         name
);


/** Turns \c path into a fully qualified path, resolving all symbolic 
 * links, multiple /, /./ and /../
 *
 * \param path The relative path to be converted into absolute form
 * \param resolvedPath Pointer to a buffer to receive the path. This must contain
 *  sufficient storage for a valid path
 */
char* unixem_realpath(
    char const* path
,   char        resolvedPath[]
);

/** Suspends execution for the given internal
 *
 * \param microSeconds The number of microseconds in the sleep interval
 */
int unixem_usleep(unsigned long microSeconds);


/** Returns the current process identifier
 */
unixem_pid_t unixem_getpid(void);


/** Returns the host name for the current machine
 *
 * \param name Pointer to an array of characters to receive the results
 * \param cchName Number of characters available in the buffer
 *
 * \retval 0 the operation completed successfully
 * \retval -1 the operation failed
 *
 * \note This function's calling convention is stdcall, to ensure
 * compatibility if it is loaded (from ws2_32l.dll) dynamically.
 */
int __stdcall unixem_gethostname(
    char*   name
,   size_t  cchName
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_unistd */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_UNIXEM_H_UNISTD */

/* ///////////////////////////// end of file //////////////////////////// */
