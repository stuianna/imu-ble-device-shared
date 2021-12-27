#ifndef __ALGORITHMS_ANGULAR_HPP
#define __ALGORITHMS_ANGULAR_HPP

#include <cstddef>
#include <cstdint>

#include "ahrs.hpp"

namespace AHRS {
  class Angular : public AHRS {
   public:
    Rotation::Euler euler() override;
    Rotation::Quarternion quarternion() override;
    void reset() override;
    void setParameters(const rawParameters& parameters) override;
    rawParameters getParameters(void) override;
    void update(const TriaxialReading& acc, const TriaxialReading& gyr, const TriaxialReading& mag) override;


    struct Parameters {
      union {
        struct {
          float samplingPeriod;
        };
        rawParameters raw;
      };
    };
    static_assert(sizeof(Parameters) == sizeof(rawParameters));

    Angular();
    explicit Angular(Parameters parameters);

    const Parameters defaultParameters{.samplingPeriod = 0.01};

   private:
    Rotation::Quarternion _currentOrientation;
    Parameters _parameters;
  };
}  // namespace AHRS

#endif  // __ALGORITHMS_ANGULAR_HPP