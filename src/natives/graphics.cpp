#include "graphics.hpp"

namespace AmxVHook {

	extern boost::shared_ptr<Debug> gDebug;
	extern boost::shared_ptr<Pool> gPool;

	namespace Natives {
		namespace Graphics {
			AMX_NATIVE_INFO list[] = {
				MOD_DEFINE_NATIVE(createTexture)
				MOD_DEFINE_NATIVE(drawTexture)
				MOD_DEFINE_NATIVE(drawInt)
				MOD_DEFINE_NATIVE(drawFloat)
				MOD_DEFINE_NATIVE(drawText)
				MOD_DEFINE_NATIVE(drawString)
				MOD_DEFINE_NATIVE(drawCounter)
				MOD_DEFINE_NATIVE(drawRect)
				MOD_DEFINE_NATIVE(drawLine)
				MOD_DEFINE_NATIVE(drawPoly)
				MOD_DEFINE_NATIVE(drawBox)
				MOD_DEFINE_NATIVE(drawMarker)
				MOD_DEFINE_NATIVE(drawSprite)
				MOD_DEFINE_NATIVE(drawSpotLight)
				MOD_DEFINE_NATIVE(drawSpotLightWithShadow)
				MOD_DEFINE_NATIVE(drawLightWithRange)
				MOD_DEFINE_NATIVE(drawLightWithRangeAndShadow)
				MOD_DEFINE_NATIVE(setTextDropShadow)
				MOD_DEFINE_NATIVE(setTextEdge)
				MOD_DEFINE_NATIVE(setTextWrap)
				MOD_DEFINE_NATIVE(setTextColor)
				MOD_DEFINE_NATIVE(setTextScale)
				MOD_DEFINE_NATIVE(setTextCentre)
				MOD_DEFINE_NATIVE(setTextFont)
				MOD_DEFINE_NATIVE(setTextJustification)
				MOD_DEFINE_NATIVE(setTextRightJustify)
				MOD_DEFINE_NATIVE(setTextEntry)
				MOD_DEFINE_NATIVE(setUILayer)
				MOD_DEFINE_NATIVE(setDrawPos)
				MOD_DEFINE_NATIVE(setDrawPosRatio)
				MOD_DEFINE_NATIVE(setDrawPosEnd)
				MOD_DEFINE_NATIVE(loadTextureDict)
				MOD_DEFINE_NATIVE(isTextureDictLoaded)
				MOD_DEFINE_NATIVE(unloadTextureDict)
				MOD_DEFINE_NATIVE(getTextureDictSize)
				MOD_DEFINE_NATIVE(addTextComponentStr)
				MOD_DEFINE_NATIVE(addTextComponentInt)
				MOD_DEFINE_NATIVE(addTextComponentFloat)

				{NULL, NULL} // terminator
			};

			MOD_NATIVE(createTexture) {
				if (!arguments(1))
					return 0;

				boost::filesystem::path path = boost::filesystem::system_complete(".\\AmxVHook\\Stuff\\" + String::get(amx, params[1]));
				if (boost::filesystem::exists(path) && !boost::filesystem::is_directory(path))
					return ::createTexture(path.string().c_str());
				
				return -1;
			}

			MOD_NATIVE(drawTexture) {
				if (!arguments(10))
					return 0;

				float size[2], center[2], pos[2], color[4];
				if (!Utility::getFloatArrayFromParam(amx, params[5], size, 2) ||
					!Utility::getFloatArrayFromParam(amx, params[6], center, 2) ||
					!Utility::getFloatArrayFromParam(amx, params[7], pos, 2) ||
					!Utility::getFloatArrayFromParam(amx, params[10], color, 4))
					return 0;

				::drawTexture(
					params[1], params[2], params[3], params[4],
					size[0], size[1],
					center[0], center[1],
					pos[0], pos[1],
					amx_ctof(params[8]), amx_ctof(params[9]),
					color[0], color[1], color[2], color[3]
				);

				return 1;
			}

			MOD_NATIVE(drawInt) {
				if (!arguments(3))
					return 0;

				Funcs::drawInt(params[1], amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(drawFloat) {
				if (!arguments(4))
					return 0;

				Funcs::drawFloat(amx_ctof(params[1]), params[4], amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(drawString) {
				if (!arguments(7))
					return 0;

				Utility::Color color(params[6]);

				::UI::SET_TEXT_FONT(params[5]);
				::UI::SET_TEXT_SCALE(amx_ctof(params[4]), amx_ctof(params[4]));
				::UI::SET_TEXT_COLOUR(color.R, color.G, color.B, color.A);
				::UI::SET_TEXT_CENTRE(params[7]);
				::UI::_SET_TEXT_ENTRY("STRING");
				::UI::_ADD_TEXT_COMPONENT_STRING((char *)String::get(amx, params[1]).c_str());
				::UI::_DRAW_TEXT(amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(drawText) {
				::UI::_DRAW_TEXT(amx_ctof(params[1]), amx_ctof(params[2]));
				return 1;
			}
			
			MOD_NATIVE(drawCounter) {
				if (!arguments(4))
					return 0;

				::UI::_SET_TEXT_ENTRY("CM_ITEM_COUNT");
				::UI::ADD_TEXT_COMPONENT_INTEGER(params[1]);
				::UI::ADD_TEXT_COMPONENT_INTEGER(params[2]);
				::UI::_DRAW_TEXT(amx_ctof(params[3]), amx_ctof(params[4]));
				return 1;
			}

			MOD_NATIVE(drawBox) {
				if (!arguments(3))
					return 0;

				float point1[3], point2[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], point1, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], point2, 3))
					return 0;

				Utility::Color color(params[3]);
				GRAPHICS::DRAW_BOX(point1[0], point1[1], point1[2], point2[0], point2[1], point2[2], color.R, color.G, color.B, color.A);

				return 1;
			}

			MOD_NATIVE(drawLine) {
				if (!arguments(3))
					return 0;

				float point1[3], point2[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], point1, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], point2, 3))
					return 0;

				Utility::Color color(params[3]);
				GRAPHICS::DRAW_LINE(point1[0], point1[1], point1[2], point2[0], point2[1], point2[2], color.R, color.G, color.B, color.A);

				return 1;
			}

			MOD_NATIVE(drawPoly) {
				if (!arguments(4))
					return 0;

				float point1[3], point2[3], point3[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], point1, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], point2, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], point3, 3))
					return 0;

				Utility::Color color(params[3]);
				GRAPHICS::DRAW_POLY(
					point1[0], point1[1], point1[2],
					point2[0], point2[1], point2[2],
					point3[0], point3[1], point3[2],
					color.R, color.G, color.B, color.A
				);

				return 1;
			}

			MOD_NATIVE(drawRect) {
				if (!arguments(5))
					return 0;

				Utility::Color color(params[5]);
				Funcs::drawRect(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), color.R, color.G, color.B, color.A);

				return 1;
			}

			MOD_NATIVE(drawMarker) {
				if (!arguments(9))
					return 0;

				float coords[3], dir[3], rot[3], scale[3];
				if (!Utility::getFloatArrayFromParam(amx, params[2], coords, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[3], dir, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[4], rot, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[5], scale, 3))
					return 0;

				Utility::Color color(params[6]);

				GRAPHICS::DRAW_MARKER(
					params[1],
					coords[0], coords[1], coords[2], // x y z
					dir[0], dir[1], dir[2], // dx dy dz
					rot[0], rot[1], rot[2], // rx ry rz
					scale[0], scale[1], scale[2], // sx sy sz
					color.R, color.G, color.B, color.A, // r b g a
					params[7], params[8], 2, FALSE, NULL, NULL, params[9]
				);

				return 1;
			}

			MOD_NATIVE(drawSprite) {
				if (!arguments(8))
					return 0;

				Utility::Color color(params[8]);

				GRAPHICS::DRAW_SPRITE(
					(char *)String::get(amx, params[1]).c_str(),
					(char *)String::get(amx, params[2]).c_str(),
					amx_ctof(params[3]), amx_ctof(params[4]),
					amx_ctof(params[5]), amx_ctof(params[6]),
					amx_ctof(params[7]),
					color.R, color.G, color.B, color.A
				);

				return 1;
			}

			MOD_NATIVE(drawSpotLight) {
				if (!arguments(8))
					return 0;

				float coords[3], dir[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], dir, 3))
					return 0;

				Utility::Color color(params[8]);

				GRAPHICS::DRAW_SPOT_LIGHT(
					coords[0], coords[1], coords[2],
					dir[0], dir[1], dir[2],
					color.R, color.G, color.B,
					amx_ctof(params[3]), amx_ctof(params[4]),
					amx_ctof(params[5]), amx_ctof(params[6]),
					amx_ctof(params[7])
				);

				return 1;
			}

			MOD_NATIVE(drawSpotLightWithShadow) {
				if (!arguments(9))
					return 0;

				float coords[3], dir[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3) ||
					!Utility::getFloatArrayFromParam(amx, params[2], dir, 3))
					return 0;

				Utility::Color color(params[9]);

				GRAPHICS::_DRAW_SPOT_LIGHT_WITH_SHADOW(
					coords[0], coords[1], coords[2],
					dir[0], dir[1], dir[2],
					color.R, color.G, color.B,
					amx_ctof(params[3]), amx_ctof(params[4]),
					amx_ctof(params[5]), amx_ctof(params[6]),
					amx_ctof(params[7]), params[8]
				);

				return 1;
			}
			
			MOD_NATIVE(drawLightWithRange) {
				if (!arguments(4))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				Utility::Color color(params[4]);

				GRAPHICS::DRAW_LIGHT_WITH_RANGE(
					coords[0], coords[1], coords[2],
					color.R, color.G, color.B, amx_ctof(params[2]), amx_ctof(params[3])
				);

				return 1;
			}

			MOD_NATIVE(drawLightWithRangeAndShadow) {
				if (!arguments(4))
					return 0;

				float coords[3];
				if (!Utility::getFloatArrayFromParam(amx, params[1], coords, 3))
					return 0;

				Utility::Color color(params[5]);

				GRAPHICS::_DRAW_LIGHT_WITH_RANGE_WITH_SHADOW(
					coords[0], coords[1], coords[2],
					color.R, color.G, color.B, amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4])
				);

				return 1;
			}

			MOD_NATIVE(setTextDropShadow) {
				if (!arguments(2))
					return 0;

				Utility::Color color(params[2]);
				::UI::SET_TEXT_DROPSHADOW(params[1], color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setTextEdge) {
				if (!arguments(2))
					return 0;

				Utility::Color color(params[2]);
				::UI::SET_TEXT_EDGE(params[1], color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setTextWrap) {
				if (!arguments(2))
					return 0;

				::UI::SET_TEXT_WRAP(amx_ctof(params[1]), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setTextColor) {
				if (!arguments(1))
					return 0;

				Utility::Color color(params[1]);
				::UI::SET_TEXT_COLOUR(color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setTextCentre) {
				if (!arguments(1))
					return 0;

				::UI::SET_TEXT_CENTRE(params[1]);

				return 1;
			}
			
			MOD_NATIVE(setTextFont) {
				if (!arguments(1))
					return 0;

				::UI::SET_TEXT_FONT(params[1]);

				return 1;
			}
			
			MOD_NATIVE(setTextJustification) {
				if (!arguments(1))
					return 0;

				::UI::SET_TEXT_JUSTIFICATION(params[1]);

				return 1;
			}
			
			MOD_NATIVE(setTextRightJustify) {
				if (!arguments(1))
					return 0;

				::UI::SET_TEXT_RIGHT_JUSTIFY(params[1]);

				return 1;
			}
			
			MOD_NATIVE(setTextEntry) {
				if (!arguments(1))
					return 0;

				::UI::_SET_TEXT_ENTRY((char *)String::get(amx, params[1]).c_str());

				return 1;
			}
			
			MOD_NATIVE(setTextScale) {
				if (!arguments(2))
					return 0;

				::UI::SET_TEXT_SCALE(amx_ctof(params[1]), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setUILayer) {
				if (!arguments(1))
					return 0;

				GRAPHICS::_0x61BB1D9B3A95D802(params[1]);

				return 1;
			}

			MOD_NATIVE(setDrawPos) {
				if (!arguments(2))
					return 0;

				GRAPHICS::_SET_SCREEN_DRAW_POSITION(amx_ctof(params[1]), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setDrawPosRatio) {
				if (!arguments(4))
					return 0;

				GRAPHICS::_0xF5A2C681787E579D(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));

				return 1;
			}

			MOD_NATIVE(setDrawPosEnd) {
				GRAPHICS::_0xE3A3DB414A373DAB();

				return 1;
			}
			
			MOD_NATIVE(loadTextureDict) {
				if (!arguments(1))
					return 0;

				GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char *)String::get(amx, params[1]).c_str(), TRUE);

				return 1;
			}
			
			MOD_NATIVE(isTextureDictLoaded) {
				if (!arguments(1))
					return 0;

				return GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char *)String::get(amx, params[1]).c_str());
			}
			
			MOD_NATIVE(unloadTextureDict) {
				if (!arguments(1))
					return 0;

				GRAPHICS::SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED((char *)String::get(amx, params[1]).c_str());

				return 1;
			}
			
			MOD_NATIVE(getTextureDictSize) {
				if (!arguments(3))
					return 0;

				Vector3 res = GRAPHICS::GET_TEXTURE_RESOLUTION((char *)String::get(amx, params[1]).c_str(), (char *)String::get(amx, params[2]).c_str());

				return Utility::setVector3ToParam(amx, params[3], res);
			}

			MOD_NATIVE(addTextComponentStr) {
				::UI::_ADD_TEXT_COMPONENT_STRING((char *)String::get(amx, params[1]).c_str());

				return 1;
			}

			MOD_NATIVE(addTextComponentInt) {
				::UI::ADD_TEXT_COMPONENT_INTEGER(params[1]);

				return 1;
			}

			MOD_NATIVE(addTextComponentFloat) {
				::UI::ADD_TEXT_COMPONENT_FLOAT(amx_ctof(params[1]), params[2]);

				return 1;
			}
		};
	};
};