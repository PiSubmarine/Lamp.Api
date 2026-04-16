#include <gtest/gtest.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Lamp/Api/IControllerMock.h"

namespace PiSubmarine::Lamp::Api
{
    TEST(IControllerMockTest, SetIntensityReturnsConfiguredSuccess)
    {
        IControllerMock controllerMock;
        constexpr auto intensity = NormalizedFraction(0.75);

        EXPECT_CALL(controllerMock, SetIntensity(intensity))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        const auto result = controllerMock.SetIntensity(intensity);

        EXPECT_TRUE(result.has_value());
    }

    TEST(IControllerMockTest, GetIntensityReturnsConfiguredValue)
    {
        const auto configuredIntensity = NormalizedFraction(0.35);
        IControllerMock controllerMock;

        EXPECT_CALL(controllerMock, GetIntensity())
            .WillOnce(testing::Return(Error::Api::Result<NormalizedFraction>(configuredIntensity)));

        const auto result = controllerMock.GetIntensity();

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), configuredIntensity);
    }
}
