#include "AllwEvents/AllegroEvent.h"


namespace Allw {
	namespace Event {

		

		AllegroEvent::AllegroEvent(double timeStamp)
		{
			this->timeStamp = timeStamp;
		}

		double AllegroEvent::getTimeStamp()
		{
			return this->timeStamp;
		}



	}
}