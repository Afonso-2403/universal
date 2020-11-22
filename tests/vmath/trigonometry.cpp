// trigonometry.cpp: test suite for vectorized trigonometry math functions
//
// Copyright (C) 2017-2020 Stillwater Supercomputing, Inc.
//
// This file is part of the universal numbers project, which is released under an MIT Open Source license.
#include <cmath>
// Configure the posit library with arithmetic exceptions
// enable posit arithmetic exceptions
#define POSIT_THROW_ARITHMETIC_EXCEPTION 1
#include <universal/posit/posit>
#include <universal/blas/blas>

constexpr double PI = 3.14159265358979323846;  // best practice for C++

template<typename Scalar>
void TestCosineVmath() {
	using namespace std;
	using namespace sw::unum::blas;
	using std::pow;
	using Vector = sw::unum::blas::vector<Scalar>;
	Vector v = linspace<Scalar>(0, 2*PI, 12);
	cout << "radians = " << v << endl;
	auto cosines = cos(v);
	cout << "cosines = " << cosines << endl;
}

int main(int argc, char** argv)
try {
	using namespace std;
	using namespace sw::unum::blas;

	int nrOfFailedTestCases = 0;

	TestCosineVmath<sw::unum::posit<32,2>>();
	TestCosineVmath<float>();

	return (nrOfFailedTestCases > 0 ? EXIT_FAILURE : EXIT_SUCCESS);
}
catch (char const* msg) {
	std::cerr << msg << std::endl;
	return EXIT_FAILURE;
}
catch (const posit_arithmetic_exception& err) {
	std::cerr << "Uncaught posit arithmetic exception: " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (const quire_exception& err) {
	std::cerr << "Uncaught quire exception: " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (const posit_internal_exception& err) {
	std::cerr << "Uncaught posit internal exception: " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (const std::runtime_error& err) {
	std::cerr << "Uncaught runtime exception: " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (...) {
	std::cerr << "Caught unknown exception" << std::endl;
	return EXIT_FAILURE;
}
