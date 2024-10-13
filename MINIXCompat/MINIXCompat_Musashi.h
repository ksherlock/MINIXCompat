//
//  MINIXCompat_Musashi.h
//  MINIXCompat
//
//  Created by Chris Hanson on 11/4/24.
//  Copyright © 2024 Christopher M. Hanson. See file LICENSE for details.
//

#ifndef MINIXCompat_Musashi_h
#define MINIXCompat_Musashi_h

/* Emulate only the 68000. */

#define M68K_EMULATE_010 M68K_OPT_OFF
#define M68K_EMULATE_020 M68K_OPT_OFF
#define M68K_EMULATE_030 M68K_OPT_OFF
#define M68K_EMULATE_040 M68K_OPT_OFF

/* Enable TRACE emulation. */

#define M68K_EMULATE_TRACE M68K_OPT_ON

/* Enable TRAP emulation. */

#define M68K_TRAP_HAS_CALLBACK M68K_OPT_ON

/* Disable PMMU emulation. */

#define M68K_EMULATE_PMMU M68K_OPT_OFF

/* Pull in the Musashi configuration (since this is used as the Musashi configuration). */

#include "m68kconf.h"

#endif /* MINIXCompat_Musashi_h */
