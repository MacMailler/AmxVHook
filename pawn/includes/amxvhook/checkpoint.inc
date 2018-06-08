#if defined __checkpoint_inc__
  #endinput
#endif
#define __checkpoint_inc__

native createCP(type, Float:p1[@Vector3], Float:p2[@Vector3]={0,0,0}, Float:radius = 2.0, r = 255, g = 255, b = 255, a = 255);
native setCPScale(checkpoint, Float:scale);
native setCPCylinderHeight(checkpoint, Float:nearHeight, Float:farHeight, Float:radius);
native setCPColor(checkpoint, r, g, b, a, type = 0);
native deleteCP(checkpoint);