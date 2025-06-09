# 🧾 Tarea 15 - Login con SQLite y Registro de Último Ingreso

## 📌 Descripción

Aplicación Qt con interfaz creada en **Qt Designer** que permite:

- Loguearse con usuarios almacenados en una base de datos **SQLite**.
- Registrar la fecha y hora del último ingreso exitoso del usuario.
- Abrir una ventana que muestra:
  - El nombre del usuario en letra grande.
  - El último ingreso en letra más pequeña.

---

## 🧱 Estructura del proyecto

### Base de datos SQLite

- Se usa una base de datos SQLite para almacenar:
  - Tabla de usuarios con campos `id`, `nombre`, `usuario`, `clave`, `ultimo_ingreso`.
- Se puede gestionar la base de datos usando herramientas como:
  - [SQLiteStudio](https://sqlitestudio.pl)
  - o `sqlite3.exe` (línea de comandos).

---

## ⚙️ Uso básico de `sqlite3.exe`

`sqlite3.exe` es un ejecutable que permite manipular bases SQLite desde la consola. Comandos básicos:

```bash
# Abrir o crear base de datos
sqlite3 usuarios.db

# Mostrar tablas
.tables

# Crear tabla usuarios
CREATE TABLE usuarios (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  nombre TEXT NOT NULL,
  usuario TEXT UNIQUE NOT NULL,
  clave TEXT NOT NULL,
  ultimo_ingreso TEXT
);

# Insertar usuario
INSERT INTO usuarios (nombre, usuario, clave) VALUES ('Facundo Jimenez', 'facu', '1234');

# Consultar usuarios
SELECT * FROM usuarios;

# Salir
.quit
