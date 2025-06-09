# 🧾 Tarea 16 - Login con SQLite, Usuario Recordado y Clave en MD5

## 📌 Descripción

Aplicación Qt con interfaz diseñada en **Qt Designer** que realiza un login validando usuarios almacenados en una base SQLite con las siguientes características:

- La **clave se almacena cifrada en MD5** en la base de datos.
- Al iniciar la aplicación, se **precarga el último usuario que inició sesión correctamente** en el campo usuario.
- Mantiene la persistencia del último usuario exitoso incluso después de cerrar la aplicación.

---

## 🧱 Estructura de la base de datos

Tabla usuarios (ejemplo):

| id | nombre | usuario | clave (MD5)                   | ultimo_ingreso           | ultimo_usuario (bool) |
|----|--------|---------|------------------------------|-------------------------|----------------------|
| 1  | Facundo| facu    | 81dc9bdb52d04dc20036dbd8313ed055 | 2025-06-09 13:00:00    | 1                    |
| 2  | Ana    | ana     | d41d8cd98f00b204e9800998ecf8427e | 2025-05-01 10:00:00    | 0                    |

- `clave` es el hash MD5 de la contraseña.
- `ultimo_usuario` indica si el usuario fue el último en iniciar sesión exitosamente (1 = sí, 0 = no).

---

## ⚙️ Flujo de la aplicación

1. Al abrir la aplicación, se consulta la base de datos para obtener el usuario con `ultimo_usuario = 1`.
2. Se coloca ese usuario en el campo `usuario` del formulario.
3. Cuando se ingresa la clave, esta se transforma a MD5 y se compara con el valor almacenado.
4. Si la validación es exitosa:
   - Se actualiza el campo `ultimo_ingreso` con la fecha/hora actual.
   - Se actualiza el campo `ultimo_usuario` para marcar solo a este usuario como último válido.
5. Si la validación falla, se muestra mensaje de error y se permite reintentar.

---

## 🔐 Uso de MD5 en Qt

Qt ofrece la clase `QCryptographicHash` para generar hashes MD5:

```cpp
QString password = "1234";
QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);
QString hashHex = hash.toHex();
