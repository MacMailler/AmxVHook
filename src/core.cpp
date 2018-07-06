#include "core.hpp"

namespace AmxVHook {

	extern boost::shared_ptr<Pool> gPool;
	extern boost::shared_ptr<Debug> gDebug;

	namespace Core {

		cell lastFrames = 0;
		bool versionVisible = true;

		void init() {
			if (!boost::filesystem::exists(".\\AmxVHook"))
				boost::filesystem::create_directory(".\\AmxVHook");

			gDebug = boost::make_shared<Debug>(".\\AmxVHook\\amxvhook.log");
			gPool = boost::make_shared<Pool>();

			gPool->setNatives({
				Natives::Core::list,
				Natives::Ped::list,
				Natives::Blip::list,
				Natives::Player::list,
				Natives::Vehicle::list,
				Natives::Gameplay::list,
				Natives::Graphics::list,
				Natives::Checkpoint::list,
				Natives::Input::list,
				Natives::Entity::list,
				Natives::Camera::list,
				Natives::Time::list,
				Natives::Weapon::list
			});

			gPool->make();

			while (true) {
				static cell timer, frames = 0;
				if (GAMEPLAY::GET_GAME_TIMER() - timer < 1000)
					frames++;
				else {
					timer = GAMEPLAY::GET_GAME_TIMER();
					lastFrames = frames;
					frames = 0;
				}

				Keyboard::displayOnScreeKeyboardProcess();
				gPool->execAll("onModUpdate");
				
				if (versionVisible)
					Funcs::drawText("AmxVHook 0.1", 0.93500f, 0.97500f, 0.2f, 0, 255, 255, 255, 48);

				WAIT(0);
			}
		}

		void cleanup() {
			gPool->clear();
			gPool.reset();
			gDebug.reset();
		}
		
		cell getFps() {
			return lastFrames;
		}
	};
};