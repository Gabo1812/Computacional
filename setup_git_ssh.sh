#!/bin/bash

# Paso 1: Generar la clave SSH (si no existe)
if [ ! -f "$HOME/.ssh/id_ed25519" ]; then
  echo "Generando nueva clave SSH..."
  ssh-keygen -t ed25519 -C "jose.alvarezcastrillo@ucr.ac.cr" -f "$HOME/.ssh/id_ed25519" -N ""
else
  echo "La clave SSH ya existe. Saltando generación."
fi

# Paso 2: Mostrar la clave pública SSH para agregarla a GitHub
echo "Tu clave pública SSH es:"
cat "$HOME/.ssh/id_ed25519.pub"
echo "Copia esta clave pública en GitHub (https://github.com/settings/keys)."

# Paso 3: Configurar la URL remota del repositorio en Git
git remote set-url origin git@github.com:Gabo1812/Computacional.git

# Paso 4: Probar la conexión SSH con GitHub
echo "Probando la conexión SSH con GitHub..."
ssh -T git@github.com

echo "¡Configuración completada!"

