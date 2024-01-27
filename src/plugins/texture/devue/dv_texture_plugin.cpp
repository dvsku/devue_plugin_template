#include "dv_texture_plugin.hpp"

#include <memory>

using namespace devue::plugins;

// Plugin instance
std::unique_ptr<dv_texture_plugin> g_plugin = nullptr;

///////////////////////////////////////////////////////////////////////////////
// C API

DV_API dv_plugin_importer* create() {
    if (g_plugin) return g_plugin.get();

    try {
        g_plugin = std::make_unique<dv_texture_plugin>();
        g_plugin->init();
    }
    catch (...) {
        return nullptr;
    }

    return g_plugin.get();
}

DV_API void release() {
    return g_plugin.reset();
}

DV_API uint8_t plugin_type() {
    return (uint8_t)dv_plugin_importer::plugin_type::texture;
}

///////////////////////////////////////////////////////////////////////////////
// IMPL

void dv_texture_plugin::init() {
    this->m_name    = "devue texture plugin";
    this->m_author  = "";
    this->m_website = "";
    this->m_version = "1.0.0";
}

std::vector<dv_file_type> dv_texture_plugin::_get_supported_types() {
    return {
        { "JPEG",   ".jpg;.jpeg"},
        { "PNG",    ".png"},
        { "Bitmap", ".bmp"},
    };
}

dv_plugin_texture dv_texture_plugin::_import(const std::filesystem::path& filepath) {
    throw std::runtime_error("Not implemented");
}

