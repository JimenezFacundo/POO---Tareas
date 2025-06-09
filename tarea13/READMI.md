# 🧾 Tarea 13 - Login con Imágenes desde Internet y Pantalla Completa

## 📌 Descripción

Este ejercicio consiste en crear una aplicación Qt con dos ventanas:

1. Un **Login** que carga como fondo una imagen obtenida desde internet.
2. Una **Ventana principal en pantalla completa**, también con una imagen de fondo descargada dinámicamente.

La ventana principal solo debe abrirse **cuando la imagen esté completamente descargada**. Además, la imagen debe mostrarse manteniendo su **relación de aspecto**, sin deformarse.

---

## 💡 Objetivos

- Cargar imágenes desde una URL utilizando `QNetworkAccessManager`.
- Establecer una imagen como fondo de una ventana (`QPalette` / `QLabel` con `QPixmap`).
- Manejar correctamente la asincronía de la descarga.
- Validar usuario y contraseña.
- Abrir una nueva ventana en modo **fullscreen** solo si la imagen ya fue cargada.
- Mantener relación de aspecto de las imágenes (`Qt::KeepAspectRatio`).

---

## 📂 Archivos

- `main.cpp`: arranca la aplicación.
- `login.h / login.cpp`: contiene la lógica de login y descarga de la imagen de fondo.
- `ventana.h / ventana.cpp`: clase `Ventana`, ventana fullscreen con otra imagen de fondo.
- Recursos: URLs de imágenes.

---

## 🎯 Requisitos técnicos

### 🧩 Login

- Mostrar imagen descargada como fondo (por ejemplo, desde Unsplash).
- Usuario válido: `admin`
- Clave válida: `1234`
- Si es válido, descarga imagen para la siguiente ventana.
- Solo abre la **segunda ventana cuando la imagen haya sido descargada completamente**.

### 🖼️ Ventana Fullscreen

- La clase `Ventana` hereda de `QWidget`.
- Se muestra en modo `fullscreen` (`this->showFullScreen();`).
- Se asigna como fondo la imagen descargada.
- La imagen debe escalar sin deformarse:

```cpp
pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
