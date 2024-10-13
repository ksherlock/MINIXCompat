//
//  MINIXCompat_Errors.h
//  MINIXCompat
//
//  Created by Chris Hanson on 12/4/24.
//  Copyright © 2024 Christopher M. Hanson. See file LICENSE for details.
//

#ifndef MINIXCompat_Errors_h
#define MINIXCompat_Errors_h

#include "MINIXCompat_Types.h"


MINIXCOMPAT_HEADER_BEGIN


/*! A MINIX `errno` value. */
typedef enum minix_error: int16_t {
    minix_EPERM =  1,
    minix_ENOENT =  2,
    minix_ESRCH =  3,
    minix_EINTR =  4,
    minix_EIO =  5,
    minix_ENXIO =  6,
    minix_E2BIG =  7,
    minix_ENOEXEC =  8,
    minix_EBADF =  9,
    minix_ECHILD = 10,
    minix_EAGAIN = 11,
    minix_ENOMEM = 12,
    minix_EACCES = 13,
    minix_EFAULT = 14,
    minix_ENOTBLK = 15,
    minix_EBUSY = 16,
    minix_EEXIST = 17,
    minix_EXDEV = 18,
    minix_ENODEV = 19,
    minix_ENOTDIR = 20,
    minix_EISDIR = 21,
    minix_EINVAL = 22,
    minix_ENFILE = 23,
    minix_EMFILE = 24,
    minix_ENOTTY = 25,
    minix_ETXTBSY = 26,
    minix_EFBIG = 27,
    minix_ENOSPC = 28,
    minix_ESPIPE = 29,
    minix_EROFS = 30,
    minix_EMLINK = 31,
    minix_EPIPE = 32,
    minix_EDOM = 33,
    minix_ERANGE = 34,
    minix_EDEADLK = 35,
    minix_ENAMETOOLONG = 36,
    minix_ENOLCK = 37,
    minix_ENOSYS = 38,
    minix_ENOTEMPTY = 39,

    minix_ERROR = 99,
} minix_error_t;


MINIXCOMPAT_EXTERN minix_error_t MINIXCompat_Errors_MINIXErrorForHostError(int host_error);

MINIXCOMPAT_EXTERN int MINIXCompat_Errors_HostErrorForMINIXError(minix_error_t minix_error);


MINIXCOMPAT_HEADER_END


#endif /* MINIXCompat_Errors_h */
