#!/bin/bash
# Asigno la cantidad de numeros aleatorios N a utilizar y la cantida de archivo i que quiero utilizar
N=$1
i=$1
# Ahora vamos a generar 5 archivos ( desde i=0 a i=4) usando un  ciclo for
for j in {0..i}
do 	
	# Ejecutar random.sh y filtrar solo líneas con números
	random_numbers=$(./random.sh | grep -E "^[0-9]+$")

	# Extraer los primeros N números
	selected_numbers=$(echo "$random_numbers" | head -n "$N")

	# Generar el nombre del archivo 
	output_file="rand_${j}_${N}.dat"

	# Guardar los números en el archivo
	echo "$selected_numbers" > "$output_file"

	# Confirmar la creación del archivo
	echo "Archivo generado: $output_file"
done
