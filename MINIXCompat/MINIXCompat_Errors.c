//
//  MINIXCompat_Errors.c
//  MINIXCompat
//
//  Created by Chris Hanson on 12/4/24.
//  Copyright © 2024 Christopher M. Hanson. See file LICENSE for details.
//

#include "MINIXCompat_Errors.h"

#include <errno.h>


MINIXCOMPAT_SOURCE_BEGIN


MINIXCOMPAT_EXTERN minix_error_t MINIXCompat_Errors_MINIXErrorForHostError(int host_error)
{
    switch (host_error) {
        case EPERM: return minix_EPERM;
        case ENOENT: return minix_ENOENT;
        case ESRCH: return minix_ESRCH;
        case EINTR: return minix_EINTR;
        case EIO: return minix_EIO;
        case ENXIO: return minix_ENXIO;
        case E2BIG: return minix_E2BIG;
        case ENOEXEC: return minix_ENOEXEC;
        case EBADF: return minix_EBADF;
        case ECHILD: return minix_ECHILD;
        case EAGAIN: return minix_EAGAIN;
        case ENOMEM: return minix_ENOMEM;
        case EACCES: return minix_EACCES;
        case EFAULT: return minix_EFAULT;
        case ENOTBLK: return minix_ENOTBLK;
        case EBUSY: return minix_EBUSY;
        case EEXIST: return minix_EEXIST;
        case EXDEV: return minix_EXDEV;
        case ENODEV: return minix_ENODEV;
        case ENOTDIR: return minix_ENOTDIR;
        case EISDIR: return minix_EISDIR;
        case EINVAL: return minix_EINVAL;
        case ENFILE: return minix_ENFILE;
        case EMFILE: return minix_EMFILE;
        case ENOTTY: return minix_ENOTTY;
        case ETXTBSY: return minix_ETXTBSY;
        case EFBIG: return minix_EFBIG;
        case ENOSPC: return minix_ENOSPC;
        case ESPIPE: return minix_ESPIPE;
        case EROFS: return minix_EROFS;
        case EMLINK: return minix_EMLINK;
        case EPIPE: return minix_EPIPE;
        case EDOM: return minix_EDOM;
        case ERANGE: return minix_ERANGE;
        case EDEADLK: return minix_EDEADLK;
        case ENAMETOOLONG: return minix_ENAMETOOLONG;
        case ENOLCK: return minix_ENOLCK;
        case ENOSYS: return minix_ENOSYS;
        case ENOTEMPTY: return minix_ENOTEMPTY;

        default: return minix_ERROR;
    }
}

MINIXCOMPAT_EXTERN int MINIXCompat_Errors_HostErrorForMINIXError(minix_error_t minix_error)
{
    switch (minix_error) {
        case minix_EPERM: return EPERM;
        case minix_ENOENT: return ENOENT;
        case minix_ESRCH: return ESRCH;
        case minix_EINTR: return EINTR;
        case minix_EIO: return EIO;
        case minix_ENXIO: return ENXIO;
        case minix_E2BIG: return E2BIG;
        case minix_ENOEXEC: return ENOEXEC;
        case minix_EBADF: return EBADF;
        case minix_ECHILD: return ECHILD;
        case minix_EAGAIN: return EAGAIN;
        case minix_ENOMEM: return ENOMEM;
        case minix_EACCES: return EACCES;
        case minix_EFAULT: return EFAULT;
        case minix_ENOTBLK: return ENOTBLK;
        case minix_EBUSY: return EBUSY;
        case minix_EEXIST: return EEXIST;
        case minix_EXDEV: return EXDEV;
        case minix_ENODEV: return ENODEV;
        case minix_ENOTDIR: return ENOTDIR;
        case minix_EISDIR: return EISDIR;
        case minix_EINVAL: return EINVAL;
        case minix_ENFILE: return ENFILE;
        case minix_EMFILE: return EMFILE;
        case minix_ENOTTY: return ENOTTY;
        case minix_ETXTBSY: return ETXTBSY;
        case minix_EFBIG: return EFBIG;
        case minix_ENOSPC: return ENOSPC;
        case minix_ESPIPE: return ESPIPE;
        case minix_EROFS: return EROFS;
        case minix_EMLINK: return EMLINK;
        case minix_EPIPE: return EPIPE;
        case minix_EDOM: return EDOM;
        case minix_ERANGE: return ERANGE;
        case minix_EDEADLK: return EDEADLK;
        case minix_ENAMETOOLONG: return ENAMETOOLONG;
        case minix_ENOLCK: return ENOLCK;
        case minix_ENOSYS: return ENOSYS;
        case minix_ENOTEMPTY: return ENOTEMPTY;
        case minix_ERROR: return ENOTRECOVERABLE;
    }
}

MINIXCOMPAT_SOURCE_END
