#include <algorithms/spacial_conversions.hpp>

Rotation::Quarternion SpacialConversions::euler2Quarternion(const Rotation::Euler& euler) {
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
  return Rotation::Quarternion(w, x, y, z);
}

Rotation::Euler SpacialConversions::quarternion2Euler(const Rotation::Quarternion& quart) {
  auto x2 = quart.x() * quart.x();
  auto y2 = quart.y() * quart.y();
  auto z2 = quart.z() * quart.z();

  auto t0 = 2.0f * (quart.w() * quart.x() + quart.y() * quart.z());
  auto t1 = 1.0f - 2.0f * (x2 + y2);
  auto roll = std::atan2(t0, t1);

  auto t2 = +2.0f * (quart.w() * quart.y() - quart.z() * quart.x());
  t2 = t2 > 1.0f ? 1.0 : t2;
  t2 = t2 < -1.0f ? -1.0f : t2;
  auto pitch = std::asin(t2);

  auto t3 = 2.0f * (quart.w() * quart.z() + quart.x() * quart.y());
  auto t4 = 1.0f - 2.0f * (y2 + z2);
  auto yaw = std::atan2(t3, t4);
  return Rotation::Euler(Angle::radians(roll), Angle::radians(pitch), Angle::radians(yaw));
}