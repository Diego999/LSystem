This is a visualized of L-System.

It uses Qt 4.8 and GLUT.

Actually, only the 2D L-System works.

The grammar to use is as follow :

    + -> yaw left
    - -> yaw right
    & -> pitch down
    ^ -> pitch up
    \ -> roll left
    / -> roll right
    | -> yaw around
    [ -> state push
    ] -> state pop```

The XML structure is quite trivial and doesn't need some explanations.
