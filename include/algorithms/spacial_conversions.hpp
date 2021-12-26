#ifndef __ALGORITHMS_SPACIAL_CONVERSIONS_HPP
#define __ALGORITHMS_SPACIAL_CONVERSIONS_HPP

#include <containers/rotation/euler.hpp>
#include <containers/rotation/quarternion.hpp>

namespace SpacialConversions {
  Rotation::Quarternion euler2Quarternion(const Rotation::Euler& euler);
  Rotation::Euler quarternion2Euler(const Rotation::Quarternion& quart);
};  // namespace SpacialConversions

#endif  // __ALGORITHMS_SPACIAL_CONVERSIONS_HPP