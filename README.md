Задание:
========

Имеется массив структур с информацией о студентах. 
В структуре в качестве подструктуры задаются фамилия, имя, отчество студентов. 
Их медицинские параметры задаются в виде объединения в этой же структуре. 
По запросу из командной строки выдать информацию о студентах с соответствующими признаками. 

Объединения включают: 
а) рост, вес; 
б) рост, вес, два-три других параметра.

Описание программы:
===================

В начале программы вводятся команды:

### 1 - Ввод данных (Enter data)
1) Вводится имя. Имя не дожно быть пустой строкой, а так же не должно начинаться с пробелов.
2) Вводится фамилия. Аналогично имени.
3) Вводится отчество. Аналогично имени.
4) Вводится рост. Число должно быть больше нуля. Дробная часть вводится через точку.
5) Вводится вес. Аналогично росту.
6) Вводится зрение. Аналогично росту.
7) Вводится группа крови. Целое, положительное число.

### 2 - Вывод роста и веса (Print a) data)
Выводит полные имена всех студентов, а так же рост и вес.

### 3 - Вывод роста, веса, зрения и группы крови (Print b) data)
Выводит полные имена всех студентов, а так же рост, вес, зрение и группу крови.

### 4 - Выход из программы (Exit)
Завершает программу