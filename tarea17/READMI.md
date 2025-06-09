# Ejercicios de Qt - Aplicaciones con QWidget

Este repositorio contiene ejercicios prácticos desarrollados en **Qt Widget Application**, con el objetivo de practicar herencia de widgets, personalización de interfaces, validación de formularios y uso de `paintEvent`.

---

# Ejercicio 7

## Descripción

Este ejercicio consiste en el desarrollo de una aplicación con interfaz gráfica que simula un sistema de autenticación seguido de un formulario de registro con validación de datos.

## Funcionalidad

### 1️⃣ Pantalla de Login

- **Campos**:
  - Usuario
  - Clave

- **Validación**:
  - Usuario: `admin`
  - Clave: `1111`

- **Comportamiento**:
  - Si las credenciales son correctas, se habilita el acceso a la pantalla de registro.
  - Si son incorrectas, se muestra un mensaje de **"No válido"**.

---

### 2️⃣ Pantalla de Registro

- **Campos obligatorios** (**No null**):
  - Legajo (Número aleatorio entre 1 y 10.000)
  - Nombre
  - Apellido

- **Captcha**:
  - Se muestra un número captcha generado aleatoriamente.
  - El usuario debe ingresar correctamente el número captcha para poder completar el alta.

- **Botón `Alta`**:
  - Si todos los campos son válidos y el captcha es correcto, se habilita la opción de **"Cerrar app"**.
  - Si hay algún campo inválido o el captcha es incorrecto, se muestra un mensaje de **"No válido"**.

---

## Flujo de la aplicación

1. El usuario ingresa en la pantalla de login.
2. Si las credenciales son correctas → pasa a la pantalla de registro.
3. En la pantalla de registro:
    - Debe completar todos los campos obligatorios.
    - Debe validar correctamente el captcha.
4. Si el formulario es válido → se muestra la opción para cerrar la aplicación.

---

## Requisitos

- Interfaz gráfica (ejemplo: Qt Widgets).
- Generación de número aleatorio para **Legajo** y **Captcha**.
- Validación de campos obligatorios.
- Manejo de navegación entre ventanas.

---

## Objetivo

- Practicar la validación de formularios.
- Manejar navegación entre ventanas.
- Implementar un captcha simple.
- Integrar controles de flujo según validaciones.

---

# Ejercicio 17

## Descripción

Este ejercicio consiste en crear una aplicación Qt basada en widgets que muestre una ventana con un fondo gráfico agradable y una serie de botones personalizados, similar a la imagen de ejemplo proporcionada.

Cada botón es una instancia de una clase personalizada `Boton`, que hereda de `QWidget` y redefine su propio `paintEvent`.

---

## Requerimientos

### 📌 Ventana

- Crear un proyecto **Qt Widget Application**.
- Crear la clase `Ventana`, que hereda de `QWidget`.
- Usar **Qt Designer** para diseñar la interfaz de `Ventana`.

### 📌 Clase Boton

- Crear una clase `Boton`, que hereda de `QWidget`.
- Usar **Qt Designer (Designer Form Class)** para diseñar la clase `Boton`.

### 📌 Personalización de Boton

- Redefinir `paintEvent` en `Boton` y usar `fillRect` para dibujar el botón con color personalizado.
- Definir una enumeración en `Boton` con los siguientes valores:

```cpp
enum ColorBoton {
    Azul,
    Verde,
    Magenta
};
