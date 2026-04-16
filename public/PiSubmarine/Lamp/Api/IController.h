#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Lamp::Api
{
    class IController
    {
    public:
        virtual ~IController() = default;

        [[nodiscard]] virtual Error::Api::Result<void> SetIntensity(NormalizedFraction intensity) = 0;
        [[nodiscard]] virtual Error::Api::Result<NormalizedFraction> GetIntensity() const = 0;
    };
}
