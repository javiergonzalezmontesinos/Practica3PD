# Práctica 3 - Parte A: Servidor Web ESP32

## Objetivo
Implementar un servidor web en la ESP32 en modo STA (Station) que muestre una página HTML accesible desde cualquier navegador en la misma red WiFi, cumpliendo con los requisitos del enunciado:

1. Conexión WiFi a una red existente.
2. Generación de una página web básica con contenido estático.
3. Visualización correcta de caracteres especiales (emojis).

## Logros alcanzados
✅ **Conexión WiFi estable**:  
La ESP32 se conecta correctamente a la red WiFi configurada y muestra su dirección IP en el Monitor Serie.

✅ **Página web funcional**:  
Se implementó una página HTML que muestra:
- Un título con emoji (😊).
- La dirección IP dinámica de la ESP32.

✅ **Estructura del proyecto**:  
- Código principal en `/src/main.cpp` donde también se ha incluido la parte de html de la propia página web.

✅ **Extras implementados**:  
- Uso de `meta charset=UTF-8` para compatibilidad con emojis.
