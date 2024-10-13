//
//  MINIXCompat.h
//  MINIXCompat
//
//  Created by Chris Hanson on 11/6/24.
//  Copyright © 2024 Christopher M. Hanson. See file LICENSE for details.
//

#ifndef MINIXCompat_h
#define	MINIXCompat_h

#include "MINIXCompat_Types.h"


MINIXCOMPAT_HEADER_BEGIN

/*!
 The states that MINIXCompat execution can be in.
 */
typedef enum MINIXCompat_Execution_State {
    /*! The emulator has just been started. */
    MINIXCompat_Execution_State_Started = 0,

    /*! The emulator is ready to run a new executable. */
    MINIXCompat_Execution_State_Ready = 1,

    /*! The emulator should be running. */
    MINIXCompat_Execution_State_Running = 2,

    /*! The emulator shoud shut down and exit with an appropriate status. */
    MINIXCompat_Execution_State_Finished = 3,
} MINIXCompat_Execution_State;


/*! Change the execution state. */
MINIXCOMPAT_EXTERN void MINIXCompat_Execution_ChangeState(MINIXCompat_Execution_State state);


MINIXCOMPAT_HEADER_END


#endif /* MINIXCompat_h */
