//
// IR remote control signal repeater
//
// Copyright 2018 tero.saarni@gmail.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include <mbed.h>

DigitalIn rx(PA_4);  // input from IR receiver chip
PwmOut tx(PB_1);     // output to IR LED

int main(int argc, char const *argv[])
{
  // Remote control signal uses 38 kHz carrier.
  // Reconstruct that by using PWM output pin with
  // (1/38000)/10^-6 = 26.3 usec period
  tx.period_us(26.3);

  while (true)
  {
    // IR receiver uses low for active (TL1838 IR receiver).
    // Value 0.5 gives square wave with 50% duty cycle.
    tx.write(rx.read() ? 0.0 : 0.5);
  }

  return 0;
}
