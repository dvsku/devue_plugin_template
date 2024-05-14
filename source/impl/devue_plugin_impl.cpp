#include "devue_plugin_impl.hpp"
#include "devue_plugin.hpp"

using namespace devue::plugins;

// Implement with your own details
void devue_plugin_impl::impl_init(devue_plugin& plugin) {
    plugin.name    = "devue plugin";
    plugin.author  = "";
    plugin.website = "";
    plugin.version = "1.0.0";
}

// Implement your supported model types.
// Example model type:
//     { "Wavefront object", "*.obj"}
// 
// If this is meant to be a texture plugin, return an empty vector.
std::vector<file_type> devue_plugin_impl::impl_get_model_types() {
    return {};
}

// Implement your supported model types.
// Example model type:
//     { "JPEG", "*.jpg *.jpeg"}
// 
// If this is meant to be a model plugin, return an empty vector.
std::vector<file_type> devue_plugin_impl::impl_get_texture_types() {
    return {};
}

// Implement model importing
devue_plugin_model devue_plugin_impl::impl_import_model(const std::filesystem::path& filepath) {
    throw std::runtime_error("Not implemented");
}

// Implement texture importing
devue_plugin_texture devue_plugin_impl::impl_import_texture(const std::filesystem::path& filepath) {
    throw std::runtime_error("Not implemented");
}
