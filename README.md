# Rek-Warfare
Awesome 2D Platform shooting game

[![Download Rek Warfare](https://sourceforge.net/sflogo.php?type=8&group_id=2412225)](https://sourceforge.net/p/rekwarfare/)

<i>Also:</i> Check out another project by a group of my friends called ![zordzman-plus-plus](https://github.com/TeamLe-Shop/zordzman-plus-plus)!

# SDL2
This project uses ![SDL2](http://libsdl.org/)

Including: ![SDL2_image](http://www.libsdl.org/projects/SDL_image/)

# Building Rek Warfare

### Linux ###

~ Make sure you install `cmake` with your package manager (apt, yum, pacman, etc.).

~ Now you go to the directory where `Rek-Warfare` is located in, and type the following:

```
mkdir rek-build   # We want to make a separate folder for our build files
cd rek-build
```

Keeping the build files in a separate directory helps keep our source folder *clean*.

~ After this, create a file named `rwbuild.sh` inside `rek-build`.

~ Open `rwbuild.sh` and copy paste the code from ![here](https://gist.github.com/Microcoding/11ade7e4d98708d8917c#file-rwbuild-sh).

~ Now, go to your terminal, `cd` (navigate) to `rek-build` and write this:

```
chmod 777 ./rwbuild.sh
```

~ After that, you can easily build Rek Warfare whenever you want with this command (as long as you stay in the `rek-build` folder):

`./rwbuild.sh`


### Other Operating Systems ###

Instructions for other operating systems are currently not available. If you know how to build using another operating system, fork this repository and make a pull request with README.md edited with build instructions.


