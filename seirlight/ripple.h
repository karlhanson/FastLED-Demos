
uint8_t r_colour;                                               // Ripple colour is randomized.
int r_center = 0;                                               // Center of the current ripple.
int r_step = -1;                                                // -1 is the initializing step.
#define r_maxsteps 16                                           // Case statement wouldn't allow a variable.


void ripple() {

  max_bright = 255;

  fadeToBlackBy(leds, NUM_LEDS, thisfade);                             // 8 bit, 1 = slow, 255 = fast
  
  switch (r_step) {

    case -1:                                                          // Initialize ripple variables.
      r_center = random(NUM_LEDS);
      r_colour = random8();
      r_step = 0;
      break;

    case 0:
      leds[r_center] = ColorFromPalette(currentPalette, r_colour, thisbright, currentBlending);
      
      r_step ++;
      break;

    case r_maxsteps:                                                    // At the end of the ripples.
      r_step = -1;
      break;

    default:                                                          // Middle of the ripples.
      leds[(r_center + r_step + NUM_LEDS) % NUM_LEDS] += ColorFromPalette(currentPalette, r_colour, thisbright/r_step*2, currentBlending);       // Simple wrap from Marc Miller
      leds[(r_center - r_step + NUM_LEDS) % NUM_LEDS] += ColorFromPalette(currentPalette, r_colour, thisbright/r_step*2, currentBlending);
      r_step ++;                                                         // Next step.
      break;  
  } // switch step
  
} // ripple()

