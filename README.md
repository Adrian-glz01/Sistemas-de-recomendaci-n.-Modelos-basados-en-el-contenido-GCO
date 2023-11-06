# ***Sistema de Recomendación. Modelos basados en el contenido***
## _Autores_
- Adrián González Expósito (alu0101404813@ull.edu.es)
- Lucas Pérez Rosario (alu0101399928@ull.edu.es)
- Alejandro García Bautista (alu0101387604@ull.edu.es)

# Como esta organizado el código
El código esta organizado en los siguientes directorios:

```bash
.
├── build --> Aquí encontramos el fichero Makefile y se generara el ejecutable del programa
├── corpus --> Aquí enocntramos los ficheros corpus proporcionados
├── examples-documents --> Aquí encontramos los ficheros que contienen los artículos 
├── src --> Aquí encontramos todo el codigo fuente del programa
│   ├── Functions --> Aquí encontramos todas las funciones necesarias para el programa DF, IDF, etc
│   └── includes --> Aquí encontramos todos los ficheros .h de nuestro programa
└── stop-words --> Aquí enocntramos los ficheros stop words proporcionados
```

# ¿Qué se encontrará en el repositorio?
En el repositorio actual se encontrará todo el código fuente necesario así como el fichero Makefile para poder realizar la compilación haciendo uso únicamente del comando ***make***, dentro del directorio **build/** se encontrarán varios ejemplos con lo que realizar la ejecución del programa

# Como se compila el programa
Para poder compilar el programa hay que estar situado en el directorio **build/** y ejecutar el comando ***make***, con esto se generará un ejecutable con el nombre *sistemas_recomendacion*. Para conocer el uso del programa se puede ejecutar ***./sistemas_recomendacion --help*** aunque que su uso se explicará en el siguiente apartado.

# Cómo se usa el programa
Para poder hacer uso del programa debemos ejecutar el siguiente comando: __./sistemas_recomendacion -f <fichero> -c <fichero_corpus> -s <fichero_sw>__

Como se indicaba en el enunciado de la practica se nombra que los argumentos sean del tipo POSIX, es por eso que el anterior ejemplo de tipo de uso del programa es solo un ejemplo de las posibles combinaciones que se pueden hacer, ya que los argumentos se pueden indicar en el orden que se desee, así como usar sus versiones largas que serian --fichero/--corpus/--stop, asi como mezclar algunos argumentos en su forma larga y otro en su forma corta.

En la opción -f debemos indicar la ruta al fichero donde tenemos la matriz que queremos completar.
En la opción -c debemos indicar la ruta al fichero donde tenemos el corpus.
En la opción -s debemos indicar la ruta al fichero donde tenemos las stop words.

Un ejemplo de uso de la aplicación puede ser la siguiente:

```bash
./sistemas_recomendacion.o --fichero ../examples-documents/documents-01.txt -c ../corpus/corpus-en.txt --stop ../stop-words/stop-words-en.txt
```

La salida de ese comando se encontrará en el fichero result.txt dentro de build y tendrá el siguiente contenido

```txt
**Articulo** 1
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
acidity                            1         7         0.154902  1         0.154902  
apple                              1         2         0.69897   1         0.69897   
aromas                             1         4         0.39794   1         0.39794   
brimstone                          1         1         1         1         1         
brisk                              1         2         0.69897   1         0.69897   
broom                              1         1         1         1         1         
citrus                             1         1         1         1         1         
dried                              2         2         0.69897   1.30103   0.909381  
expressive                         1         1         1         1         1         
fruit                              1         2         0.69897   1         0.69897   
herb                               1         2         0.69897   1         0.69897   
include                            1         1         1         1         1         
offer                              1         2         0.69897   1         0.69897   
overly                             1         1         1         1         1         
palate                             1         3         0.522879  1         0.522879  
sage                               1         1         1         1         1         
tropical                           1         1         1         1         1         
unripened                          1         1         1         1         1         


**Articulo** 2
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
2016                               1         1         1         1         1         
a                                  1         7         0.154902  1         0.154902  
acidity                            1         7         0.154902  1         0.154902  
berry                              1         2         0.69897   1         0.69897   
drinkable                          1         1         1         1         1         
fill                               1         1         1         1         1         
firm                               1         2         0.69897   1         0.69897   
freshened                          1         1         1         1         1         
fruits                             1         2         0.69897   1         0.69897   
fruity                             1         2         0.69897   1         0.69897   
juicy                              1         1         1         1         1         
red                                1         2         0.69897   1         0.69897   
ripe                               1         1         1         1         1         
smooth                             1         1         1         1         1         
structured                         1         1         1         1         1         
tannins                            1         2         0.69897   1         0.69897   
wine                               1         5         0.30103   1         0.30103   


**Articulo** 3
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
acidity                            1         7         0.154902  1         0.154902  
crisp                              1         2         0.69897   1         0.69897   
dominate                           1         1         1         1         1         
fermented                          1         1         1         1         1         
flavors                            2         3         0.522879  1.30103   0.680281  
flesh                              1         1         1         1         1         
green                              1         2         0.69897   1         0.69897   
lime                               1         1         1         1         1         
pineapple                          1         2         0.69897   1         0.69897   
pokes                              1         1         1         1         1         
rind                               1         2         0.69897   1         0.69897   
snappy                             1         1         1         1         1         
stainless-steel                    1         1         1         1         1         
tart                               1         1         1         1         1         
underscoring                       1         1         1         1         1         
wine                               1         5         0.30103   1         0.30103   


**Articulo** 4
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
a                                  2         7         0.154902  1.30103   0.201532  
aromas                             1         4         0.39794   1         0.39794   
astringent                         1         1         1         1         1         
bite                               1         1         1         1         1         
blossom                            1         1         1         1         1         
finish                             1         2         0.69897   1         0.69897   
give                               1         1         1         1         1         
guava                              1         1         1         1         1         
honey-drizzled                     1         1         1         1         1         
lemon                              1         1         1         1         1         
mango                              1         1         1         1         1         
note                               1         2         0.69897   1         0.69897   
opulent                            1         1         1         1         1         
orange                             1         1         1         1         1         
palate                             1         3         0.522879  1         0.522879  
pineapple                          1         2         0.69897   1         0.69897   
pith                               1         1         1         1         1         
rind                               1         2         0.69897   1         0.69897   
semidry                            1         1         1         1         1         
slightly                           1         1         1         1         1         
start                              1         1         1         1         1         


**Articulo** 5
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
2012                               1         1         1         1         1         
a                                  3         7         0.154902  1.47712   0.228809  
bottling                           1         1         1         1         1         
characteristics                    1         1         1         1         1         
companion                          1         1         1         1         1         
country                            1         1         1         1         1         
earthy                             1         1         1         1         1         
good                               1         1         1         1         1         
hearty                             1         1         1         1         1         
herbal                             1         2         0.69897   1         0.69897   
pleasantly                         1         1         1         1         1         
regular                            1         1         1         1         1         
rough                              1         1         1         1         1         
rustic                             1         1         1         1         1         
stew                               1         1         1         1         1         
tannic                             1         1         1         1         1         
unfussy                            1         1         1         1         1         
wine                               1         5         0.30103   1         0.30103   
winter                             1         1         1         1         1         


**Articulo** 6
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
a                                  1         7         0.154902  1         0.154902  
acidity                            1         7         0.154902  1         0.154902  
aromas                             1         4         0.39794   1         0.39794   
blackberry                         1         1         1         1         1         
bodied                             1         1         1         1         1         
case                               1         1         1         1         1         
complement                         1         1         1         1         1         
dark                               1         1         1         1         1         
finish                             1         2         0.69897   1         0.69897   
flavors                            1         3         0.522879  1         0.522879  
fresh                              1         4         0.39794   1         0.39794   
fruit                              1         2         0.69897   1         0.69897   
full                               1         1         1         1         1         
grabby                             1         1         1         1         1         
green                              1         2         0.69897   1         0.69897   
herbal                             1         2         0.69897   1         0.69897   
herbs                              1         1         1         1         1         
horseradish                        1         1         1         1         1         
mouth                              1         1         1         1         1         
navarran                           1         1         1         1         1         
plum                               1         1         1         1         1         
raspberry                          1         1         1         1         1         
show                               1         1         1         1         1         
spicy                              1         1         1         1         1         
tomatoey                           1         1         1         1         1         
typical                            1         1         1         1         1         
whiff                              1         1         1         1         1         


**Articulo** 7
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
a                                  1         7         0.154902  1         0.154902  
acidity                            1         7         0.154902  1         0.154902  
aromas                             1         4         0.39794   1         0.39794   
balance                            1         3         0.522879  1         0.522879  
berry                              1         2         0.69897   1         0.69897   
bright                             1         1         1         1         1         
candied                            1         1         1         1         1         
carry                              1         1         1         1         1         
fresh                              1         4         0.39794   1         0.39794   
herb                               1         2         0.69897   1         0.69897   
informal                           1         1         1         1         1         
open                               1         1         1         1         1         
palate                             1         3         0.522879  1         0.522879  
pepper                             1         1         1         1         1         
red                                1         2         0.69897   1         0.69897   
savory                             1         2         0.69897   1         0.69897   
soft                               1         1         1         1         1         
tannins                            1         2         0.69897   1         0.69897   
white                              1         1         1         1         1         


**Articulo** 8
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
a                                  1         7         0.154902  1         0.154902  
acidity                            1         7         0.154902  1         0.154902  
balance                            1         3         0.522879  1         0.522879  
dry                                1         2         0.69897   1         0.69897   
firm                               1         2         0.69897   1         0.69897   
food                               1         1         1         1         1         
offer                              1         2         0.69897   1         0.69897   
profusion                          1         1         1         1         1         
restrain                           1         1         1         1         1         
spice                              1         2         0.69897   1         0.69897   
texture                            1         2         0.69897   1         0.69897   
wine                               1         5         0.30103   1         0.30103   


**Articulo** 9
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
accent                             1         1         1         1         1         
brisk                              1         2         0.69897   1         0.69897   
dried                              1         2         0.69897   1         0.69897   
elegant                            1         1         1         1         1         
flavors                            1         3         0.522879  1         0.522879  
footprint                          1         1         1         1         1         
fresh                              1         4         0.39794   1         0.39794   
fruity                             1         2         0.69897   1         0.69897   
note                               1         2         0.69897   1         0.69897   
off-dry                            1         1         1         1         1         
peach                              1         1         1         1         1         
preserve                           1         1         1         1         1         
savory                             1         2         0.69897   1         0.69897   
sprightly                          1         1         1         1         1         
sunnier                            1         1         1         1         1         
thyme                              1         1         1         1         1         
wine                               1         5         0.30103   1         0.30103   


**Articulo** 10
-----------
Termino                            Rep       DF        IDF       TF        TF-IDF    
a                                  1         7         0.154902  1         0.154902  
acidity                            1         7         0.154902  1         0.154902  
apple                              1         2         0.69897   1         0.69897   
balance                            1         3         0.522879  1         0.522879  
crisp                              1         2         0.69897   1         0.69897   
depth                              1         1         1         1         1         
drink                              1         1         1         1         1         
dry                                1         2         0.69897   1         0.69897   
flavor                             1         1         1         1         1         
fresh                              1         4         0.39794   1         0.39794   
fruits                             1         2         0.69897   1         0.69897   
great                              1         1         1         1         1         
pear                               1         1         1         1         1         
spice                              1         2         0.69897   1         0.69897   
texture                            1         2         0.69897   1         0.69897   
touch                              1         1         1         1         1         


-----Similitudes-----
A1 -> A2: 0.056097
A1 -> A3: 0.056611
A1 -> A4: 0.0993202
A1 -> A5: 0
A1 -> A6: 0.133538
A1 -> A7: 0.21225
A1 -> A8: 0.133538
A1 -> A9: 0.129081
A1 -> A10: 0.115647
A2 -> A3: 0.118725
A2 -> A4: 0.0677495
A2 -> A5: 0.133734
A2 -> A6: 0.093352
A2 -> A7: 0.278207
A2 -> A8: 0.280056
A2 -> A9: 0.117647
A2 -> A10: 0.181902
A3 -> A4: 0.105102
A3 -> A5: 0.0544824
A3 -> A6: 0.155491
A3 -> A7: 0.0561513
A3 -> A8: 0.141311
A3 -> A9: 0.136595
A3 -> A10: 0.122379
A4 -> A5: 0.0918472
A4 -> A6: 0.136399
A4 -> A7: 0.162598
A4 -> A8: 0.0806381
A4 -> A9: 0.0520738
A4 -> A10: 0.0698346
A5 -> A6: 0.106117
A5 -> A7: 0.0754325
A5 -> A8: 0.159175
A5 -> A9: 0.0539877
A5 -> A10: 0.0822007
A6 -> A7: 0.176604
A6 -> A8: 0.111111
A6 -> A9: 0.093352
A6 -> A10: 0.144338
A7 -> A8: 0.19868
A7 -> A9: 0.111283
A7 -> A10: 0.229416
A8 -> A9: 0.070014
A8 -> A10: 0.433013
A9 -> A10: 0.0606339
```