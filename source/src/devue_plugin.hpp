#pragma once

#include <devue_sdk.hpp>

namespace devue::plugins {
    class devue_plugin : public devue::sdk::devue_plugin_base {
    public:
        devue_plugin();

    protected:
        devue::sdk::devue_model_pack impl_import_model(const std::filesystem::path& filepath);
        devue::sdk::devue_image      impl_import_image(const std::filesystem::path& filepath);
    };
}

/*
    Exported API functions.
    Do NOT change.
*/

DEVUE_API devue::sdk::devue_plugin_interface* create();
DEVUE_API void                                release();
DEVUE_API uint64_t                            version();
