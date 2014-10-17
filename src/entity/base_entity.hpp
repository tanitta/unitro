#pragma once
#include "kinetic_model.hpp"
namespace unitro {
	namespace entity {
		class BaseEntity {
			public:
				unitro::entity::KineticModel kinetic_model_;
				BaseEntity():kinetic_model_(){};
				virtual ~BaseEntity(){};
		};
	} // namespace entity
} // namespace unitro
