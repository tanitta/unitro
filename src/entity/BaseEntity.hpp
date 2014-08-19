#pragma once
#include "KineticModel.hpp"
namespace unitro {
	namespace entity {
		class BaseEntity {
			public:
				unitro::entity::KineticModel kineticModel;
				BaseEntity():kineticModel(){};
				virtual ~BaseEntity(){};
		};
	} // namespace entity
} // namespace unitro
