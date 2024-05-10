//
// RT64
//

#include "rt64_metal.h"

namespace RT64 {
    MTL::PixelFormat toMtl(RenderFormat format) {
        switch (format) {
            case RenderFormat::UNKNOWN:
                return MTL::PixelFormatInvalid;
            case RenderFormat::R32G32B32A32_TYPELESS:
                return MTL::PixelFormatRGBA32Float;
            case RenderFormat::R32G32B32A32_FLOAT:
                return MTL::PixelFormatRGBA32Float;
            case RenderFormat::R32G32B32A32_UINT:
                return MTL::PixelFormatRGBA32Uint;
            case RenderFormat::R32G32B32A32_SINT:
                return MTL::PixelFormatRGBA32Sint;
            case RenderFormat::R32G32B32_TYPELESS:
                return MTL::PixelFormatRGBA32Float;
            case RenderFormat::R32G32B32_FLOAT:
                return MTL::PixelFormatRGBA32Float;
            case RenderFormat::R32G32B32_UINT:
                return MTL::PixelFormatRGBA32Uint;
            case RenderFormat::R32G32B32_SINT:
                return MTL::PixelFormatRGBA32Sint;
            case RenderFormat::R16G16B16A16_TYPELESS:
                return MTL::PixelFormatRGBA16Float;
            case RenderFormat::R16G16B16A16_FLOAT:
                return MTL::PixelFormatRGBA16Float;
            case RenderFormat::R16G16B16A16_UNORM:
                return MTL::PixelFormatRGBA16Unorm;
            case RenderFormat::R16G16B16A16_UINT:
                return MTL::PixelFormatRGBA16Uint;
            case RenderFormat::R16G16B16A16_SNORM:
                return MTL::PixelFormatRGBA16Snorm;
            case RenderFormat::R16G16B16A16_SINT:
                return MTL::PixelFormatRGBA16Sint;
            case RenderFormat::R32G32_TYPELESS:
                return MTL::PixelFormatRG32Float;
            case RenderFormat::R32G32_FLOAT:
                return MTL::PixelFormatRG32Float;
            case RenderFormat::R32G32_UINT:
                return MTL::PixelFormatRG32Uint;
            case RenderFormat::R32G32_SINT:
                return MTL::PixelFormatRG32Sint;
            case RenderFormat::R8G8B8A8_TYPELESS:
                return MTL::PixelFormatRGBA8Unorm;
            case RenderFormat::R8G8B8A8_UNORM:
                return MTL::PixelFormatRGBA8Unorm;
            case RenderFormat::R8G8B8A8_UINT:
                return MTL::PixelFormatRGBA8Uint;
            case RenderFormat::R8G8B8A8_SNORM:
                return MTL::PixelFormatRGBA8Snorm;
            case RenderFormat::R8G8B8A8_SINT:
                return MTL::PixelFormatRGBA8Sint;
            case RenderFormat::B8G8R8A8_UNORM:
                return MTL::PixelFormatBGRA8Unorm;
            case RenderFormat::R16G16_TYPELESS:
                return MTL::PixelFormatRG16Float;
            case RenderFormat::R16G16_FLOAT:
                return MTL::PixelFormatRG16Float;
            case RenderFormat::R16G16_UNORM:
                return MTL::PixelFormatRG16Unorm;
            case RenderFormat::R16G16_UINT:
                return MTL::PixelFormatRG16Uint;
            case RenderFormat::R16G16_SNORM:
                return MTL::PixelFormatRG16Snorm;
            case RenderFormat::R16G16_SINT:
                return MTL::PixelFormatRG16Sint;
            case RenderFormat::R32_TYPELESS:
                return MTL::PixelFormatR32Float;
            case RenderFormat::D32_FLOAT:
                return MTL::PixelFormatDepth32Float;
            case RenderFormat::R32_FLOAT:
                return MTL::PixelFormatR32Float;
            case RenderFormat::R32_UINT:
                return MTL::PixelFormatR32Uint;
            case RenderFormat::R32_SINT:
                return MTL::PixelFormatR32Sint;
            case RenderFormat::R8G8_TYPELESS:
                return MTL::PixelFormatRG8Unorm;
            case RenderFormat::R8G8_UNORM:
                return MTL::PixelFormatRG8Unorm;
            case RenderFormat::R8G8_UINT:
                return MTL::PixelFormatRG8Uint;
            case RenderFormat::R8G8_SNORM:
                return MTL::PixelFormatRG8Snorm;
            case RenderFormat::R8G8_SINT:
                return MTL::PixelFormatRG8Sint;
            case RenderFormat::R16_TYPELESS:
                return MTL::PixelFormatR16Float;
            case RenderFormat::R16_FLOAT:
                return MTL::PixelFormatR16Float;
            case RenderFormat::D16_UNORM:
                return MTL::PixelFormatDepth16Unorm;
            case RenderFormat::R16_UNORM:
                return MTL::PixelFormatR16Unorm;
            case RenderFormat::R16_UINT:
                return MTL::PixelFormatR16Uint;
            case RenderFormat::R16_SNORM:
                return MTL::PixelFormatR16Snorm;
            case RenderFormat::R16_SINT:
                return MTL::PixelFormatR16Sint;
            case RenderFormat::R8_TYPELESS:
                return MTL::PixelFormatR8Unorm;
            case RenderFormat::R8_UNORM:
                return MTL::PixelFormatR8Unorm;
            case RenderFormat::R8_UINT:
                return MTL::PixelFormatR8Uint;
            case RenderFormat::R8_SNORM:
                return MTL::PixelFormatR8Snorm;
            case RenderFormat::R8_SINT:
                return MTL::PixelFormatR8Sint;
            default:
                assert(false && "Unknown format.");
                return MTL::PixelFormatInvalid;
        }
    }

    static MTL::TextureType toTextureType(RenderTextureDimension dimension) {
        switch (dimension) {
            case RenderTextureDimension::TEXTURE_1D:
                return MTL::TextureType1D;
            case RenderTextureDimension::TEXTURE_2D:
                return MTL::TextureType2D;
            case RenderTextureDimension::TEXTURE_3D:
                return MTL::TextureType3D;
            default:
                assert(false && "Unknown resource dimension.");
                return MTL::TextureType2D;
        }
    }

    static MTL::CullMode toMtl(RenderCullMode cullMode) {
        switch (cullMode) {
            case RenderCullMode::NONE:
                return MTL::CullModeNone;
            case RenderCullMode::FRONT:
                return MTL::CullModeFront;
            case RenderCullMode::BACK:
                return MTL::CullModeBack;
            default:
                assert(false && "Unknown cull mode.");
                return MTL::CullModeNone;
        }
    }

    static MTL::PrimitiveType toMtl(RenderPrimitiveTopology topology) {
        switch (topology) {
            case RenderPrimitiveTopology::POINT_LIST:
                return MTL::PrimitiveTypePoint;
            case RenderPrimitiveTopology::LINE_LIST:
                return MTL::PrimitiveTypeLine;
            case RenderPrimitiveTopology::TRIANGLE_LIST:
                return MTL::PrimitiveTypeTriangle;
            default:
                assert(false && "Unknown primitive topology type.");
                return MTL::PrimitiveTypePoint;
        }
    }

    static MTL::BlendFactor toMtl(RenderBlend blend) {
        switch (blend) {
            case RenderBlend::ZERO:
                return MTL::BlendFactorZero;
            case RenderBlend::ONE:
                return MTL::BlendFactorOne;
            case RenderBlend::SRC_COLOR:
                return MTL::BlendFactorSourceColor;
            case RenderBlend::INV_SRC_COLOR:
                return MTL::BlendFactorOneMinusSourceColor;
            case RenderBlend::SRC_ALPHA:
                return MTL::BlendFactorSourceAlpha;
            case RenderBlend::INV_SRC_ALPHA:
                return MTL::BlendFactorOneMinusSourceAlpha;
            case RenderBlend::DEST_ALPHA:
                return MTL::BlendFactorDestinationAlpha;
            case RenderBlend::INV_DEST_ALPHA:
                return MTL::BlendFactorOneMinusDestinationAlpha;
            case RenderBlend::DEST_COLOR:
                return MTL::BlendFactorDestinationColor;
            case RenderBlend::INV_DEST_COLOR:
                return MTL::BlendFactorOneMinusDestinationColor;
            case RenderBlend::SRC_ALPHA_SAT:
                return MTL::BlendFactorSourceAlphaSaturated;
            case RenderBlend::BLEND_FACTOR:
                return MTL::BlendFactorBlendColor;
            case RenderBlend::INV_BLEND_FACTOR:
                return MTL::BlendFactorOneMinusBlendColor;
            case RenderBlend::SRC1_COLOR:
                return MTL::BlendFactorSource1Color;
            case RenderBlend::INV_SRC1_COLOR:
                return MTL::BlendFactorOneMinusSource1Color;
            case RenderBlend::SRC1_ALPHA:
                return MTL::BlendFactorSource1Alpha;
            case RenderBlend::INV_SRC1_ALPHA:
                return MTL::BlendFactorOneMinusSource1Alpha;
            default:
                assert(false && "Unknown blend factor.");
                return MTL::BlendFactorZero;
        }
    }

    static MTL::BlendOperation toMtl(RenderBlendOperation operation) {
        switch (operation) {
            case RenderBlendOperation::ADD:
                return MTL::BlendOperationAdd;
            case RenderBlendOperation::SUBTRACT:
                return MTL::BlendOperationSubtract;
            case RenderBlendOperation::REV_SUBTRACT:
                return MTL::BlendOperationReverseSubtract;
            case RenderBlendOperation::MIN:
                return MTL::BlendOperationMin;
            case RenderBlendOperation::MAX:
                return MTL::BlendOperationMax;
            default:
                assert(false && "Unknown blend operation.");
                return MTL::BlendOperationAdd;
        }
    }

    // Metal does not support Logic Operations in the public API.

    static MTL::CompareFunction toMtl(RenderComparisonFunction function) {
        switch (function) {
            case RenderComparisonFunction::NEVER:
                return MTL::CompareFunctionNever;
            case RenderComparisonFunction::LESS:
                return MTL::CompareFunctionLess;
            case RenderComparisonFunction::EQUAL:
                return MTL::CompareFunctionEqual;
            case RenderComparisonFunction::LESS_EQUAL:
                return MTL::CompareFunctionLessEqual;
            case RenderComparisonFunction::GREATER:
                return MTL::CompareFunctionGreater;
            case RenderComparisonFunction::NOT_EQUAL:
                return MTL::CompareFunctionNotEqual;
            case RenderComparisonFunction::GREATER_EQUAL:
                return MTL::CompareFunctionGreaterEqual;
            case RenderComparisonFunction::ALWAYS:
                return MTL::CompareFunctionAlways;
            default:
                assert(false && "Unknown comparison function.");
                return MTL::CompareFunctionNever;
        }
    }

    static MTL::SamplerMinMagFilter toMtl(RenderFilter filter) {
        switch (filter) {
            case RenderFilter::NEAREST:
                return MTL::SamplerMinMagFilterNearest;
            case RenderFilter::LINEAR:
                return MTL::SamplerMinMagFilterLinear;
            default:
                assert(false && "Unknown filter.");
                return MTL::SamplerMinMagFilterNearest;
        }
    }

    static MTL::SamplerMipFilter toMtl(RenderMipmapMode mode) {
        switch (mode) {
            case RenderMipmapMode::NEAREST:
                return MTL::SamplerMipFilterNearest;
            case RenderMipmapMode::LINEAR:
                return MTL::SamplerMipFilterLinear;
            default:
                assert(false && "Unknown mipmap mode.");
                return MTL::SamplerMipFilterNearest;
        }
    }

    static MTL::SamplerAddressMode toMtl(RenderTextureAddressMode mode) {
        switch (mode) {
            case RenderTextureAddressMode::WRAP:
                return MTL::SamplerAddressModeRepeat;
            case RenderTextureAddressMode::MIRROR:
                return MTL::SamplerAddressModeMirrorRepeat;
            case RenderTextureAddressMode::CLAMP:
                return MTL::SamplerAddressModeClampToEdge;
            case RenderTextureAddressMode::BORDER:
                return MTL::SamplerAddressModeClampToBorderColor;
            case RenderTextureAddressMode::MIRROR_ONCE:
                return MTL::SamplerAddressModeMirrorClampToEdge;
            default:
                assert(false && "Unknown texture address mode.");
                return MTL::SamplerAddressModeRepeat;
        }
    }

    static MTL::SamplerBorderColor toMtl(RenderBorderColor color) {
        switch (color) {
            case RenderBorderColor::TRANSPARENT_BLACK:
                return MTL::SamplerBorderColorTransparentBlack;
            case RenderBorderColor::OPAQUE_BLACK:
                return MTL::SamplerBorderColorOpaqueBlack;
            case RenderBorderColor::OPAQUE_WHITE:
                return MTL::SamplerBorderColorOpaqueWhite;
            default:
                assert(false && "Unknown border color.");
                return MTL::SamplerBorderColorTransparentBlack;
        }
    }

    static MTL::IndexType toIndexType(RenderFormat format) {
        switch (format) {
            case RenderFormat::R16_UINT:
                return MTL::IndexTypeUInt16;
            case RenderFormat::R32_UINT:
                return MTL::IndexTypeUInt32;
            default:
                assert(false && "Format is not supported as an index type.");
                return MTL::IndexTypeUInt16;
        }
    }
}