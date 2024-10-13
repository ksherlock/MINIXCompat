//
//  MINIXCompat_Types.h
//  MINIXCompat
//
//  Created by Chris Hanson on 11/16/24.
//  Copyright © 2024 Christopher M. Hanson. See file LICENSE for details.
//

#ifndef MINIXCompat_Types_h
#define MINIXCompat_Types_h

#include <stdint.h>


/* Useful macros for wrapping headers and sources. */

#define MINIXCOMPAT_ASSUME_NONNULL_BEGIN    _Pragma("clang assume_nonnull begin")
#define MINIXCOMPAT_ASSUME_NONNULL_END      _Pragma("clang assume_nonnull end")
									
#define MINIXCOMPAT_HEADER_BEGIN    MINIXCOMPAT_ASSUME_NONNULL_BEGIN
#define MINIXCOMPAT_HEADER_END      MINIXCOMPAT_ASSUME_NONNULL_END

#define MINIXCOMPAT_SOURCE_BEGIN    MINIXCOMPAT_ASSUME_NONNULL_BEGIN
#define MINIXCOMPAT_SOURCE_END      MINIXCOMPAT_ASSUME_NONNULL_END


MINIXCOMPAT_HEADER_BEGIN


/*! Mark an "external" C symbol even in C++. */
#ifdef __cplusplus
#define MINIXCOMPAT_EXTERN extern "C"
#else
#define MINIXCOMPAT_EXTERN extern
#endif


/*! Pack a structure, which many 68000 compilers do by default. */
#define MINIXCOMPAT_PACK_STRUCT __attribute__((packed))


/*!
 An address within the m68k address space, which is 32-bit.

 The address must actually be constrained to 24 bits, since we're using pure 68000 emulation.

 - Note: This kind of type should really come from Musashi, as should emulator-specific types for a byte, word, and long word.
 */
typedef uint32_t m68k_address_t;


MINIXCOMPAT_HEADER_END


#endif /* MINIXCompat_Types_h */
