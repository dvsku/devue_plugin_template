#include "devue_plugin.hpp"

using namespace devue::plugins;

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENT

// Implement with your own details
void dv_model_plugin::impl_init() {
    this->name    = "devue plugin";
    this->author  = "";
    this->website = "";
    this->version = "1.0.0";
}

// Implement your supported model types.
// Example model type:
//     { "Wavefront object", ".obj"}
// 
// If this is meant to be a texture plugin, return an empty vector.
std::vector<devue_plugin_base::file_type> dv_model_plugin::impl_get_model_types() {
    return {};
}

// Implement your supported model types.
// Example model type:
//     { "JPEG", ".jpg;.jpeg"}
// 
// If this is meant to be a texture plugin, return an empty vector.
std::vector<devue_plugin_base::file_type> dv_model_plugin::impl_get_texture_types() {
    return {};
}

// Implement model importing
devue_plugin_model dv_model_plugin::impl_import_model(const std::filesystem::path& filepath) {
    throw std::runtime_error("Not implemented");
}

// Implement texture importing
devue_plugin_texture dv_model_plugin::impl_import_texture(const std::filesystem::path& filepath) {
    throw std::runtime_error("Not implemented");
}

///////////////////////////////////////////////////////////////////////////////
// C API - DO NOT CHANGE

#include <memory>

std::unique_ptr<dv_model_plugin> plugin_instance = nullptr;

DV_API devue_plugin_interface* create() {
    if (plugin_instance) return plugin_instance.get();

    try {
        plugin_instance = std::make_unique<dv_model_plugin>();
        plugin_instance->impl_init();
    }
    catch (...) {
        return nullptr;
    }

    return plugin_instance.get();
}

DV_API void release() {
    return plugin_instance.reset();
}