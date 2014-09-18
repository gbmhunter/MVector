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
- Last Modified: 2014-09-18
- Version: v1.0.0.0
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
v1.0.0.0  2014-09-18 Initial commit, basic vector with Append() and Erase() implemented, and simple unit tests added, closes #1.
========= ========== ===================================================================================================