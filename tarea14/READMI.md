# 🎨 Tarea 14 - Clase de Dibujo a Mano Alzada con Qt

## 📌 Descripción

Se desarrolló una clase personalizada llamada `Pintura`, que hereda de `QWidget`, permitiendo **dibujar a mano alzada** con el mouse.

El usuario puede:

- Dibujar líneas con el mouse (arrastrar).
- Cambiar el **color del pincel** con las teclas `R`, `G`, `B`.
- Cambiar el **tamaño del trazo** con el scroll del mouse.
- **Borrar todo** lo dibujado presionando `Escape`.


---

## 🎯 Funcionalidades principales

### 🖱️ Dibujo a mano alzada
- Se comienza a dibujar al presionar y mantener el botón izquierdo del mouse.
- Se trazan líneas entre puntos consecutivos con `QPainter`.

### 🎨 Cambio de color del pincel

| Tecla | Color seleccionado |
|------|---------------------|
| `R`  | Rojo                |
| `G`  | Verde               |
| `B`  | Azul                |

Se maneja mediante el evento `keyPressEvent()`.

### 🖍️ Cambio del grosor del pincel

- Al girar la **rueda del mouse** (`wheelEvent`), el tamaño del trazo aumenta o disminuye.
- Se limita el tamaño mínimo y máximo para evitar trazos invisibles o excesivos.

### ⌨️ Borrar dibujo

- Presionando `Escape`, se borra completamente el dibujo.
- Esto se logra vaciando la estructura que almacena los puntos y llamando a `update()` para forzar el repintado.

---

## 🧱 Estructura de la clase `Pintura`

```cpp
class Pintura : public QWidget {
    Q_OBJECT

private:
    QVector<QPoint> puntos;          // Lista de puntos dibujados
    QVector<QColor> colores;         // Color por punto
    QVector<int> grosores;           // Grosor por punto
    QColor colorActual = Qt::black;  // Color del pincel actual
    int grosorActual = 3;            // Grosor del pincel actual

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void keyPressEvent(QKeyEvent *) override;
    void wheelEvent(QWheelEvent *) override;

public:
    Pintura(QWidget *parent = nullptr);
};
