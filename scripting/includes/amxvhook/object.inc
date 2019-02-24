#if defined __object_inc__
  #endinput
#endif
#define __object_inc__

native createObect(modelHash, coords[@Vector3], bool:dynamic);
native createObectNoOffset(modelHash, coords[@Vector3], bool:dynamic);
native deleteObject(object);

native setObjectTargettable(object, bool:targettable);

native slideObject(object, to[@Vector3], speed[@Vector3], bool:collision);
