# CUB3D

## About

Cub3d is an impressive project that offers a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective.<br />
This captivating project is achieved by implementing Ray-Casting principles, leveraging an array of resources and [documents](https://lodev.org/cgtutor/raycasting.html) available on the internet for guidance.<br />
This synergy between mathematical precision and innovative design allows Cub3d to transform a simple maze into an immersive 3D world, where players can explore and navigate with a truly engaging first-person view.<br />

Made together with [ZPedro99](https://github.com/ZPedro99).

## Little Demo On How The Project Works


![ezgif com-video-to-gif(1)-min](https://github.com/RafaSoares1/CUB3D/assets/103336451/c9057800-168d-4527-a2a5-9eae973be42d)

## Understand the subject
The project must respect certain aspects:

- Using minilibx library;
- Display different wall textures for north, south, east and west
- Set colors for the floor and ceiling
- `WASD` must allow to move the "player"
- The left and right arrow keys must allows to rotate the perspective
- `ESC` and the cross on the window's frame must close the program
- The program take a map only with the `.cub` extension


## MinilibX

The minilibx is a C library used for rendering graphics, primarily used by 42 students. As the name implies, this library is built on top of the X Window System API, to provide a much simpler programming interface suited for beginners. Indeed, no X knowledge is needed at all to render graphics properly using this kind of library.

Here are some websites that can help you better understand this library:<br />
https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx <br />
https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx <br />

## How to compile?

First we need to download the MinilibX library to our so_long folder:

```sh
wget https://projects.intra.42.fr/uploads/document/document/15283/minilibx-linux.tgz
```

The project is divided in two parts, the mandatory part and the bonus part.

To compile the mandatory part use:

```sh
make 
```
To compile the bonus part use:

```sh
make bonus
```

### Play the game


To run the game, you must choose one of the maps. Example:

```sh
./cub3D maps/valid_maps/map.cub
```

Or for the bonus:

```sh
./cub3D_bonus maps/valid_maps/map.cub
```

### Game Elements

| CHARACTER  | DESCRIPTION |
| ------------- | ------------- |
|   0 |    Floor |
|   1   |   Wall |
|   N,S,E,W   |   Spwaning Orientation |


### How to play

|KEYBOARD  | 	ACTION |
| ------- | -------- |
|W |	Move up |
|S |	Move down |
|A |	Move left |
|D |	Move right |
|→ |	Rotate right |
|← |	Rotate left |
|ESC ⎋ |	Close the game window |

### Final Grade

![Screenshot 2023-10-17 at 17-57-11 Intra Projects cub3d](https://github.com/RafaSoares1/CUB3D/assets/103336451/c0509757-916f-44a7-9b60-0fc855d92152)

