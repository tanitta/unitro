#include "boost/multi_array.hpp"
##include "../Env.h"
namespace unitro{
namespace data{
	boost::multi_array<data::Cell, 3> currentLocalMatrix;
	boost::multi_array<data::Cell, 3> nextLocalMatrix;
}
}