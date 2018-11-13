/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <unistd.h>
#include <iterator>

#include <media/EffectsConfig.h>

#include "utility/ValidateXml.h"

// Stringify the argument.
#define QUOTE(x) #x
#define STRINGIFY(x) QUOTE(x)

#define AUDIO_HAL_VERSION V4_0

TEST(CheckConfig, audioEffectsConfigurationValidation) {
    RecordProperty("description",
                   "Verify that the effects configuration file is valid according to the schema");
    using namespace android::effectsConfig;

    std::vector<const char*> locations(std::begin(DEFAULT_LOCATIONS), std::end(DEFAULT_LOCATIONS));
    const char* xsd = "/data/local/tmp/audio_effects_conf_" STRINGIFY(AUDIO_HAL_VERSION) ".xsd";
    // Starting with V4, audio effect XML is required
    EXPECT_ONE_VALID_XML_MULTIPLE_LOCATIONS(DEFAULT_NAME, locations, xsd);
}
