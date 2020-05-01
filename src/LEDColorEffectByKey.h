// -*- mode: c++ -*-
// Kaleidoscope-LEDEffectSwitchOnLayer -- A litte plugin that changes an led-effect when the layer changed.
// Copyright (C) 2019 Stephan Bösebeck <stephan@boesebeck.biz>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <Kaleidoscope.h>
//#include "kaleidoscope/plugin/LEDModeInterface.h"
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-FocusSerial.h>
namespace kaleidoscope {
namespace plugin {

class LEDColorEffectByKey: public Plugin {
  public:
    // Basic plugin status functions.
    static void enable();
    static void disable();
    static bool active();
   
    // Event handlers. Delete what you don't need.
    EventHandlerResult onSetup();
    EventHandlerResult beforeEachCycle();
    EventHandlerResult onKeyswitchEvent(Key &mapped_key,KeyAddr key_addr, 
                                        uint8_t key_state);
    EventHandlerResult beforeReportingState();
    EventHandlerResult afterEachCycle();

    EventHandlerResult onLayerChange();

  private:
    static bool disabled_;
};


}  // namespace plugin
}  // namespace kaleidoscope

extern kaleidoscope::plugin::LEDColorEffectByKey LEDColorEffectByKey;
