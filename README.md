Сортировка чисел
=============================

  Размер памяти необходимый для массива из миллиарда double чисел превышает допустимый (10^9 чисел требуют около 8 гигабайт памяти). То есть хранить все полученные числа в памяти не получится. Реализуем сортировку на меньшем примере.
  
  Для того чтобы не заполнять массив из большого количества элементов вручную, создадим функцию для генерации случайных чисел. Её будем вызывать циклически, заполняя все элементы массива. Для этой функции используем формулу:
 
        (double)(rand())/RAND_MAX * SIZE
  
, которая генерирует случайное число от 0 до N. Для того чтобы числа генерировались в другом диапазоне, изменим формулу до:

        (double)(rand())/RAND_MAX*(max - min) + min

, где max и min – соответственно, наибольшее и наименьшее значение, которое может принимать случайное значение.
	
  В качестве метода сортировки выберем метод сортировки Шелла, так как он не включает больших затрат на память. Мы начинаем с n/2 подсписков (половина длины сортируемого массива), на следующем проходе сортируются n/4 подсписков и т. д. Таким образом, формируется массив, в котором подмассивы элементов, стоящие друг от друга на заданное число элементов, сортируются отдельно. 

  Такой алгоритм сортирует массив в худшем случае со сложностью O(n^2), в лучшем – O(n). В среднем случае сложность = O(n*log(n)^2): 1-ый цикл работает за log(n), каждый из которых вызывает ещё один цикл из log(n) по n.
  
=============================
Программа компилируется, как в Windows, средствами Visual Studio, так и в консоли Linux с помощью команды g++ Sort.cpp –o Sort.
=============================
=============================
Также программа использует следующие библиотеки: 
1) #include <iostream> – стандартная библиотека ввода-вывода, необходимая для вывода в консоль;
2) #include <cstdlib> – заголовочный файл определяет несколько функций общего назначения, необходим для применения инициализатора генератора псевдослучайных чисел (Функция srand) и определения максимального значения, генерируемого функцией rand (RAND_MAX).
3) #include <ctime> – заголовочный файл содержит функции для работы со временем, необходима для инициализации генератора случайных чисел;
4) #include <chrono> – библиотека также работает со временем, необходима для определения интервала работы сортировки;
5) #include <algorithm> – библиотека алгоритмов, упрощающая написание и понимание кода; необходима для замены функцией swap обмена значений переменных.
