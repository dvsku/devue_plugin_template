#include "devue_plugin.hpp"
#include "plugin.hpp"

using namespace devue::plugins;

//////////////////////////////////////////////////////////////////////////////
// Plugin impl

devue_plugin::devue_plugin() {
    // You can edit macro defines in plugin.hpp
    // PLG_NAME, PLG_AUTHOR and PLG_VERSION_STR are also used to set .dll properties.
    m_desc.name    = PLG_NAME;
    m_desc.author  = PLG_AUTHOR;
    m_desc.website = "";
    m_desc.version = PLG_VERSION_STR;

    // Add your supported model types.
    // Example model type:
    //     { "Wavefront object", "*.obj"}
    // 
    // If this is meant to be an image plugin, you can leave it empty.
    m_desc.model_types = {};

    // Add your supported model types.
    // Example model type:
    //     { "JPEG", "*.jpg *.jpeg"}
    // 
    // If this is meant to be a model plugin, you can leave it empty.
    m_desc.image_types = {};
}

// Implement model importing
devue::sdk::devue_model_col devue_plugin::impl_import_model(const std::filesystem::path& filepath) {
    throw std::runtime_error("Not implemented");
}

// Implement texture importing
devue::sdk::devue_image devue_plugin::impl_import_image(const std::filesystem::path& filepath) {
    throw std::runtime_error("Not implemented");
}

//////////////////////////////////////////////////////////////////////////////
// Exported API functions.
// Do NOT change.

#include <memory>

std::unique_ptr<devue_plugin> plugin_instance = nullptr;

DEVUE_API devue::sdk::devue_plugin_interface* create() {
    if (plugin_instance) return plugin_instance.get();

    try {
        plugin_instance = std::make_unique<devue_plugin>();
    }
    catch (...) {
        return nullptr;
    }
        
    return plugin_instance.get();
}

DEVUE_API void release() {
    plugin_instance.reset();
}

DEVUE_API uint64_t version() {
    return DEVUE_SDK_VERSION_PACKED;
}
