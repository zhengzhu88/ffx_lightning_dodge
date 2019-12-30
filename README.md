# Final Fantasy X Lightning Dodger

This project aims to beat the challenge in [Final Fantasy X](https://en.wikipedia.org/wiki/Final_Fantasy_X) where the player must dodge 200 lightning bolts consecutively.

## Minigame background
The minigame involves dodging the randomly spaced lightning bolts that will strike the player's avatar while it is in the overworld. Before the bolt strikes, the screen will flash white for a fraction of a second, and to dodge a lightning bolt, the player must press the X button during this flash.

### Minigame challenges
There are a number of challenges that make this minigame one of the hardest in the game.
1. Short input window --- The input window for the button press is incredibly short, on the order of 10 frames.
2. No button mashing --- The natural response to this challenge is to mash X for 20 to 30 minutes to get the 200 dodges. The developers anticipated this workaround though, and programmed the game to send an undodgeable lightning bolt if it thought the player was button mashing. Since the challenge is to dodge bolts **consecutively**, the natural button mashing approach doesn't work.
3. No progress saving --- In addition to getting struck by lightning, saving the game, leaving the map, or otherwise doing anything that isn't dodging lightning bolts will reset the counter.
4. Mental strain --- While there are ways to make the pattern of lightning strikes a little more consistent, the player still has to sit and maintain unwavering focus for around 20 minutes, making sure not to miss a single input window during that time.

## Technical Details

### Description
The circuit is actually fairly straightforward; it's an Arduino connected to a photodetector and a servo. The Arduino reads at a predefined sample rate from the photodetector, and the Arduino buffers the last 10 readings to establish a baseline voltage. Flashes trigger a decrease in voltage that then triggers the Arduino to rotate the servo.

### Challenges
Initially, the idea was to solve the challenge using OpenCV, but the timing was simply too strict for the operating system. After that, I ran into the following challenges, listed approximately in chronological order:
* Figuring out which parts to buy for my circuit
* Learning how to write Arduino code (turns out it's basically C)
* Working around noisy photodetector values
* Finding servo rotation angles that work well

## Motivation
Beating this challenge grants the player an item that unlocks the full powers of an ultimate weapon. More personally, the full-powered ultimate weapon was the very last objective I had for this game. Since I got the game in 2001, I had thoroughly completed every other possible objective, both formal and informal, the game had to offer. I attempted this challenge normally, but I only ever got as high as 197 consecutive dodges before I was struck. The fact that each attempt took around 20 minutes was also frustrating, because every lightning strike I missed represented another 20 minutes of work gone. I figured that a computer would be much more capable and consistent than I could be.

## Notes
Project inspired by this [video](https://www.youtube.com/watch?v=2HbIHVoTY2M).
Thanks to [redwall9](https://github.com/redwall9) for general EE consulting.
