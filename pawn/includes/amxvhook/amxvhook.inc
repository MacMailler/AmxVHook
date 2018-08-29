#if defined __amxvhook_inc__
  #endinput
#endif
#define __amxvhook_inc__


#include <core>
#include <float>
#include <string>

#include <amxvhook\defines>
#include <amxvhook\player>
#include <amxvhook\graphics>
#include <amxvhook\ui>
#include <amxvhook\input>
#include <amxvhook\blip>
#include <amxvhook\gameplay>
#include <amxvhook\checkpoint>
#include <amxvhook\vehicle>
#include <amxvhook\ped>
#include <amxvhook\entity>
#include <amxvhook\camera>
#include <amxvhook\time>
#include <amxvhook\weapon>
#include <amxvhook\streaming>
#include <amxvhook\audio>
#include <amxvhook\timer>
#include <amxvhook\misc>

forward onModLoad();
forward onModUnload();
forward onModUpdate();

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

native log(const text[], {Float, _}:...);
native format(dest[], maxlen = sizeof dest, const fstr[], {Float, _}:...);
native callFunc(const funcname[], const fstr[]="", const modname[]="self", {Float, _}:...);

//native strtok(const str[], dest[][], const delims[] = " ", maxtokens = sizeof dest, maxlen = sizeof dest[]);