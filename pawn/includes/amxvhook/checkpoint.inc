#if defined __checkpoint_inc__
  #endinput
#endif
#define __checkpoint_inc__

native createCP(type, Float:p1[@Vector3], Float:p2[@Vector3]={0,0,0}, Float:radius = 2.0, color = 0xFFFFFFFF);
native setCPScale(checkpoint, Float:scale);
native setCPCylinderHeight(checkpoint, Float:nearHeight, Float:farHeight, Float:radius);
native setCPColor(checkpoint, color = 0xFFFFFFFF);
native setCPIconColor(checkpoint, color = 0xFFFFFFFF);
native deleteCP(checkpoint);