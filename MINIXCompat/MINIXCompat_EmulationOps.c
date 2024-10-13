//
//  MINIXCompat_EmulationOps.c
//  MINIXCompat
//
//  Created by Chris Hanson on 11/10/24.
//  Copyright © 2024 Christopher M. Hanson. See file LICENSE for details.
//

/*
 For some reason, Xcode 16.1 isn't adding these back into the build after generating them via a Run Script build phase, despite being listed as Output Files.

 So instead of relying on that, pull them into the Musashi target's sources entirely manually.
 */

#include "m68k.h"
#include "m68kops.h"
#include "m68kops.c"
