#if defined __checkpoint_inc__
  #endinput
#endif
#define __checkpoint_inc__

native createCheckpoint(type, p1[@Vector3], p2[@Vector3]={0.0,...}, Float:radius = 2.0, color = 0xFFFFFFFF, reserved = 0);
native setCheckpointScale(checkpoint, Float:scale);
native setCheckpointCylinderHeight(checkpoint, Float:nearHeight, Float:farHeight, Float:radius);
native setCheckpointColor(checkpoint, color = 0xFFFFFFFF);
native setCheckpointIconColor(checkpoint, color = 0xFFFFFFFF);
native deleteCheckpoint(checkpoint);