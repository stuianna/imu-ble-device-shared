#include <algorithms/spacial_conversions.hpp>

RotationQuarternion SpacialConversions::euler2Quarternion(const RotationEuler& euler) {
  auto yaw = euler.yaw().radians() / 2.f;
  auto pitch = euler.pitch().radians() / 2.f;
  auto roll = euler.roll().radians() / 2.f;
  auto sinRoll = std::sin(roll);
  auto cosRoll = std::cos(roll);
  auto sinPitch = std::sin(pitch);
  auto cosPitch = std::cos(pitch);
  auto sinYaw = std::sin(yaw);
  auto cosYaw = std::cos(yaw);

  auto x = (sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw);
  auto y = (cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw);
  auto z = (cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw);
  auto w = (cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw);
  return RotationQuarternion(w, x, y, z);
}