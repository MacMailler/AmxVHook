#if defined __streaming_inc__
  #endinput
#endif
#define __streaming_inc__

native isModelValid(modelHash);
native isModelLoaded(modelHash);
native isModelAVehicle(modelHash);
native isModelInRpf(modelHash);
native isEntityFocus(entity);

native setFocusEntity(entity);
native setVehiclePopulationBudget(budget);
native setPedPopulationBudget(budget);
native setInteriorActive(interiorid, bool:toggle);

native loadModel(modelHash);
native unloadModel(modelHash);