#if defined __amxvhook_inc__
  #endinput
#endif
#define __amxvhook_inc__

#include <core>
#include <float>

#include <amxvhook\defines>
#include <amxvhook\player>
#include <amxvhook\graphics>
#include <amxvhook\input>
#include <amxvhook\blip>
#include <amxvhook\gameplay>
#include <amxvhook\checkpoint>
#include <amxvhook\vehicle>
#include <amxvhook\ped>
#include <amxvhook\entity>
#include <amxvhook\camera>
#include <amxvhook\time>

forward onModLoad();
forward onModUnload();
forward onModUpdate();

native log(const text[]);
native logf(const text[], {Float, _}:...);

native isModLoaded(const modname[]);

native getFps();
native getVersion();
native getPoolSize();
native getTickCount();
native getAllPeds(dest[], len = sizeof dest);
native getAllObjects(dest[], len = sizeof dest);
native getAllPickups(dest[], len = sizeof dest);
native getAllVehicles(dest[], len = sizeof dest);

native setVersionVisible(bool:visible);

native callFunc(const funcname[], const f[]="", bool:remote=false, {Float,_}:...);

native format(dest[], size=sizeof dest, const format[], {Float, _}:...);