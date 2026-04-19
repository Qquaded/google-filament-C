#include <gltfio/AssetLoader.h>
#include <gltfio/FilamentAsset.h>

#include <filament/Engine.h>

#include "API.h"

using namespace filament;
using namespace gltfio;

struct FAssetLoader {};
struct FFilamentAsset {};

FAssetLoader *Filament_AssetLoader_Create(FEngine *engine) {
    AssetConfiguration config;
    config.engine = engine;
    return (FAssetLoader*) AssetLoader::create(config);
}

void Filament_AssetLoader_Destroy(FAssetLoader **loader) {
    AssetLoader** ptr = (AssetLoader**)loader;
    AssetLoader::destroy(ptr);
}

FFilamentAsset *Filament_AssetLoader_CreateAsset(FAssetLoader *loader, const uint8_t *bytes, uint32_t byteCount) {
    return (FFilamentAsset*) ((AssetLoader*)loader)->createAsset(bytes, byteCount);
}

void Filament_AssetLoader_DestroyAsset(FAssetLoader *loader, const FFilamentAsset *asset) {
    ((AssetLoader*)loader)->destroyAsset((FilamentAsset*)asset);
}

size_t Filament_FilamentAsset_GetEntityCount(const FFilamentAsset *asset) {
    return ((FilamentAsset*)asset)->getEntityCount();
}

const FEntity *Filament_FilamentAsset_GetEntities(const FFilamentAsset *asset) {
    return (const FEntity*) ((FilamentAsset*)asset)->getEntities();
}

FEntity Filament_FilamentAsset_GetRoot(const FFilamentAsset *asset) {
    return (FEntity) ((FilamentAsset*)asset)->getRoot().getId();
}
