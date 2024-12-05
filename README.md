# MINIXCompat

MINIXCompat is a compatibility environment that can run M68000 MINIX 1.5
binaries on modern UNIX-style systems such as macOS and Linux.

It consists of a version of the Musashi M68000 emulator that has been modified
to perform a callback upon encountering a `TRAP` instruction, plus a system
call emulator invoked by that callback that more-or-less directly translates
the UNIX V7 system calls issued by MINIX binaries into modern POSIX system
calls, and then translates their results back.


## The MINIXCompat Execution Environment

MINIXCompat expects a `MINIXCOMPAT_DIR` environment variable to be set in the
environment to indicate where an Atari ST MINIX 1.5.10.7 installation is
located, and expects all execution to take place within this directory. If
none is suppleid, a default of `/opt/minix` is used.

To set the environment’s initial working directory, you can `cd` to a
directory undereneath `MINIXCOMPAT_DIR` before invoking the environment, or
you can specify an absolute path via the `MINIXCOMPAT_PWD` environment
variable that will be treated as the directory within `MINIXCOMPAT_DIR` to use
as the initial working directory.

MINIXCompat is invoked via the command line using any number of arguments and
no options; its first argument is the MINIX-style path to the MINIX executable
to run, and all subsequent arguments are passed to the MINIX executable via
its argument vector.  The entire host environment is **not** passed to the
MINIX executable, instead only environment variables with a `MINIX_` prefix
are passed, without the prefix.

I'm making [a tarball of an Atari ST MINIX 1.5.10.7
installation](http://rendezvous.eschatologist.net/cmh/minix-st-1.5.10.7.tar.bz2)
available which is essentially just an archive of the file hierarchy in
the [ACSI disk image here](http://www.subsole.org/minix_on_the_atari_st).


## Future Work

The primary goal for MINIXCompat is to enable compilation of M68000 MINIX
(such as Atari ST MINIX) from within a modern UNIX-style environment.
Therefore the primary focus has been to run tools such as `/usr/bin/cc` and
`/usr/bin/make`, and many system calls that are not necessary for this
toolchain have not been implemented yet including `ioctl(2)` and `fcntl(2)`.

Subtleties in the emulation of some system calls is also incomplete. For
example `open(2)` and `read(2)` require substantial additional work to
synthesize MINIX-style directory content so they will work with MINIX’s
userspace `readdir` implementation, which expects a directory to behave like
an ordinary file with well-defined contents. It will not be possible to use
MINIX’s `ls` tool until this is addressed.

Finally, the implementation of some subsystems may be inadequate for their
full needs. An example may be the process abstraction, which sits mostly atop
the host system’s process abstraction: A `fork(2)` in the MINIX environment
results in a `fork(2)` of MINIXCompat that attempts to preserve as much
information as possible about the process tree. Subsequent `fork(2)` system
calls within child processes, however, may not produce a coherent view of the
process table across all members of the resulting process tree. One way to
address this might be share the memory containing the process table across the
entire tree, though this may also add substantially to the complexity of the
process implementation.

A lot of this results from the need to accommodate the use of a 16-bit `int`
within MINIX for M68000: Since it was a fork of 16-bit x86 MINIX and based on
UNIX V7, MINIX for M68000 used an LP32 model rather than an ILP32 model such
as used by BSD, SunOS, and Linux. Since so many system values such as process
IDs and lengths use `int` in MINIX, maps between the MINIX-side and host-side
values must be maintained and consulted.


## Building MINIXCompat

To build MINIXCompat you’ll need Xcode 16.1 on your Mac, and then to do the
following:

1. Clone this repository and `cd` into the resulting directory.
2. `git submodule init` to initialize all submodules.
3. `git submodule update --recursive` to get the right versions of submodules.
4. Build the `Musashi` scheme.
5. If the build fails due to an error running `m68kmake` to generate the Musashi M68000 emulator core, run the build again *without cleaning first*.

Unfortunately the build failure with `m68kmake` appears to be an Xcode 16 bug
(FB15735449) when a Run Script build phase depends on the result of building
another target: The build system tries to execute the Run Script phase that
uses `m68kmake` before `m68kmake` has its code signed, which happens because
signing is done in-place.


## Porting MINIXCompat

MINIXCompat is written in ANSI/ISO C99 and attempts to stay close POSIX
wherever possible rather than use other OS facilities, and should be fairly
portable as a result. However, no Makefile is currently provided.

For ease of inter-operation between the emulated 68K environment and the
modern POSIX host, MINIXCompat uses enums with fixed underlying types, so
you’ll need a compiler with support for that feature.

As an example, the stock `gcc` included with NetBSD 10 doesn’t support enums
with fixed underlying types in C, so building MINIXCompat on it will require
using a more recent `gcc` or `clang` as the compiler.
