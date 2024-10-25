# So Long

**So Long** es un proyecto de la formación en 42 Barcelona cuyo objetivo es implementar un juego sencillo en 2D utilizando la biblioteca gráfica **minilibx**. En este proyecto, el jugador debe recorrer un mapa recogiendo todos los elementos y llegar a la salida para ganar. Este proyecto permite aprender sobre gráficos básicos, manejo de eventos y lógica de juegos en C.

## Objetivo

El objetivo de **So Long** es desarrollar un pequeño juego en 2D donde el jugador pueda moverse en un mapa, recolectar objetos y encontrar la salida mientras enfrenta algunos desafíos y restricciones.

## Requisitos

- **Librerías permitidas**: solo se permite el uso de la biblioteca **minilibx**, `malloc`, `free`, `read`, `write`, `open`, `close`.
- **Compilación**: el programa debe compilarse con `cc` y las banderas `-Wall -Wextra -Werror`.
- **Mapa**: el mapa debe cumplir ciertas reglas:
  - Debe estar contenido en un archivo `.ber`.
  - Debe ser rectangular y rodeado de paredes.
  - Debe contener al menos un personaje, una salida y un coleccionable.
  
## Especificaciones Técnicas

### Movimiento del Jugador

El jugador debe poder moverse utilizando las teclas:
- **W**: Mover hacia arriba
- **A**: Mover hacia la izquierda
- **S**: Mover hacia abajo
- **D**: Mover hacia la derecha
- **Q**: Atacar (elección personal)

### Contenido del Mapa

El mapa contiene los siguientes elementos:
- **P**: Posición inicial del jugador.
- **E**: Posición de la salida.
- **C**: Coleccionables que el jugador debe recoger.
- **1**: Paredes del mapa que bloquean el paso.
- **0**: Espacios vacíos por los que el jugador puede moverse.
- **2**: Enemigos (bonus).

### Funcionalidades del Juego

1. El jugador debe recoger todos los elementos coleccionables antes de dirigirse a la salida para ganar.
2. El juego debe mostrar el número de movimientos del jugador.
3. El juego debe cerrarse cuando el jugador alcanza la salida, después de recoger todos los coleccionables.

### Gestión de Errores

El programa debe gestionar adecuadamente los errores, como:
- Mapas no válidos.
- Archivos de mapa incorrectos o ausentes.
- Falta de elementos requeridos en el mapa (jugador, salida, coleccionables).

## Instalación

Para compilar el proyecto, se requiere **minilibx**. En un sistema de Linux o macOS con `make` instalado, ejecuta los siguientes comandos:

1. Clona este repositorio.
   ```bash
   git clone https://github.com/gyanpolo/42-so_long.git
   cd so_long
