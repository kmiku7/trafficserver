/** @file

  A brief file description

  @section license License

  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 */

#if !defined (_Compatability_h_)
#define _Compatability_h_

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <strings.h>

#include "ink_port.h"
#include "ink_resource.h"

// We can't use #define for min and max becuase it will conflict with
// other declarations of min and max functions.  This conflict
// occurs with STL
template<class T> T min(const T a, const T b)
{
  return a < b ? a : b;
}

template<class T> T max(const T a, const T b)
{
  return a > b ? a : b;
}

// Define the directory separator for UNIX
#define DIR_SEP "/"

#define _O_ATTRIB_NORMAL  0x0000
#define _O_ATTRIB_OVERLAPPED 0x0000

//
// If you the gethostbyname() routines on your system are automatically
// re-entrent (as in Digital Unix), define the following
//
#if (HOST_OS == linux)
#define NEED_ALTZONE_DEFINED
#define MAP_SHARED_MAP_NORESERVE (MAP_SHARED)
#elif (HOST_OS == darwin)
#define MAP_SHARED_MAP_NORESERVE (MAP_SHARED)
#else
#define MAP_SHARED_MAP_NORESERVE (MAP_SHARED | MAP_NORESERVE)
#endif

#if (HOST_OS == darwin)
typedef uint32_t in_addr_t;
#endif

#define NEED_HRTIME

#define ink_pread      pread
#define ink_pwrite     pwrite
#define ink_open       open
#define ink_close      close
#define ink_lseek      lseek
#define ink_write      write
#define ink_pwrite     pwrite
#define ink_read       read
#define ink_pread      pread
#define ink_writev     writev
#define ink_readv      readv
#define ink_fsync      fsync
#define ink_ftruncate  ftruncate

#if (HOST_OS == freebsd) || (HOST_OS == darwin)
#define ink_ftruncate64(_fd,_s)  ftruncate(_fd, (off_t)(_s))
#else
#define ink_ftruncate64  ftruncate64
#endif

#define ink_fstat      fstat
#define ink_mmap       mmap
#define ink_sleep      sleep

#include "Resource.h"

#endif
