#if defined __amxvhook_inc__
  #endinput
#endif
#define __amxvhook_inc__

#include <core>
#include <float>

#include <amxvhook\defines>
#include <amxvhook\player>
#include <amxvhook\ui>
#include <amxvhook\graphics>
#include <amxvhook\input>
#include <amxvhook\blip>
#include <amxvhook\gameplay>
#include <amxvhook\checkpoint>
#include <amxvhook\vehicle>
#include <amxvhook\ped>
#include <amxvhook\entity>
#include <amxvhook\camera>

forward onModLoad();
forward onModUnload();
forward onModUpdate();

native log(text[]);

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

// native callFunction(const funcname[], const f[]="", bool:local=true, {Float,_}:...});

native format(dest[], size=sizeof dest, bool:pack=false, const format[], {Float,_}:...) = strformat;