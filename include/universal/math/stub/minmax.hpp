#pragma once
// math_minmax.hpp: templated min/max function stubs for native floating-point
//
// Copyright (C) 2017-2021 Stillwater Supercomputing, Inc.
//
// This file is part of the universal numbers project, which is released under an MIT Open Source license.


namespace sw::universal {

	template<typename Scalar,
		typename = typename std::enable_if<std::is_floating_point<Scalar>::value>::type>
		Scalar min(Scalar x, Scalar y) {
		return std::min(x, y);
	}

	template<typename Scalar,
		typename = typename std::enable_if<std::is_floating_point<Scalar>::value>::type>
		Scalar max(Scalar x, Scalar y) {
		return std::max(x, y);
	}

}  // namespace sw::universal
