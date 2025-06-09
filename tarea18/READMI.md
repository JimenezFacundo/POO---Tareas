# 🦖 Tarea 18 - T-Rex Extremo

## 📌 Descripción

Implementación de un juego inspirado en el clásico T-Rex Runner de Google Chrome donde:

- El jugador controla un dinosaurio que debe **esquivar cactus y pájaros**.
- Cada pájaro es una instancia con su propio `QTimer` que mueve su posición horizontal.
- Un `QTimer` principal controla movimiento de cactus, colisiones y aparición de nuevos pájaros.
- Se implementa lógica para **colisiones**, **movimientos del jugador** y **aumento de dificultad**.
- Al chocar, se muestra imagen de "Game Over" y se puede reiniciar el juego.

---

## 🧱 Clases principales

### Clase `TRex`

- Hereda de `QWidget` o usa `QImage` para representar el dinosaurio.
- Controla estado del jugador (saltando, agachado, corriendo, detenido).
- Métodos para manejar entradas del teclado:
  - Espacio → salto.
  - Flecha abajo → agacharse.
  - Flecha derecha → acelerar.
  - Flecha izquierda → desacelerar.

---

### Clase `Pajaro`

- Hereda de `QWidget` o usa `QImage`.
- Cada objeto tiene su propio `QTimer` que mueve al pájaro hacia la izquierda.
- Altura aleatoria para diferentes tipos de pájaros.
- Cuando sale de pantalla, se elimina o se detiene.

---

### Clase Obstáculos / Cactus

- Controlados por un `QTimer` principal.
- Se mueven horizontalmente hacia la izquierda.
- Aumentan velocidad conforme pasa el tiempo.

---

## 🕹️ Mecánica del juego

- El jugador puede controlar el dinosaurio con el teclado para esquivar obstáculos.
- Cada 5 segundos aparece un nuevo pájaro con su `QTimer`.
- Detectar colisiones entre:
  - Dinosaurio y cactus.
  - Dinosaurio y pájaros.
- Cuando hay colisión:
  - Se muestra imagen "Game Over".
  - Opción para reiniciar el juego.
- La velocidad de los obstáculos y pájaros aumenta progresivamente para incrementar dificultad.

---

## 🔧 Detalles técnicos y recomendaciones

- Conectar `QTimer` usando:

```cpp
connect(timer, SIGNAL(timeout()), this, SLOT(moverObjeto()));
                                                                      
            ─────────────────────────────
            |         🦖 TREX          |
            |                           |
            |       🌵      🐦         |
            |   Obstáculos que avanzan  |
            |                           |
            | → Controles:              |
            |   Espacio = Salto         |
            |   Flecha ↓ = Agacharse    |
            |   Flecha → = Acelerar     |
            |   Flecha ← = Frenar       |
            ─────────────────────────────

