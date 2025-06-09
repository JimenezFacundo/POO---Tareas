# 🧾 Tarea 6 - Login con Validación y Cambio de Ventana

## 📌 Descripción

Este ejercicio consiste en crear un sistema de **Login** utilizando `QGridLayout` en Qt. El login debe reconocer un usuario/clave específicos y, si son correctos, mostrar una nueva ventana con un formulario de ingreso de datos. En caso contrario, se borra el campo de clave.

---

## 💡 Objetivos

- Implementar interfaces gráficas con `QGridLayout`.
- Enmascarar la clave usando asteriscos (`QLineEdit::setEchoMode`).
- Detectar la tecla `Enter` para simular un clic en el botón de login.
- Crear una nueva clase `Formulario` que hereda de `QWidget`.
- Realizar validación de usuario y contraseña desde el código.
- Controlar la visibilidad entre ventanas (cerrar login, mostrar formulario).

---

## 📦 Archivos

- `main.cpp`: inicia la aplicación y muestra el login.
- `Login.h / Login.cpp`: define la ventana de login con validación.
- `Formulario.h / Formulario.cpp`: define el formulario que aparece tras un login exitoso.

---

## 🧱 Composición de interfaces

### 🧩 Login

- `QLabel`: “Usuario”, “Clave”
- `QLineEdit`: uno para el usuario, otro para la clave (con asteriscos)
- `QPushButton`: botón de “Ingresar”
- Disposición: `QGridLayout`

### 🔐 Lógica de autenticación

- Usuario válido: `admin`
- Clave válida: `1111`
- Si son correctos:
  - Se cierra la ventana de login.
  - Se muestra el formulario.
- Si son incorrectos:
  - Se borra la clave (`lineEditClave->clear()`).

### ⌨️ Detección de Enter

Se configura el `QLineEdit` de la clave para que al presionar `Enter` se active el slot del botón:

```cpp
connect(lineEditClave, &QLineEdit::returnPressed, botonLogin, &QPushButton::click);
