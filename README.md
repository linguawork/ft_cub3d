# cub3d

Developed by Id Software by the famous John Carmack and John Romero, published in 1992 by Apogee Software, Wolfenstein 3D is the first true “First Person
Shooter” in the history of video games.
Wolfenstein 3D is the ancestor of games like Doom (Id Software, 1993), Doom II
(Id Software, 1994), Duke Nukem 3D (3D Realm, 1996) and Quake (Id Software, 1996),
that are additional eternal milestones in the world of video games.
You may try the original game available at this link:
http://users.atw.hu/wolf3d/

According to the project reqirements I had to create a “realistic” 3D graphical
representation of the inside of a maze from a first-person perspective. I had to create this representation using the Ray-Casting principles.


The constraints of the project are as follows:
• Using the miniLibX library is a must. The library is provided by the subject. 

• The management of the window must remain smooth: changing to another window, minimizing, etc.

• Display different wall textures (of my choice) that vary depending on which side the wall is facing (North, South, East, West).

• My program must be able to set the floor and ceiling colors to two different ones.

• The program displays the image in a window and respects the following rules:

  ◦ The left and right arrow keys of the keyboard must allow the player to look left and
  right in the maze.

  ◦ The W, A, S, and D keys must allow the player to move the point of view through
  the maze.
  
  ◦ Pressing ESC must close the window and quit the program cleanly.
  
  ◦ Clicking on the red cross on the window’s frame must close the window and
  quit the program cleanly.
  
  ◦ The use of images of the minilibX is strongly recommended.
  
  • The program must take as a first argument a scene description file with the .cub
  extension.
  
  ◦ The map must be composed of only 6 possible characters: 0 for an empty space,
  1 for a wall, and N,S,E or W for the player’s start position and spawning
  orientation.
  
  This is a simple valid map:
  <img width="526" alt="Screen Shot 2022-04-25 at 9 22 53 PM" src="https://user-images.githubusercontent.com/12897177/165150647-7d645ba6-3ad3-4fa6-acef-bb2dd590284b.png">

  ◦ The map must be closed/surrounded by walls, if not the program must return
  an error.
  
  ◦ Except for the map content, each type of element can be separated by one or
  more empty line(s).
  
  ◦ Except for the map content which always has to be the last, each type of
  element can be set in any order in the file.
  
  ◦ Except for the map, each type of information from an element can be separated
  by one or more space(s).
  
  ◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
  map and are up to you to handle. You must be able to parse any kind of map,
  as long as it respects the rules of the map.
  

  ◦ Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order such as :
  
  North texture:
  NO ./path_to_the_north_texture
  · identifier: NO
  · path to the north texure
  
  South texture:
  SO ./path_to_the_south_texture
  · identifier: SO
  · path to the south texure
  
  West texture:
  WE ./path_to_the_west_texture
  · identifier: WE
  · path to the west texure
  
  East texture:
  EA ./path_to_the_east_texture
  · identifier: EA
  · path to the east texure
  
  Floor color:
  F 220,100,0
  · identifier: F
  · R,G,B colors in range [0,255]: 0, 255, 255
  
  Ceilling color:
  C 225,30,0
  · identifier: C
  · R,G,B colors in range [0,255]: 0, 255, 255
  
 Example of the mandatory part with a minimalist .cub scene:
 
 
<img width="526" alt="Screen Shot 2022-04-25 at 9 21 40 PM" src="https://user-images.githubusercontent.com/12897177/165150284-ad19efdd-a1ae-4d5e-a282-cf731405acb5.png">





Brief Russian language description of the project.

Проект написан на языке С, в нем воссоздан аналог игрового движка популярной игры Wolfenstein 3D с применением технологии  рейкастинга  - это метод преобразования ограниченной формы данных (карта этажа) в трёхмерную проекцию с помощью трассировки лучей из точки обзора в объём обзора, а также графической библиотеки mlx. На основе входного файла вырисовывается трехмерная проекция. В файле содержатся пути к текстурам, цвет пола и потолка, а также сама двумерная карта.
Вложил в этот проект часть своей души – попытался реализовать игру в теме фильма “Terminator II”, использовал текстуры сцен из фильма, а в качестве спрайта (спрайт - это объект на карте) создал образ машины Т100. Реализовал аудиосопровождение игры используя оригинальный голос Арнольда Шварцнеггера c его знаменитыми фразами "I'll be back", "No problemo", "She'll be back", "Hastalavista" и голос легендарного переводчика эпохи VHS – Л.Володарского "И восстали машины из пепла ядерного огня...". Все звуки привязал к нажатию комбинаций кнопок.


"I'll be back":   нажать на клавиатуре Мака клавиши A + S;

"No problemo":    S + D; 

"She'll be back": < + >;

"Hastalavista":   Esc или нажатие курсором на крестик чтобы закрыть экран

"И восстали машины из пепла ядерного огня...": Z - вкл, X - откл


Ниже выкладываю видео с бонусной частью проекта  и нужно будет выбрать любую карту со словом _terminator.
Чтобы запустить игру в теме Терминатора  нужно выполнить make bonus, затем подать бинарник с картой: ./cub3d map_terminator.cub

https://user-images.githubusercontent.com/12897177/165137665-07e2ad5a-a5da-426a-a30a-e4e3dbd524cb.mov


При наличии времени планирую доработать и поменять тему игры. Проект понравился, оторваться от проекта заставили дедлайны, есть желание развиваться в разработке игр. 
