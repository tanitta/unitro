#pragma once
#include "KineticModel.hpp"
namespace unitro {
namespace entity {
	class BaseEntity {
		unitro::entity::KineticModel kineticModel;
		public:
			BaseEntity():kineticModel(){};
			virtual ~BaseEntity(){};
	};
} // namespace entity
} // namespace unitro
