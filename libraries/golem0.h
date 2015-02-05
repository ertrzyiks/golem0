#ifndef _golem0_included
#define _golem0_included

#include <Arduino.h>

#include "core/entity.h"
#include "core/world.h"
#include "core/log.h"

#include "animation/animation.h"

#include "pin/pin.h"
#include "pin/input_pin.h"
#include "pin/output_pin.h"

#include "devices/led/led.h"
#include "devices/button/button.h"

void world_init();

#endif
