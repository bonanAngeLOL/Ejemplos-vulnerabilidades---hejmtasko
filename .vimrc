" Configuración de VIM usada para la presentación
"   Compatible con VIM 8.2

" Marcar lineas:
"    Agrega toda la linea al patrón de busqueda y lo ilumina presionando
"    CTRL+l en modo normal
nmap <silent> <c-l> :call matchadd('Search', '\%'.line('.').'l')<cr>

" Correr programas en C:
"    Corre un programa en C usando gcc en una terminal, aunque se podría
"    cambiar por cualquier otro compilador y para otro lenguaje.
"    Para pasarle argumentos por consola se debe escribir al inicio de la 
"    linea '//Arguments:' y despues la lista de argumentos separadas por
"    espacios.
"    Al presionar <F8> se ejecuta en una consola en pantalla dividida
"    con los argumentos del comentario. Se corre con 'sudo' para mostrar 
"    mejor las vulnerabilidades.
autocmd filetype c nnoremap <F8> :w<bar>let Args = getline(".")[0:11]=="//Arguments:" ? getline(".")[12:] : ""<bar>execute 'term ++shell sudo gcc %:p -o %:p:r && sudo %:p:r' Args<CR>
