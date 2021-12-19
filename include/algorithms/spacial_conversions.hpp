#ifndef __ALGORITHMS_SPACIAL_CONVERSIONS_HPP
#define __ALGORITHMS_SPACIAL_CONVERSIONS_HPP

#include <containers/rotation_euler.hpp>
#include <containers/rotation_quarternion.hpp>

namespace SpacialConversions {
  RotationQuarternion euler2Quarternion(const RotationEuler& euler);
  RotationEuler quarternion2Euler(const RotationQuarternion& quart);
};  // namespace SpacialConversions

#endif  // __ALGORITHMS_SPACIAL_CONVERSIONS_HPP