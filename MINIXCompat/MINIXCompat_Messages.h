//
//  MINIXCompat_Messages.h
//  MINIXCompat
//
//  Created by Chris Hanson on 11/16/24.
//  Copyright © 2024 Christopher M. Hanson. See file LICENSE for details.
//

#ifndef MINIXCompat_Messages_h
#define MINIXCompat_Messages_h

#include "MINIXCompat_Types.h"


MINIXCOMPAT_HEADER_BEGIN


/* Different system calls use different message structures that are all combined into a union for some manner of type safety. */

struct minix_mess_1 {int16_t m1i1, m1i2, m1i3; m68k_address_t m1p1, m1p2, m1p3;} MINIXCOMPAT_PACK_STRUCT;
struct minix_mess_2 {int16_t m2i1, m2i2, m2i3; int32_t m2l1, m2l2; m68k_address_t m2p1;} MINIXCOMPAT_PACK_STRUCT;
struct minix_mess_3 {int16_t m3i1, m3i2; m68k_address_t m3p1; char m3ca1[14];} MINIXCOMPAT_PACK_STRUCT;
struct minix_mess_4 {int32_t m4l1, m4l2, m4l3, m4l4;} MINIXCOMPAT_PACK_STRUCT;
struct minix_mess_5 {char m5c1, m5c2; int16_t m5i1, m5i2; int32_t m5l1, m5l2, m5l3;} MINIXCOMPAT_PACK_STRUCT;
struct minix_mess_6 {int16_t m6i1, m6i2, m6i3; int32_t m6l1; m68k_address_t m6f1;} MINIXCOMPAT_PACK_STRUCT;
typedef struct minix_mess_1 minix_mess_1;
typedef struct minix_mess_2 minix_mess_2;
typedef struct minix_mess_3 minix_mess_3;
typedef struct minix_mess_4 minix_mess_4;
typedef struct minix_mess_5 minix_mess_5;
typedef struct minix_mess_6 minix_mess_6;

/*!
 MINIX messages are used for system calls.
 Different system calls have different message structures.

 All content in a message is in network byte order on the emulator side.
 */
struct minix_message {
    int16_t m_source;           /* who sent the message */
    int16_t m_type;             /* what kind of message is it */
    union {
        minix_mess_1 m_m1;
        minix_mess_2 m_m2;
        minix_mess_3 m_m3;
        minix_mess_4 m_m4;
        minix_mess_5 m_m5;
        minix_mess_6 m_m6;
    } m_u;
} MINIXCOMPAT_PACK_STRUCT;
typedef struct minix_message minix_message_t;


#if defined(__LITTLE_ENDIAN__)

/*! Swap a message's content to host byte order given its type and a pointer to it. */
#define MINIXCompat_Message_Swap(t,m) MINIXCompat_Message_Swap_##t(m)

/* For little-endian systems each message type has a swap function. */
MINIXCOMPAT_EXTERN void MINIXCompat_Message_Swap_mess1(minix_message_t * _Nonnull msg);
MINIXCOMPAT_EXTERN void MINIXCompat_Message_Swap_mess2(minix_message_t * _Nonnull msg);
MINIXCOMPAT_EXTERN void MINIXCompat_Message_Swap_mess3(minix_message_t * _Nonnull msg);
MINIXCOMPAT_EXTERN void MINIXCompat_Message_Swap_mess4(minix_message_t * _Nonnull msg);
MINIXCOMPAT_EXTERN void MINIXCompat_Message_Swap_mess5(minix_message_t * _Nonnull msg);
MINIXCOMPAT_EXTERN void MINIXCompat_Message_Swap_mess6(minix_message_t * _Nonnull msg);

#elif defined(__BIG_ENDIAN__)

/*! Swap a message's content to host byte order given its type and a pointer to it. */
#define MINIXCompat_Message_Swap(t,m) /* Do nothing on big-endian. */

#else
#error One of __LITTLE_ENDIAN__ or __BIG_ENDIAN__ must be defined.
#endif


/*! Clear a message prior to filling it out, to prevent any garbage from being present. */
MINIXCOMPAT_EXTERN void MINIXCompat_Message_Clear(minix_message_t * _Nonnull msg);


/* The following defines provide names for useful members. */
#define m1_i1  m_u.m_m1.m1i1
#define m1_i2  m_u.m_m1.m1i2
#define m1_i3  m_u.m_m1.m1i3
#define m1_p1  m_u.m_m1.m1p1
#define m1_p2  m_u.m_m1.m1p2
#define m1_p3  m_u.m_m1.m1p3
#define m2_i1  m_u.m_m2.m2i1
#define m2_i2  m_u.m_m2.m2i2
#define m2_i3  m_u.m_m2.m2i3
#define m2_l1  m_u.m_m2.m2l1
#define m2_l2  m_u.m_m2.m2l2
#define m2_p1  m_u.m_m2.m2p1
#define m3_i1  m_u.m_m3.m3i1
#define m3_i2  m_u.m_m3.m3i2
#define m3_p1  m_u.m_m3.m3p1
#define m3_ca1 m_u.m_m3.m3ca1
#define m4_l1  m_u.m_m4.m4l1
#define m4_l2  m_u.m_m4.m4l2
#define m4_l3  m_u.m_m4.m4l3
#define m4_l4  m_u.m_m4.m4l4
#define m5_c1  m_u.m_m5.m5c1
#define m5_c2  m_u.m_m5.m5c2
#define m5_i1  m_u.m_m5.m5i1
#define m5_i2  m_u.m_m5.m5i2
#define m5_l1  m_u.m_m5.m5l1
#define m5_l2  m_u.m_m5.m5l2
#define m5_l3  m_u.m_m5.m5l3
#define m6_i1  m_u.m_m6.m6i1
#define m6_i2  m_u.m_m6.m6i2
#define m6_i3  m_u.m_m6.m6i3
#define m6_l1  m_u.m_m6.m6l1
#define m6_f1  m_u.m_m6.m6f1

/* Names of messages fields used in reply messages from tasks. */
#define REP_PROC_NR    m2_i1    /* # of proc on whose behalf I/O was done */
#define REP_STATUS     m2_i2    /* bytes transferred or error number */

/*!
 The well-known tasks are:

 - -9: TTY driver
 - -7: Printer driver (same codes as tty driver)
 - -6: Hard disk driver
 - -5: Floppy disk driver
 - -4: Memory driver (/dev/ram, /dev/mem, /dev/kmem)
 - -3: Clock driver
 - -2: System task
 - -1: Hardware handling task
 -  0: The memory manager
 -  1: The file system
 -  2: `init`, the first process on the system

 User processes have a task ID of 3 or higher.
 */
typedef enum minix_task: int16_t {
    minix_task_tty = -9,
    minix_task_printer = -7,
    minix_task_storage_fixed = -6,
    minix_task_storage_removable = -5,
    minix_task_memory = -4,
    minix_task_clock = -3,
    minix_task_system = -2,
    minix_task_hardware = -1,
    minix_task_mm = 0,
    minix_task_fs = 1,
    minix_task_init = 2,
} minix_task_t;

/*! tty & printer task messages */
typedef enum minix_tty_func: int16_t {
    minix_tty_read = 3,
    minix_tty_write = 4,
    minix_tty_ioctl = 5,
    minix_tty_setpgrp = 6,
    minix_tty_open = 7,
    minix_tty_close = 8,
    minix_tty_suspend = -998,
} minix_tty_func_t;

/* Names of message fields for messages to TTY task. */
#define TTY_LINE       m2_i1    /* message parameter: terminal line */
#define TTY_REQUEST    m2_i3    /* message parameter: ioctl request code */
#define TTY_SPEK       m2_l1    /* message parameter: ioctl speed, erasing */
#define TTY_FLAGS      m2_l2    /* message parameter: ioctl tty mode */
#define TTY_PGRP       m2_i3    /* message parameter: process group */

/*! storage task messages */
typedef enum minix_storage_func: int16_t {
    minix_storage_read = 3,
    minix_storage_write = 4,
    minix_storage_ioctl = 5,
    minix_storage_scattered_io = 6,
    minix_storage_optional_io = 16,
} minix_storage_func_t;

/* Names of message fields used for messages to block and character tasks. */
#define DEVICE         m2_i1    /* major-minor device */
#define PROC_NR        m2_i2    /* which (proc) wants I/O? */
#define COUNT          m2_i3    /* how many bytes to transfer */
#define POSITION       m2_l1    /* file offset */
#define ADDRESS        m2_p1    /* core buffer address */

/*! clock task messages */
typedef enum minix_clock_func: int16_t {
    minix_clock_alarm_set = 1,    /* send to set an alarm */
    minix_clock_time_get = 3,
    minix_clock_time_set = 4,
    minix_clock_real_time = 1,    /* here is real time */
} minix_clock_func_t;

/* Names of message fields for messages to CLOCK task. */
#define DELTA_TICKS    m6_l1    /* alarm interval in clock ticks */
#define FUNC_TO_CALL   m6_f1    /* pointer to function to call */
#define NEW_TIME       m6_l1    /* value to set clock to (SET_TIME) */
#define CLOCK_PROC_NR  m6_i1    /* which proc (or task) wants the alarm? */
#define SECONDS_LEFT   m6_l1    /* how many seconds were remaining */

/* system task messages */
typedef enum minix_system_func: int16_t {
    minix_system_exit = 1,
    minix_sysetm_getsp = 2,
    minix_system_sig = 3,
    minix_system_fork = 4,
    minix_system_newmap = 5,
    minix_system_copy = 6,
    minix_system_exec = 7,
    minix_system_times = 8,
    minix_system_abort = 9,
    minix_system_fresh = 10,
    minix_system_kill = 11,
    minix_system_gboot = 12,
    minix_system_umap = 13,
    minix_system_mem = 14,
    minix_system_trace = 15,
} minix_system_func_t;

/* Names of fields for copy message to SYSTASK. */
#define SRC_SPACE      m5_c1    /* T or D space (stack is also D) */
#define SRC_PROC_NR    m5_i1    /* process to copy from */
#define SRC_BUFFER     m5_l1    /* virtual address where data come from */
#define DST_SPACE      m5_c2    /* T or D space (stack is also D) */
#define DST_PROC_NR    m5_i2    /* process to copy to */
#define DST_BUFFER     m5_l2    /* virtual address where data go to */
#define COPY_BYTES     m5_l3    /* number of bytes to copy */

/* Field names for accounting, SYSTASK and miscellaneous. */
#define USER_TIME      m4_l1    /* user time consumed by process */
#define SYSTEM_TIME    m4_l2    /* system time consumed by process */
#define CHILD_UTIME    m4_l3    /* user time consumed by process' children */
#define CHILD_STIME    m4_l4    /* sys time consumed by process' children */

#define PROC1          m1_i1    /* indicates a process */
#define PROC2          m1_i2    /* indicates a process */
#define PID            m1_i3    /* process id passed from MM to kernel */
#define STACK_PTR      m1_p1    /* used for stack ptr in sys_exec, sys_getsp */
#define PR             m6_i1    /* process number for sys_sig */
#define SIGNUM         m6_i2    /* signal number for sys_sig */
#define FUNC           m6_f1    /* function pointer for sys_sig */
#define MEM_PTR        m1_p1    /* tells where memory map is for sys_newmap */
#define CANCEL             0    /* general request to force a task to cancel */
#define SIG_MAP        m1_i2    /* used by kernel for passing signal bit map */


MINIXCOMPAT_HEADER_END


#endif /* MINIXCompat_Messages_h */
