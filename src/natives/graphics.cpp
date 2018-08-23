#include "graphics.hpp"

namespace AmxVHook {
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
				checkargs(1);

				Fs::path path = Fs::system_complete(".\\AmxVHook\\Stuff\\" + String::get(amx, params[1]));
				if (Fs::exists(path) && !Fs::is_directory(path))
					return ::createTexture(path.string().c_str());
				
				return -1;
			}

			MOD_NATIVE(drawTexture) {
				checkargs(10);

				cell *size, *center, *pos, *color;
				if (amx_GetAddr(amx, params[5], &size) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[6], &center) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[7], &pos) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[10], &color) != AMX_ERR_NONE)
					return 0;

				::drawTexture(
					params[1], params[2], params[3], params[4],
					amx_ctof(size[0]), amx_ctof(size[1]),
					amx_ctof(center[0]), amx_ctof(center[1]),
					amx_ctof(pos[0]), amx_ctof(pos[1]),
					amx_ctof(params[8]), amx_ctof(params[9]),
					amx_ctof(color[0]), amx_ctof(color[1]), amx_ctof(color[2]), amx_ctof(color[3])
				);

				return 1;
			}

			MOD_NATIVE(drawInt) {
				checkargs(3);

				Funcs::drawInt(params[1], amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(drawFloat) {
				checkargs(4);

				Funcs::drawFloat(amx_ctof(params[1]), params[4], amx_ctof(params[2]), amx_ctof(params[3]));

				return 1;
			}

			MOD_NATIVE(drawString) {
				checkargs(7);

				Color color(params[6]);

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
				checkargs(4);

				::UI::_SET_TEXT_ENTRY("CM_ITEM_COUNT");
				::UI::ADD_TEXT_COMPONENT_INTEGER(params[1]);
				::UI::ADD_TEXT_COMPONENT_INTEGER(params[2]);
				::UI::_DRAW_TEXT(amx_ctof(params[3]), amx_ctof(params[4]));
				
				return 1;
			}

			MOD_NATIVE(drawBox) {
				checkargs(3);
				
				cell *p1, *p2;
				if (amx_GetAddr(amx, params[1], &p1) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &p2) != AMX_ERR_NONE)
					return 0;

				Color color(params[3]);
				
				GRAPHICS::DRAW_BOX(
					amx_ctof(p1[0]), amx_ctof(p1[1]), amx_ctof(p1[2]),
					amx_ctof(p2[0]), amx_ctof(p2[1]), amx_ctof(p2[2]),
					color.R, color.G, color.B, color.A
				);

				return 1;
			}

			MOD_NATIVE(drawLine) {
				checkargs(3);

				cell *p1, *p2;
				if (amx_GetAddr(amx, params[1], &p1) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &p2) != AMX_ERR_NONE)
					return 0;

				Color color(params[3]);
				
				GRAPHICS::DRAW_LINE(
					amx_ctof(p1[0]), amx_ctof(p1[1]), amx_ctof(p1[2]),
					amx_ctof(p2[0]), amx_ctof(p2[1]), amx_ctof(p2[2]),
					color.R, color.G, color.B, color.A
				);

				return 1;
			}

			MOD_NATIVE(drawPoly) {
				checkargs(4);

				cell *p1, *p2, *p3;
				if (amx_GetAddr(amx, params[1], &p1) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &p2) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &p3) != AMX_ERR_NONE)
					return 0;

				Color color(params[4]);
				
				GRAPHICS::DRAW_POLY(
					amx_ctof(p1[0]), amx_ctof(p1[1]), amx_ctof(p1[2]),
					amx_ctof(p2[0]), amx_ctof(p2[1]), amx_ctof(p2[2]),
					amx_ctof(p3[0]), amx_ctof(p3[1]), amx_ctof(p3[2]),
					color.R, color.G, color.B, color.A
				);

				return 1;
			}

			MOD_NATIVE(drawRect) {
				checkargs(5);

				Color color(params[5]);
				Funcs::drawRect(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), color.R, color.G, color.B, color.A);

				return 1;
			}

			MOD_NATIVE(drawMarker) {
				checkargs(9);
					
				cell *coords, *dir, *rot, *scale;
				if (amx_GetAddr(amx, params[2], &coords) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[3], &dir) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[4], &rot) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[5], &scale) != AMX_ERR_NONE)
					return 0;


				Color color(params[6]);

				GRAPHICS::DRAW_MARKER(
					params[1],
					amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]), // x y z
					amx_ctof(dir[0]), amx_ctof(dir[1]), amx_ctof(dir[2]), // dx dy dz
					amx_ctof(rot[0]), amx_ctof(rot[1]), amx_ctof(rot[2]), // rx ry rz
					amx_ctof(scale[0]), amx_ctof(scale[1]), amx_ctof(scale[2]), // sx sy sz
					color.R, color.G, color.B, color.A, // r b g a
					params[7], params[8], 2, FALSE, NULL, NULL, params[9]
				);

				return 1;
			}

			MOD_NATIVE(drawSprite) {
				checkargs(8);

				Color color(params[8]);

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
				checkargs(8);

				cell *coords, *dir;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &dir) != AMX_ERR_NONE)
					return 0;
					
				Color color(params[8]);

				GRAPHICS::DRAW_SPOT_LIGHT(
					amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]),
					amx_ctof(dir[0]), amx_ctof(dir[1]), amx_ctof(dir[2]),
					color.R, color.G, color.B,
					amx_ctof(params[3]), amx_ctof(params[4]),
					amx_ctof(params[5]), amx_ctof(params[6]),
					amx_ctof(params[7])
				);

				return 1;
			}

			MOD_NATIVE(drawSpotLightWithShadow) {
				checkargs(9);

				cell *coords, *dir;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE ||
					amx_GetAddr(amx, params[2], &dir) != AMX_ERR_NONE)
					return 0;

				Color color(params[9]);

				GRAPHICS::_DRAW_SPOT_LIGHT_WITH_SHADOW(
					amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]),
					amx_ctof(dir[0]), amx_ctof(dir[1]), amx_ctof(dir[2]),
					color.R, color.G, color.B,
					amx_ctof(params[3]), amx_ctof(params[4]),
					amx_ctof(params[5]), amx_ctof(params[6]),
					amx_ctof(params[7]), params[8]
				);

				return 1;
			}
			
			MOD_NATIVE(drawLightWithRange) {
				checkargs(4);

				cell *coords;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE)
					return 0;

				Color color(params[4]);

				GRAPHICS::DRAW_LIGHT_WITH_RANGE(
					amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]),
					color.R, color.G, color.B, amx_ctof(params[2]), amx_ctof(params[3])
				);

				return 1;
			}

			MOD_NATIVE(drawLightWithRangeAndShadow) {
				checkargs(4);

				cell *coords;
				if (amx_GetAddr(amx, params[1], &coords) != AMX_ERR_NONE)
					return 0;

				Color color(params[5]);

				GRAPHICS::_DRAW_LIGHT_WITH_RANGE_WITH_SHADOW(
					amx_ctof(coords[0]), amx_ctof(coords[1]), amx_ctof(coords[2]),
					color.R, color.G, color.B, amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4])
				);

				return 1;
			}

			MOD_NATIVE(setTextDropShadow) {
				checkargs(2);

				Color color(params[2]);
				::UI::SET_TEXT_DROPSHADOW(params[1], color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setTextEdge) {
				checkargs(2);

				Color color(params[2]);
				::UI::SET_TEXT_EDGE(params[1], color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setTextWrap) {
				checkargs(2);

				::UI::SET_TEXT_WRAP(amx_ctof(params[1]), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setTextColor) {
				checkargs(1);

				Color color(params[1]);
				::UI::SET_TEXT_COLOUR(color.R, color.G, color.B, color.A);

				return 1;
			}
			
			MOD_NATIVE(setTextCentre) {
				checkargs(1);

				::UI::SET_TEXT_CENTRE(params[1]);

				return 1;
			}
			
			MOD_NATIVE(setTextFont) {
				checkargs(1);

				::UI::SET_TEXT_FONT(params[1]);

				return 1;
			}
			
			MOD_NATIVE(setTextJustification) {
				checkargs(1);

				::UI::SET_TEXT_JUSTIFICATION(params[1]);

				return 1;
			}
			
			MOD_NATIVE(setTextRightJustify) {
				checkargs(1);

				::UI::SET_TEXT_RIGHT_JUSTIFY(params[1]);

				return 1;
			}
			
			MOD_NATIVE(setTextEntry) {
				checkargs(1);

				::UI::_SET_TEXT_ENTRY((char *)String::get(amx, params[1]).c_str());

				return 1;
			}
			
			MOD_NATIVE(setTextScale) {
				checkargs(2);

				::UI::SET_TEXT_SCALE(amx_ctof(params[1]), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setUILayer) {
				checkargs(1);

				GRAPHICS::_0x61BB1D9B3A95D802(params[1]);

				return 1;
			}

			MOD_NATIVE(setDrawPos) {
				checkargs(2);

				GRAPHICS::_SET_SCREEN_DRAW_POSITION(amx_ctof(params[1]), amx_ctof(params[2]));

				return 1;
			}

			MOD_NATIVE(setDrawPosRatio) {
				checkargs(4);

				GRAPHICS::_0xF5A2C681787E579D(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));

				return 1;
			}

			MOD_NATIVE(setDrawPosEnd) {
				GRAPHICS::_0xE3A3DB414A373DAB();

				return 1;
			}
			
			MOD_NATIVE(loadTextureDict) {
				checkargs(1);

				GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char *)String::get(amx, params[1]).c_str(), TRUE);

				return 1;
			}
			
			MOD_NATIVE(isTextureDictLoaded) {
				checkargs(1);

				return GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char *)String::get(amx, params[1]).c_str());
			}
			
			MOD_NATIVE(unloadTextureDict) {
				checkargs(1);

				GRAPHICS::SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED((char *)String::get(amx, params[1]).c_str());

				return 1;
			}
			
			MOD_NATIVE(getTextureDictSize) {
				checkargs(3);

				Vector3 res = GRAPHICS::GET_TEXTURE_RESOLUTION((char *)String::get(amx, params[1]).c_str(), (char *)String::get(amx, params[2]).c_str());

				return Aux::setVector3(amx, params[3], res);
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