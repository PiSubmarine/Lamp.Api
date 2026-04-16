#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lamp/Api/IController.h"

namespace PiSubmarine::Lamp::Api
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), SetIntensity, (NormalizedFraction intensity), (override));
        MOCK_METHOD((Error::Api::Result<NormalizedFraction>), GetIntensity, (), (const, override));
    };
}
