//!
//! @file				MVector.hpp
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
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MVECTOR_MVECTOR_H
#define MVECTOR_MVECTOR_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	template < typename ElementT >
	class MVector;
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

// System headers
#include <cstdint>		// uint32_t
#include <cstring>		// memcpy()
//#include <iostream>

// User libraries
#include "MAssert/api/MAssertApi.hpp"	// M_ASSERT_FAIL()

// User headers
// none

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	//! @brief		Vector container class designed for embedded applications.
	//! @details	Exceptions are not used.
	template < typename ElementT >
	class MVector
	{	
		
		public:


			//======================================================================================//
			//==================================== PUBLIC METHODS ==================================//
			//======================================================================================//
					

			//! @brief		Simplified constructor.
			//! @details
			MVector() :
				elementsPtr(nullptr),
				size(0)

			{
				// Nothing to do here...
			};

			//! @brief		Copy constructor.
			//! @details	Delegates to normal constructor.
			//MVector(const MVector &obj);

			//! @brief		Destructor.
			//! @details	Deletes memory that was allocated for the vectors elements.
			~MVector()
			{
				// Delete memory that was allocated in the constructor.
				delete[] this->elementsPtr;
			}

			//! @brief		Call to find how many objects are currently in the vector.
			//! @returns
			uint32_t Size()
			{
				// Easy, just return the internal length variable
				return this->size;
			}

			//! @brief		Append a C-style string onto the end of the current string.
			//! @param		objToAppend		A pointer to the object you wish to append to the vector.
			void Append(const ElementT & objToAppend)
			{
				// Allocate memory for new vector with an additional element
				ElementT * newElementsPtr = new ElementT[this->size + 1];

				// Copy across existing memory
				memcpy(newElementsPtr, this->elementsPtr, sizeof(ElementT)*this->size);

				// Copy across second section
				memcpy(newElementsPtr + this->size, &objToAppend, sizeof(ElementT));

				// Free old memory
				delete[] this->elementsPtr;

				// Save new pointer
				this->elementsPtr = newElementsPtr;

				// Update length
				this->size++;

			}

			//! @brief		Erases a specific object from the vector.
			void Erase(uint32_t index)
			{
				/*std::cout << "MVector::Erase() called." << std::endl;*/

				// Make sure index is not out-of-bounds
				M_ASSERT(index < this->size);

				/*std::cout <<
					"oldPtr[0] = '" << ((uint32_t *)this->elementsPtr)[0] <<
					"', oldPtr[1] = '" << ((uint32_t *)this->elementsPtr)[1] <<
					"', oldPtr[2] = '" << ((uint32_t *)this->elementsPtr)[2] << "'." << std::endl;*/

				ElementT * newElementsPtr = new ElementT[this->size - 1];

				// Make sure memory allocation was successful
				M_ASSERT(newElementsPtr);

				/*std::cout <<
					"Going to copy '" <<
					sizeof(ElementT)*index <<
					"bytes' from mem address '" <<
					this->elementsPtr <<
					"' to mem address '" <<
					newElementsPtr <<
					"'." << std::endl;*/

				// Copy everything from the old vector up to (but not including)
				// the element we wish to remove.
				// This should work even if index is 0 (nothing will be copied)
				memcpy(
					newElementsPtr,					// Write to the start of the new memory space
					this->elementsPtr,				// Read from the start of the old array
					sizeof(ElementT)*index);		// Copy everything upto the element we wish to remove

				// Now copy everything from the old vector after the element
				// we wish to remove
				/*std::cout <<
					"Going to copy '" <<
					sizeof(ElementT)*(this->size - index - 1) <<
					"bytes' from mem address '" <<
					this->elementsPtr + index + 1 <<
					"' to mem address '" <<
					newElementsPtr + index <<
					"'." << std::endl;*/

				memcpy(
					newElementsPtr + index,								// Start writing to the next element
					this->elementsPtr + index + 1,						// The +1 is to skip over the element we wish to erase
					sizeof(ElementT)*(this->size - index - 1));


				/*std::cout <<
					"newPtr[0] = '" << ((uint32_t *)newElementsPtr)[0] <<
					"', newPtr[1] = '" << ((uint32_t *)newElementsPtr)[1] << "'." << std::endl;*/

				// Free old memory
				delete[] this->elementsPtr;

				// Save new pointer
				this->elementsPtr = newElementsPtr;

				// Update size
				this->size--;

			}


			//======================================================================================//
			//============================ PUBLIC OPERATOR OVERLOAD DECLARATIONS ===================//
			//======================================================================================//

			//! @brief		Assignment operator overload. Allows you to make one vector equal another.
			//! @details	Copies the contents of the RHS vector into the LHS, so that they both have
			//!				the same contents (but do not point to the same memory!).
			//MVector & operator= (const MVector & other);

			//! @brief		Subscript operator overload. Allows access to individual elements.
			//! @returns	Reference to element located at position 'index'. If index is out-of-bounds,
			//!				assert will be raised.
			ElementT & operator[] (const uint32_t index)
			{

				// Check if index is >= size
				if(index >= this->size)
				{
					M_ASSERT_FAIL("%s", "MVector::operator[] index was out-of-bounds.");

					// Index is out of bounds, the best we can do is return
					// something is in bounds, so let's return
					// the last char. This could cause unexpected behaviour,
					// so an assert() needs to be added!
					return this->elementsPtr[0];
				}

				return this->elementsPtr[index];
			}


			//======================================================================================//
			//================================= PUBLIC VARIABLES ===================================//
			//======================================================================================//
				
				
		private:
						
			//======================================================================================//
			//=================================== PRIVATE METHODS ==================================//
			//======================================================================================//
			
			// none
			
			//======================================================================================//
			//================================== PRIVATE VARIABLES =================================//
			//======================================================================================//

			ElementT * elementsPtr;

			//! @brief		Remembers the number of elements stored in the vector.
			uint32_t size;

		protected:

			//======================================================================================//
			//=================================== PROTECTED METHODS ================================//
			//======================================================================================//
			
			// none
			
			//======================================================================================//
			//================================== PROTECTED VARIABLES ===============================//
			//======================================================================================//

			// none
		
	}; // class MVector


} // namespace MbeddedNinja

#endif	// #ifndef MVECTOR_MVECTOR_H

// EOF
