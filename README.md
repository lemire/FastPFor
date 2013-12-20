# The FastPFOR C++ library : Fast integer compression
by Daniel Lemire, Leonid Boytsov, Owen Kaser, Maxime Caron, Louis Dionne, Michel Lemay, Erik Kruus


## What is this?

A research library with integer compression schemes.
It is broadly applicable to the compression of arrays of
32-bit integers where most integers are small.
The library seeks to exploit SIMD instructions (SSE)
whenever possible.

It should be suitable for applications to d-gap
compression and differential coding in general.

It is used by the zsearch engine (http://victorparmar.github.com/zsearch/)
as well as in GMAP and GSNAP (http://research-pub.gene.com/gmap/). It
has been ported to Java (https://github.com/lemire/JavaFastPFOR) and 
Go (https://github.com/reducedb/encoding). The Java port is used by
ClueWeb Tools (https://github.com/lintool/clueweb).


## Reference and documentation

For a simple example, please see 

example.cpp 

in the root directory of this project.

Please see:

Daniel Lemire and Leonid Boytsov, Decoding billions of integers per second through vectorization,
Software Practice & Experience (to appear)
http://arxiv.org/abs/1209.2137
http://onlinelibrary.wiley.com/doi/10.1002/spe.2203/abstract


## License

This code is licensed under Apache License, Version 2.0 (ASL2.0).

## Software Requirements

This code requires a compiler supporting C++11. This was
a design decision.

It builds under 

*  clang++ 3.2 (LLVM 3.2) or better,
*  Intel icpc (ICC) 13.0.1 or better,
*  MinGW32 (x64-4.8.1-posix-seh-rev5)
*  Microsoft VS 2012 or better,
* and GNU GCC 4.7 or better.

The code was tested under Windows, Linux and MacOS.

## Hardware Requirements

To fully use the library, your processor should support SSSE3. This includes almost every Intel or AMD processor
sold after 2006. (Note: the key schemes require merely SSE2.) 

Some specific binaries will only run if your processor supports SSE4.1. They have been purely used for specific tests however.

## Building with CMake

At the root of the project:

- Create a directory to contain the out-of-source build.

        mkdir build
        cd build

- Generate the files to actually perform the build. Many build systems are
supported by CMake, so you may want to look at the [documentation](http://www.cmake.org).

        cmake ..

- Given you generated Unix Makefiles (the default), you can now build the
library.

        make

## Building with make

You can specify which C++ compiler you are using with the YOURCXX variable.

e.g., under bash type

    export YOURCXX=g++-4.7
    make

### Installing GCC 4.7 under Linux

We support clang, Visual Studio and the Intel compiler, but a common default is GCC 4.7 or better.

Under a recent version of Ubuntu (12.10), you can install
GCC 4.7 by typing:

    sudo apt-get install gcc-4.7 g++-4.7

### Installing GCC 4.7 under Mac

Mac Ports supports GCC 4.7. You can install it by typing:

    sudo port install gcc47

## Why C++11?

With minor changes, all schemes will compile fine under
compilers that do not support C++11. And porting the code
to C should not be a challenge.

In any case, we already support 3 major C++ compilers so portability
is not a major issue.

## What if I prefer Java?

Many schemes cannot be efficiently ported to Java. However
some have been. Please see:

https://github.com/lemire/JavaFastPFOR

## Testing

If you used CMake to generate the build files, the `check` target will
run the unit tests. For example , if you generated Unix Makefiles

    make check

will do it. If you used raw make, type the following:

    make
    ./unit

Note that we are thorough in the unit tests so it can
take several minutes to run through them all.

## Simple benchmark

    make codecs
    ./codecs --clusterdynamic
    ./codecs --uniformdynamic

## Optional : Snappy

Typing "make allallall" will install some testing binaries that depend
on Google Snappy. If you want to build these, you need to install
Google snappy. You can do so on a recent ubuntu machine as:

    sudo apt-get install libsnappy-dev

## Processing data files

Typing "make" will generate an "inmemorybenchmark"
executable that can process data files.

You can use it to process arrays on (sorted!) integers
on disk using the following 32-bit format: 1 unsigned 32-bit
integer  indicating array length followed by the corresponding
number of 32-bit integer. Repeat.

 ( It is assumed that the integers are sorted.)


Once you have such a binary file somefilename you can
process it with our inmemorybenchmark:

    ./inmemorybenchmark --minlength 10000 somefilename

The "minlength" flag skips short arrays. (Warning: timings over
short arrays are unreliable.)


## Testing with the ClueWeb09 data set

Grab the data set from:

http://boytsov.info/datasets/clueweb09gap/

Using the provided software, uncompress it and
run the "toflat" executable to create a "clueweb09.bin" file
then run:

    ./inmemorybenchmark --minlength 10000 clueweb09.bin

Note: processing can take over an hour.

## Testing with the Gov2 data set

You can test the library over d-gaps data
from the TREC GOV2 data set that was made graciously
available by   Fabrizio Silvestri,  Takeshi Yamamuro
and Rossano Venturini.

Go to:

http://integerencoding.isti.cnr.it/?page_id=8

Download both the software and the gov.sort.tar file.
You might find useful to grow their stable-0.2.0 version from
https://github.com/maropu/integer_encoding_library/releases/tag/stable-0.2.0

Untar the tar file:

    tar xvf gov2.sort.tar

You may want to make the newly generated files non-writeable
(I'm paranoid):

    chmod -w gov2.sort.Delta gov2.sort.Delta.TOC

Build the software (you need the decoders executable)
and

You need to run this command

    ./decoders 3 gov2.sort somefilename

where "3" is for delta.

Then you should be able to test with out inmemorybenchmark:

    ./inmemorybenchmark --minlength 10000 somefilename.DEC

Note: processing can take over an hour.


## I used your code and I get segmentation faults

Our code is thoroughly tested.

One common issue is that people do not provide large enough buffers.
Some schemes can have such small compression rates that the compressed data
generated will be much larger than the input data.

Also, make sure that all provided buffers are 16-byte aligned or else,
some SSE instructions may fail.

## Is any of this code subject to patents?

I (D. Lemire) did not patent anything.

However, we implemented varint-G8UI which was patented by its authors. 
DO NOT use varint-G8UI if you want to avoid patents.

The rest of the library *should be* patent-free.


