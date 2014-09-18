//!
//! @file				MVector.cpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-18
//! @last-modified		2014-09-18
//! @brief
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System libraries
#include <cstdint>		// int8_t, int32_t e.t.c
#include <cstring>		// strlen(), strncpy()
#include <cstdio>
#include <iostream>		//!< @debug

// User libraries
// none

// User source
#include "../include/MVector.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{


	//============================================================================================//
	//=============================== PUBLIC METHOD DEFINITIONS ==================================//
	//============================================================================================//


/*
	MString::MString(const MString &obj) :
		MString(obj.cStr)	// Delegate to base constructor, passing in the C-style string
	{
		// Copy constructor
		// Nothing here
	}*/


	//===========================================================================================//
	//=========================== PUBLIC OPERATOR OVERLOAD DEFINITIONS ==========================//
	//===========================================================================================//

	//=========================================== ASSIGNMENT ====================================//

	/*
	MString & MString::operator= (const MString & other)
	{
		//std::cerr << "Assignment operator overload called.\r\n";

		// Assignment operator
		if (this != &other) // protect against invalid self-assignment
		{
			// Make sure C-string ptr is valid
			if(!other.cStr)
				return *this;

			//std::cerr << "LHS.cStr = '" << this->cStringPtr << "'. Length = '" <<
			//		this->length << "'.\r\n" << std::endl;
			//std::cerr << "RHS.cStr = '" << other.cStringPtr << "'. Length = '" <<
			//					other.length << "'.\r\n" << std::endl;

			// Deallocate current memory
			delete[] this->cStr;

			// Copy length
			this->length = other.length;

			// allocate memory for our copy
			this->cStr = new char[this->length + 1];

			// Copy the parameter the newly allocated memory
			strncpy(this->cStr, other.cStr, this->length + 1);

			// Make sure a null is inserted at the end
			// This should never be required and strncpy should always insert it,
			// but better to be safe than sorry
			this->cStr[this->length] = '\0';

			//std::cerr << "New LHS.cStr = '" << this->cStringPtr << "'. New Length = '" <<
			//					this->length << "'.\r\n" << std::endl;

		}

		// Return *this for chaining
		return *this;
	}
*/
	//====================================== SUBSCRIPT OPERATOR =================================//




	//============================================================================================//
	//============================== PRIVATE METHOD DEFINITIONS ==================================//
	//============================================================================================//

	// none

} // namespace MbeddedNinja

// EOF
