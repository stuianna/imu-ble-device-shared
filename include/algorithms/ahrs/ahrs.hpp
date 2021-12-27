#ifndef __ALGORITHMS_AHRS_HPP
#define __ALGORITHMS_AHRS_HPP

#include <array>
#include <containers/rotation/euler.hpp>
#include <containers/rotation/quarternion.hpp>
#include <containers/triaxial_reading.hpp>
#include <cstddef>
#include <cstdint>

namespace AHRS {
  class AHRS {
   public:
    typedef std::array<uint8_t, 24> rawParameters;
    virtual Rotation::Euler euler() = 0;
    virtual Rotation::Quarternion quarternion() = 0;
    virtual void reset() = 0;
    virtual void setParameters(const rawParameters& bytes) = 0;
    virtual rawParameters getParameters(void) = 0;
    virtual void update(const TriaxialReading& acc, const TriaxialReading& gyr, const TriaxialReading& mag) = 0;
    virtual ~AHRS() = default;

   protected:
    AHRS(){};
  };
};  // namespace AHRS

#endif  // __ALGORITHMS_AHRS_HPP