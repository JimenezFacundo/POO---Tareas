# 🧾 Tarea 4 - Control de Volumen con Actualización Dinámica del Título

## 📌 Descripción

En este ejercicio se parte del código de ejemplo del **control de volumen** usando Qt (QSlider + QSpinBox). El objetivo es **actualizar el título de la ventana principal** con el valor actual del `QSlider` cada vez que este se modifique.

---

## 💡 Objetivos

- Utilizar señales y slots en Qt.
- Sincronizar dos widgets: `QSlider` y `QSpinBox`.
- Modificar dinámicamente el título de la ventana (`QWidget`) según el valor del slider.
- Familiarizarse con el manejo básico de eventos en interfaces gráficas.

---

## 📦 Archivos

- `main.cpp`: contiene todo el código de la interfaz gráfica, la lógica de conexión de señales y la modificación del título.

---

## 🧠 Lógica implementada

- Se sincronizan `QSlider` y `QSpinBox` mediante señales y slots.
- Se conecta la señal `valueChanged(int)` del `QSlider` a un **slot personalizado** (o lambda) que actualiza el título de la ventana.
  
Ejemplo de la nueva conexión agregada:

```cpp
QObject::connect(slider, &QSlider::valueChanged, [=](int value) {
    ventana->setWindowTitle(QString("Volumen: %1").arg(value));
});
