Program Structure & Functionality:
- The Display Controller Abstracts Away Display
- The Display is an FL_Window containing an FL_GL_WINDOW. It is responsible for all elements related to user interaction and calling the redraw on the opengl window.
- The RenderWindow is the opengl window that takes care of all the responsibilities related to navigating the 3d space of the screen, as well as drawing, coloring, and editing the mesh.
- The MeshController contains all the functionality for fractalizing and creating the mesh.
- The Camera class provides camera functionality for the user.
- The Face class provides a base-line wrapper for a list of three vertices represented by gVector4's.

GUI:
- For window movement, the 'w' key rotates forward, the 's' key rotates back, the 'a' key rotates left, the 'd' key rotates right, the 'q' key zooms out and the 'e' key zooms in.
- The first four tickers provide the user the ability to set the amount of rows and colums a mesh will have along with its length and width
- The color picker will set the color of the mesh in real time
- The create mesh button will create a mesh based on the values set in the first four tickers
- The Top View will show the user the top of the mesh
- The Side View will show the user the top of the mesh
- The mesh display toggle will toggle through Mesh, Wire, and Both in that specific order.
- The Vertex list will update as meshes are created and fractalized. Vertices are associated with their face in the listing.
- When a vertex is selected in the vertex list, it will be highlighted in red on the screen in the wire and both modes, and will be available for moment by the X, Y, and Z modifier buttons.
- The input for the range box determines the initial range for the fractalization. If there is no input, it is 0. If change after a fractalization, the fractalization starts anew with the new range.
- The Fractalize button fractalizes the mesh. If the range is not changed, it will continue to fractilize will a reducing range.
- The Snow Cap Height Slider will adjust the height of the snow cap from -2.0 to 2.0 in realtime.

Known Bugs:
- Continual fractalization will eventually cause the program to hang due to lack of optimization.
- Zooming in on the mesh will eventually cause an inversion and appear to have zoom out functionality instead.