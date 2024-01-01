#pragma once

#include <Kaleidoscope.h>
//#include "kaleidoscope/plugin/LEDModeInterface.h"
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-FocusSerial.h>
namespace kaleidoscope {
    namespace plugin {

        class ScreenSaverLEDs: public Plugin {
            public:
            // Basic plugin status functions.

            static void enable();
            static void disable();
            static bool active();

            static uint32_t idleTimeoutSeconds();
            static void setIdleTimeoutSeconds(uint32_t new_limit);
            static kaleidoscope::plugin::LEDModeInterface * screenSaverLEDEffect();
            static void setScreenSaverLEDEffect(kaleidoscope::plugin::LEDModeInterface & mode);

            // Event handlers. Delete what you don't need.
            // EventHandlerResult onSetup();
            EventHandlerResult beforeEachCycle();
            EventHandlerResult onKeyEvent(KeyEvent &event);
            // EventHandlerResult beforeReportingState();
            // EventHandlerResult afterEachCycle();

            // EventHandlerResult onLayerChange();

            private:
            static uint32_t idle_time_limit;
            static bool disabled_;
            static bool idle_;
            static uint32_t start_time_;
            static kaleidoscope::plugin::LEDModeInterface * saver_mode_;
            static uint8_t normal_mode_index_;
        };


    }  // namespace plugin
}  // namespace kaleidoscope

extern kaleidoscope::plugin::ScreenSaverLEDs ScreenSaverLEDs;
