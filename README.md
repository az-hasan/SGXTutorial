# SGXTutorial

--------------------------
Purpose of SGXTutorial
--------------------------
An attempt to understand and replicate Intel's "SGX Tutorial for Windows", on Linux.

- The tutorial uses C++/CLI (C++ modified for Common Language Infrastructure),
so the code is not directly portable for use on my machine (Linux: Ubuntu) 
- Some things that are not compatible right off the bat are "managed types" - i.e.
objects created using "gcnew".
Maybe I could use something like Mono (an open source implementation of 
Microsoft's .NET framework). "Part of the .NET Framework's job is translating
C++/CLI porgrams into native programs, which means they have much less direct
access to the machine": 
http://stackoverflow.com/questions/1969085/what-is-the-difference-between-ansi-iso-c-and-c-cli
 
I'd like to try without Mono first though, since SGX for Linux may have
compatibility issues with Mono

------------------------------------
How to Build/Execute the Sample Code
------------------------------------
1. Install Intel(R) SGX SDK for Linux* OS
2. Build the project with the prepared Makefile:
    a. Hardware Mode, Debug build:
        $ make
    b. Hardware Mode, Pre-release build:
        $ make SGX_PRERELEASE=1 SGX_DEBUG=0
    c. Hardware Mode, Release build:
        $ make SGX_DEBUG=0
    d. Simulation Mode, Debug build:
        $ make SGX_MODE=SIM
    e. Simulation Mode, Pre-release build:
        $ make SGX_MODE=SIM SGX_PRERELEASE=1 SGX_DEBUG=0
    f. Simulation Mode, Release build:
        $ make SGX_MODE=SIM SGX_DEBUG=0
3. Execute the binary directly:
    $ ./app
4. Remember to "make clean" before switching build mode
