#include "AllwInit/Allw.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_video.h>
#include <allegro5/allegro_native_dialog.h>

namespace Allw {


	Allw::Allw(Init::Mode mode, float width, float height, float fps)
	{
		if (al_init())
			this->success = true;

		switch (mode) {
		case Init::Mode::Full:
			if (success)
				initNativeDialogAddon();
			if (success)
				initVideoAddon();
			if (success)
				initAudioAddon();
			if (success)
				initImageAddon();
		case Init::Mode::Events:
			if (success)
				initEventsAddon();
			if (success)
				initMouseAddon();
			if (success && fps == Init::NoValue)
				initTimerAddon();
			else if (success)
				initTimerAddon(fps);
		case Init::Mode::Basic:
			if (success)
				initDisplayAddon(width, height);
			if (success)
				initKeyboardAddon();
			if (success)
				initFontAddon();
			if (success)
				initPrimitivesAddon();
		case Init::Mode::Empty:
			break;
		}

		if (success && (mode == Init::Mode::Full || mode == Init::Mode::Events))
			registerAllAvailableEventsSource();
	}

	Allw::Allw()
	{
		if (al_init())
			this->success = true;
	}

	void Allw::initImageAddon()
	{
		if (imageAddon == nullptr) {
			this->imageAddon = new Init::ImageAddon();
			this->success = imageAddon->getSuccess();
		}
	}

	void Allw::initAudioAddon()
	{
		if (audioAddon == nullptr) {
			this->audioAddon = new Init::AudioAddon();
			this->success = audioAddon->getSuccess();
		}
	}
    void Allw::wait(double seconds)
    {
	    al_rest(seconds);
    }

	void Allw::initFontAddon()
	{
		if (fontAddon == nullptr) {
			this->fontAddon = new Init::FontAddon();
			this->success = fontAddon->getSuccess();
		}
	}

	void Allw::initKeyboardAddon()
	{
		if (keyboardAddon == nullptr) {
			this->keyboardAddon = new Init::KeyboardAddon();
			this->success = keyboardAddon->getSuccess();
		}
	}

	void Allw::initDisplayAddon(float x, float y)
	{
		if (displayAddon == nullptr) {
			this->displayAddon = new Init::DisplayAddon(x, y);
			this->success = displayAddon->getSuccess();
		}
	}

	void Allw::initMouseAddon()
	{
		if (mouseAddon == nullptr) {
			this->mouseAddon = new Init::MouseAddon();
			this->success = mouseAddon->getSuccess();
		}
	}

	void Allw::initEventsAddon()
	{
		if (eventsAddon == nullptr) {
			this->eventsAddon = new Init::EventsAddon();
			this->success = eventsAddon->getSuccess();
		}
	}

	void Allw::initTimerAddon(float fps)
	{
		if (this->timerAddon == nullptr) {
			this->timerAddon = new Init::TimerAddon(fps);
			this->success = timerAddon->getSuccess();
		}
	}

	void Allw::initTimerAddon()
	{
		if (this->timerAddon == nullptr) {
			this->timerAddon = new Init::TimerAddon();
			this->success = timerAddon->getSuccess();
		}
	}

	void Allw::initPrimitivesAddon()
	{
		if (primitivesAddon == nullptr) {
			this->primitivesAddon = new Init::PrimitivesAddon();
			this->success = primitivesAddon->getSuccess();
		}
	}

	void Allw::initVideoAddon()
	{
		if (videoAddon == nullptr) {
			this->videoAddon = new Init::VideoAddon();
			this->success = videoAddon->getSuccess();
		}
	}

	void Allw::initNativeDialogAddon()
	{
		if (nativeDialogAddon == nullptr) {
			this->nativeDialogAddon = new Init::NativeDialogAddon();
			this->success = nativeDialogAddon->getSuccess();
		}
	}

	void Allw::uninstallImageAddon()
	{
		if (imageAddon != nullptr)
			delete imageAddon;
		imageAddon = nullptr;
	}

	void Allw::uninstallAudioAddon()
	{
		if (audioAddon != nullptr)
			delete audioAddon;
		audioAddon = nullptr;
	}

	void Allw::uninstallFontAddon()
	{
		if (fontAddon != nullptr)
			delete fontAddon;
		fontAddon = nullptr;
	}

	void Allw::uninstallKeyboardAddon()
	{
		if (keyboardAddon != nullptr)
			delete keyboardAddon;
		keyboardAddon = nullptr;
	}

	void Allw::uninstallDisplayAddon()
	{
		if (displayAddon != nullptr)
			delete displayAddon;
		displayAddon = nullptr;
	}

	void Allw::uninstallMouseAddon()
	{
		if (mouseAddon != nullptr)
			delete mouseAddon;
		mouseAddon = nullptr;
	}

	void Allw::uninstallEventsAddon()
	{
		if (eventsAddon != nullptr)
			delete eventsAddon;
		eventsAddon = nullptr;
	}

	void Allw::uninstallTimerAddon()
	{
		if (timerAddon != nullptr)
			delete timerAddon;
		timerAddon = nullptr;
	}

	void Allw::uninstallPrimitivesAddon()
	{
		if (primitivesAddon != nullptr)
			delete primitivesAddon;
		primitivesAddon = nullptr;
	}

	void Allw::uninstallVideoAddon()
	{
		if (videoAddon != nullptr)
			delete videoAddon;
		videoAddon = nullptr;
	}

	void Allw::uninstallNativeDialogAddon()
	{
		if (nativeDialogAddon != nullptr)
			delete nativeDialogAddon;
		nativeDialogAddon = nullptr;
	}

	void Allw::registerAllAvailableEventsSource()
	{
		if (eventsAddon != nullptr) {
			if (this->timerAddon != nullptr && this->timerAddon->getRefreshTimer() != nullptr)
				eventsAddon->registerEventSourceAddon(timerAddon);
			if (this->keyboardAddon != nullptr)
				eventsAddon->registerEventSourceAddon(keyboardAddon);
			if (this->mouseAddon != nullptr)
				eventsAddon->registerEventSourceAddon(mouseAddon);
			if (this->displayAddon != nullptr && this->displayAddon->getDisplay() != nullptr)
				eventsAddon->registerEventSourceAddon(displayAddon);
		}
	}

	void Allw::registerEventSource(ALLEGRO_VIDEO * video)
	{
		if (this->eventsAddon != nullptr)
			eventsAddon->registerEventSource(video);
	}

	void Allw::registerEventSource(ALLEGRO_DISPLAY * disp)
	{
		if (this->eventsAddon != nullptr)
			eventsAddon->registerEventSource(disp);
	}

	void Allw::registerEventSource(ALLEGRO_TIMER * timer)
	{
		if (this->eventsAddon != nullptr)
			eventsAddon->registerEventSource(timer);
	}

	void Allw::unregisterEventSource(ALLEGRO_VIDEO * video)
	{
		if (eventsAddon != nullptr)
			al_unregister_event_source(this->eventsAddon->getEventQueue(), al_get_video_event_source(video));
	}

	void Allw::unregisterEventSource(ALLEGRO_DISPLAY * disp)
	{
		if (eventsAddon != nullptr)
			al_unregister_event_source(this->eventsAddon->getEventQueue(), al_get_display_event_source(disp));
	}

	void Allw::unregisterEventSource(ALLEGRO_TIMER * timer)
	{
		if (eventsAddon != nullptr)
			al_unregister_event_source(this->eventsAddon->getEventQueue(), al_get_timer_event_source(timer));
	}

	ALLEGRO_EVENT_QUEUE * Allw::getEventQueue()
	{
		return this->eventsAddon->getEventQueue();
	}

	void Allw::setDisplayColor(Color::AllegroColor color)
	{
		displayAddon->setDisplayColor(color);
	}

	void Allw::setDisplayColor(const char * color)
	{
		displayAddon->setDisplayColor(Color::AllegroColor(color));
	}

	void Allw::setDisplayName(const char * name)
	{
		al_set_window_title(displayAddon->getDisplay(), name);
	}

	void Allw::setMainDisplay()
	{
		al_set_target_backbuffer(this->displayAddon->getDisplay());
	}

	void Allw::updateDisplay()
	{
		displayAddon->updateDisplay();
	}

	ALLEGRO_DISPLAY * Allw::getDisplay()
	{
		return displayAddon->getDisplay();
	}


	Allw::~Allw()
	{
		this->uninstallImageAddon();
		this->uninstallAudioAddon();
		this->uninstallFontAddon();
		this->uninstallKeyboardAddon();
		this->uninstallDisplayAddon();
		this->uninstallMouseAddon();
		this->uninstallEventsAddon();
		this->uninstallTimerAddon();
		this->uninstallPrimitivesAddon();
		this->uninstallVideoAddon();
	}

	bool Allw::inhibitScreenSaver()
	{
		return al_inhibit_screensaver(true);
	}

	bool Allw::allowScreenSaver()
	{
		return al_inhibit_screensaver(false);
	}

}