// Show a "screen saver" LED effect after some amount of idle time,
// then "wake up" next time a key is pressed by restoring the previous effect.
// Based heavily on the IdleLEDs plugin.
#include "ScreenSaverLEDs.h"

namespace kaleidoscope {
    namespace plugin {
        uint32_t ScreenSaverLEDs::idle_time_limit = 600000;  // 10 minutes
        uint32_t ScreenSaverLEDs::start_time_     = 0;
        bool ScreenSaverLEDs::idle_;
        kaleidoscope::plugin::LEDMode * ScreenSaverLEDs::saver_mode_ = nullptr;
        uint8_t ScreenSaverLEDs::normal_mode_index_;

        uint32_t ScreenSaverLEDs::idleTimeoutSeconds() {
            return idle_time_limit / 1000;
        }

        void ScreenSaverLEDs::setIdleTimeoutSeconds(uint32_t new_limit) {
            idle_time_limit = new_limit * 1000;
        }

        kaleidoscope::plugin::LEDMode * ScreenSaverLEDs::screenSaverLEDEffect() {
            return saver_mode_;
        }

        void ScreenSaverLEDs::setScreenSaverLEDEffect(kaleidoscope::plugin::LEDMode & mode) {
            saver_mode_ = & mode;
        }
        kaleidoscope::EventHandlerResult ScreenSaverLEDs::beforeEachCycle() {
            if (idle_time_limit == 0) {
                return kaleidoscope::EventHandlerResult::OK;
            }

            if (!idle_ && saver_mode_ &&
                kaleidoscope::Runtime.hasTimeExpired(start_time_, idle_time_limit)) {
                normal_mode_index_ = ::LEDControl.get_mode_index();
                saver_mode_->activate();
                idle_ = true;
            }

            return kaleidoscope::EventHandlerResult::OK;
        }
        kaleidoscope::EventHandlerResult ScreenSaverLEDs::onKeyEvent(KeyEvent & event) {
            if (idle_) {
                ::LEDControl.set_mode(normal_mode_index_);
                idle_ = false;
            }

            start_time_ = kaleidoscope::Runtime.millisAtCycleStart();
            return kaleidoscope::EventHandlerResult::OK;
        }
    }
}
kaleidoscope::plugin::ScreenSaverLEDs ScreenSaverLEDs;
