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
LEDModeInterface* LEDEffectSwitchOnLayer::effects[32] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };


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

void LEDEffectSwitchOnLayer::setPluginForLayer(int layer,int offset){
    activePlugins[layer]=effects[offset];
}
void LEDEffectSwitchOnLayer::setPluginForLayer(int layer,LEDModeInterface &p){
    activePlugins[layer]=&p;
}

void LEDEffectSwitchOnLayer::setPluginOrder(int num, LEDModeInterface &p){
	effects[num]=&p;
}

LEDModeInterface* LEDEffectSwitchOnLayer::getPlugin(int num){
	return effects[num];
}
// Event handlers.
EventHandlerResult LEDEffectSwitchOnLayer::onLayerChange() {
  if (activePlugins[Layer.mostRecent()]!=NULL){
	activePlugins[Layer.mostRecent()]->activate();
  }
  return EventHandlerResult::OK;
}

}  // namespace plugin
}  // namespace kaleidoscope

kaleidoscope::plugin::LEDEffectSwitchOnLayer LEDEffectSwitchOnLayer;
