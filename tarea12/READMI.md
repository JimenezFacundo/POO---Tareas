# 🧾 Tarea 12 - Login con Qt Designer y Consulta de Temperatura vía API

## 📌 Descripción

Se trata de un login gráfico creado con **Qt Designer**, que además consume una **API externa** para mostrar en pantalla la **temperatura actual en la Ciudad de Córdoba**. Si el usuario ingresa credenciales válidas, se abre una nueva ventana vacía.

---

## 💡 Objetivos

- Diseñar la interfaz con Qt Designer (`.ui`).
- Cargar y usar archivos `.ui` en C++ con `QUiLoader` o `uic`.
- Validar un login (usuario y clave).
- Obtener datos en tiempo real desde una API REST (ej: temperatura).
- Mostrar datos dinámicos con `QLabel`.
- Cambiar de ventana luego del login.

---

## 🧱 Estructura de ventanas

### 🧩 Login

Componentes definidos en Qt Designer:

- `QLineEdit`: para el usuario.
- `QLineEdit`: para la clave (en modo password).
- `QPushButton`: botón "Ingresar".
- `QLabel`: para mostrar la temperatura actual en Córdoba.

### ✅ Validación

- Usuario válido: `admin`
- Clave válida: `1234`

Si es correcto:
- Se cierra la ventana de login.
- Se muestra una ventana vacía.

Si es incorrecto:
- Se borra el campo de la clave.

---

## 🌡️ Consulta a la API del clima

- Se utiliza una API pública como [OpenWeatherMap](https://openweathermap.org/api).
- Se hace una solicitud HTTP (`QNetworkAccessManager`) al iniciar la app o al cargar el login.
- Se muestra la temperatura obtenida (ej: `"Temperatura: 22°C"`).

### 🔧 Ejemplo de código para solicitud

```cpp
QNetworkAccessManager *manager = new QNetworkAccessManager(this);
QUrl url("http://api.openweathermap.org/data/2.5/weather?q=Cordoba,AR&appid=TU_API_KEY&units=metric");

QNetworkRequest request(url);
QNetworkReply *reply = manager->get(request);
connect(reply, &QNetworkReply::finished, this, &Login::procesarRespuesta);
