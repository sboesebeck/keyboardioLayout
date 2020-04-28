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

#include "LEDEffectSwitchOnLayer.h"

namespace kaleidoscope {
namespace plugin {

// LEDEffectSwitchOnLayer

// Member variables.
bool LEDEffectSwitchOnLayer::disabled_ = false;
LEDModeInterface* LEDEffectSwitchOnLayer::activePlugins[32] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };


// Basic plugin status functions.

// Enable the plugin.
void LEDEffectSwitchOnLayer::enable() {
  disabled_ = false;
}

// Disable the plugin.
void LEDEffectSwitchOnLayer::disable() {
  disabled_ = true;
}

// Returns true if the plugin is enabled.
bool LEDEffectSwitchOnLayer::active() {
  return !disabled_;
}

// setting plugins for certain layers

void LEDEffectSwitchOnLayer::setPluginForLayer(int layer,LEDModeInterface &p){
    activePlugins[layer]=&p;
}
// Event handlers.

// Runs once, when the plugin is initialized during Kaleidoscope.setup().
EventHandlerResult LEDEffectSwitchOnLayer::onSetup() {
  // Code goes here.
  return EventHandlerResult::OK;
}

// Run as the first thing at the start of each cycle.
EventHandlerResult LEDEffectSwitchOnLayer::beforeEachCycle() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Run for every non-idle key, in each cycle the key isn't idle in. If a key
// gets pressed, released, or is held, it is not considered idle, and this
// event handler will run for it too.
EventHandlerResult LEDEffectSwitchOnLayer::onKeyswitchEvent(Key &mapped_key,KeyAddr key_addr, 
                                               uint8_t key_state) {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Runs each cycle right before sending the various reports (keys pressed, mouse
// events, etc) to the host.
EventHandlerResult LEDEffectSwitchOnLayer::beforeReportingState() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Runs at the very end of each cycle.
EventHandlerResult LEDEffectSwitchOnLayer::afterEachCycle() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

EventHandlerResult LEDEffectSwitchOnLayer::onLayerChange() {
  if (activePlugins[Layer.top()]!=NULL){
	activePlugins[Layer.top()]->activate();
  }
  return EventHandlerResult::OK;
}

}  // namespace plugin
}  // namespace kaleidoscope

kaleidoscope::plugin::LEDEffectSwitchOnLayer LEDEffectSwitchOnLayer;
