=======
MVector
=======

---------------------------------------------------------------------------------------------
A microcontroller-friendly C++ vector object specifically designed for embedded applications.
---------------------------------------------------------------------------------------------

.. image:: https://api.travis-ci.org/mbedded-ninja/MVector.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MVector

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- First Ever Commit: 2014-09-18
- Last Modified: 2014-10-09
- Version: v1.0.3.0
- Company: mbedded.ninja
- Project: MToolkit Module
- Language: C++
- Compiler: GCC	
- uC Model: Any
- Computer Architecture: Any
- Operating System: Any
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

A microcontroller-friendly C++ vector object specifically designed for embedded applications.

Features:

- Dynamic allocation and resize capabilities (with data preservation)
- Embedded (microcontroller) support
- Small flash/RAM memory footprint (no depedance on the C++ :code:`std::vector` class)
- Unit tests
- Doxygen-style well-documented API.
- Portability
	

External Dependencies
=====================

Nothing here yet.

Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet.

Usage
=====

See the unit tests in the 'test/' directory for basic examples.
	
Changelog
=========

========= ========== ===================================================================================================
Version   Date       Comment
========= ========== ===================================================================================================
v1.0.3.0  2014-10-09 Fixed bug where copy constructor not available, compiler does automatic shallow copy and creates memory issues, closes #4. Fixed bug where invalid delete called if MVector was constructed but no elements added before destructed, closes #3.
v1.0.2.0  2014-09-18 Fixed bug where calling MVector::Erase() with just one element attempts to allocate 0 bytes of memory, closes #2.
v1.0.1.0  2014-09-18 Removed unneeded includes from 'MVector.cpp'.
v1.0.0.0  2014-09-18 Initial commit, basic vector with Append() and Erase() implemented, and simple unit tests added, closes #1.
========= ========== ===================================================================================================