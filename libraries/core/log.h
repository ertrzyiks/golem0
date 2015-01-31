#ifndef _golem0_log_included
#define _golem0_log_included

#include <Arduino.h>

#ifdef GOLEM0_SUPPRESS_ERRORS
#define Golem0LogError(data) ""
#endif

#ifndef GOLEM_SUPPRESS_ERRORS
#define Golem0LogError(data) if(Serial) Serial.println(data)
#endif

#ifdef GOLEM0_DEBUG
#define Golem0LogDebug(data) if(Serial) Serial.println(data)
#endif

#ifndef GOLEM0_DEBUG
#define GolemLogDebug(data) ""
#endif

#endif
