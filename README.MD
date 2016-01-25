# Fractal Heightmap Modeler

The purpose of this program is to generate and model a 3D heightmap, which gains more detail as it is further fractalized. The user can change the perspective of the camera, the height of the "snowcaps", further fractalize, change the color, and adjust the positions of the individual verticies generated for the model.

## Installation

This program was originally developed with Visual Studio 2013 and FLTK 1.3.2. It has been updated to use Visual Studio 2015 and FLTK 1.3.3.

The process of building the program should be as follows
  1. [Download FLTK 1.3.3 source (Or the most recent version available)](http://www.fltk.org/software.php) and extract to a folder.
  2. Download Visual Studio 2015 (Or newest version)
  3. Create an environment variable called $(FLTK_HOME) pointing to the folder containing the FLTK source.
  4. Clone the this repository
  5. Open the solution file
  6. Build the project in either release or debug mode
  7. Done

## Usage

- For window movement, the 'w' key rotates forward, the 's' key rotates back, the 'a' key rotates left, the 'd' key rotates right, the 'q' key zooms out and the 'e' key zooms in.
- The first four tickers provide the user the ability to set the amount of rows and colums a mesh will have along with its length and width
- The color picker will set the color of the mesh in real time
- The create mesh button will create a mesh based on the values set in the first four tickers
- The Top View will show the user the top of the mesh
- The Side View will show the user the side of the mesh
- The mesh display toggle will toggle through Mesh, Wire, and Both in that specific order.
- The Vertex list will update as meshes are created and fractalized. Vertices are associated with their face in the listing.
- When a vertex is selected in the vertex list, it will be highlighted in red on the screen in the wire and both modes, and will be available for moment by the X, Y, and Z modifier buttons.
- The input for the range box determines the initial range for the fractalization. If there is no input, it is 0. If change after a fractalization, the fractalization starts anew with the new range.
- The Fractalize button fractalizes the mesh. If the range is not changed, it will continue to fractilize will a reducing range.
- The Snow Cap Height Slider will adjust the height of the snow cap from -2.0 to 2.0 in realtime.

## The MIT License (MIT)
Copyright (c) 2016 Paul Coley <paulcoley1@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
