# 🔐 Ejercicio 11 - Login con Qt Designer (2025)

Este ejercicio consiste en replicar una aplicación de **Login** utilizando **Qt Designer**, lo que permite construir la interfaz gráficamente mediante archivos `.ui` y luego conectar la lógica desde código C++.

## 🎯 Objetivo

- Crear una interfaz de login utilizando Qt Designer (`.ui`).
- Conectar los elementos del formulario con lógica C++ usando `setupUi()`.
- Validar usuario y contraseña desde código.
- Utilizar `QLineEdit`, `QPushButton`, y `QLabel`.

## 📹 Video demostración

El desarrollo fue grabado en un video explicativo y subido a YouTube como **No listado**:

🔗 [Ejercicio 11 – Login con Qt Designer 2025](https://www.youtube.com/watch?v=_B2M6wrXM3M)

> 📽️ *En el video se muestra cómo diseñar la interfaz con Qt Designer, cómo enlazarla al código C++, y cómo validar credenciales.*

## 🛠️ Requisitos del ejercicio

- Crear un formulario con Qt Designer (`.ui`) que contenga:
  - Campo de usuario (`QLineEdit`)
  - Campo de contraseña (`QLineEdit` con modo `Password`)
  - Botón de login (`QPushButton`)
  - Etiqueta para mensajes (`QLabel`)
- Conectar los elementos al código mediante `Ui::Login` y `setupUi(this)`.
- Validar credenciales en un `slot`.
- Grabar un video con pantalla compartida explicando el proceso.
- Subir el video a YouTube en modo **No listado**.

## ⚙️ Tecnologías utilizadas

- **Lenguaje:** C++
- **Framework:** Qt 6.9 (o compatible)
- **IDE recomendado:** Qt Creator
- **Herramientas:** Qt Designer (`.ui`), signals & slots, `setupUi()`

## 💡 Notas

- Las credenciales esperadas por defecto son: `admin / 1234`.
- El formulario y los elementos deben tener nombres (`objectName`) claros y consistentes con el código.

---

🎓 *Ejercicio presentado para la materia Programación Orientada a Objetos - Ingeniería en Informática.*
