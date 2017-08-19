#ifndef CONFETTI_ORIGINAL_H
#define CONFETTI_ORIGINAL_H

/* This is adapted from the confetti routine created by Mark Kriegsman */

/*  Usage - confetti_original();
 *   
 *  thisfade
 *  thisdelay
 *  currentPalette and targetPalette
 *  thisdiff
 *  thisindex
 *  thisinc
 *  thisbright
 */


void confetti_original() {                                                                                               // random colored speckles that blink in and fade smoothly

  fadeToBlackBy(leds, NUM_LEDS, 15);                                                                      
  int pos = random16(NUM_LEDS);                                                                                      // Pick an LED at random.
  EVERY_N_MILLISECONDS( 20 ) { thishue++; } // slowly cycle the "base color" through the rainbow
  leds[pos] += CHSV( thishue + random8(64), 200, 255);
  //leds[pos] = ColorFromPalette(currentPalette, thisindex + random8(thisdiff)/4 , thisbright, currentBlending);      // Munge the values and pick a colour from the palette
  //thisindex = thisindex + thisinc;                                                                                  // base palette counter increments here.
}

#endif
