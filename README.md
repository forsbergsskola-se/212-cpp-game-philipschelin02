# SDL Cookie Clicker

Welcome to my README file! In this document, I go over what's going on behind the scenes of my Cookie Clicker project. Please have a read!

# Description

This here, is my SDL game I created in my time at Forsbergs Skola.

Right off the bat you might notice it really isn't that much of a game, as the only thing you do is press a button, the button goes down,
and the score counter goes up every time you do so. See the attached videos and pictures down below:

https://github.com/forsbergsskola-se/212-cpp-game-philipschelin02/assets/112477616/9285ce86-abbe-42d7-bbc2-b7ff241ae463

![image](https://github.com/forsbergsskola-se/212-cpp-game-philipschelin02/assets/112477616/9342c1fc-69b6-4d3a-9c39-16a3464f0665)

![screenshot_2](https://github.com/forsbergsskola-se/212-cpp-game-philipschelin02/assets/112477616/e7303cfe-187d-49dc-b0fe-8eb619d3a61a)

While this is definitely true, it doesn't take away the fact that even then, this isn't more basic of an SDL project than any other. In fact, I like to see it as more of an abstract, dadaistic art project, in software-form.

Truth is that a lot of the most necessary and common of SDL functions are being used behind the scenes, in this program.

Not only is this project an example of native C++ programming, but many other factors come into play:

Game loop: The game is relatively simple and similar, so it essentially relies on looping. You press the button down, the button's image changes, and the counter on top of this button goes up once. This process is looped as many times as you press space.

SDL: This game heavily uses SDL libraries, which provides support for 2D pixel operations, sound, file access, event handling, timing and threading. Aside from these, the game is written almost entirely in C++.

Texture loading: This game uses image files to display graphics. These, of course, count as textures.

Observer patterns: This is the most important point in my opinion. This program utilizes so-called observer patterns. It does this by notifying every time the button is pressed. One could implement things such as achievements, using this type of technology.

Thank you for reading, and enjoy my all-you-can-click software!
