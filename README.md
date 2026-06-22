# SDL Image Viewer

A simple image viewer built in C using SDL2.

This project reads a binary PPM (P6) image from standard input, parses the image header, extracts RGB pixel data, and renders the image pixel-by-pixel using SDL2.

## Features

* Reads PPM image files (P6 format)
* Parses image dimensions from the file header
* Creates an SDL window matching the image dimensions
* Maps RGB values to SDL colour format
* Renders images pixel-by-pixel
* Uses SDL2 for window management and rendering

## Dependencies

Install SDL2 development libraries:

```bash
sudo apt install libsdl2-dev libsdl2-2.0-0 -y
```

## Compilation

Basic compilation:

```bash
gcc -Wall -Wextra -g -o iv iv.c
```

SDL2 compilation:

```bash
gcc -Wall -Wextra -g -o iv iv.c `sdl2-config --cflags --libs`
```

If the source file is named `main.c`:

```bash
gcc -Wall -Wextra -g -o iv main.c `sdl2-config --cflags --libs`
```

## Usage

Compile the program:

```bash
gcc -Wall -Wextra -g -o iv main.c `sdl2-config --cflags --libs`
```

Run the image viewer by piping a PPM image into standard input:

```bash
cat image.ppm | ./iv
```

Example output:

```text
Width=638 , Height=480
```

The application will then open an SDL window and display the image.

## Project Structure

```text
.
├── main.c
├── image.ppm
├── .gitignore
└── README.md
```

## Current Learning Goals

This project is being used to learn:

* C programming
* Pointers and memory management
* File I/O
* Binary file formats
* SDL2 graphics programming
* Pixel-based image rendering

## Implementation Overview

1. Read the PPM file header.
2. Extract image width and height.
3. Create an SDL window matching the image dimensions.
4. Read RGB values for each pixel.
5. Convert RGB values to SDL colour format using `SDL_MapRGB`.
6. Draw each pixel using `SDL_FillRect`.
7. Display the rendered image using `SDL_UpdateWindowSurface`.
