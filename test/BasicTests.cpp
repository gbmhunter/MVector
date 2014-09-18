//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-18
//! @last-modified 	2014-09-18
//! @brief 			Contains basic tests.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <cstdint>	// uint32_t, e.t.c

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MVectorApi.hpp"

using namespace MbeddedNinja;

namespace MVectorTestsNs
{

	MTEST(BasicTest)
	{
		// Create a vector of uint32_t's
		MVector<uint32_t> myVector;

		myVector.Append(32);

		CHECK_EQUAL(myVector[0], 32);
	}

	MTEST(SizeTest)
	{
		// Create a vector of uint32_t's
		MVector<uint32_t> myVector;

		CHECK_EQUAL(myVector.Size(), 0);

		myVector.Append(32);

		CHECK_EQUAL(myVector.Size(), 1);

		myVector.Append(32);

		CHECK_EQUAL(myVector.Size(), 2);
	}

	MTEST(EraseTest)
	{
		// Create a vector of uint32_t's
		MVector<uint32_t> myVector;

		//myVector.Append(32);

		//myVector.Erase(0);

		CHECK_EQUAL(myVector.Size(), 0);

		myVector.Append(10);

		CHECK_EQUAL(myVector[0], 10);

		myVector.Append(11);

		CHECK_EQUAL(myVector[1], 11);

		myVector.Append(12);

		CHECK_EQUAL(myVector[2], 12);

		myVector.Erase(1);

		CHECK_EQUAL(myVector[0], 10);
		CHECK_EQUAL(myVector[1], 12);

		CHECK_EQUAL(myVector.Size(), 2);


	}


} // namespace MVectorTestsNs
